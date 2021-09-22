#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define max_size 5 //队列最大容量
typedef int status;
typedef int ElemType;

//C语言实现循环队列

typedef struct SeqQueue {

	ElemType data[max_size]; //存放data
	int front; //队首
	int rear; //队尾

} SeqQueue;

//初始化
SeqQueue* initQueue(SeqQueue* seqQueue)
{
	if (seqQueue == NULL)
	{
		seqQueue=(SeqQueue*)malloc(sizeof(SeqQueue));
	}

	seqQueue->front = seqQueue->rear = 0; //循环队列初始化指针指向0
	printf("初始化成功......\n");
	return seqQueue;
}

//队列空(和普通队列一样，都是队首=队尾就为空)
status hasNull(SeqQueue* seqQueue)
{
	if (seqQueue->front == seqQueue->rear) {
		return true;
	}
	else {
		return false;
	}
}

//队列满(和普通队列不一样,循环队列是队尾+1模上数组长度=队首就为满)
status hasFull(SeqQueue* seqQueue)
{
	if (((seqQueue->rear) + 1) % max_size == seqQueue->front) {
		return true;
	}
	else {
		return false;
	}
}

//入队
status enQueue(SeqQueue* seqQueue,int data)
{
	if (hasFull(seqQueue) == true)
	{
		printf("队列已满，不能入队......\n");
		return false;
	}
	else {
		seqQueue->data[seqQueue->rear] = data;
		//队尾指针后移
		seqQueue->rear = ((seqQueue->rear) + 1) % max_size; //等价于普通队列的rear+1
		printf("入队成功......\n");
		return true;
	}
}
//出队
status deQueue(SeqQueue* seqQueue)
{
	if (hasNull(seqQueue) == true)
	{
		printf("队列空，出队失败......\n");
		return false;
	}
	else {
		printf("出队成功......\n");
		seqQueue->front=(seqQueue->front + 1) % max_size;
		return true;
	}
}


void printQueue(SeqQueue* seqQueue)
{
	if (hasNull(seqQueue) == true)
	{
		printf("队列空，打印失败......\n");
	}
	else {

		printf("正在打印队列......\n");
		int temp = (seqQueue->front ) % max_size; //指向队首结点下一个
		//分情况
		//if (seqQueue->front > seqQueue->rear) {
			while (temp != (seqQueue->rear)) {
				printf("%d  ",seqQueue->data[temp]);
				temp = (temp + 1) % max_size;
			}
		 
		//else if(seqQueue->front < seqQueue->rear) {
			//while (temp != (seqQueue->rear) + 1)
			 //{}
		//}
	printf("\n打印成功......\n");
	}

}


int main(void)
{
	SeqQueue* seqQueue = NULL;
	seqQueue=initQueue(seqQueue);

	enQueue(seqQueue,10);
	enQueue(seqQueue, 20);
	enQueue(seqQueue, 30);

	deQueue(seqQueue);
	deQueue(seqQueue);

	enQueue(seqQueue, 50);
	enQueue(seqQueue, 60);


	printQueue(seqQueue);

	return 0;
}