//
// Created by sari mansour on 31/03/2024.
//

#ifndef HW6_STRING_ARRAY_H
#define HW6_STRING_ARRAY_H

#include "generic-string.h"
#include "string.h"

class StringArray {

private:
    GenericString** array;
    int capacity;
    int CurrentSize;


    // private function to resize array when it maxed
    void resize ();

public:
    void clear(); // Declaration of the clear method

    StringArray(int capacity = 4);
    ~StringArray();
    StringArray (const StringArray &other)  ;
    StringArray & operator = (const StringArray &other) ;
    void add(GenericString* str);
    void remove(int index);
    GenericString* get(int index) const;
    int size();
    GenericString* get(int index);

};




#endif //HW6_STRING_ARRAY_H
