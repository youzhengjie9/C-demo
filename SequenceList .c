#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 5 //顺序表最大容量
#define true 1  //成功
#define false 0 //失败
typedef int status;

//C语言实现顺序表

//定义顺序表结构体
typedef struct List {
	int data[MAX_SIZE]; //模拟顺序表
	int length; //顺序表实际长度 length>=0 && length<=MAX_SIZE ,线性表是从1开始的，数组才是从0开始
} list;

status init(list *plist) {
	//如果plist=NULL则分配内存
	if (plist == NULL) {
		printf("正在分配内存....\n");
		plist = (list*)malloc(sizeof(list));
	}
	plist->length = 0;
}


//顺序表插入（尾部直接插入）
status insertData(list* list, int dt) {
	//如果list没有初始化
	if (hasInit(list) == false) {
		printf("list没有初始化，操作失败\n");
		return false;
	}
	//判断顺序表是否满了
	if (list->length >= MAX_SIZE) {
		printf("顺序表满了,插入失败......\n");
		return false;
	}

	list->data[list->length]=dt;
	list->length++;
	printf("插入成功......\n");
	return true;
}
//顺序表插入（自定义位置插入）
status insertData_zi(list* list, int n, int dt) {
	//如果list没有初始化
	if (hasInit(list) == false) {
		printf("list没有初始化，操作失败\n");
		return false;
	}
	//判断顺序表是否满了
	if (list->length >= MAX_SIZE) {
		printf("顺序表满了,插入失败......\n");
		return false;
	}
	//判断自定义的位置n是否合法
	if (n <= 0 || n >= MAX_SIZE) {
		return false;
	}
	else {
		int i;
		for (i = list->length; i >= n; i--) {

			list->data[i] = list->data[i - 1];

		}
		list->data[n - 1] = dt; //插入
		list->length++; //长度+1
		return true;
	}
}

//删除元素
status deleteData(list *list,int n) {
	//如果list没有初始化
	if (hasInit(list) == false) {
		printf("list没有初始化，操作失败\n");
		return false;
	}
	//如果列表为空，则不能删除
	if (list->length == 0) {
		printf("列表为空，不能删除\n");
		return false;
	}

	//如果n不合法，则删除失败
	if (n<1||n>MAX_SIZE) {
		printf("参数n不合法，删除失败\n");
		return false;
	}

	int i;
	for (i = n - 1; i < list->length - 1; i++) {

		list->data[i] = list->data[i + 1];
	}

	list->length--;
	return true;
}

//判断是否初始化表
status hasInit(list* list) {

	if (list == NULL) {

		return false;
	}
	else {

		return true;
	}
}


//修改指定元素
status changeData(list *list,int n,int dt)
{
	//如果list没有初始化
	if (hasInit(list) == false) {
		printf("list没有初始化，操作失败\n");
		return false;
	}
	//线性表为空
	if (list->length == 0) {
		return false;
	}
	//判断n是否合法
	//if (n<1 || n>MAX_SIZE) { //这里不能使用n>MAX_SIZE，要n>list->length
	if (n<1 || n>list->length) {

		return false;
	}
	else
	{ //此时可以修改

		list->data[n - 1] = dt;
		return true;
	}
}


//查找元素(按照值进行查找，并把“下标”保存到res数组中,最多查找出10个)
status getElem(list *list,int dt,int res[10],int *count) {


	//如果list没有初始化
	if (hasInit(list) == false) {
		printf("list没有初始化，操作失败\n");
		return false;
	}


	int i;
	int index = 0;
	for (i = 0; i < list->length; i++)
	{
		if (list->data[i] == dt) {
			printf("index:%d\n",i);
			res[index] = i;
			index++;
		}

	}
	*count = index;

	return true;
}



status printList(list *list)
{
	//如果list没有初始化
	if (hasInit(list) == false) {
		printf("list没有初始化，操作失败\n");
		return false;
	}
	int i;
	printf("打印顺序表list......\n");
	for (i = 0; i < list->length; i++)
	{
		printf("%d ",list->data[i]);
	}
	printf("\n.........................\n");
	return true;
}


int main(void)
{
	list* plist = (list*)malloc(sizeof(list));
	init(plist);
	insertData(plist,10);
	insertData(plist, 20);
	printList(plist);

	int res[10] = { 0 };
	int *len = (int*)malloc(sizeof(int));
	getElem(plist,30,res,len);
	printf("getElem长度为：%d\n", *len);
	printf("%d\n",res[0]);

	return 0;
}