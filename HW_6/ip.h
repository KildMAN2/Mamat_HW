#ifndef IP_H
#define IP_H

#include <stddef.h>
#include <iostream>
#include "generic-field.h"

class ip : public GenericField {
	public:

		String current_field;
		ip(String packet);
		int legal_bits;
		int ip_fields[4];

	    bool set_value(String packet);
	    bool match(String packet);
};

#endif
