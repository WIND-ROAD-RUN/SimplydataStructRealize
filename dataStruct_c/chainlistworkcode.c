#define OK 1
#define ERROR 0
#define true 1
#define false 0

#include<stdio.h>
#include<stdlib.h>

typedef int state;
typedef int chainlisttype;
 
typedef struct chailist {
	chainlisttype data;
	struct chainlist * next;
}chainlist;
typedef chainlist* listptr;

void create_chainlist_head(listptr * list,int num);								//����ָ���������������ͷ��
void create_chainlist_tail(listptr * list, int num);							//����ָ���������������β��
state ptr * list,int num,chainlisttype number);			//����
state delete_chainlist(listptr * list,int num);									//ɾ��
state get_chainlist(listptr  list,int num,chainlisttype * result);				//��ȡ
state clear_chainlist(listptr *list);											//�������
state initialize_chainlist(listptr * list);										//����ͷ���
state check_chainlist(listptr list);											//����Ƿ�Ϊ������
int length_chainlist(listptr list);												//���������
int locate_chainlist(listptr list,chainlisttype number);						//��ȡ��ͬԪ�ص�λ��
void  show_chainlist(listptr  list);														//�������
void  limit_show_chainlist(listptr  list,int num);										//�Թ̶���ʽ�������

void create_chainlist_head(listptr *list,int num) {
	listptr  p;
	int i;
	srand(time(0));
	*list = (listptr)malloc(sizeof(chainlist));
	(*list)->next = NULL;
	for (i = 0;i<num;i++) {
		p = (listptr)malloc(sizeof(chainlist));
		p->data = rand() % 100 + 1;
		p->next = (*list)->next;
		(*list)->next = p;
	}
}
void create_chainlist_tail(listptr* list, int num) {
	listptr p, r;
	int i;
	srand(time(0));
	*list = (listptr)malloc(sizeof(chainlist));
	r = *list;
	for (i = 0;i<num;i++) {
		p = (listptr)malloc(sizeof(chainlist));
		p->data = rand() % 100, +1;
		r->next = p;
		r = p;
	}
	r->next = NULL;
}
state insert_chainlist(listptr* list, int num, chainlisttype number) {
	int i;
	listptr p, s;
	p = *list;
	i = 1;
	while (p && i < num) {
		p = p->next;
		i++;
	}
	if (!p||i>num) {
		return ERROR;
	}
	s = (listptr)malloc(sizeof(chainlist));
	s->data = number;
	s->next = p->next;
	p->next = s;
	return OK;
}
state delete_chainlist(listptr* list, int num) {
	int i;
	listptr p, q;
	p = *list;
	i = 1;
	while (p->next&&i<num) {
		p = p->next;
		i++;
	}
	if (!(p->next||i>num)) {
		return ERROR;
	}
	q = p->next;
	p->next = q->next;
	free(q);
	return OK;


}
state get_chainlist(listptr list, int num, chainlisttype * result) {
	int i;
	listptr p;
	p = list->next;
	i = 1;
	while (p&&i<num) {
		p = p->next;
		i++;
	}
	if (!p || i > num) {
		return ERROR;
	}
	*result = p->data;
	return OK;
}
state clear_chainlist(listptr* list) {
	listptr p, q;
	p = (*list)->next;
	while(p){
		q = p->next;
		free(p);
		p = q;
	}
	(*list)->next = NULL;
	return OK;
}
state initialize_chainlist(listptr* list) {
	*list = (listptr)malloc(sizeof(chainlist));
	if (!(*list)) {
		return ERROR;
	}
	(*list)->next = NULL;
	return OK;
}
state check_chainlist(listptr list) {
	if (list->next) {
		return true;
	}
	return false;
}
int length_chainlist(listptr list) {
	int i = 0;
	while (list->next) {
		i++;
		list = list->next;
	}
	return i;
}
int locate_chainlist(listptr list, chainlisttype number) {
	int i=0;
	list = list->next;
	while (list) {
		i++;
		if (number == list->data) {
			return i;
		}
		list = list->next;
	}
	return ERROR;
}
void  show_chainlist(listptr list) {
	listptr list1 = list->next;
	while (list1) {
		printf("%-5d", list1->data);
		list1 = list1->next;
	}
}
void  limit_show_chainlist(listptr  list, int num) {
	int i=1;
	listptr list1 = list->next;
	while (list1) {
		if (i > num) {
			printf("\n");
			i = 0;
		}
		printf("%-5d", list1->data);
		list1 = list1->next;
		i++;
	}
}

