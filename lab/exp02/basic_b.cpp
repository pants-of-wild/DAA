#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

int m;  //������ 
const int maxn = 10000;

struct node{
	int data;
	struct node *next;
};
node *head; // headָ��ͷ�ڵ� 

void insert(int i, int x){//����x��a[i] 
    node *tmp = head;
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    while(--i){
    	tmp = tmp->next;
	}
	newNode->next = tmp->next;
	tmp->next = newNode;
} 

void deleteByIndex(int i){ //ɾ��a[i] 
	node *pre = head;
    while(--i){
        pre = pre->next;
	}
	node *tmp = pre->next;
	pre->next = tmp->next;
	free(tmp);
} 

int find(int x){//���ҵ�һ��x 
    node *tmp = head;
    int index = 0;
    while(tmp->next != NULL){
    	index++;
    	tmp = tmp->next;
    	if(tmp->data == x)return index;
	}
	return 0;
}

void eliminateRepeat(){ //ȥ���ظ�Ԫ�� 
    int tmp[maxn];  
    node *pre = head;
    int tail = 0;
    node *cnt = pre->next;
    while(pre->next != NULL){
    	cnt = pre->next;
    	int flag = 0;
    	for(int j = 1; j <= tail; j++){
    		if(cnt->data == tmp[j]){
    			flag = 1;
    			pre->next = cnt->next;
    			free(cnt);
    			break;
			}
		}
		if(flag == 0){
			pre = pre->next;
			tmp[++tail] = cnt->data;
		}
	}
}

void count(int x, int y){//ͳ��[x,y]��Ԫ�ظ���	
	int k = 0;
	node *p = head->next; 
	while (p != NULL){
		if (p->data >= x && p->data <= y) k++;
		p = p->next;
	}
	printf("%d\n", k);
}

void deleteByRange(int x, int y){ //ȥ��[x,y]��Χ�ڵ�Ԫ�� 
	node *p = head;
	node *q = head-> next;
	while (q != NULL){
		if (q->data >= x && q->data <= y){
			p->next = q->next; free(q); q = p->next;
		}
		else{
			p = q; q = p->next;
		}
	}
} 

int main() {
	scanf("%d", &m);
	head = (node*) malloc(sizeof(node));
	head->next = NULL;
	for (int k = 0; k < m; k++){
		int c, i, x, y;
		scanf("%d", &c);
		switch (c){
			case 1: scanf("%d%d", &i, &x); insert(i, x); break;
			case 2: scanf("%d", &i); deleteByIndex(i); break;
			case 3: scanf("%d", &x); printf("%d\n",find(x)); break;
			case 4: scanf("%d%d", &x, &y); count(x, y); break;
			case 5: eliminateRepeat(); break;
			case 6: scanf("%d%d", &x, &y); deleteByRange(x, y); break;
		}
	}
	return 0;
}

