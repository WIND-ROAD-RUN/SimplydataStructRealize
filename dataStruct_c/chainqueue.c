/*#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
#define EMPTY 0

#include<stdio.h>
#include<stdlib.h>

typedef int chainqueuetype;
typedef struct chainqueuenode {
	chainqueuetype data;
	struct chainqueuenode * next;
}chainqueuenode;
typedef struct {
	chainqueuenode * front;
	chainqueuenode * rear;
}chainqueue;
typedef int state;

state initialize_chainqueue(chainqueue * queue);
state into_chainqueue(chainqueue * queue, chainqueuetype number);
state delete_chainqueue(chainqueue * queue,chainqueuetype * number);
state  practice_chainqueue(chainqueue * queue,int num);
void show_chainqueue(const chainqueue * queue);
int length_chainqueue(const chainqueue * queue);
state clear_chainqueue(chainqueue * queue);
state get_chainqueue(const chainqueue *queue,chainqueuetype *number);
state destroy_chainqueue(chainqueue * queue);

state initialize_chainqueue(chainqueue* queue) 
{
	chainqueuenode* ptr;
	ptr = (chainqueuenode*)malloc(sizeof(chainqueuenode));
	if (!ptr) {
		return ERROR;
	}
	ptr->next = NULL;
	ptr->data = EMPTY;
	queue->front = ptr;
	queue->rear = ptr;
	return OK;
}
state into_chainqueue(chainqueue* queue, chainqueuetype number) 
{
	chainqueuenode* ptr;
	ptr = (chainqueuenode*)malloc(sizeof(chainqueuenode));
	if (!ptr) {
		return ERROR;
	}
	ptr->next = NULL;
	ptr->data = number;
	queue->rear->next = ptr;
	queue->rear = ptr;
	queue->front->data++;
	return OK;
}
state delete_chainqueue(chainqueue* queue, chainqueuetype* number) {
	chainqueuenode* ptr;
	if (queue->front==queue->rear) {
		return ERROR;
	}
	ptr = queue->front->next;
	*number = ptr->data;
	queue->front->next = ptr->next;
	if (queue->rear==ptr) {
		queue->rear = queue->front;
	}
	free(ptr);
	queue->front->data--;
	return OK;
}
state  practice_chainqueue(chainqueue* queue, int num) {
	srand(time(0));
	chainqueuenode* ptr;
	int i;
	for (i = 0;i<num;i++) {
		ptr = (chainqueuenode*)malloc(sizeof(chainqueuenode));
		if (!ptr) {
			return ERROR;
		}
		ptr->data = rand() % 100 + 1;
		ptr->next = NULL;
		queue->rear->next = ptr;
		queue->rear = ptr;
		queue->front->data++;
	}
	return OK;
}
void show_chainqueue(const chainqueue* queue) {
	chainqueuenode* ptr;
	ptr = queue->front;
	while (ptr != queue->rear) {
		ptr = ptr->next;
		printf("%-4d",ptr->data);
	}
}
int length_chainqueue(const chainqueue* queue) {
	return queue->front->data;
}
state clear_chainqueue(chainqueue* queue) {
	chainqueuenode * ptr,*ptr_;
	ptr = queue->front->next;
	queue->rear = queue->front;
	while (ptr) {
		ptr_ = ptr->next;
		free(ptr);
		ptr = ptr_;
	}
	queue->front->next = NULL;
	return OK;
}
state get_chainqueue(const chainqueue * queue, chainqueuetype* number) {
	if (queue->front==queue->rear) {
		return EMPTY;
	}
	*number = queue->front->next->data;
	return OK;
}
state destroy_chainqueue(chainqueue* queue) {
	while (queue->front) {
		queue->rear = queue->front->next;
		free(queue->front);
		queue->front = queue->rear;
	}
	return OK;
}*/
