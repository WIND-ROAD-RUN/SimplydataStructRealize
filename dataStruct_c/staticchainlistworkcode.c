#define STATICCHAINLISTSIZE 10
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define empty 0
#define tail 0

#include<stdio.h>
#include<stdlib.h>

typedef int staticchainlisttype;
typedef int state;
typedef struct list{
	staticchainlisttype data;
	int next;
}staticchainlist[STATICCHAINLISTSIZE];
typedef staticchainlist * listptr;

state initialize_staticchainlist(staticchainlist list);
int length_staticchainlist(staticchainlist list);
state insert_staticchainlist(staticchainlist list,int num, staticchainlisttype number);
state delete_staticchainlist(staticchainlist list, int num);
void show_staticchainlist(staticchainlist list);
state practice_staticchainlist(staticchainlist list,int num);
state get_staticchainlist(staticchainlist list,int num, staticchainlisttype * number);
int locate_staticchainlist(staticchainlist list, staticchainlisttype number);
state check_staticchainlist(staticchainlist list);

int main() {
	staticchainlist list1;
	initialize_staticchainlist(list1);
	practice_staticchainlist(list1, 8);
	printf("%d\n", length_staticchainlist(list1));
	show_staticchainlist(list1);
	printf("%d", check_staticchainlist(list1));
}

state initialize_staticchainlist(staticchainlist list) {
	int i ;
	list[0].data = STATICCHAINLISTSIZE - 2;
	list[0].next = 1;
	list[STATICCHAINLISTSIZE-1].data = empty;
	list[STATICCHAINLISTSIZE-1].next = tail;
	for (i = 0;i< STATICCHAINLISTSIZE-2;i++) {
		list[i].next = i + 1;
	}
	list[i].next = tail;
	return OK;
}
int length_staticchainlist(staticchainlist list) {
	if (list[STATICCHAINLISTSIZE - 1].data==0) {
		return empty;
	}
	else {
		return list[STATICCHAINLISTSIZE - 1].data;
	}
}
state insert_staticchainlist(staticchainlist list,int num, staticchainlisttype number) {
	int i, ptr,ptrspace;
	ptr = STATICCHAINLISTSIZE - 1;
	if (num<1||num>list[STATICCHAINLISTSIZE-1].data+1) {
		return ERROR;
	}
	if (list[0].data < 1) {
		return ERROR;
	}
	for (i = 1;i<num;i++) {
		ptr = list[ptr].next;
	}
	ptrspace = list[0].next;
	list[0].next = list[list[0].next].next;
	list[0].data = list[0].data - 1;
	list[ptrspace].data = number;
	list[ptrspace].next = list[ptr].next;
	list[ptr].next = ptrspace;
	list[STATICCHAINLISTSIZE - 1].data = list[STATICCHAINLISTSIZE - 1].data + 1;
	return OK;
}
state delete_staticchainlist(staticchainlist list, int num) {
	int i, ptr, ptrspace;
	ptr = STATICCHAINLISTSIZE - 1;
	if (list[STATICCHAINLISTSIZE-1].data<1) {
		return ERROR;
	}
	if (num<1||num>list[STATICCHAINLISTSIZE-1].data) {
		return ERROR;
	}
	for (i = 0; i < num; i++) {
		ptr = list[ptr].next;
	}
	ptrspace = list[0].next;
	list[ptr - 1].next = list[ptr].next;
	list[0].next = ptr;
	list[ptr].next = ptrspace;
	list[0].data = list[0].data + 1;
	list[STATICCHAINLISTSIZE - 1].data = list[STATICCHAINLISTSIZE - 1].data -1;
	return OK;
}
void show_staticchainlist(staticchainlist list) {
	int i,ptr;
	ptr = list[STATICCHAINLISTSIZE - 1].next;
	printf("元素个数：%d\n",list[STATICCHAINLISTSIZE-1].data);
	printf("备用区域个数：%d\n", list[0].data);
	printf("元素为：");
	for (i=0;i< list[STATICCHAINLISTSIZE - 1].data;i++) {
		printf("%5d",list[ptr].data);
		ptr = list[ptr].next;
	}
	printf("\n");
}
state practice_staticchainlist(staticchainlist list,int num) {
	int i;
	srand(time(0));
	if (num<1 || num>STATICCHAINLISTSIZE - 2) {
		return ERROR;
	}
	for (i = 0;i< num;i++) {
		insert_staticchainlist(list, i + 1, rand()%100+1);
	}
	return OK;
}
state get_staticchainlist(staticchainlist list, int num,staticchainlisttype * number) {
	int i,ptr;
	if (num<1||num>list[STATICCHAINLISTSIZE - 1].data) {
		*number = 0;
		return ERROR;
	}
	ptr = STATICCHAINLISTSIZE-1;
	for (i = 0;i<num;i++) {
		ptr = list[ptr].next;
	}
	*number = list[ptr].data;
	return OK;
}
int locate_staticchainlist(staticchainlist list, staticchainlisttype number) {
	if (list[STATICCHAINLISTSIZE - 1].data==0) {
		return ERROR;
	}
	int i=1, ptr;
	ptr = list[STATICCHAINLISTSIZE - 1] .next;
	while ((list[ptr].data)!=number) {
		i++;
		if (i> list[STATICCHAINLISTSIZE - 1].data) {
			return FALSE;
		}
		ptr = list[ptr].next;
	}
	return i;
}
state check_staticchainlist(staticchainlist list) {
	if (list[STATICCHAINLISTSIZE-1].data==0) {
		return FALSE;
	}
	return TRUE;
}
