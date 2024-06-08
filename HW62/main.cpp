#include <iostream>
#include "port.h"
#include "ip.h"
#include "input.h"
#include "string.h"

int main(int argc, char** argv) {
    if (argc <2)
        return -1;

    char delimiters[2] = {'=', ','};
    String trimArray = String(argv[1]);
    trimArray=trimArray.trim().as_string();
    StringArray splitArray = trimArray.split(delimiters);


    if(splitArray.get(0)->as_string() == "src-ip")
    {
        ip srcIp("src-ip");
        srcIp.rules(splitArray.get(1)->as_string());
        parse_input(srcIp);
    }
    if((splitArray.get(0))->as_string() == ("dst-ip")){
        ip dstIp("dst-ip");
        dstIp.rules(*splitArray.get(1));
        parse_input(dstIp);
    }
    if(splitArray.get(0)->as_string() == "src-port"){
        port srcPort("src-port");
        srcPort.rules(splitArray.get(1)->as_string());
        parse_input(srcPort);


    }
    if((splitArray.get(0)->as_string() == "dst-port"))
    {
        port dstPort("dst-port");
        dstPort.rules(splitArray.get(1)->as_string());
        parse_input(dstPort);
    }
    return 0;
}
