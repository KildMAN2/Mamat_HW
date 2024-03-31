#include "string.h"
#include <iostream>
#include <string.h>
const int TRUE=1;
const int FALSE=0;

String::String() {

	data= new char[1];
	data[0]='\0';
	length=1;
}



String::String(const String &str){

	data = new char[str.length];
	length = str.length;
	strcpy(data,str.data);
	data[length-1]='\0';
}



String::String(const char *str) {

	length=strlen(str)+1;
	data = new char[length];
	strcpy(data,str);
	data[length-1]='\0';

}



String::~String() {

	delete[] data;
}




String &String::operator=(const String &rhs) {

	if (this == &rhs) {
		return *this;
	}
	delete[] data;
	char* clone_str=new char[rhs.length];
	strcpy(clone_str,rhs.data);
	length=rhs.length;
	data=clone_str;

	return *this;
}


String &String::operator=(const char *str) {

	delete[] data;
	length= strlen(str)+1;
	char* clone_str=new char[length];
	strcpy(clone_str,str);
	data=clone_str;
	return *this;
}



bool String::equals(const String &rhs) const {

	if(strcmp(this->data,rhs.data)) {
		return FALSE;
	}
	return TRUE;
}




bool String::equals(const char *rhs) const {
	if(length != (strlen(rhs)+1)){
		return FALSE;
	}
	for (int i=0 ; i<(int)strlen(rhs) ; i++){
		if(rhs[i]!=data[i]) return FALSE;
	}
	return TRUE;
}




void String::split(const char *delimiters,String **output, size_t *size) const{


	if (this->data == NULL) {
		*size =0;
		output = NULL;
		return;
	}

	if (size==NULL){
		return;
	}
	if (delimiters==NULL){
		return;
	}

	int delim_count=0;
	for(int i =0 ; i<(int)this->length;i++){
		for (int j=0;j<(int)strlen(delimiters);j++){
			if(this->data[i] == delimiters[j]) {
				delim_count++;

			}
		}
	}

	if(output==NULL){
		*size=delim_count+1;
		return;
	}

	(*output) = new String[delim_count+1];

	int start = -1;
	int substr_index=0;
	int output_index=0;
	int last=0;
	for(int i =0 ; i<(int)this->length;i++){
		for (int j=0;j<(int)strlen(delimiters);j++){
			if(this->data[i] == delimiters[j]) {
				last=i-start;
				substr_index=0;
				char current_substr[i-start];
				while(start<i-1){
					current_substr[substr_index]=this->data[start+1];
					start++;
					substr_index++;
				}
				current_substr[last-1]='\0';
				start=i;
				(*output)[output_index]=String(current_substr);
				output_index++;

			}
		}
	}
	char current_substr[(int)this->length-start];
	substr_index=0;
	while(start<(int)this->length-1){
		current_substr[substr_index]=this->data[start+1];
		start++;
		substr_index++;

	}
	current_substr[substr_index]='\0';
	(*output)[output_index]=String(current_substr);
	*size=delim_count+1;
	 return;
}


int String::to_integer() const{

	return atoi(data);
}

String String::trim() const {
	String new_string;
	new_string=data;
	int l_counter=0;//spaces at the beginning
	int r_counter=0;//spaces at the end

//checks the number of spaces at the start of the string
	for (int i =0;i<(int)length;i++) {
		if (data[i] !=' ') break;
		l_counter++;
	}
//checks the number of spaces at the end of the string
	for (int j=length-1;j>=0;j--) {
		if (data[j] !=' ') break;
		r_counter++;
	}
	int m=0;
	int n=l_counter;
	while(n<(int)length){
		new_string.data[m]=new_string.data[n];
		m++;
		n++;
	}
//deleting leading and railing spaces
	new_string.length=new_string.length-r_counter-l_counter;
	return new_string;
}












