//
// Created by sari mansour on 31/05/2023.
//

#include "port.h"
#include "string.h"

#define MAX 65535
#define MIN 0
#define LENGTH 2
#define ONE 1



Port ::Port(String value)
{
    src_port =0;
    dst_port= 0 ;
    set_value(value);
}

bool Port::set_value(String value)
{
    // Remove leading and trailing whitespaces
    value.trim();
    String *split_packets;
    size_t Num_fields;
    value.split("-",&split_packets,&Num_fields);
    if (Num_fields!=LENGTH)
    {
        delete []split_packets;
        return false;
    }
    src_port = split_packets[0].to_integer();
    dst_port = split_packets[ONE].to_integer();
    if (src_port <MIN || src_port>MAX || dst_port <MIN || dst_port >MAX)
    {
        delete [] split_packets;
        return false; // Invalid port range format
    }
    delete [] split_packets;
    return true;
}

bool Port::match(String packet) {
    packet.trim();
    String *fields;
    size_t num_fields;
    // split by space and ","
    packet.split(",", &fields, &num_fields);
    for (size_t i = 0; i < num_fields; ++i)
    {
        fields[i].trim();
        String *Key_Values;
        size_t num_key_values;
        // split by space and "="
        fields[i].split("=", &Key_Values, &num_key_values);
        if ((num_key_values == LENGTH) && (Key_Values[0].equals("src-port")))
        {
            int port_value = Key_Values[ONE].to_integer();
            if (port_value >= src_port && port_value <= dst_port)
            {
                delete[] fields;
                delete[] Key_Values;
                return true;
            }
        }

        delete[] Key_Values;
    }
    delete[] fields;
    return false;
}
