#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 5 //˳����������
#define true 1  //�ɹ�
#define false 0 //ʧ��
typedef int status;

//C����ʵ��˳���

//����˳���ṹ��
typedef struct List {
	int data[MAX_SIZE]; //ģ��˳���
	int length; //˳���ʵ�ʳ��� length>=0 && length<=MAX_SIZE ,���Ա��Ǵ�1��ʼ�ģ�������Ǵ�0��ʼ
} list;

status init(list *plist) {
	//���plist=NULL������ڴ�
	if (plist == NULL) {
		printf("���ڷ����ڴ�....\n");
		plist = (list*)malloc(sizeof(list));
	}
	plist->length = 0;
}


//˳�����루β��ֱ�Ӳ��룩
status insertData(list* list, int dt) {
	//���listû�г�ʼ��
	if (hasInit(list) == false) {
		printf("listû�г�ʼ��������ʧ��\n");
		return false;
	}
	//�ж�˳����Ƿ�����
	if (list->length >= MAX_SIZE) {
		printf("˳�������,����ʧ��......\n");
		return false;
	}

	list->data[list->length]=dt;
	list->length++;
	printf("����ɹ�......\n");
	return true;
}
//˳�����루�Զ���λ�ò��룩
status insertData_zi(list* list, int n, int dt) {
	//���listû�г�ʼ��
	if (hasInit(list) == false) {
		printf("listû�г�ʼ��������ʧ��\n");
		return false;
	}
	//�ж�˳����Ƿ�����
	if (list->length >= MAX_SIZE) {
		printf("˳�������,����ʧ��......\n");
		return false;
	}
	//�ж��Զ����λ��n�Ƿ�Ϸ�
	if (n <= 0 || n >= MAX_SIZE) {
		return false;
	}
	else {
		int i;
		for (i = list->length; i >= n; i--) {

			list->data[i] = list->data[i - 1];

		}
		list->data[n - 1] = dt; //����
		list->length++; //����+1
		return true;
	}
}

//ɾ��Ԫ��
status deleteData(list *list,int n) {
	//���listû�г�ʼ��
	if (hasInit(list) == false) {
		printf("listû�г�ʼ��������ʧ��\n");
		return false;
	}
	//����б�Ϊ�գ�����ɾ��
	if (list->length == 0) {
		printf("�б�Ϊ�գ�����ɾ��\n");
		return false;
	}

	//���n���Ϸ�����ɾ��ʧ��
	if (n<1||n>MAX_SIZE) {
		printf("����n���Ϸ���ɾ��ʧ��\n");
		return false;
	}

	int i;
	for (i = n - 1; i < list->length - 1; i++) {

		list->data[i] = list->data[i + 1];
	}

	list->length--;
	return true;
}

//�ж��Ƿ��ʼ����
status hasInit(list* list) {

	if (list == NULL) {

		return false;
	}
	else {

		return true;
	}
}


//�޸�ָ��Ԫ��
status changeData(list *list,int n,int dt)
{
	//���listû�г�ʼ��
	if (hasInit(list) == false) {
		printf("listû�г�ʼ��������ʧ��\n");
		return false;
	}
	//���Ա�Ϊ��
	if (list->length == 0) {
		return false;
	}
	//�ж�n�Ƿ�Ϸ�
	//if (n<1 || n>MAX_SIZE) { //���ﲻ��ʹ��n>MAX_SIZE��Ҫn>list->length
	if (n<1 || n>list->length) {

		return false;
	}
	else
	{ //��ʱ�����޸�

		list->data[n - 1] = dt;
		return true;
	}
}


//����Ԫ��(����ֵ���в��ң����ѡ��±ꡱ���浽res������,�����ҳ�10��)
status getElem(list *list,int dt,int res[10],int *count) {


	//���listû�г�ʼ��
	if (hasInit(list) == false) {
		printf("listû�г�ʼ��������ʧ��\n");
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
	//���listû�г�ʼ��
	if (hasInit(list) == false) {
		printf("listû�г�ʼ��������ʧ��\n");
		return false;
	}
	int i;
	printf("��ӡ˳���list......\n");
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
	printf("getElem����Ϊ��%d\n", *len);
	printf("%d\n",res[0]);

	return 0;
}