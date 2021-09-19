#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

//C����ʵ��ѭ������

//������
typedef struct Node {

	int data;
	struct Node* next;

} node;

typedef struct Node* linklist;

void initList(linklist head)
{
	printf("��ʼ��ѭ������......\n");
	if (head == NULL) {
		head = (node*)malloc(sizeof(node));
	}
	head->data = 0;
	head->next = head; //��ʼ����head��ָ��ָ���Լ�

}

//����(β�巨)
void tailAddNode(linklist head,int data) {

	node* p = (node*)malloc(sizeof(node));
	p->next = head;
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	while (true) {

		if (p->next->next == head) { //��ǰp->next����β
			p->next->next = newNode;
			newNode->next = head;
			head->data++;
			printf("������ɹ�......\n");
			break;
		}
		else {
			p->next = p->next->next;
		}
	}
}



//ɾ��
void deleteNode(linklist head,int index)
{
	node* p = (node*)malloc(sizeof(node));
	p->next = head;
	int cur = 0;
	//int in = index % (head->data); //in��ȡģ����±�
	while (true)
	{
		if ((cur+1)==index) //��ʱ��һ������������Ҫɾ���Ľ��
		{
			node* temp = p->next->next;

			p->next->next = p->next->next->next;
			head->data--;
			free(temp);
			printf("ɾ�����ɹ�......\n");
			break;
		}
		else {
			p->next = p->next->next;
			cur++;
		}


	}

}

void printList(linklist head)
{
	node* p = (node*)malloc(sizeof(node));
	p->next = head->next;

	while (true) {

		if (p->next->next == head) {
			printf("%d ", p->next->data);
			printf("����ѭ��-> %d ", p->next->next->next->data);
			break;
		}
		else {
			printf("%d ",p->next->data);
			p->next = p->next->next;
		}

	}


}
int main(void)
{

	linklist head = (node*)malloc(sizeof(node));

	initList(head);

	tailAddNode(head, 15);

	tailAddNode(head, 22);

	tailAddNode(head, 33);

	printList(head);

	deleteNode(head,3);

	printList(head);

	return 0;

}