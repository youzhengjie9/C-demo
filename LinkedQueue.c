#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int status;
typedef int Elemtype;

//C ʵ����ʽ����
typedef struct Node {

	Elemtype data;
	struct Node* next;

} node;

typedef struct LinkedQueue
{
	struct Node* front; //ָ����׵�ָ��
	struct Node* rear; //ָ���β��ָ��

} LinkedQueue;

//init queue
LinkedQueue* initQueue(LinkedQueue* linkedQueue)
{
	if (linkedQueue == NULL)
	{
		linkedQueue = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	}
	//����һ�������Ϊ���е�ͷ��㣨���Ƕ�ͷ��
	linkedQueue->front = linkedQueue->rear = (node*)malloc(sizeof(node));
	printf("init queue success......\n");
	return linkedQueue;
}

//���
status enQueue(LinkedQueue* linkedQueue,int data)
{
	if (linkedQueue == NULL)
	{
		printf("���ʧ��...\n");
		return false;
	}
	else {

		node* newNode = (node*)malloc(sizeof(node));
		newNode->data = data;

		//���
		linkedQueue->rear->next = newNode;
		newNode->next = NULL;

		//��Ӻ�βָ����Ƶ��½ڵ�
		linkedQueue->rear = newNode;
		printf("��ӳɹ�...\n");
		return true;
	}


}

//����
int* deQueue(LinkedQueue* linkedQueue)
{
	if (linkedQueue == NULL || (linkedQueue->front == linkedQueue->rear))
	{	
		printf("����û���κ�Ԫ�أ�����ʧ��......\n");
		return -99999;
	}
	else {
		node* p = linkedQueue->front->next; //��������ӽ��
		int res = p->data;

		//���׽���ָ��ָ������ӽ�����һ����㼴��
		linkedQueue->front->next = p->next;

		free(p); //�ͷų��ӽ����Դ
		return res;
	}

}

void printQueue(LinkedQueue* linkedQueue)
{
	printf("��ӡ����......\n");
	//(linkedQueue->front == linkedQueue->rear) ���Ϊtrue�������û���κ�Ԫ��
	if (linkedQueue == NULL || (linkedQueue->front == linkedQueue->rear))
	{
		printf("����û���κ�Ԫ��......\n");
	}
	else {
		//����һ��ָ��ָ����׽��
		node* temp=(node*)malloc(sizeof(node));
		temp->next = linkedQueue->front;

		while (temp->next->next!=NULL)
		{
			printf("%d  ",temp->next->next->data);
			temp->next = temp->next->next;
		}
		printf("\n��ӡ�ɹ�......\n");
	}

}


int main(void)
{
	LinkedQueue* linkedQueue = NULL;
	linkedQueue = initQueue(linkedQueue);

	enQueue(linkedQueue, 20);
	enQueue(linkedQueue, 50);
	enQueue(linkedQueue, 115);
	enQueue(linkedQueue, 95);
	printQueue(linkedQueue);

	printf("���ӽ�㣺%d\n", deQueue(linkedQueue));
	printf("���ӽ�㣺%d\n", deQueue(linkedQueue));

	printf("���ӽ�㣺%d\n", deQueue(linkedQueue));
	printQueue(linkedQueue);
	return 0;
}