//
// Created by sari mansour on 31/03/2024.
//
#include "string.h"
#include <cstring>
#include <cstdlib>

String :: String(const char *str)
{
    data = new char [strlen(str) + 1];
    strcpy(data,str);
    length = strlen(str) + 1;
}

String ::String()
{
    data = new char[1];
    data[0] ='\0';
    length = 1;
}

String& String::operator=(const String &other) {
    if (this != &other) {
        char* newData = new char[other.length ];
        strcpy(newData, other.data);
        delete[] data;
        data = newData;
        length = other.length;
    }
    return *this;
}


String ::String(const String &str)
{
    data = new char [str.length];
    length = str.length;
    strcpy(data,str.data);
}
StringArray String ::split(const char *delimiters) const
{
    StringArray  result ;
    if (!data || !delimiters)
    {
        return result;
    }
    int start = 0; // start index of substring
    for (int i = 0; i < length; ++i)
    {
        // Create substring from start to i and add to the stringArray result
        if (strchr(delimiters, data[i]) != nullptr)
        {
            if(i > start)
            {
                // create substring for start to i and add to result
                char* substring = new char [i - start +1];
                strncpy(substring, data + start, i - start);
                substring[i - start] = '\0';
                GenericString * temp = make_string(substring);
                result.add(temp);
                delete [] substring;
                delete temp;
            }
            start = i + 1; //move start to the past delimiter
        }

    }
    // handle last substring if not followed by a delimiter
    if(start < length)
    {
        char* substring = new char [length - start + 1];
        strncpy(substring, data + start,length - start);
        substring[length - start] = '\0';
        GenericString * temp = make_string(substring);
        result.add(temp);
        delete [] substring;
        delete temp;
    }
    return result;
}

GenericString& String::operator =(const char *str){
    if (this->data != str)
    {
        delete[]data;
        data = new char[strlen(str) + 1];
        strcpy(data, str);
        length = strlen(str) + 1;
    }
    return *this;
}
bool String ::operator==(const GenericString &other) const {
    const String* otherString = dynamic_cast<const String*> (&other);
    if(otherString)
    {
        return strcmp(data,otherString->data) ==0 ; //succeed
    }
    return false;
}
bool String :: operator ==(const char *str) const
{
    return strcmp(data,str) == 0;
}
int String :: to_integer() const {
    return atoi(data);
}
String& String ::as_string() {
    return dynamic_cast <String&> (*this);
}
const String& String ::as_string() const {
    return dynamic_cast <const String&> (*this);
}
GenericString* make_string(const char *str)
{
    return new String(str); // Assuming String is derived from GenericString
}
String::~String() {
   // if (length == 0 && data != nullptr) return;
    delete[] data;
    length = 0;
}

GenericString& String::trim() {

    int l_counter=0;//spaces at the beginning
    int r_counter=0;//spaces at the end

//checks the number of spaces at the start of the string
    for (int i =0;i<length;i++) {
        if (data[i] !=' ') break;
        l_counter++;
    }
//checks the number of spaces at the end of the string
    for (int j = length - 1; j>=0 ;j--) {
        if (data[j] !=' ') break;
        r_counter++;
    }
    int newLength = length -r_counter-l_counter;
    char* newdata = new char [newLength +  1];
    for (int m = 0, n = l_counter; n < length - r_counter; m++, n++) {
        newdata[m] = data[n];
    }
    newdata[newLength] = '\0';
//deleting leading and railing spaces

    delete [] data;
    data = newdata;
    length = newLength;
    return *this;
}
