#define ORDERLISTSIZE 10
#define OK 1
#define ERROR 0

#include<stdio.h>

typedef int state;
typedef int orderlisttype;

typedef struct {
	orderlisttype data[ORDERLISTSIZE];
	int length;
}orderlist;

void initialize_orderlist(orderlist * list);//初始化线性表（全部变成零）
void show_orderlist(orderlist * list);//显示线性表的全部元素
state getdata_orderlist(orderlist * list,int num, orderlisttype* result);//将元素号为num的元素赋值给result
state insert_orderlist(orderlist * list,int num, orderlisttype  number);//将元素号为num的位置插入新元素；
state delete_orderlist(orderlist* list, int num);//将元素号为num的位置的元素删除


void initialize_orderlist(orderlist * list) {
	int i;
	list->length = 0;
	for (i = 0;i<ORDERLISTSIZE;i++) {
		list->data[i] = 0;
	}
}//初始化线性表
void show_orderlist(orderlist * list) {
	int i;
	for (i = 0; i < list->length; i++) {
		printf("%2d", list->data[i]);
	}
	printf("\n有效元素个数为：%d",list->length);
}//显示线性表的全部元素
state getdata_orderlist(orderlist * list, int num, orderlisttype* result) {
	if (list->length==0||num<1||num>list->length) {
		return ERROR;
	}
	*result = list->data[num - 1];
	return OK;
}
state insert_orderlist(orderlist * list, int num, orderlisttype  number) {
	int i;
	if ((list->length)==0) {
		return ERROR;
	}
	if (num<1||num>(list->length+1)) {
		return ERROR;
	}
	if (num<=list->length) {
		for (i = list->length - 1;i>=num-1;i--) {
			list->data[i + 1] = list->data[i];
		}
	}
	list->data[num - 1] = number;
	list->length++;

	return OK;
}
state delete_orderlist(orderlist * list, int num) {
	int i;
	if (list->length==0) {
		return ERROR;
	}
	if (num<1 || num>list->length ) {
		return ERROR;
	}
	if (num<list->length) {
		for (i = num - 1;i<list->length;i++) {
			list->data[i - 1] = list->data[i];
		}
	}
	list->length--;
	return OK;
}

