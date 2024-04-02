//
// Created by Badir on 28/03/2024.
//

#ifndef HW06_NEW__IP_H
#define HW06_NEW__IP_H
#include "generic-field.h"
#include "string.h"

class ip : public GenericField {
    String currentField;
    int legalBits;
    int ipFields[4];

public:
    ip(String str);
    virtual bool match(const GenericString &packet) const ;
    virtual void rules(const GenericString &packet);
    bool check_Shifting(String array)const;
    int shift_Right(int val , int after_slash)const;
};
#endif //HW06_NEW__IP_H
