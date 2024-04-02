//
// Created by sari mansour on 30/03/2024.
//

#ifndef HW06_NEW__PORT_H
#define HW06_NEW__PORT_H

#include "generic-field.h"
#include "string.h"

class port : public GenericField {
    String CurrentField;
    int portRanges[2];


public:
    port(String str);
    virtual bool match(const GenericString &packet) const ;
    virtual void rules(const GenericString &packet);
    bool helping_func(String arr)const;
};

#endif //HW06_NEW__PORT_H
