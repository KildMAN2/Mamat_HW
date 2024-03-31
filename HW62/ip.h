#ifndef IP_H
#define IP_H

#include "string.h" // Ensure this includes your custom String class
#include "generic-field.h"

class Ip : public GenericField {
private:
    String currentField;
    StringArray ip_fields;
    int legal_bits;
public:
    Ip(String packet);
    bool set_value(GenericString &packet);
    bool match(const GenericString &packet) const;
};

#endif // IP_H
