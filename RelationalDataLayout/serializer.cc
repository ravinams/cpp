/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstring>
#include <cassert>
#include <vector>
#include <iostream>
#include "serializer.h"


/**
 * Compute the number of bytes required to serialize record
 */
int fixed_len_sizeof(Record *record) {
    
    int size = 0 ;
    for(Record::iterator i = record->begin(); i != record->end(); i++) {
         size += strlen(*i);    
    }
    return size ;
}

/**
 * Serialize the record to a byte array to be stored in buf.
 */
void fixed_len_write(Record *record, void *buf)
{
    
    for(Record::iterator i = record->begin(); i != record->end(); i++) {
        memcpy(buf, *i, ATTRIBUTE_SIZE);
        buf = (char *) buf + ATTRIBUTE_SIZE;
    }
}

/**
 * Deserializes `size` bytes from the buffer, `buf`, and
 * stores the record in `record`.
 */
void fixed_len_read(void *buf, int size, Record *record)
{
    assert(size == fixed_len_sizeof(record));  
    
    for(int i = 0; i < ATTRIBUTE_COUNT; i++) {
        memcpy((char *) record->at(i), (char *) buf + ATTRIBUTE_SIZE * i, ATTRIBUTE_SIZE);
    }
}






