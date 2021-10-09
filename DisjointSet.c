#include <stdio.h>
#include <stdlib.h>
#define sz 5 //数组大小常量
typedef int elemtype;

//C语言实现并查集Disjoint Set

//并查集结构体
typedef struct disjointSet
{
	int size; //fa数组的大小
	elemtype* fa; //存储父节点的数组

} disjointSet;

disjointSet* initSet(disjointSet* ds)
{
	if (ds == NULL)
	{
		ds = (disjointSet*)malloc(sizeof(disjointSet));
	}
	ds->size = sz;

	//给fa数组分配内存
	ds->fa = malloc(sizeof(elemtype) * ds->size + 1);

	int i;
	for (i = 1; i <=ds->size; i++)
	{
		//默认父结点数组元素指向0，其实就是指向它自己
		ds->fa[i] = 0;
	}
	printf("初始化并查集成功......\n");

	return ds;
}


//并查集的递归查找元素的‘’最顶层‘’的父节点，因为fa数组存储的是结点的父节点（有可能不是最顶层结点）
int findSet(disjointSet* disjointSet,int n)
{
	
	if (disjointSet->fa[n] == 0) //说明n结点指向自己,也说明这是最顶层的结点
	{
		return n;
	}
	else {
		//路径压缩,提高查询性能
		disjointSet->fa[n]=findSet(disjointSet, disjointSet->fa[n]); //递归找到最顶层的结点
	}
}


//并查集的合并（核心）,合并n1-n2
void unionSet(disjointSet* disjointSet, int n1, int n2)
{
	//找到n1-n2的最顶层的父节点进行合并
	int f1 = findSet(disjointSet, n1); 
	int f2 = findSet(disjointSet, n2);

	if (f1 == f2) //如果f1=f2，说明是在同一个集合中，不需要合并
	{
		printf("n1和n2已经在同一个集合中，不需要合并......\n");
		return;
	}
	else {
		disjointSet->fa[f1] = f2; //合并
		printf("合并成功......\n");
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
