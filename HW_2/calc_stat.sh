arg_num=1
course=$1

if [[ ! $# -eq arg_num ]]; then 
	echo "Wrong number of arguments" >&2
	exit 1
	
else if [[ ! -e $course".txt" ]]; then
		echo "Course not found" >&2
		exit 1
		
else if [[ -d $course"_stat" ]]; then 
		rm -r $course"_stat"
fi
fi
fi
mkdir $course"_stat"

gcc -g -Wall hist.c -o hist.exe
./hist.exe < $course".txt" > ./$course"_stat"/histogram.txt

gcc -g -Wall mean.c -o mean.exe
./mean.exe < $course".txt" > $course"_stat"/statistics.txt
gcc -g -Wall median.c -o median.exe
./median.exe < $course".txt" >> $course"_stat"/statistics.txt
gcc -g -Wall min.c -o min.exe
./min.exe  < $course".txt" >> $course"_stat"/statistics.txt
gcc -g -Wall max.c -o max.exe
./max.exe < $course".txt" >> $course"_stat"/statistics.txt

./hist.exe -n_bins 100 < $course".txt" > all_grades.txt
students_num=0 	#overall number of students
fail_num=0  	#overall number of failed students
current_grade=0	#the current grade at the line we are at
num_of_grades=0	#the students number that got the current grade

while read -r line 
do
	current_grade=$(echo $line | awk -F"-" '{print $1}')
	num_of_grades=$(echo $line | awk '{print $2}')
	
	if [[ $current_grade -gt 54 ]]; then
		(( fail_num=fail_num+num_of_grades ))
	fi
	
	(( students_num=students_num+num_of_grades ))
	
done < all_grades.txt

(( fail_ratio=(fail_num*100)/students_num ))

echo $fail_ratio"%" >> $course"_stat"/statistics.txt






	
