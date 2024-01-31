
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked-list.h"
#include "grades.h"

typedef struct grades {
	struct list* students_list;

} Grade;

typedef struct student {

	char* name;
	int id;
	struct list* courses_list;

} Student;

typedef struct course  {

	char* name;
	int grade;

} Course;


/* user functions declarations */

int clone_course(void *element, void **output);
void destroy_course(void *element);
int clone_student(void *element, void **output);
void destroy_student(void *element);


/*  functions implementations   */

int clone_student(void *element, void **output) {

	Student* student = (Student*)element;

	Student* cloned_student = malloc(sizeof(Student));
	if (!cloned_student) return 1;
	cloned_student->name = (char*)malloc(strlen(student->name)+1);
	if (!cloned_student->name) return 1;
	strcpy(cloned_student->name,student->name);
	cloned_student->id = student->id;

	cloned_student->courses_list = list_init((element_clone_t)clone_course,
			(element_destroy_t)destroy_course);
	if (!cloned_student->courses_list) return 1;

	struct iterator* source_iterator=list_begin(student->courses_list );
	struct iterator* clone_iterator=list_begin(cloned_student->courses_list );
	Course* source_course;

	int i=0;
	while (i<(int)list_size(student->courses_list)) {

		source_iterator=list_next(source_iterator);
		source_course= list_get(source_iterator);
		list_insert(cloned_student->courses_list,clone_iterator,source_course);
		clone_iterator=list_next(clone_iterator);
		i++;
	}
	*output=cloned_student;
	return 0;

}


int clone_course(void *element, void **output) {
	if (!element) {
		return 1;
	}
	Course* course = (Course*)element;

	Course* cloned_course = malloc(sizeof(Course));
	if (!cloned_course) return 1;
	cloned_course->name = (char*)malloc(strlen(course->name)+1);
	if (!cloned_course->name) return 1;
	strcpy(cloned_course->name,course->name);
	cloned_course->grade =course->grade;
	*output = cloned_course;
	return 0;
}

void destroy_course(void* element) {
	Course* course = (Course*)element;
	free(course->name);
	free(course);

}

void destroy_student(void *element) {
	Student* student = (Student*)element;
	list_destroy(student->courses_list);
	free(student->name);
	free(student);
}



struct grades* grades_init() {
	Grade* grade = malloc(sizeof(Grade));
	if (grade == NULL) return NULL;
	grade->students_list=list_init((element_clone_t)clone_student,
			(element_destroy_t)destroy_student);
	return grade;

}


void grades_destroy(struct grades *grades) {
	list_destroy(grades->students_list);
	free(grades);
}


int grades_add_student(struct grades *grades, const char *name, int id) {
	if (!grades) return 1;
	if (id<0) return 1;
	struct iterator* itr = list_begin(grades->students_list);
	Student* checker;

	while(itr){
		checker = list_get(itr);
		if(checker->id == id){
			return 1;
		}
		itr=list_next(itr);
	}
	Student* new_student = (struct student*)malloc(sizeof(Student));
	if (!new_student) return 1;
	new_student->id = id;
	new_student->name=(char*)malloc((int)strlen(name)+1);
	if (!new_student->name) return 1;
	strcpy(new_student->name , name);
	new_student->courses_list = list_init((element_clone_t)clone_course,
	                                     (element_destroy_t)destroy_course);
	if (list_push_back(grades->students_list,new_student)) {
		free(new_student->name);
		list_destroy(new_student->courses_list);
		free(new_student);
		return 1;
	}

	free(new_student->name);
	list_destroy(new_student->courses_list);
	free(new_student);
	return 0;
}


int grades_add_grade(struct grades *grades,
                     const char *name,
                     int id,
                     int grade) {


	if(!grades) return 1;
	if (id<0) return 1;
	if (grade<0 || grade>100) return 1;
	struct iterator* itr_student = list_begin(grades->students_list);
	Student* student_check;
	Course* course_check;
	int flag=0;
	while(itr_student){
		student_check = list_get(itr_student);
		if(student_check->id == id){
			flag=1;
			break;
		}
		itr_student=list_next(itr_student);
	}
	if (flag==0) return 1;

	struct iterator* itr_course = list_begin(student_check->courses_list);
	while (itr_course){
		course_check=list_get(itr_course);
		if (!strcmp(course_check->name,name)){
			return 1;
		}
		itr_course=list_next(itr_course);
	}
	Course* new_course=malloc(sizeof(Course));
	if (!new_course) return 1;
	new_course->grade=grade;
	new_course->name=malloc(strlen(name)+1);
	if (!new_course->name) return 1;
	strcpy(new_course->name,name);
	if(list_push_back(student_check->courses_list,new_course)) {
		free(new_course->name);
		free(new_course);
		return 1;
	}

	free(new_course->name);
	free(new_course);
	return 0;

}


float grades_calc_avg(struct grades *grades, int id, char **out) {

	if(!grades) {
		*out =NULL;
		return -1;
	}
	if (id<0) {
		*out = NULL;
		return -1;
	}
	int sum=0;
	int counter=0;

	struct iterator* itr_student1 = list_begin(grades->students_list);
	Student* student_check1;
	Course* course_check1;
	int flag=0;
	while(itr_student1){
		student_check1 = list_get(itr_student1);
		if(student_check1->id == id){
			flag=1;
			*out=(char*)malloc(strlen(student_check1->name)+1);
			strcpy(*out,student_check1->name);
			break;
		}
		itr_student1=list_next(itr_student1);
	}

	if(flag==0) {
		*out=NULL;
		return -1;
	}

	struct iterator* itr_course1 = list_begin(student_check1->courses_list);
	if(itr_course1==NULL) return 0;
	while (itr_course1){
		course_check1=list_get(itr_course1);
		sum+=course_check1->grade;
		counter++;
		itr_course1=list_next(itr_course1);
	}

	float avg=(float)sum/(float)counter;
	return avg;

}


int grades_print_student(struct grades *grades, int id){
	if(!grades) return 1;
	struct iterator* itr_mystudent = list_begin(grades->students_list);
	Student* mystudent;
	Course* mycourse;
	int flag =0;

	while(itr_mystudent){
		mystudent = list_get(itr_mystudent);
		if(mystudent->id == id){
			flag=1;
			printf("%s %d:",mystudent->name,mystudent->id);
			break;
		}
		itr_mystudent=list_next(itr_mystudent);
	}
	if (flag==0) return 1;

	struct iterator* itr_mycourse = list_begin(mystudent->courses_list);

	if (itr_mycourse){
		mycourse=list_get(itr_mycourse);
		printf(" %s %d",mycourse->name,mycourse->grade);
		itr_mycourse=list_next(itr_mycourse);
	}
	while (itr_mycourse){
		printf(",");
		mycourse=list_get(itr_mycourse);
		printf(" %s %d",mycourse->name,mycourse->grade);
		itr_mycourse=list_next(itr_mycourse);
	}
	printf("\n");
	return 0;

}




int grades_print_all(struct grades *grades){

	if(!grades) return 1;
	struct iterator* student_index=list_begin(grades->students_list);
	Student* current_student;

	while(student_index) {
		current_student = list_get(student_index);
		grades_print_student(grades,current_student->id);
		student_index=list_next(student_index);
	}

	return 0;

}


