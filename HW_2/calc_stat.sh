#!/bin/bash
arg_num=1
course=$1
course_stat="${course}_stat"
 #checks number of the arguments if is it more than 1
if [[ ! $# -eq "$arg_num" ]]; then
    echo "Wrong number of arguments" >&2
    exit 1
elif ! ls ./*"$course"* 1> /dev/null 2>&1; then
    echo "Course not found" >&2
    exit 1
elif [[ -d "$course_stat" ]]; then
    rm -r "$course_stat"
fi

mkdir "$course_stat"


{
./hist.exe < "$course" > ./"$course_stat"/histogram.txt
    ./mean.exe < "$course"
    ./median.exe < "$course"
    ./min.exe < "$course"
    ./max.exe < "$course"
} >> "$course_stat/statistics.txt"



