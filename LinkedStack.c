#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int status;
typedef int Elemtype;
//C实现链式栈


typedef struct Node {

	Elemtype data; //每个结点的数据
	struct Node* next; //指向下一个结点的指针

} node;

typedef struct LinkedStack
{
	struct node* top; //栈顶指针

} LinkedStack;

//初始化
LinkedStack* init(LinkedStack* linkedStack)
{
	if (linkedStack == NULL)
	{
		linkedStack=(LinkedStack*)malloc(sizeof(linkedStack));
	}

	linkedStack->top = 0; //这段代码等价于===》linkedStack->top=NULL

	printf("初始化链栈完成......\n");
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
		printf("没有元素......\n");
		return false;
	}
	else {
		node* p = (node*)malloc(sizeof(node));
		p->next = linkedStack->top;
		printf("弹出元素：%d\n",p->next->data);
		linkedStack->top = p->next->next; //栈顶下移
		return true;
	}

}



void printStack(LinkedStack* linkedStack)
{
	printf("print start......\n");

	//创建一个指针指向栈顶
	node* temp = (node*)malloc(sizeof(node));
	temp->next = linkedStack -> top;

	//如果栈顶为NULL就退出
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