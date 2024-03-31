#include "ip.h"
#include <iostream>



ip ::ip(String packet) : current_field(packet){
    for(int i=0;i<4;i++){
        this->ip_fields[i] = -1;
    }
    legal_bits= 0;
}


bool ip::set_value(String packet) {

	String *split_by_slash;
	String *split_by_dot;
	size_t dot_count=3;
	size_t slash_count=1;

	packet.split("/",&split_by_slash,&slash_count);
	packet.split(".",&split_by_dot,&dot_count);

	if(split_by_slash[1].to_integer()>32 ||
	   split_by_slash[1].to_integer()<0	) {
		delete[] split_by_slash;
		delete[] split_by_dot;
		return false;
	}

	for(int i=0;i<(int)dot_count;i++){
		if(split_by_dot[i].to_integer()>255 || split_by_dot[i].to_integer() <0){
			delete[] split_by_slash;
			delete[] split_by_dot;
			return false;
		}
	}
//we set every field in the ip rule in array called ip_fields
	for(int i=0; i<(int)dot_count;i++){
		this->ip_fields[i] = split_by_dot[i].to_integer();
	 }

//this is the bits that we intend to check if they are similar to the rule
	legal_bits=split_by_slash[1].to_integer();

	delete[] split_by_slash;
	delete[] split_by_dot;
	return true;

}

//this is a function to check the bits if the bits we want to check are
//less than 1 byte
int bits_check(int check_bits,int field){
    int tmp = field;
    for (int i=0; i<(8-check_bits); i++) {
        tmp = tmp/2;
    }
    return tmp;
}

bool ip::match(String packet) {
//this is an array of Strings that contains the substrings after we split
//them according to the delimiters
	String *packet_split;
	char delimiters[3]="=,";
	size_t length;
//we split the packet
	packet.split(delimiters, &packet_split, &length);
	if(!length){
		delete[] packet_split;
		return false;
	}
	for(size_t i=0;i<length;i++){
//to check if there is an ip field
		if (current_field.equals(packet_split[i])){
			int bits=this->legal_bits;
			String *split_by_dots;
			packet_split[i+1]=packet_split[i+1].trim();
			size_t dot_count=3;
			packet_split[i+1].split(".",&split_by_dots,&dot_count);
		    if(bits == 0){
		    	delete[] split_by_dots;
		    	delete[] packet_split;
		    	return true;
		    }

		    int j=0;
		    while(bits>0) {
		    	if(bits>=8 && split_by_dots[j].to_integer()!=ip_fields[j]){
		    		delete[] split_by_dots;
		    		delete[] packet_split;
		    		return false;
		    	}
		    	if( (legal_bits<8) &&
		    	    (  (bits_check(bits,split_by_dots[j].to_integer()))
		            != (bits_check(bits,ip_fields[j]))  )
		    	)
		    	{
		    		delete[] split_by_dots;
		    		delete[] packet_split;
		    		return false;
		    	}
		    	bits-=8;//we move to the next byte
		    	j++;

		    }
		    delete[] split_by_dots;
			break;
		}
	}
	delete[] packet_split;
	return true;
}





