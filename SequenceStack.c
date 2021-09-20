#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0
#define max_size 5
typedef int elemtype;
typedef int status;

//C����ʵ��˳��ջ

typedef struct Stack {

	int top; //ջ������
	elemtype data[max_size]; //ջ����

}Stack;


Stack* init(Stack* stack)
{
	printf("init stack start......\n");

	stack = (Stack*)malloc(sizeof(stack));
	if (stack == NULL)
	{
		printf("�����ڴ�ʧ��......\n");
		exit(0);
	}

	stack->top = -1; //��ʼ��ջ��ָ��

	printf("init stack success......\n");
	return stack;
}

//ջ��
status hasNull(Stack* stack)
{
	if (stack->top <= -1) {
		return true;
	}
	else {
		return false;
	}
}

//ջ��
status hasFull(Stack* stack)
{
	if (stack->top==max_size-1) {
		return true;
	}
	else {
		return false;
	}
}

//��ջ
status push(Stack *stack,int data)
{
	if (hasFull(stack) == true)
	{
		printf("stack is full......\n");
		return false;
	}
	else {
		stack->data[++stack->top] = data;
		printf("push success......\n");
		return true;
	}

}

//��ջ
status pop(Stack* stack)
{
	if (hasNull(stack)==true)
	{
		printf("stack is Null......\n");
		return false;
	}
	else {
		printf("����Ԫ��: %d \n",stack->data[stack->top--]);
		return true;
	}
}

void printStack(Stack* stack)
{
	if (hasNull(stack) == true) //���ջ��
	{
		printf("ջΪ��......\n");
	}
	else {
		int i;
		printf("���ڴ�ӡջ......\n");
		for (i = stack->top; i >= 0; i--)
		{
			printf("%d\n",stack->data[i]);
		}
		printf("��ӡ���......\n");
	}


}


int main(void)
{
	Stack* stack = NULL;
	stack=init(stack);

	printStack(stack);

	push(stack, 13);
	push(stack, 23);
	push(stack, 66);
	push(stack, 16);
	push(stack, 25);

	push(stack, 33);
	printStack(stack);

	pop(stack);

	pop(stack);

	printStack(stack);

	return 0;
}