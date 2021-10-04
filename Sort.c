#include <stdio.h>
#include <stdlib.h>

//排序数组 -leetCode


//冒泡排序  ---超时
int* sortArray1(int* nums, int numsSize, int* returnSize) {

	returnSize = &numsSize; //*returnSize = numsSize;  leetcode测试时需要改成这段代码，不然无法通过
	printf("开始排序\n");
	int i = 0;
	int j = 0;
	for ( i = 0; i < numsSize-1; i++)
	{
		for ( j = 1; j < numsSize-i; j++)
		{
			if (nums[j] < nums[j - 1])
			{
				int temp = nums[j - 1];
				nums[j - 1] = nums[j];
				nums[j] = temp;
			}
		}
	}
	return nums;
}


//选择排序 ---超时
int* sortArray2(int* nums, int numsSize, int* returnSize) {

	returnSize = &numsSize;

	int i = 0;
	int j = 0;

	for ( i = 0; i < numsSize-1; i++)
	{
		int minIndex = i; //假设的最小值，等待后续选出真正的最小值出来
		int minData = nums[i];
		for ( j = i+1; j < numsSize; j++)
		{
			if (nums[j] < minData)
			{
				//更新选择出来的最小值（但不一定是真正的最小值，最起码比假设出来的小）
				minIndex = j;
				minData = nums[j];
			}
		}
		int temp = nums[i];
		nums[i] = minData;
		nums[minIndex] = temp;
	}
	
	return nums;
}


//插入排序 --超时

int* sortArray3(int* nums, int numsSize, int* returnSize) {

	
	int j;

	for ( j=1; j < numsSize; j++) //遍历无序表
	{
		int temp = j - 1; //指向有序表的最后一个元素，也就是无序表头的前一个元素
		
		if (nums[j] < nums[temp]) //符合这个条件就要遍历有序表，找插入的位置
		{

			int cur=nums[j];
			//for (temp; temp >= 0; temp--)
			//{
			//	if (cur < nums[temp])
				//{
				//	nums[temp+1] = nums[temp]; //后移

				//}
				//else {

				//	break;
			//	}
				
			//}
			//nums[temp + 1] = cur; //插入

			//循环寻找插入点
			while (1)
			{
				if (temp < 0|| cur >= nums[temp])
				{
					break;
				}
				else {

					nums[temp + 1] = nums[temp];
					temp--;
				}

			}
			nums[temp + 1] = cur; //插入
		}


	}

	return nums;


}


//快排

//找基准值的（下标）
int getPoint(int* nums,int left,int right)
{

	//假设基准值是第一个左边元素
	int p = nums[left];

	while (left < right) //这里一定要进行循环判断,不然意思就是值比较一轮
	{
		//先比较右边
		while (left < right && nums[right] >= p)
		{
			right--;
		}
		//进行交换
		if (left < right)
		{
			int temp = nums[right];
			nums[right] = nums[left];
			nums[left] = temp;
		}
		//再比较左边
		while (left < right && nums[left] <= p)
		{
			left++;
		}
		//进行交换
		if (left < right)
		{
			int temp = nums[right];
			nums[right] = nums[left];
			nums[left] = temp;
		}

	}

	return left; //返回基准值下标

}


void quickSort(int *nums,int left,int right)
{

	if (left < right)
	{
		int point=getPoint(nums, left, right);

		quickSort(nums,left,point-1); //以基准值的左边进行递归
		quickSort(nums, point + 1, right);//以基准值的右边进行递归

	}
	 

}

int* sortArray4(int* nums, int numsSize, int* returnSize) {

	printf("开始排序\n");
	quickSort(nums,0,numsSize-1);

	returnSize = &numsSize;
	
	printf("排序结束\n");
	return nums;

}


int main(void)
{

	int arr[] = { 12,36,22,8,63,11,12,16,5,33,50,27 };
	int numsSize = 12;
	printf("排序前\n");

	int i = 0;
	for ( i = 0; i < numsSize; i++)
	{
		printf("%d  ",arr[i]);
	}
	printf("\n");

	//调用排序函数
	int* returnSize = -1;
	
	//int *resArr =sortArray1(arr, numsSize, returnSize);
	 
	//int* resArr = sortArray2(arr, numsSize, returnSize);


	int* resArr = sortArray3(arr, numsSize, returnSize);

	//int* resArr = sortArray4(arr, numsSize, returnSize);


	printf("排序后\n");

	int j = 0;
	for (j = 0; j < numsSize; j++)
	{
		printf("%d  ", resArr[j]);
	}
	printf("\n");

}