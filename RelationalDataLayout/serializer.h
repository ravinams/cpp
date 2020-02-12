/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   serializer.h
 * Author: 
 *
 * Created on February 15, 2018, 8:26 AM
 */

#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <vector>

typedef const char * V;
typedef std::vector<V> Record;

const int ATTRIBUTE_SIZE = 10;
const int ATTRIBUTE_COUNT = 100;

/**
 * Compute the number of bytes required to serialize record
 */
int fixed_len_sizeof(Record *record);

/**
 * Serialize the record to a byte array to be stored in buf.
 */
void fixed_len_write(Record *record, void *buf);

/**
 * Deserializes `size` bytes from the buffer, `buf`, and
 * stores the record in `record`.
 */
void fixed_len_read(void *buf, int size, Record *record);

#endif /* SERIALIZER_H */

