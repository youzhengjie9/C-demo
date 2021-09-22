#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int status;
typedef int Elemtype;

//C 实现链式队列
typedef struct Node {

	Elemtype data;
	struct Node* next;

} node;

typedef struct LinkedQueue
{
	struct Node* front; //指向队首的指针
	struct Node* rear; //指向队尾的指针

} LinkedQueue;

//init queue
LinkedQueue* initQueue(LinkedQueue* linkedQueue)
{
	if (linkedQueue == NULL)
	{
		linkedQueue = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	}
	//创建一个结点作为队列的头结点（不是队头）
	linkedQueue->front = linkedQueue->rear = (node*)malloc(sizeof(node));
	printf("init queue success......\n");
	return linkedQueue;
}

//入队
status enQueue(LinkedQueue* linkedQueue,int data)
{
	if (linkedQueue == NULL)
	{
		printf("入队失败...\n");
		return false;
	}
	else {

		node* newNode = (node*)malloc(sizeof(node));
		newNode->data = data;

		//入队
		linkedQueue->rear->next = newNode;
		newNode->next = NULL;

		//入队后尾指针后移到新节点
		linkedQueue->rear = newNode;
		printf("入队成功...\n");
		return true;
	}


}

//出队
int* deQueue(LinkedQueue* linkedQueue)
{
	if (linkedQueue == NULL || (linkedQueue->front == linkedQueue->rear))
	{	
		printf("队列没有任何元素，出队失败......\n");
		return -99999;
	}
	else {
		node* p = linkedQueue->front->next; //保存待出队结点
		int res = p->data;

		//队首结点的指针指向待出队结点的下一个结点即可
		linkedQueue->front->next = p->next;

		free(p); //释放出队结点资源
		return res;
	}

}

void printQueue(LinkedQueue* linkedQueue)
{
	printf("打印队列......\n");
	//(linkedQueue->front == linkedQueue->rear) 如果为true，则队列没有任何元素
	if (linkedQueue == NULL || (linkedQueue->front == linkedQueue->rear))
	{
		printf("队列没有任何元素......\n");
	}
	else {
		//创建一个指针指向队首结点
		node* temp=(node*)malloc(sizeof(node));
		temp->next = linkedQueue->front;

		while (temp->next->next!=NULL)
		{
			printf("%d  ",temp->next->next->data);
			temp->next = temp->next->next;
		}
		printf("\n打印成功......\n");
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

	printf("出队结点：%d\n", deQueue(linkedQueue));
	printf("出队结点：%d\n", deQueue(linkedQueue));

	printf("出队结点：%d\n", deQueue(linkedQueue));
	printQueue(linkedQueue);
	return 0;
}