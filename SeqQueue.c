#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define max_size 5 //�����������
typedef int status;
typedef int ElemType;

//C����ʵ��ѭ������

typedef struct SeqQueue {

	ElemType data[max_size]; //���data
	int front; //����
	int rear; //��β

} SeqQueue;

//��ʼ��
SeqQueue* initQueue(SeqQueue* seqQueue)
{
	if (seqQueue == NULL)
	{
		seqQueue=(SeqQueue*)malloc(sizeof(SeqQueue));
	}

	seqQueue->front = seqQueue->rear = 0; //ѭ�����г�ʼ��ָ��ָ��0
	printf("��ʼ���ɹ�......\n");
	return seqQueue;
}

//���п�(����ͨ����һ�������Ƕ���=��β��Ϊ��)
status hasNull(SeqQueue* seqQueue)
{
	if (seqQueue->front == seqQueue->rear) {
		return true;
	}
	else {
		return false;
	}
}

//������(����ͨ���в�һ��,ѭ�������Ƕ�β+1ģ�����鳤��=���׾�Ϊ��)
status hasFull(SeqQueue* seqQueue)
{
	if (((seqQueue->rear) + 1) % max_size == seqQueue->front) {
		return true;
	}
	else {
		return false;
	}
}

//���
status enQueue(SeqQueue* seqQueue,int data)
{
	if (hasFull(seqQueue) == true)
	{
		printf("�����������������......\n");
		return false;
	}
	else {
		seqQueue->data[seqQueue->rear] = data;
		//��βָ�����
		seqQueue->rear = ((seqQueue->rear) + 1) % max_size; //�ȼ�����ͨ���е�rear+1
		printf("��ӳɹ�......\n");
		return true;
	}
}
//����
status deQueue(SeqQueue* seqQueue)
{
	if (hasNull(seqQueue) == true)
	{
		printf("���пգ�����ʧ��......\n");
		return false;
	}
	else {
		printf("���ӳɹ�......\n");
		seqQueue->front=(seqQueue->front + 1) % max_size;
		return true;
	}
}


void printQueue(SeqQueue* seqQueue)
{
	if (hasNull(seqQueue) == true)
	{
		printf("���пգ���ӡʧ��......\n");
	}
	else {

		printf("���ڴ�ӡ����......\n");
		int temp = (seqQueue->front ) % max_size; //ָ����׽����һ��
		//�����
		//if (seqQueue->front > seqQueue->rear) {
			while (temp != (seqQueue->rear)) {
				printf("%d  ",seqQueue->data[temp]);
				temp = (temp + 1) % max_size;
			}
		 
		//else if(seqQueue->front < seqQueue->rear) {
			//while (temp != (seqQueue->rear) + 1)
			 //{}
		//}
	printf("\n��ӡ�ɹ�......\n");
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