arg_num=1
course=$1

if [[ ! $# -eq arg_num ]]; then
	echo "Wrong number of arguments" >&2
	exit 1

elif [[ ! -e $course".txt" ]]; then
		echo "Course not found" >&2
		exit 1

elif [[ -d $course"_stat" ]]; then
		rm -r $course"_stat"
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









