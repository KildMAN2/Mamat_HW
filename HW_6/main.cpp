#include <iostream>
#include "input.h"
#include "string.h"
#include "generic-field.h"
#include "ip.h"
#include "port.h"

const int delim_arr_len=2;

int main(int argc, char ** argv) {

	if(check_args(argc,argv)){
		return -1;
	}

	String input = String(argv[1]);
	size_t input_parts=0;
	input=input.trim();
	String *input_args;

	input.split("=,",&input_args,&input_parts);

	if(input_args[0].equals("src-ip")) {
		ip src_ip("src-ip");
		src_ip.set_value(input_args[1]);
		parse_input(src_ip);
	}

	if(input_args[0].equals("dst-ip")) {
		ip dst_ip("dst-ip");
		dst_ip.set_value(input_args[1]);
		parse_input(dst_ip);
	}

	if(input_args[0].equals("src-port")) {
		Port src_port("src-port");
		src_port.set_value(input_args[1]);
		parse_input(src_port);
	}

	if(input_args[0].equals("dst-port")) {
		Port dst_port("dst-port");
		dst_port.set_value(input_args[1]);
		parse_input(dst_port);
	}

	delete[] input_args;
	return 0;


}
