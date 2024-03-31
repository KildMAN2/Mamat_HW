#! /bin/bash


#deletes spaces from in packets file
packets=$(cat | sed 's/ //g')

#define the input as the first argument
input_file="$1"

while read line
do

	#delete all spaces and comments(starts with "#")
	rules=$(echo "$line" | sed 's/#.*//; s/ //g') 
	 
	#if the line is not empty
	if [[ "$rules" != "" ]]; then
		
			
		src_ip=$(echo $rules | awk -F, '{print $1}')
		dst_ip=$(echo $rules | awk -F, '{print $2}')	
		src_port=$(echo $rules | awk -F, '{print $3}')	
		dst_port=$(echo $rules | awk -F, '{print $4}')

				
       corr_pkts+=$(echo "$packets" | ./firewall.exe "$src_ip"   |
    				      ./firewall.exe "$dst_ip"   | 
       				      ./firewall.exe "$src_port" |
       				      ./firewall.exe "$dst_port" )
		corr_pkts+="\n"
	fi


done < "$input_file"

echo -e "$corr_pkts" | sed "s/src-ip/\n&/g" | sed '/^$/d' | sort -u
