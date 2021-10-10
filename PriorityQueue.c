#include <stdio.h>
#include <stdlib.h>
#define sz 5   //final queue size
#define true 1
#define false 0
typedef int elemtype;
//优先队列priority queue

typedef struct priorityQueue
{
	int cur; //priorityQueue current index
	int size; //priorityQueue size
	elemtype* queue; //priorityQueue arr
	
} priorityQueue;

//init queue
priorityQueue* initQueue(priorityQueue* q)
{
		if(q==NULL)
		{
			q=(priorityQueue*)malloc(sizeof(priorityQueue)*2);
		}
		
		q->cur=0;
		q->size=sz;
		q->queue=(elemtype*)malloc(sizeof(elemtype)*q->size+2);
		
		
		return q;
}

//队列满
int hasFull(priorityQueue* q)
{
	if(q->cur>=q->size)
	{
		return true; //满了
	}else{
		return false;
	}
	
}

//insert q->queue[1] is head-Node
void insert(priorityQueue* q,int x)
{
	if(hasFull(q)==true) //队列满
	{
		printf("queue is full......\n");
		return;
	}
	if(q->cur==0) //if queue is null
	{
		++q->cur;
		q->queue[1]=x;
		printf("insert success......\n");
		return;
	}else{
		
		int i; //插入index
		for(i=++q->cur;q->queue[i/2]>q->queue[i];i=i/2)
		{
			q->queue[i]=q->queue[i/2];
		}
		q->queue[i]=x;
		printf("queue insert success......\n");
		return;
	}
	
}

//find min
int find_min(priorityQueue* q)
{
	return q->queue[1]; //index=1 is min
}





int main(void)
{
		priorityQueue* q=NULL;
		q=initQueue(q);
		
		insert(q,25);
		insert(q,33);
		insert(q,12);
		insert(q,19);
	
		printf("min=%d\n",find_min(q));
	
		return 0;
	
}
 

