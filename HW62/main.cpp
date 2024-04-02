#include <iostream>
#include "port.h"
#include "ip.h"
#include "input.h"
#include "string.h"

int main(int argc, char** argv) {
    if (argc <2)
        return -1;

    char delimeters[2] = {'=',','};
    String trimArray = String(argv[1]);
    trimArray=trimArray.trim().as_string();
    StringArray splitArray = trimArray.split(delimeters);


    if(splitArray.get(0)->as_string() == "src-ip")
    {
        ip srcIp("src-ip");
        srcIp.rules(splitArray.get(1)->as_string());
        parse_input(srcIp);
    }
    if((splitArray.get(0))->as_string().operator==("dst-ip")){
        ip dstIp("dst-ip");
        dstIp.rules(*splitArray.get(1));
        parse_input(dstIp);
    }
    if(splitArray.get(0)->as_string() == "src-port"){
        port srcport("src-port");
        srcport.rules(splitArray.get(1)->as_string());
        parse_input(srcport);


    }
    if((splitArray.get(0)->as_string() == "dst-port"))
    {
        port dstport("dst-port");
        dstport.rules(splitArray.get(1)->as_string());
        parse_input(dstport);
    }
    return 0;
}
