#include <stdio.h>
#include <stdlib.h>
#define sz 5 //�����С����
typedef int elemtype;

//C����ʵ�ֲ��鼯Disjoint Set

//���鼯�ṹ��
typedef struct disjointSet
{
	int size; //fa����Ĵ�С
	elemtype* fa; //�洢���ڵ������

} disjointSet;

disjointSet* initSet(disjointSet* ds)
{
	if (ds == NULL)
	{
		ds = (disjointSet*)malloc(sizeof(disjointSet));
	}
	ds->size = sz;

	//��fa��������ڴ�
	ds->fa = malloc(sizeof(elemtype) * ds->size + 1);

	int i;
	for (i = 1; i <=ds->size; i++)
	{
		//Ĭ�ϸ��������Ԫ��ָ��0����ʵ����ָ�����Լ�
		ds->fa[i] = 0;
	}
	printf("��ʼ�����鼯�ɹ�......\n");

	return ds;
}


//���鼯�ĵݹ����Ԫ�صġ�����㡮���ĸ��ڵ㣬��Ϊfa����洢���ǽ��ĸ��ڵ㣨�п��ܲ�������㣩
int findSet(disjointSet* disjointSet,int n)
{
	
	if (disjointSet->fa[n] == 0) //˵��n���ָ���Լ�,Ҳ˵���������Ľ��
	{
		return n;
	}
	else {
		//·��ѹ��,��߲�ѯ����
		disjointSet->fa[n]=findSet(disjointSet, disjointSet->fa[n]); //�ݹ��ҵ����Ľ��
	}
}


//���鼯�ĺϲ������ģ�,�ϲ�n1-n2
void unionSet(disjointSet* disjointSet, int n1, int n2)
{
	//�ҵ�n1-n2�����ĸ��ڵ���кϲ�
	int f1 = findSet(disjointSet, n1); 
	int f2 = findSet(disjointSet, n2);

	if (f1 == f2) //���f1=f2��˵������ͬһ�������У�����Ҫ�ϲ�
	{
		printf("n1��n2�Ѿ���ͬһ�������У�����Ҫ�ϲ�......\n");
		return;
	}
	else {
		disjointSet->fa[f1] = f2; //�ϲ�
		printf("�ϲ��ɹ�......\n");
		return;
	}

}


int main(void)
{
	disjointSet* disjointSet = NULL;

	disjointSet = initSet(disjointSet);

	unionSet(disjointSet, 6, 2);
	unionSet(disjointSet, 5, 4);
	unionSet(disjointSet, 4, 1);
	unionSet(disjointSet, 3, 1);



	int f1=findSet(disjointSet, 6);

	printf("findset:%d\n",f1);

	int f2 = findSet(disjointSet, 1);

	printf("findset:%d\n", f2);


	return 0;

}
