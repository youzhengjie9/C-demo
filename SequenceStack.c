#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0
#define max_size 5
typedef int elemtype;
typedef int status;

//C语言实现顺序栈

typedef struct Stack {

	int top; //栈顶索引
	elemtype data[max_size]; //栈数组

}Stack;


Stack* init(Stack* stack)
{
	printf("init stack start......\n");

	stack = (Stack*)malloc(sizeof(stack));
	if (stack == NULL)
	{
		printf("分配内存失败......\n");
		exit(0);
	}

	stack->top = -1; //初始化栈顶指针

	printf("init stack success......\n");
	return stack;
}

//栈空
status hasNull(Stack* stack)
{
	if (stack->top <= -1) {
		return true;
	}
	else {
		return false;
	}
}

//栈满
status hasFull(Stack* stack)
{
	if (stack->top==max_size-1) {
		return true;
	}
	else {
		return false;
	}
}

//入栈
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

//弹栈
status pop(Stack* stack)
{
	if (hasNull(stack)==true)
	{
		printf("stack is Null......\n");
		return false;
	}
	else {
		printf("弹出元素: %d \n",stack->data[stack->top--]);
		return true;
	}
}

void printStack(Stack* stack)
{
	if (hasNull(stack) == true) //如果栈空
	{
		printf("栈为空......\n");
	}
	else {
		int i;
		printf("正在打印栈......\n");
		for (i = stack->top; i >= 0; i--)
		{
			printf("%d\n",stack->data[i]);
		}
		printf("打印完成......\n");
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