#pragma warning(disable:4996)
#include"stdio.h"
#include"stdlib.h"
struct listnode {
	int num;
	listnode* next;
};
typedef struct listnode node;
int main() {
	int M, N, count,result;
	node* head;
	scanf("%d %d", &N, &M);
	head = new node;
	head->next = NULL;
	head->num = 1;
	node* q=NULL, *p = head;
	for (int i = 2; i < N+1; i++) {
		q = new node;
		q->num = i;
		q->next = NULL;
		p->next = q;
		p = p->next;
	}
	p->next = head;
	p = head;
	for (int i = N-1; i > 0; i--) {
		count = M-1;
		while (count > 0) {
			q = p;
			p = p->next;
			count--;
		}
		q->next = p->next;
		free(p);
		p = q->next;
	}
	result = q->num;
	printf("%d", result);

	return 0;
	
}