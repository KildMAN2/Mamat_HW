//
// Created by sari mansour on 31/03/2024.
//
//
// Created by sari mansour on 31/05/2023.
//

#include "port.h"
#include "string.h"

#define MAX 65535
#define MIN 0
#define LENGTH 2
#define ONE 1






bool Port::set_value(String value) {
    StringArray parts = value.trim().split("-");
    if (parts.size() != 2) return false;

    src_port = parts.get(0)->to_integer();
    dst_port = parts.get(1)->to_integer();

    if (src_port < MIN || dst_port > MAX) return false;
    return src_port <= dst_port;
}


bool  Port::match(const GenericString &packet) const {
    const String& packetStr = packet.as_string();
    StringArray fields = packetStr.split(",");
    for (int i = 0; i < fields.size(); ++i)
    {
        const String& field = fields.get(i)->as_string();
        StringArray keyValue = field.split("=");
        if(keyValue.size() == LENGTH)
        {
            const String& key = keyValue.get(0)->as_string();
            const String& value = keyValue.get(ONE)->as_string();
            if(key == "src-port")
            {
                int portValue = value.to_integer();
                if((portValue >= src_port) && (portValue <= dst_port))
                    return true;
            }
        }

    }
    return false;
}
Port::Port(const String& value) {
    set_value(value);
}



