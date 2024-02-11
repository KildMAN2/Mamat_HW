#include <string.h>
#include "student.h"




elem_t student_clone(elem_t e){
	pstudent_t student = (pstudent_t)e;
	pstudent_t clone = malloc(sizeof(student_t));
	if (clone == NULL) return NULL;

	clone->name = malloc(strlen(student->name)+1);
	if (clone->name == NULL) {
		free(clone);
		return NULL;
	}
	strcpy(clone->name , student->name);
	clone->id =  student->id;
	clone->age = student->age;

	return clone;

}

void student_destroy(elem_t e) {
	pstudent_t student = (pstudent_t)e;
	free(student->name);
	free(student);

}

void student_print(elem_t e){
	pstudent_t student = (pstudent_t)e;
	printf("student name: %s, ", student->name);
	printf("age: %d, ", student->age);
	printf("id: %d.\n", student->id);
}
st







