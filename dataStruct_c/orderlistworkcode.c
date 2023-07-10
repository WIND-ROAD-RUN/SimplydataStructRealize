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

void initialize_orderlist(orderlist * list);//��ʼ�����Ա�ȫ������㣩
void show_orderlist(orderlist * list);//��ʾ���Ա��ȫ��Ԫ��
state getdata_orderlist(orderlist * list,int num, orderlisttype* result);//��Ԫ�غ�Ϊnum��Ԫ�ظ�ֵ��result
state insert_orderlist(orderlist * list,int num, orderlisttype  number);//��Ԫ�غ�Ϊnum��λ�ò�����Ԫ�أ�
state delete_orderlist(orderlist* list, int num);//��Ԫ�غ�Ϊnum��λ�õ�Ԫ��ɾ��


void initialize_orderlist(orderlist * list) {
	int i;
	list->length = 0;
	for (i = 0;i<ORDERLISTSIZE;i++) {
		list->data[i] = 0;
	}
}//��ʼ�����Ա�
void show_orderlist(orderlist * list) {
	int i;
	for (i = 0; i < list->length; i++) {
		printf("%2d", list->data[i]);
	}
	printf("\n��ЧԪ�ظ���Ϊ��%d",list->length);
}//��ʾ���Ա��ȫ��Ԫ��
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

