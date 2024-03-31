#ifndef STRING_H
#define STRING_H

#include "string-array.h" // Include the StringArray header

#include <cstring> // For strlen, strcpy, strtok
#include <cstdlib> // For atoi

class String {
private:
    char* data;
    size_t length;

public:
    // Constructor
    String(const char* str);

    // Destructor
    ~String();

    // Copy constructor
    String(const String& other);

    // Assignment operator
    String& operator=(const String& other);

    // Method to split the string into substrings based on a delimiter
    StringArray split(const char* delimiters) const;

    // Method to convert the string representation of an integer to an actual integer value
    int to_integer() const;

    // Method to compare two strings for equality
    bool equals(const String& other) const;

    // Method to remove leading and trailing whitespace from the string
    void trim();

    // Method to convert String to GenericString
    operator GenericString() const;
};

#endif // STRING_H
