/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstring>
#include <cassert>
#include "library.h"
#include "serializer.h"

inline int _capacity(Page *page) {
    return page->page_size/(sizeof(char) + page->slot_size);
}

void *_slot_offset(Page *page, int slot) {
    return (char *) page->data + _capacity(page) + page->slot_size * slot;
}

/**
 * Find an empty slot in the given page and return its index. Return -1 if
 * page is full.
 */
inline int _find_empty_slot(Page *page) {
    char *slot = (char*) page->data;
    for (int i = 0; i < _capacity(page); ++slot, ++i)
        if (*slot == 0)
            return i;
    return -1;
}
/**
 * Initializes a page using the given slot size
 */
void init_fixed_len_page(Page *page, int page_size, int slot_size) {
    /* Set page and slot sizes */
    page->page_size = page_size;
    page->slot_size = slot_size;

    /* Allocate memory and initialize slot directory */
    page->data = new char[page_size];
    memset(page->data, 0, page_size);
}

/**
 * Calculates the maximal number of records that fit in a page
 */
int fixed_len_page_capacity(Page *page) {
    return _capacity(page);
}

/**
 * Calculate the free space (number of free slots) in the page
 */
int fixed_len_page_freeslots(Page *page) {
    char *directory = (char *) page->data;
    int slots = 0;
    for(int i = 0; i < _capacity(page); i++)
        slots += 1 - directory[i];
    return slots;
}

/**
 * Add a record to the page
 * Returns:
 *   record slot offset if successful,
 *   -1 if unsuccessful (page full)
 */
int add_fixed_len_page(Page *page, Record *r) {
    /* If slot is smaller than serialized record we can't store it */
    if(fixed_len_sizeof(r) > page->slot_size) {
        return -1;
    }

    int slot;
    if ((slot = _find_empty_slot(page)) != -1) {
        write_fixed_len_page(page, slot, r);
        return slot;
    }

    return -1;
}

/**
 * Write a record into a given slot.
 */
void write_fixed_len_page(Page *page, int slot, Record *r) {
    assert(slot >= 0);
    /* Write the record and mark the slot as filled. */
    fixed_len_write(r, _slot_offset(page, slot));
    ((char*) page->data)[slot] = 1;
}

/**
 * Read a record from the page from a given slot.
 */
bool read_fixed_len_page(Page *page, int slot, Record *r) {
    assert(slot >= 0);
    if (((char*)page->data)[slot] != 1)
        return false;
    fixed_len_read(_slot_offset(page, slot), fixed_len_sizeof(r), r);
    return true;
}
