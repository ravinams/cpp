/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   library.h
 * Author: oracle
 *
 * Created on February 15, 2018, 9:06 AM
 */

#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>

// PAGE
typedef const char* V;
typedef std::vector<V> Record;


typedef struct {
    void *data; // Points to a byte array (Record).
    int page_size; // The total page_size, implicitly includes size_of_directory
    int slot_size; // How big a Record is.
} Page;


void init_fixed_len_page(Page *page, int page_size, int slot_size);

int fixed_len_page_capacity(Page *page);

int fixed_len_page_freeslots(Page *page);

int add_fixed_len_page(Page *page, Record *r);

void write_fixed_len_page(Page *page, int slot, Record *r);

bool read_fixed_len_page(Page *page, int slot, Record *r);

#endif /* LIBRARY_H */

