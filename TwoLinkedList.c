#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0
typedef int status;
typedef int elemtype;

//Cʵ��˫������

typedef struct Node
{
	elemtype data;
	struct Node* pre; //ָ����һ�����
	struct Node* next; //ָ����һ�����

} node;
typedef struct Node* linklist;


node* init(linklist head)
{
	printf("init start......\n");
	if (head == NULL)
	{
		head = (linklist)malloc(sizeof(node));
	}

	head->data = 0;
	head->pre = NULL;
	head->next = NULL;
	if (head == NULL) {
		printf("init fail......\n");
		exit(0); //�˳�����
	}
	else {
		printf("init success......\n");
		return head;
	}
}
//ͷ�巨
status headInsertNode(linklist head,int data)
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data=data;
	if (head == NULL) {
		init(head);
	}	
	if (head->next == NULL) {
		head->next = newNode;
		newNode->next = NULL;
		newNode->pre = head;
		head->data++;
		printf("insert success......\n");
		return true;
	}
	else {
		node* temp = (node*)malloc(sizeof(node)*1);
		temp->next = head;
		
		newNode->next = temp->next->next;
		newNode->pre = temp->next;
		temp->next->next = newNode;
		temp->next->next->pre = newNode;
		head->data++;
		printf("insert success......\n");
		return true;
	}
}
//β��
status tailInsertNode(linklist head, int data)
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	if (head == NULL) {
		init(head);
	}
	else {
		node* temp = (node*)malloc(sizeof(node) * 1);
		temp->next = head;
		while (temp->next->next!=NULL)
		{
			temp->next = temp->next->next;
		}

		temp->next->next = newNode;
		newNode->pre = temp->next;
		newNode->next = NULL;
		head->data++;
		printf("insert success......\n");
		return true;
	}

}
//ɾ��
status deleteNode(linklist head,int index)
{
	if (index<1 || index>head->data) {
		printf("����index���Ϸ���ɾ��ʧ��......\n");
		exit(0);
	}
	else {
		int cur = 0;
		node* temp = (node*)malloc(sizeof(node));
		temp->next = head;

		while ((cur + 1) != index)
		{
			temp->next = temp->next->next;
			cur++;
		}
		node* d = temp->next->next;
		temp->next->next = temp->next->next->next;
		head->data--;
		free(d); //�ͷ��ڴ�
		printf("delete node success......\n");
		return true;
	}
}
void printList(linklist head)
{
	printf("print start......\n");
	node* p = (node*)malloc(sizeof(node));
	p->next = head->next;

	while (p->next!=NULL)
	{
		printf("%d  ",p->next->data);
		p->next = p->next->next;

	}
	printf("\nprint success......\n");
}

int main(void)
{
	linklist head=NULL;
	head=init(head);

	printList(head);


	headInsertNode(head, 11);
	headInsertNode(head, 22);

	tailInsertNode(head, 33);

	tailInsertNode(head, 66);

	printList(head);

	deleteNode(head, 2);
	printList(head);

	return 0;
}