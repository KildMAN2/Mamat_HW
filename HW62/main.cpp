#include <iostream>
#include "input.h"
#include "string.h"
#include "ip.h"
#include "port.h"


int main(int argc, char **argv) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <field>=<value>" << std::endl;
        return -1;
    }

    String input = String(argv[1]);
    input = input.trim().as_string();
    StringArray inputArgs = input.split("=,");

    if (inputArgs.size() != 2) {
        std::cerr << "Invalid input format. Please provide input in the format <field>=<value>" << std::endl;
        return -1;
    }

    String fieldName = inputArgs.get(0)->trim().as_string();
    String fieldValue = inputArgs.get(1)->trim().as_string();

    if (fieldName == ("src-ip")) {
        String temp ( "src-ip");
        Ip srcIp(temp);
        if (!srcIp.set_value(fieldValue)) {
            std::cerr << "Invalid src-ip value." << std::endl;
            return -1;
        }
        parse_input(srcIp);
    } else if (fieldName == ("dst-ip")) {
        String tempdstIp ( "dst-ip");
        Ip dstIp(tempdstIp);
        if (!dstIp.set_value(fieldValue)) {
            std::cerr << "Invalid dst-ip value." << std::endl;
            return -1;
        }
        parse_input(dstIp);
    } else if (fieldName == ("src-port")) {
        String tempsrcPort ( "src-port");
        Port srcPort(tempsrcPort);
        if (!srcPort.set_value(fieldValue)) {
            std::cerr << "Invalid src-port value." << std::endl;
            return -1;
        }
        parse_input(srcPort);
    } else if (fieldName == ("dst-port")) {
        String tempdstPort ( "dst-port");
        Port dstPort(tempdstPort);
        if (!dstPort.set_value(fieldValue)) {
            std::cerr << "Invalid dst-port value." << std::endl;
            return -1;
        }
        parse_input(dstPort);
    } else {
        //std::cerr << "Unknown field name: " << fieldName << std::endl;
        return -1;
    }

    return 0;
}
