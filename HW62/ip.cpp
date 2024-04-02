//
// Created by sari mansour on 30/03/2024.

#include "ip.h"
#include "string.h"
#define INIT_VALUE -1

ip :: ip(String str) : currentField(str) {
    for (int i=0;i<4;i++){
        this->ipFields[i] = INIT_VALUE;
    }
    this->legalBits=0;
}


bool ip ::match(const GenericString &packet) const {

    bool val = false;
    int size;

    StringArray arr=packet.split("=, ");
    size=arr.size();
    if(!size )
    {
        return false;
    }
    for (int i = 0; i < size; i=i+2) {
        if(currentField.operator==((arr.get(i)->as_string()))){
            val = check_Shifting(arr.get(i + 1)->as_string());
            break;
        }
    }
    return val;

}

bool ip:: check_Shifting(String array) const{
    int  after_slash = this->legalBits;
    array= array.trim().as_string();
    int temp[4];
    int i =0,k = 0;
    while(i<4)
    {
        temp[i] = this->ipFields[i];
        i++;
    }
    StringArray dotArray=array.split(".");

    if(!after_slash)
    {
        return true;
    }


    // check the ip code by the set_value.
    while (after_slash>0)

    {
        if(dotArray.get(k)->to_integer() != this->ipFields[k]
           && after_slash >= 8)
        {
            return false;
        }

        if( ((shift_Right(after_slash, dotArray.get(k)->to_integer()))
             != (shift_Right(temp[k], after_slash)))
            &&  (after_slash<8))
        {
            return false;

        }

        after_slash = (after_slash - 8);
        k++;
    }
    return true;
}

void ip :: rules(const GenericString &packet){
    const String& rule = packet.as_string();

        // Split rule by slashes to separate the IP and mask.
        StringArray slashSplit = rule.split("/");
        // Split the IP part by dots.
        StringArray dotSplit = slashSplit.get(0)->as_string().split(".");

        this->legalBits = slashSplit.get(1)->as_string().to_integer();

        for (int k = 0; k < 4; ++k) {
            this->ipFields[k] = dotSplit.get(k)->as_string().to_integer();
        }
}

int ip::shift_Right(int val, int after_slash) const {
    int t = val;
    for(int i = 0; i<(8-after_slash);i++){
        t=t/2;
    }
    return t;
}


