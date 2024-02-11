
#include "student.h"//

pstack_t stack_create(size_t size,
					  clone_t clone,
					  destroy_t destroy,
					  print_t print)
{
	pstack_t stack = malloc(sizeof(struct stack));
    if (stack == NULL) return NULL;
    stack->data = malloc(sizeof(elem_t) * size);
    if (stack->data == NULL) {
   	free(stack);
   	return NULL;
    }
    stack->top = -1;
    stack->size = size;
    stack->print = print;
    stack->destroy = destroy;
    stack->clone = clone;
    return stack;
}

bool stack_destroy(pstack_t stack) {
	if (stack != NULL ) {
		for (int i = 0; i <= stack->top; i++) {
			stack->destroy(stack->data[i]);
	}

		free(stack->data);
		free(stack);
		return SUCCESS;
	}

	return FAIL;

}

bool stack_push(pstack_t stack, elem_t e) {

    if (stack->top == stack->size - 1) {
        return FAIL;
    }
    stack->data[++stack->top] = stack->clone(e);
    return SUCCESS;
}

void stack_pop(pstack_t stack) {
    if (stack->top == -1) {
        return ;
    }
    stack->destroy(stack->data[stack->top]);
    stack->top--;
}

elem_t stack_peek(pstack_t stack) {
    if (stack->top == -1) {
        return NULL;
    }
    return stack->data[stack->top];
}

size_t stack_size(pstack_t stack)
{
    if (stack == NULL)
        return 0;
    return stack->top + 1;
}

bool stack_is_empty(pstack_t stack) {
    return stack->top == -1;
}

size_t stack_capacity(pstack_t stack)
{
    if (stack == NULL) {
        return 0;
    }
	return stack->size - (stack->top + 1);
}

void stack_print(pstack_t stack) {

    for (int i = stack->top; i >= 0; i--) {
           stack->print(stack->data[i]);
    }
}





