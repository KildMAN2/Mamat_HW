#ifndef __STACK__
#define __STACK__

#include <stddef.h>  /* size_t */
#include <stdbool.h> /* bool   */
#include <stdlib.h>
#include <stdio.h>




typedef void *elem_t;  //
typedef elem_t (*clone_t)(elem_t e);
typedef void (*destroy_t)(elem_t e);
typedef void (*print_t)(elem_t e);

/*
 * we did pstack_t as pointer for stack and in the the stack there will be elem_t that
 * he point on data also we save the index of the top of the stack to make easier for us
 * in the later functions to do so some commands in the execution all the others are pointers
 * for the functions that we gonna use for the execution for the functions of the stack
 */
typedef struct stack *pstack_t;
struct stack {
    elem_t *data;
    int top;
    size_t size;
    clone_t clone;
    destroy_t destroy;
    print_t print;

} ;



pstack_t stack_create(size_t size, clone_t, destroy_t, print_t);
bool stack_destroy(pstack_t stack);
bool stack_push(pstack_t stack,elem_t e);
void stack_pop(pstack_t stack);
elem_t stack_peek(pstack_t stack);
size_t stack_size(pstack_t stack);
bool stack_is_empty(pstack_t stack);
size_t stack_capacity(pstack_t stack);
void stack_print(pstack_t stack);

#endif
