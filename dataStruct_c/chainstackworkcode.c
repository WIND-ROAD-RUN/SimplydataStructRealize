/*#define ERROR 0
#define OK 1
#define EMPTY 0
#define TRUE

#include<stdlib.h>
#include<stdio.h>

typedef int chainstacktype;
typedef struct chainstack{
	chainstacktype data;
	struct chainstack * next;
}chainstack;
typedef chainstack * stackptr;
typedef int state;

state initialize_chainstack(stackptr * stack);
state push_chainstack(stackptr * stack, chainstacktype number);
state pop_chainstack(stackptr* stack, chainstacktype * number);
state practice_chainstack(stackptr* stack,chainstacktype num);
void show_chainstack(stackptr stack);
state clear_chainstack(stackptr * stack);
int length_chainstack(stackptr stack);
state get_chainstack(stackptr stack,chainstacktype *number);

state initialize_chainstack(stackptr * stack) {
	*stack = (stackptr)malloc(sizeof(chainstack));
	if (!(*stack)) {
		return ERROR;
	}
	(*stack)->next = NULL;
	(*stack)->data = EMPTY;
	return OK;
}
state push_chainstack(stackptr * stack,chainstacktype number) {
	stackptr ptr = (stackptr)malloc(sizeof(chainstack));
	if (!ptr) {
		return ERROR;
	}
	ptr->next = (*stack)->next;
	ptr->data = number;
	(*stack)->next = ptr;
	(*stack)->data++;
	return OK;
}
state pop_chainstack(stackptr* stack, chainstacktype * number) {
	stackptr ptr;
	if (!(*stack)->next) {
		return ERROR;
	}
	ptr = (*stack)->next;
	(*stack)->next = ptr->next;
	(*stack)->data--;
	*number = (*stack)->data;
	free(ptr);
	return OK;
}
state practice_chainstack(stackptr* stack, chainstacktype num) {
	srand(time(0));
	int i;
	stackptr ptr;
	for (i = 0;i<num;i++) {
		ptr = (stackptr)malloc(sizeof(chainstack));
		if (!ptr) {
			return ERROR;
		}
		ptr->data = rand() % 100 + 1;
		ptr->next = (*stack)->next;
		(*stack)->next = ptr;
		(*stack)->data++;
	}
	return OK;



}
void show_chainstack(stackptr stack) {
	stackptr ptr;
	ptr = stack->next;
	while (ptr) {
		printf("%-4d",ptr->data);
		ptr = ptr->next;
	}
}
state clear_chainstack(stackptr* stack) {
	stackptr ptr, ptr_;
	ptr = (*stack)->next;
	while (ptr) {
		ptr_ = ptr->next;
		free(ptr);
		ptr = ptr_;
	}
	(*stack)->next = NULL;
	(*stack)->data = EMPTY;
	return OK;
}
int length_chainstack(stackptr stack) {
	return stack->data;
}
state get_chainstack(stackptr stack, chainstacktype * number) {
	if (stack->data==0) {
		return ERROR;
	}
	*number = stack->next->data;
	return OK;
}*/