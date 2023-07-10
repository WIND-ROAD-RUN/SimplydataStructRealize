/*#define ORDERSTACKSIZE 100
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE
#define EMPTY 0

#include<stdio.h>

typedef int orderstacktype;
typedef struct{
	orderstacktype data[ORDERSTACKSIZE];
	int top;
}orderstack;
typedef int state;

void initialize_orderstack(orderstack* stack);
state push_orderstack(orderstack* stack, orderstacktype number);
state pop_orderstack(orderstack* stack, orderstacktype* number);
state show_orderstack(const orderstack * stack);
int length_orderstack(const orderstack *stack);
state get_orderstack(const orderstack *stack,orderstacktype * number);
int main() {
	orderstack stack1;
	initialize_orderstack(&stack1);
	push_orderstack(&stack1, 10);
	push_orderstack(&stack1, 20);
	show_orderstack(&stack1);
}

void initialize_orderstack(orderstack* stack) {
	stack->top = -1;
}
state push_orderstack(orderstack * stack, orderstacktype number) {
	if (stack->top==ORDERSTACKSIZE-1) {
		return ERROR;
	}
	stack->top++;
	stack->data[stack->top] = number;
	return OK;
}
state pop_orderstack(orderstack* stack, orderstacktype * number) {
	if (stack->top==-1) {
		return ERROR;
	}
	*number = stack->data[stack->top];
	stack->top--;
	return OK;
}
state show_orderstack(const orderstack* stack) {
	int i;
	if(stack->top==-1){
		return EMPTY;
	}
	for (i = 0; i < stack->top + 1; i++) {
		printf("%-3d",stack->data[i]);
	}
	return TRUE;
}
int length_orderstack(const orderstack* stack) {
	return stack->top + 1;
}
state get_orderstack(const orderstack* stack, orderstacktype* number) {
	if (stack->top==-1) {
		*number = EMPTY;
		return EMPTY;
	}
	*number = stack->top + 1;
	return TRUE;
}*/