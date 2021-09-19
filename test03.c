#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

//C语言实现循环链表

//链表结点
typedef struct Node {

	int data;
	struct Node* next;

} node;

typedef struct Node* linklist;

void initList(linklist head)
{
	printf("初始化循环链表......\n");
	if (head == NULL) {
		head = (node*)malloc(sizeof(node));
	}
	head->data = 0;
	head->next = head; //初始化给head的指针指向自己

}

//插入(尾插法)
void tailAddNode(linklist head,int data) {

	node* p = (node*)malloc(sizeof(node));
	p->next = head;
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	while (true) {

		if (p->next->next == head) { //当前p->next就是尾
			p->next->next = newNode;
			newNode->next = head;
			head->data++;
			printf("插入结点成功......\n");
			break;
		}
		else {
			p->next = p->next->next;
		}
	}
}



//删除
void deleteNode(linklist head,int index)
{
	node* p = (node*)malloc(sizeof(node));
	p->next = head;
	int cur = 0;
	//int in = index % (head->data); //in是取模后的下标
	while (true)
	{
		if ((cur+1)==index) //此时下一个结点就是我们要删除的结点
		{
			node* temp = p->next->next;

			p->next->next = p->next->next->next;
			head->data--;
			free(temp);
			printf("删除结点成功......\n");
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
			printf("进入循环-> %d ", p->next->next->next->data);
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