#!/bin/bash
arg_num=1
course=$1

if [[ ! $# -eq arg_num ]]; then
  echo "Wrong number of arguments" >&2
  exit 1
elif [[ ! -e "$course.txt" ]]; then
  echo "Course not found" >&2
  exit 1
fi

course_stat="${course}_stat"

if [[ -d "$course_stat" ]]; then
  rm -r "$course_stat"
fi

mkdir "$course_stat"

gcc -g -Wall hist.c -o hist.exe
./hist.exe -nbins 100 < "$course.txt" > "$course_stat/histogram.txt"

gcc -g -Wall mean.c -o mean.exe
./mean.exe < "$course.txt" > "$course_stat/statistics.txt"
gcc -g -Wall median.c -o median.exe
./median.exe < "$course.txt" >> "$course_stat/statistics.txt"
gcc -g -Wall min.c -o min.exe
./min.exe < "$course.txt" >> "$course_stat/statistics.txt"
gcc -g -Wall max.c -o max.exe
./max.exe < "$course.txt" >> "$course_stat/statistics.txt"

# Calculate fail ratio
all_grades="$course_stat/all_grades.txt"
./hist.exe -nbins 100 < "$course.txt" > "$all_grades"

students_num=0    # overall number of students
fail_num=0        # overall number of failed students
current_grade=0   # the current grade at the line we are at
num_of_grades=0   # the students number that got the current grade

while read -r line; do
  # Extract the grade and count from the line
  current_grade=$(echo "$line" | awk '{print $1}')
  num_of_grades=$(echo "$line" | awk '{print $2}')
  
  # Check if the current grade is less than or equal to 54
  if ((current_grade <= 54)); then
    ((fail_num += num_of_grades))
  fi
  
  ((students_num += num_of_grades))
done < "$all_grades"

# Calculate the fail ratio
if [[ $students_num -gt 0 ]]; then
    fail_ratio=$(( (fail_num * 100) / students_num ))
else
    fail_ratio=0
fi

# Append the result to statistics.txt
echo "$fail_ratio%" >> "$course_stat/statistics.txt"
