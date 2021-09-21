#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int status;
typedef int Elemtype;
//Cʵ����ʽջ


typedef struct Node {

	Elemtype data; //ÿ����������
	struct Node* next; //ָ����һ������ָ��

} node;

typedef struct LinkedStack
{
	struct node* top; //ջ��ָ��

} LinkedStack;

//��ʼ��
LinkedStack* init(LinkedStack* linkedStack)
{
	if (linkedStack == NULL)
	{
		linkedStack=(LinkedStack*)malloc(sizeof(linkedStack));
	}

	linkedStack->top = 0; //��δ���ȼ���===��linkedStack->top=NULL

	printf("��ʼ����ջ���......\n");
	return linkedStack;
}

status push(LinkedStack* linkedStack,int data)
{

	node* newNode = (node*)malloc(sizeof(node));

	newNode->data = data;

	newNode->next = linkedStack->top;
	linkedStack->top = newNode;
	return true;
}

status pop(LinkedStack* linkedStack)
{

	if (linkedStack->top == 0)
	{
		printf("û��Ԫ��......\n");
		return false;
	}
	else {
		node* p = (node*)malloc(sizeof(node));
		p->next = linkedStack->top;
		printf("����Ԫ�أ�%d\n",p->next->data);
		linkedStack->top = p->next->next; //ջ������
		return true;
	}

}



void printStack(LinkedStack* linkedStack)
{
	printf("print start......\n");

	//����һ��ָ��ָ��ջ��
	node* temp = (node*)malloc(sizeof(node));
	temp->next = linkedStack -> top;

	//���ջ��ΪNULL���˳�
	while (temp->next != 0)
	{
		printf("%d\n",temp->next->data);
		temp->next = temp->next->next;
	}


	printf("print success......\n");
}


int main(void)
{
	LinkedStack* linkedStack = NULL;
	linkedStack =init(linkedStack);
	push(linkedStack,12);
	push(linkedStack, 22);
	push(linkedStack, 32);
	printStack(linkedStack);

	pop(linkedStack);

	printStack(linkedStack);
	return 0;
}