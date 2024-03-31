//
// Created by sari mansour on 31/03/2024.
//

#include <cstdio>
#include "ip.h"
#include <cstring>
#include <cstdlib>





bool Ip::set_value(GenericString& packet)
{
    StringArray splitBySlash = packet.as_string().split("/");
    if (splitBySlash.size() != 2 )
    {
        return false;
    }
    int subnetMask = splitBySlash.get(1)->to_integer();
    if (subnetMask > 32 || subnetMask < 0)
    {
        return false;
    }
    StringArray splitByDot = splitBySlash.get(0)->split(".");
    if (splitByDot.size() != 4)
    {
        return false;
    }
    for (int i = 0; i < 4; ++i)
    {
        int octet = splitByDot.get(i)->to_integer();
        if (octet >255 || octet <0)
        {
            return false;
        }
        char octetStr[4]; // Max 3 digits for an octet + null terminator
        snprintf(octetStr, sizeof(octetStr), "%d", octet);

        // Use make_string (if it correctly handles allocation) to add to ip_fields.
        // Ensure make_string creates a String object, which ip_fields can store.
        ip_fields.add(make_string(octetStr));
    }
    legal_bits =subnetMask;
    return true;
}
bool  Ip::match(const GenericString &packet) const {
    String packetStr = packet.as_string();

    // Split the packet by delimiters "=", ","
    StringArray packetSplit = packetStr.split("=,");

    if (packetSplit.size() == 0) {
        return false;
    }

    for (size_t i = 0; i < packetSplit.size(); i += 2) {
        // Directly access and trim the key
        String key = packetSplit.get(i)->trim().as_string();

        // Check if this is the key we're interested in
        if (key == currentField && (i + 1 < packetSplit.size())) {
            // Trim and split the next field by "." to get the IP address segments
            StringArray splitByDots = packetSplit.get(i + 1)->trim().split(".");

            // Validate the IP address format
            if (splitByDots.size() != 4) {
                return false;
            }

            int bitsRemaining = this->legal_bits;
            for (int j = 0; j < splitByDots.size() && bitsRemaining > 0; j++) {
                int octet = splitByDots.get(j)->to_integer();
                int targetOctet = ip_fields.get(j)->to_integer(); // Assuming ip_fields stores strings that represent integers

                if (bitsRemaining >= 8) {
                    if (octet != targetOctet) {
                        return false;
                    }
                    bitsRemaining -= 8;
                } else {
                    // Check only the required bits
                    if ((octet >> (8 - bitsRemaining)) != (targetOctet >> (8 - bitsRemaining))) {
                        return false;
                    }
                    bitsRemaining = 0; // No more bits to check
                }
            }

            // If the loop completes without returning false, it's a match
            return bitsRemaining <= 0;
        }
    }

    // If no matching field was found, or if the loop completes without a match
    return false;
}
Ip ::Ip(String packet)
{
    set_value(packet);
}



