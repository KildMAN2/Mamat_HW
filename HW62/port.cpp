//
// Created by sari mansour on 30/03/2024.

#include "port.h"


port::port(String str) : CurrentField(str) {
    portRanges[0]=0;
    portRanges[1]=0;
}
bool port::helping_func(String arr) const{
    int port_value = arr.trim().to_integer();
    return ((port_value >= portRanges[0]) && (port_value <= portRanges[1]));

}

bool port::match(const GenericString &packet) const {

    bool val = false;


    StringArray arr=packet.split("=, ");
    int size = arr.size();
    if(!size )
    {
        return false;
    }
    for (int i = 0; i < size; i=i+2) {
        if(CurrentField == ((arr.get(i)->as_string())))
        {
            val=helping_func(arr.get(i+1)->as_string());
            break;
        }
    }
    return val;

}

void port :: rules(const GenericString &packet){
    const String* rule = &packet.as_string();
    // Split the rule string based on the delimiter '-'
    StringArray splitResult = rule->split("-");

    // Check if the split operation gave us two parts (start and end of the range)
    if (splitResult.size() >= 2) {
        // Convert the start and end of the range from String to integer and store them
        portRanges[0] = splitResult.get(0)->trim().to_integer();
        portRanges[1] = splitResult.get(1)->trim().to_integer();
    }
}


