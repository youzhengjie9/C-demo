#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//宏定义常量
#define true 1
#define false 0

//C语言实现单链表


//链表结点结构体
typedef struct Node {
	int data; //数据域(头结点的数据域存储链表结点数量，其他普通结点存储用户输入的数据)
	struct Node *next; //指针域
} node;

//初始化链表
void initList(node *head)
{
	if (head == NULL) {
		head = (node*)malloc(sizeof(node));
	}
	head->next = NULL; //头结点指针指向空
	head->data = 0; //头结点的数据源存储链表长度
	printf("初始化链表成功......\n");
}


//自定义插入(index就是第几个结点位置插入)，比如10 20 30，index=2 data=40 =>10 40 20 30
int addNodeByIndex(node *head,int index,int data)
{
	if (index<1 || index>head->data) {
		printf("参数index不合法，请检查......\n");
		return false;
	}
	else {
		node* newNode = (node*)malloc(sizeof(node));
		newNode->data = data;
		node* p = (node*)malloc(sizeof(node));
		p->next = head;
		int cur = 0;	//当前指针p指向的下标

		while (true) {

			if ((cur+1) == index) { //如果下一个结点是，则找到
				newNode->next = p->next->next;
				p->next->next = newNode;
				head->data++;
				printf("自定义插入成功......\n");
				break;
			}
			else { //继续遍历
				p->next = p->next->next;
				cur++;
			}

		}


	}

}



//往链表添加结点（头插法）
int headAddNode(node *head,int data) {

	if (head == NULL) {
		printf("链表头为空,自动初始化链表......\n");
		initList(head);
		printf("初始化链表成功......\n");
	}
	node* newNode = (node*)malloc(sizeof(node));

	newNode->data = data;

	//尾插法插入，有两种情况
	//1：head->next!=NULL //这种情况是第一次插入元素的情况下执行，否则链表会断
	if (head->next != NULL) {
		addNodeByIndex(head,1,data);
	}
	//2:head->next==NULL   //这种情况是在已经插入过元素的情况下执行
	else{
	head->next = newNode;
	newNode->next = NULL;
	//结点数量++
	head->data++;
	}

	printf("头插法插入成功......\n");
	return true;
}



//往链表添加结点（尾插法）
int tailAddNode(node *head,int data) {

	if (head == NULL) {
		printf("链表头为空,自动初始化链表......\n");
		initList(head);
		printf("初始化链表成功......\n");
	}

	node* newNode = (node*)malloc(sizeof(node)); //新结点
	newNode->data = data;


	node* p = (node*)malloc(sizeof(node));
	p->next = head;

	//找链表尾
	while (1) {

		if (p->next->next != NULL) {
			p->next = p->next->next;
		}
		else {
			//可以插入
			p->next->next = newNode;
			newNode->next = NULL;
			//头结点的数据域+1（也就是链表长度+1）
			head->data++;
			printf("插入成功......\n");
			break;
		}

	}
	return true;
}
//修改结点数据
int updateNode(node *head,int index,int newDate) {

	if (index<1 || index>head->data) {
		printf("参数index不合法，修改失败......\n");
		return false;
	}
	else {
		int cur = 1;
		node* p = (node*)malloc(sizeof(node));
		p->next = head->next;
		while (true) {

			if (cur == index) {
				p->next->data = newDate;
				printf("修改结点数据成功......\n");
				break;
			}
			else {
				p->next = p->next->next;
				cur++;
			}

		}
	}



}


//清空链表
int clear(node* head)
{

	head == NULL;
	free(head); //释放内存
	return true;
}

//删除指定index元素
int deleteNode(node *head,int index) {

	if (index<1 || index>head->data) {
		printf("参数index不合法，修改失败......\n");
		return false;
	}
	else {

		int cur = 0;
		node* p = (node*)malloc(sizeof(node));
		p->next = head;
		while (true) {

			if (cur+1 == index) {
				node* d = p->next->next; //保存需要删除的结点，以便释放内存
				p->next->next = p->next->next->next;
				free(d);
				printf("删除结点成功......\n");
				break;
			}
			else {
				p->next = p->next->next;
				cur++;
			}

		}


	}


}


//判断链表是否为空或者是否长度为0（也就是头结点的数据域是否为0）
int hasNULL(node *head) {

	return (head == NULL || head->data == 0) ? true : false;
}


//遍历打印链表元素
void printList(node *head)
{
	if (hasNULL(head) == true) {
		printf("链表为空，遍历失败......\n");
		return;
	}
	else
	{
		node* p = head->next; //创建一个指针p指向头结点的下一个
		printf("打印链表元素......\n");
		while (true)
		{
			if (p == NULL) {
				printf("\n遍历完成......\n");
				break;
			}
			else
			{
				printf("%d  ", p->data);
				p = p->next; //移动指针
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