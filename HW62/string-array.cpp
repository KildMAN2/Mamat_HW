//
// Created by sari mansour on 31/03/2024.
//
#include "string-array.h"
#include <algorithm>
#include <cassert>

StringArray :: StringArray(int capacity) : capacity(capacity), CurrentSize(0)
{
    array = new GenericString * [capacity];
}
StringArray :: ~StringArray()
{
    for (int i = 0; i < CurrentSize; ++i)
    {
        delete array[i];
    }
    delete array;
}
StringArray ::StringArray(const StringArray &other) : capacity(other.capacity),
CurrentSize(other.CurrentSize)
{
    array = new GenericString * [capacity];
    for (int i = 0; i < CurrentSize; ++i)
    {
       array[i] = other.array[i];
    }
}
StringArray& StringArray::operator=(const StringArray &other) {
    if (this != &other) {
        // Deep copy with proper cleanup
        GenericString** newArray = new GenericString*[other.capacity];
        for (int i = 0; i < other.CurrentSize; ++i) {
            newArray[i] = other.array[i];
        }
        for (int i = 0; i < CurrentSize; ++i) {
            delete array[i];
        }
        delete[] array; // Correctly delete the old array
        array = newArray;
        capacity = other.capacity;
        CurrentSize = other.CurrentSize;
    }
    return *this;
}

void StringArray::resize()
{
    capacity *=2;
    GenericString** newArray = new GenericString* [capacity];
    std::copy(array, array + CurrentSize,newArray); // i asked chat chpt for easy way to copy arraies
    delete [] array;
    array = newArray;
}
void StringArray::add(GenericString *str)
{

    if(CurrentSize >= capacity)
    {
        resize();
    }
    array[CurrentSize++] = new String(str->as_string());
}
void StringArray::remove(int index)
{
    if ((index >=0) && (index < CurrentSize))
    {
        delete array[index];
        for (int i = index; i < CurrentSize-1; ++i)
        {
            array[i] = array[i + 1];
        }
        array[CurrentSize - 1] = nullptr;
        CurrentSize--;
    }
}
int StringArray::size()
{
    return CurrentSize;
}
GenericString* StringArray::get(int index) const
{
    assert((index >=0) && (index < CurrentSize));
    return array[index];
}
GenericString* StringArray::get(int index)
{
    assert((index >=0) && (index < CurrentSize));
    return array[index];
}