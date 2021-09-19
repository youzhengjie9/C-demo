#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//�궨�峣��
#define true 1
#define false 0

//C����ʵ�ֵ�����


//������ṹ��
typedef struct Node {
	int data; //������(ͷ����������洢������������������ͨ���洢�û����������)
	struct Node *next; //ָ����
} node;

//��ʼ������
void initList(node *head)
{
	if (head == NULL) {
		head = (node*)malloc(sizeof(node));
	}
	head->next = NULL; //ͷ���ָ��ָ���
	head->data = 0; //ͷ��������Դ�洢������
	printf("��ʼ������ɹ�......\n");
}


//�Զ������(index���ǵڼ������λ�ò���)������10 20 30��index=2 data=40 =>10 40 20 30
int addNodeByIndex(node *head,int index,int data)
{
	if (index<1 || index>head->data) {
		printf("����index���Ϸ�������......\n");
		return false;
	}
	else {
		node* newNode = (node*)malloc(sizeof(node));
		newNode->data = data;
		node* p = (node*)malloc(sizeof(node));
		p->next = head;
		int cur = 0;	//��ǰָ��pָ����±�

		while (true) {

			if ((cur+1) == index) { //�����һ������ǣ����ҵ�
				newNode->next = p->next->next;
				p->next->next = newNode;
				head->data++;
				printf("�Զ������ɹ�......\n");
				break;
			}
			else { //��������
				p->next = p->next->next;
				cur++;
			}

		}


	}

}



//��������ӽ�㣨ͷ�巨��
int headAddNode(node *head,int data) {

	if (head == NULL) {
		printf("����ͷΪ��,�Զ���ʼ������......\n");
		initList(head);
		printf("��ʼ������ɹ�......\n");
	}
	node* newNode = (node*)malloc(sizeof(node));

	newNode->data = data;

	//β�巨���룬���������
	//1��head->next!=NULL //��������ǵ�һ�β���Ԫ�ص������ִ�У�����������
	if (head->next != NULL) {
		addNodeByIndex(head,1,data);
	}
	//2:head->next==NULL   //������������Ѿ������Ԫ�ص������ִ��
	else{
	head->next = newNode;
	newNode->next = NULL;
	//�������++
	head->data++;
	}

	printf("ͷ�巨����ɹ�......\n");
	return true;
}



//��������ӽ�㣨β�巨��
int tailAddNode(node *head,int data) {

	if (head == NULL) {
		printf("����ͷΪ��,�Զ���ʼ������......\n");
		initList(head);
		printf("��ʼ������ɹ�......\n");
	}

	node* newNode = (node*)malloc(sizeof(node)); //�½��
	newNode->data = data;


	node* p = (node*)malloc(sizeof(node));
	p->next = head;

	//������β
	while (1) {

		if (p->next->next != NULL) {
			p->next = p->next->next;
		}
		else {
			//���Բ���
			p->next->next = newNode;
			newNode->next = NULL;
			//ͷ����������+1��Ҳ����������+1��
			head->data++;
			printf("����ɹ�......\n");
			break;
		}

	}
	return true;
}
//�޸Ľ������
int updateNode(node *head,int index,int newDate) {

	if (index<1 || index>head->data) {
		printf("����index���Ϸ����޸�ʧ��......\n");
		return false;
	}
	else {
		int cur = 1;
		node* p = (node*)malloc(sizeof(node));
		p->next = head->next;
		while (true) {

			if (cur == index) {
				p->next->data = newDate;
				printf("�޸Ľ�����ݳɹ�......\n");
				break;
			}
			else {
				p->next = p->next->next;
				cur++;
			}

		}
	}



}


//�������
int clear(node* head)
{

	head == NULL;
	free(head); //�ͷ��ڴ�
	return true;
}

//ɾ��ָ��indexԪ��
int deleteNode(node *head,int index) {

	if (index<1 || index>head->data) {
		printf("����index���Ϸ����޸�ʧ��......\n");
		return false;
	}
	else {

		int cur = 0;
		node* p = (node*)malloc(sizeof(node));
		p->next = head;
		while (true) {

			if (cur+1 == index) {
				node* d = p->next->next; //������Ҫɾ���Ľ�㣬�Ա��ͷ��ڴ�
				p->next->next = p->next->next->next;
				free(d);
				printf("ɾ�����ɹ�......\n");
				break;
			}
			else {
				p->next = p->next->next;
				cur++;
			}

		}


	}


}


//�ж������Ƿ�Ϊ�ջ����Ƿ񳤶�Ϊ0��Ҳ����ͷ�����������Ƿ�Ϊ0��
int hasNULL(node *head) {

	return (head == NULL || head->data == 0) ? true : false;
}


//������ӡ����Ԫ��
void printList(node *head)
{
	if (hasNULL(head) == true) {
		printf("����Ϊ�գ�����ʧ��......\n");
		return;
	}
	else
	{
		node* p = head->next; //����һ��ָ��pָ��ͷ������һ��
		printf("��ӡ����Ԫ��......\n");
		while (true)
		{
			if (p == NULL) {
				printf("\n�������......\n");
				break;
			}
			else
			{
				printf("%d  ", p->data);
				p = p->next; //�ƶ�ָ��
			}

		}
	}


}


int main(void) {

	node* head = (node*)malloc(sizeof(node));
	initList(head);
	printList(head);

	tailAddNode(head, 15);

	tailAddNode(head, 25);

	headAddNode(head,33);

	headAddNode(head, 66);

	updateNode(head, 3, 99);

	printList(head);

	deleteNode(head,1);

	//clear(head);

	printList(head);

	return 0;

}