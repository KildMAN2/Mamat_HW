//
// Created by sari mansour on 02/06/2023.
//

#ifndef PORT_H
#define PORT_H
#include "generic-field.h"
#include "string.h"


class Port : public GenericField{
private:

    /**
     * @brief source port value
     */
    int src_port;
    int dst_port; /** <destination port value> */

public:
    /**
     * @brief Default constructor for port class
     * initializes the port with specified value
     */
    Port(String value);
    /**
     * @brief Sets the Port number value based on the provided string.
     * @param value the string containing the port number value
     * @return True if the Port valid and set successfully , False otherwise
     */
    bool set_value(String value) ;
    /**
     * @brief Matches the port filed of a packet with the stored port number
     * @param packet the packet string to match against
     * @return True if the Port field matches the sorted port number, False otherwise
     */
    bool match (String packet) ;
};
#endif //PORT_H
