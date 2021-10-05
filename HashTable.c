#include <stdio.h>
#include <stdlib.h>
#define max 5
#define defaultNum 95535
//��ϣ�� ������ʵ�ֱ�ɢ�У�

typedef struct Hashtable
{

	int cur; //��ǰԪ�ظ���
	int maxSize; //�������
	int* table; //���ݴ洢�ռ�

} Hashtable;

//��ʼ����ϣ��
Hashtable* init(Hashtable *hashtable)
{
	 
	if (hashtable == NULL)
	{
		hashtable = (Hashtable*)malloc(sizeof(hashtable));

	}

	hashtable->cur = 0; //��ʼ��Ԫ�ظ���Ϊ0
	hashtable->maxSize = max;
	
	hashtable->table=(int*)malloc(sizeof(int) * max);   //����һ��Ҫ��int*��������ڴ�---------

	int i = 0;
	for ( i = 0; i < hashtable->maxSize; i++)
	{
		hashtable->table[i] = defaultNum;
	}
	printf("init success......\n");
	return hashtable;

}


//ɢ�к���
int hash(Hashtable* hashtable, int data)
{
	return data % hashtable->maxSize;
}


//���Ԫ��
void put(Hashtable* hashtable, int data)
{

	if (hashtable->cur >= hashtable->maxSize)
	{
		printf("��ϣ������������ʧ��......\n");
		return;
	}
	else {

		int index = hash(hashtable, data); //��ȡɢ�к��index

		if (hashtable->table[index] == defaultNum) //˵��û�з�����ϣ��ͻ������ֱ�Ӳ���
		{
			hashtable->cur++;
			hashtable->table[index] = data;
			printf("����Ԫ�سɹ�......\n");
			return;
		}
		else
		{
			int i = 1;
			while (1)
			{

				index =hash(hashtable,data+i);
				i++;
				if (hashtable->table[index] == defaultNum) //�ٹ�ϣ
				{
					hashtable->cur++;
					hashtable->table[index] = data;
					printf("�ٹ�ϣ������Ԫ�سɹ�......\n");
					break;
				}

				if (i == hashtable->maxSize - 1)
				{
					printf("�ѱ�����������ϣ��û�к���λ�ò���.......\n");
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
		printf("û�и�Ԫ��......\n");
		return -99;
	}
	else {

		if (hashtable->table[index] == data)
		{
			printf("���ҳɹ�......\n");
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
					printf("���ҳɹ�......\n");
					return index;
				}
				 

				if (i == hashtable->maxSize - 1)
				{
					printf("����ʧ��......\n");
					break;
				}

			}
			return -99;
		}

	}




}


void printHash(Hashtable* hashtable)
{
	printf("��ʼ��ӡ......\n");
	int i = 0;
	for ( i = 0; i < hashtable->maxSize; i++)
	{
		printf("%d   ",hashtable->table[i]);
	}
	printf("\n��ӡ����......\n");
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
