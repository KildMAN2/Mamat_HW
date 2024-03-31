//
// Created by sari mansour on 31/03/2024.
//

#ifndef HW6_STRING_H
#define HW6_STRING_H

#include "generic-string.h"
#include "string-array.h"

class String : public GenericString
{
private:
    char* data;
    int length;


public:
    String();
    String(const String &str);
    explicit String(const char * str);
     bool operator==(const GenericString &other) const override  ;
     bool operator==(const char *other) const override ;
    StringArray split(const char *delimiters) const override ;
    GenericString& operator=(const char *str) override ;
    GenericString& trim() override ;
    int to_integer() const override ;
    String& as_string() override ;
    const String& as_string() const override ;
    ~String() override;


};




#endif //HW6_STRING_H
