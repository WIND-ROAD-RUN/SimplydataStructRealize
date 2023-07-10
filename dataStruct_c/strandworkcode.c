#define ORDERSTRANDSIZE 100
#define OK 1
#define ERROR 0
#define EMPTY 0
#define TRUE 1
#define FALSE 0

#include<stdio.h>

typedef char orderstrandtype;
typedef orderstrandtype orderstrand[ORDERSTRANDSIZE];
typedef int state;

state initialize_orderstrand(orderstrand strand);
state insert_orderstrand(orderstrand strand);
state show_orderstrand(orderstrand strand);
state copy_orderstrand(orderstrand target,orderstrand source);
int search_ordetstrand(orderstrand templatestrand,orderstrand contraststrand,int num);
state concat_orederstrand(orderstrand target, orderstrand source);
int length_orderstrand(orderstrand strand);
state empty_orderstrand(orderstrand strand);
state clear_orderstrand(orderstrand strand);
state delete_orderstrand(orderstrand strand,int num,int number);

state initialize_orderstrand(orderstrand  strand) {
    strand[0] = 0;
    return OK;
}
state insert_orderstrand(orderstrand strand) {
    int i;
    for (i=1;i<ORDERSTRANDSIZE;i++) {
        strand[i] = getchar();
        strand[0]++;
        if (strand[i]=='\n'||strand[i]==EOF) {
            strand[0]--;
            return OK;
        }
    }
    return ERROR;
}
state show_orderstrand(orderstrand strand) {
    int i;
    for (i = 0;i<strand[0];i++) {
        printf("%c",strand[i+1]);
    }
    return OK;
}
state copy_orderstrand(orderstrand target, orderstrand source) {
    int i;
    for (i = 0;i<source[0]+1;i++) {
        target[i] = source[i];
    }
    return OK;

}
int search_ordetstrand(orderstrand templatestrand, orderstrand contraststrand,int num) {
    int i, k,j;
    i = 1;
    k = 0;
    int next[ORDERSTRANDSIZE];
    next[0] = templatestrand[0];
    next[1] = 0;
    while (i<templatestrand[0]) {
        if (k==0||templatestrand[i] ==templatestrand[k]) {
            i++;
            k++;
            next[i] = k;
        }
        else {
            k = next[k];
        }
    }
    i = num;
    j = 1;
    while (i<= contraststrand[0]&&j<=templatestrand[0]) {
        if(j==0|| contraststrand[i]== templatestrand[j]) {
            i++;
            j++;
        }
        else {
            j = next[j];
        }
    }
    if (j>templatestrand[0]) {
        return i - templatestrand[0];
    }
    else {
        return 0;
    }
}
state concat_orederstrand(orderstrand target, orderstrand source) {
    int i, j;
    if (target[0]+source[0]>ORDERSTRANDSIZE-1) {
        return ERROR;
    }
    for (i = target[0] + 1,j = 1;j< source[0] + 1;j++,i++) {
        target[i] = source[j];
        target[0]++;
    }
    return OK;
}
int length_orderstrand(orderstrand strand) {
    return strand[0];
}
state empty_orderstrand(orderstrand strand) {
    if (strand[0]==0) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}
state clear_orderstrand(orderstrand strand) {
    strand[0] = 0;
    return OK;
}
state delete_orderstrand(orderstrand strand, int num, int number) {
    int i;
    if (number+num>strand[0]) {
        return ERROR;
    }
    for (i = num;i+number<strand[0] + 1; i++) {
        strand[i] = strand[i + number];
    }
    strand[0] = strand[0] - number;
    return OK;
}