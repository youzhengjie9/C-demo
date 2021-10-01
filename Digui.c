#include <stdio.h>
#include <stdlib.h>

//µİ¹éÌâ easy

//1.ì³²¨ÄÇÆõÊıÁĞ
int fib(int n) {

	if (n == 0)
	{
		return 0;
	}

	if (n == 1)
	{
		return 1;
	}
	 
		return fib(n - 1) + fib(n - 2);
 
}

//2.½×³Ë
int jiecheng(int n)
{
	 
	if (n==0||n == 1)
	{
		return 1;
	}
	else {

		return n * jiecheng(n - 1);
	}

}


int main(void)
{
	int res=jiecheng(10);
	printf("%d\n",res);

	return 0;

}