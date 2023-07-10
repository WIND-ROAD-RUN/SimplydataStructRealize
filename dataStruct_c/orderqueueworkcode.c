/*#define ORDERQUEUESIZE 10
#define OK 1
#define ERROR 0
#define EMPTY 0
#define TRUE 1
#define FALSE 0

#include<stdio.h>

typedef int orderqueuetype;
typedef struct {
	orderqueuetype data[ORDERQUEUESIZE];
	int front;
	int rear;
}orderqueue;
typedef int state;

state initialize_orederqueue(orderqueue * queue);
int length_ordetqueue(const orderqueue * queue);
state into_orderqueue(orderqueue * queue,orderqueuetype number);
state delete_orderqueue(orderqueue* queue, orderqueuetype * number);
void show_orderqueue(const orderqueue * queue);
state get_orderqueue(const orderqueue * queue,orderqueuetype *number);

state initialize_orederqueue(orderqueue* queue) {
	queue->front = 0;
	queue->rear = 0;
	return OK;
}
int length_ordetqueue(const orderqueue* queue) {
	return (queue->rear - queue->front + ORDERQUEUESIZE) % ORDERQUEUESIZE;
}
state into_orderqueue(orderqueue* queue, orderqueuetype number) {
	if ((queue->rear + 1) % ORDERQUEUESIZE == queue->front) {
		return ERROR;
	}
	queue->data[queue->rear] = number;
	queue->rear=(queue->rear+1)%ORDERQUEUESIZE;
	return OK;
}
state delete_orderqueue(orderqueue* queue, orderqueuetype* number) {
	if (queue->front==queue->rear) {
		return EMPTY;
	}
	*number = queue->data[queue->front];
	queue->front = (queue->front + 1) % ORDERQUEUESIZE;
	return OK;
}
void show_orderqueue(const orderqueue* queue) {
	int i;
	i = queue->front;
	while (i!=queue->rear) {
		printf("%-3d",queue->data[i]);
		i = (i + 1) % ORDERQUEUESIZE;
	}

}
state get_orderqueue(const orderqueue* queue, orderqueuetype* number) {
	if (queue->front == queue->rear) {
		return EMPTY;
	}
	*number = queue->data[queue->front];
	return OK;
}*/
