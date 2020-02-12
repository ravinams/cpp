#include "SSLColumn.h"
#include <iostream>
#include <stdexcept>
#include <climits>
using namespace std;

SSLColumn::SSLColumn(int n)
{
    m_data = new int[n];
    m_start = 0;
    m_end = 0;
    m_capacity = n;
    m_size = 0;
    
    for (int i = 0; i < n; i++) {
        m_data[i] = INT_MAX;
    }
}

SSLColumn::SSLColumn(const SSLColumn & other)
{
    m_start = other.m_start;
    m_end = other.m_end;
    m_capacity = other.m_capacity;
    m_size = other.m_size;
    m_data = new int[m_capacity];
    
    
    for (int i = 0; i < m_capacity; i++) {
        m_data[i] = other.m_data[i];
    }
}

SSLColumn::~SSLColumn()
{
    delete[] m_data;
}

const SSLColumn & SSLColumn::operator=(const SSLColumn & rhs)
{
    if (m_capacity > rhs.m_capacity) {
        int ri = rhs.m_start;
        for (int i = 0; i < rhs.m_size; i++) {
            
            if (ri > rhs.m_capacity - 1)
                ri = 0;
            m_data[i] = (rhs.m_data[ri]);
            ri++;
        }
    }
    else
    {
        m_capacity = rhs.m_capacity;
        delete[] m_data;

        m_data = new int[m_capacity];
        int ri = rhs.m_start;
        for (int i = 0; i < m_capacity; i++) {
            
            if (ri > rhs.m_capacity - 1)
                ri = 0;
            m_data[i] = (rhs.m_data[ri]);
            ri++;
        }
    }
    
    
    m_size = rhs.m_size;
    m_start = 0;
    m_end = m_size;
    
    
    return *this;
}

void SSLColumn::add(int data)
{
    //size!=capacity, otherwise array is full
    if (m_size < m_capacity)
    {
        //If array is empty -> put data to end of buffer and move end pointer t\
        o the right
        if (m_size == 0) {
            m_data[m_end] = data;
            m_end++;
            m_size++;
        }
        else
        {
            
            int c = m_start;
            
            int end = m_end - 1;
            
            if (end < 0)
                end = m_capacity - 1;
            if (data >= m_data[end]) {
                m_data[m_end] = data;
                m_size++;
                m_end++;
                
                if (m_end > m_capacity - 1)
                    m_end = 0;
                
            }
            else if (data <= m_data[m_start]) {
                m_start--;
                if (m_start < 0)
                    m_start = m_capacity - 1;
                m_data[m_start] = data;
                m_size++;
                
            }
            else {
                int current = m_start;
                int next;
                for (int i = 0; i < m_size; i++) {
                    next = current + 1;
                    if (next > m_capacity - 1)
                        next = 0;
                    if (m_data[current] <= data && m_data[next] >= data) {
                        m_start--;
                        if (m_start < 0)
                            m_start = m_capacity - 1;
                        int c = m_start;
                        while (c != current) {
                            next = c + 1;
                            if (next > m_capacity - 1)
                                next = 0;
                            m_data[c] = m_data[next];
                            c++;
                            if (c > m_capacity - 1)
                                c = 0;
                        }
                        m_data[current] = data;
                        m_size++;
                        break;
                        
                    }
                    current++;
                    if (current > m_capacity - 1)
                        current = 0;
                }
            }
        }
        
    }
    else {
        throw std::overflow_error("column full");
    }
    
}


void SSLColumn::addFirst(int data)
{
    //Check for room in array
    if (m_size < m_capacity) {
        //Shift start to the left. If the array is not full, there will be no val\
        ue here.
        m_start--;
        //If start is at index 0, it will be out of bounds after shift. So start \
        will be last index of array.
        if (m_start < 0)
            m_start = m_capacity - 1;
        
        //Put value at start and increase size.
        m_data[m_start] = data;
        m_size++;
    }
    else
        throw std::overflow_error("column full");
}

void SSLColumn::addLast(int data)
{
    //Check for room in array
    if (m_size < m_capacity) {
        //put data at end of buffer
        m_data[m_end] = data;
        
        m_end++;
        if (m_end > m_capacity - 1) {
            m_end = 0;
        }
        
        m_size++;
    }
    else
        throw std::overflow_error("column full");
}

int SSLColumn::find(int data)
{
    int first = 0,                 //first array element
    last =  m_size,            //last array element
    middle;                        //mid point of search
    
    while (first <= last)
    {
        
        
        middle = (first + last) / 2; //this finds the mid point
        
        int middleT = middle + m_start;
        if (middleT > m_capacity - 1)
            middleT -= m_capacity;
        
        if (m_data[middleT] == data) {
            return middle;
        }
        else if (m_data[middleT]> data) // if it's in the lower half
        {
            last = middle - 1;
        }
        else {
            first = middle + 1;                 //if it's in the upper half
        }
    }
    return -1;  // not found
    
    
}

int SSLColumn::findAt(int pos)
{
    if (m_size > 0) {
        if (pos == -1) {
            if (m_end - 1 >= 0)
                return m_data[m_end - 1];
        }
        
        if(pos < -1)
        {
            throw std::underflow_error("bad position");
        }
        
        if(pos > m_end)
        {
            throw std::overflow_error("bad position");
        }
        
        int n = pos + m_start;
        if (n > m_capacity - 1) {
            n -= m_capacity;
        }
        return m_data[n];
    }
    else
        throw std::underflow_error("Buffer is empty");
}

int SSLColumn::remove(int data)
{
    if (m_size > 0) {
        int n = m_start;
        for (int i = m_start; i < m_size+m_start;i++) {
            if (n > m_capacity - 1){
                n = 0;
            }
            if(m_data[n] == data){
                if(n == m_start){
                    m_start++;
                    if (m_start > m_capacity - 1) {
                        m_start = 0;
                    }
                }
                else {
                    for(int j = n; j < m_size+m_start; j++){
                        m_data[j] = m_data[j+1];
                    }
                    m_end--;
                    if (m_end < 0) {
                        m_end = m_capacity - 1;
                    }
                }
                m_size--;
            }
            n++;
        }
    }
    else {
        throw std::underflow_error("Buffer is empty");
    }
    return 0;
}

int SSLColumn::removeFirst(void)
{
    int value = 0;
    if (m_size > 0) {
        value = m_data[m_start];
        m_start++;
        if (m_start > m_capacity - 1) {
            m_start = 0;
        }
        m_size--;
        
        return value;
    }
    else {
        throw std::underflow_error("Buffer is empty");
    }
}

int SSLColumn::removeLast(void)
{
    
    if (m_size > 0) {
        m_end--;
        if (m_end < 0) {
            m_end = m_capacity - 1;
        }
        m_size--;
        return m_data[m_end];
    }
    else {
        throw std::underflow_error("Buffer is empty");
    }
    
}

int SSLColumn::capacity()
{
    return m_capacity;
}

int SSLColumn::size()
{
    return m_size;
}

void SSLColumn::dump()
{
    //std::cout << "-----" << std::endl;
    int n = m_start;
    for (int i = m_start; i < m_size+m_start;i++) {
        if (n > m_capacity - 1)
            n = 0;
        std::cout << m_data[n] << std::endl;
        n++;
    }
    //  std::cout << "-----" << std::endl;
}

