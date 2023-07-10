/*#define SHAREORDERSTACKSIZE 100
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
#define EMPTY 0

#include<stdio.h>
#include<stdlib.h>

typedef int shareorderstacktype ;
typedef struct{
	shareorderstacktype data[SHAREORDERSTACKSIZE];
	int top1;
	int top2;
}shareorderstack;
typedef int state;

state initialize_shareorderstack(shareorderstack * stack);
state push_shareorderstack(shareorderstack* stack,int num,shareorderstacktype number);
state pop_shareorderstack(shareorderstack *stack,int num, int * number);
void show_shareorderstack(shareorderstack *stack,int stack1,int stack2);
state practice_shareorderstack(shareorderstack * stack,int stack1,int stack2);
int length_shareorderstack1(shareorderstack* stack);
int length_shareorderstack2(shareorderstack* stack);
state get_shareorderstack1(shareorderstack* stack, shareorderstacktype *number);
state get_shareorderstack2(shareorderstack* stack, shareorderstacktype * number);

state initialize_shareorderstack(shareorderstack * stack) {
	stack->top1 = -1;
	stack->top2 = SHAREORDERSTACKSIZE;
	return OK;
}
state push_shareorderstack(shareorderstack* stack, int num, shareorderstacktype number) {
	if (stack->top1+1==stack->top2) {
		return ERROR;
	}
	if (num==1) {
		stack->data[++stack->top1] = number;
	}
	if (num == 2) {
		stack->data[--stack->top2] = number;
	}
	return OK;
}
state pop_shareorderstack(shareorderstack* stack, int num,int * number) {
	if (num==1) {
		if (stack->top1==-1) {
			return ERROR;
		}
		*number=stack->data[stack->top1--];
	}
	if (num==2) {
		if (stack->top2 == SHAREORDERSTACKSIZE) {
			return ERROR;
		}
		*number = stack->data[stack->top2++];
	}
	return OK;
}
void show_shareorderstack(shareorderstack* stack, int stack1, int stack2) {
	int i;
	if (stack1!=0) {
		printf("stack1:");
		for (i = 0;i<stack->top1+1;i++) {
			printf("%-3d",stack->data[i]);
		}
		printf("\n");
	}
	if (stack2!= 0) {
		printf("stack2:");
		for (i = SHAREORDERSTACKSIZE-1; i > stack->top2 - 1; i--) {
			printf("%-3d", stack->data[i]);
		}
		printf("\n");
	}

}
state practice_shareorderstack(shareorderstack* stack, int stack1, int stack2) {
	if (stack1+stack2>SHAREORDERSTACKSIZE) {
		return ERROR;
	}
	srand(time(0));
	stack->top1 = stack1 - 1;
	stack->top2 = SHAREORDERSTACKSIZE - stack2;
	int i;
	for (i = 0;i<stack1;i++) {
		stack->data[i]=rand()%100+1;
	}
	for (i = SHAREORDERSTACKSIZE-1; i > stack->top2-1; i--) {
		stack->data[i] = rand()%100+1;
	}
	return OK;
}
int length_shareorderstack1(shareorderstack* stack) {
	if (stack->top1==-1) {
		return EMPTY;
	}
	return stack->top1 + 1;
}
int length_shareorderstack2(shareorderstack* stack) {
	if (stack->top2 == SHAREORDERSTACKSIZE) {
		return EMPTY;
	}
	return SHAREORDERSTACKSIZE- stack->top2;
}
state get_shareorderstack1(shareorderstack* stack, shareorderstacktype * number) {
	if (stack->top1==-1) {
		return EMPTY;
	}
	*number = stack->data[stack->top1];
	return OK;
}
state get_shareorderstack2(shareorderstack* stack, shareorderstacktype* number) {
	if (stack->top1 == SHAREORDERSTACKSIZE) {
		return EMPTY;
	}
	*number = stack->data[stack->top2];
	return OK;
}
*/