#include <stdio.h>
#include <stdlib.h>
#define max 5
#define defaultNum 95535
//哈希表 （数组实现闭散列）

typedef struct Hashtable
{

	int cur; //当前元素个数
	int maxSize; //最大容量
	int* table; //数据存储空间

} Hashtable;

//初始化哈希表
Hashtable* init(Hashtable *hashtable)
{
	 
	if (hashtable == NULL)
	{
		hashtable = (Hashtable*)malloc(sizeof(hashtable));

	}

	hashtable->cur = 0; //初始化元素个数为0
	hashtable->maxSize = max;
	
	hashtable->table=(int*)malloc(sizeof(int) * max);   //这里一定要给int*数组分配内存---------

	int i = 0;
	for ( i = 0; i < hashtable->maxSize; i++)
	{
		hashtable->table[i] = defaultNum;
	}
	printf("init success......\n");
	return hashtable;

}


//散列函数
int hash(Hashtable* hashtable, int data)
{
	return data % hashtable->maxSize;
}


//添加元素
void put(Hashtable* hashtable, int data)
{

	if (hashtable->cur >= hashtable->maxSize)
	{
		printf("哈希表已满，插入失败......\n");
		return;
	}
	else {

		int index = hash(hashtable, data); //获取散列后的index

		if (hashtable->table[index] == defaultNum) //说明没有发生哈希冲突，可以直接插入
		{
			hashtable->cur++;
			hashtable->table[index] = data;
			printf("插入元素成功......\n");
			return;
		}
		else
		{
			int i = 1;
			while (1)
			{

				index =hash(hashtable,data+i);
				i++;
				if (hashtable->table[index] == defaultNum) //再哈希
				{
					hashtable->cur++;
					hashtable->table[index] = data;
					printf("再哈希，插入元素成功......\n");
					break;
				}

				if (i == hashtable->maxSize - 1)
				{
					printf("已遍历完整个哈希表，没有合适位置插入.......\n");
					break;
				}


			}


		}

	}

	 



}


int search(Hashtable* hashtable, int data)
{

	int index = hash(hashtable, data);

	if (hashtable->table[index] == defaultNum)
	{
		printf("没有该元素......\n");
		return -99;
	}
	else {

		if (hashtable->table[index] == data)
		{
			printf("查找成功......\n");
			return index;
		}
		else {

			int i = 1;

			while (1)
			{
				index = hash(hashtable, data+i);
				i++;
				if (hashtable->table[index] == data)
				{
					printf("查找成功......\n");
					return index;
				}
				 

				if (i == hashtable->maxSize - 1)
				{
					printf("查找失败......\n");
					break;
				}

			}
			return -99;
		}

	}




}


void printHash(Hashtable* hashtable)
{
	printf("开始打印......\n");
	int i = 0;
	for ( i = 0; i < hashtable->maxSize; i++)
	{
		printf("%d   ",hashtable->table[i]);
	}
	printf("\n打印结束......\n");
}

 


int main(void)
{

	Hashtable* hashtable = NULL;

	hashtable = init(hashtable);

	put(hashtable, 13);
	put(hashtable, 10);
	put(hashtable, 17);
	put(hashtable, 15);
	put(hashtable, 13);
	put(hashtable, 16);


	printHash(hashtable);

	int x1=search(hashtable,15);

	printf("search:%d\n",x1);


	return 0;


}
