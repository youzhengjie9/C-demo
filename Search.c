#include <stdio.h>
#include <stdlib.h>

//�����㷨


//���ֲ��� 1

int search1(int* nums, int numsSize, int target) {

	int left = 0; //leftָ��
	int right = numsSize - 1; //rightָ��

	int mid = (left + right) / 2;
	while (left <= right)
	{

		if (nums[mid] == target)
		{
			return mid;
		}
		else if (nums[mid] > target)
		{
			right = mid - 1;
			mid= (left + right) / 2;

		}
		else if (nums[mid] < target)
		{
			left = mid + 1;
			mid = (left + right) / 2;
		}

	}

	return -1;
}




//���ֲ��� 2
int search(int* nums, int numsSize, int target) {

	int left = 0; //leftָ��
	int right = numsSize - 1; //rightָ��


	while (left <= right)
	{
		int mid = left + (right - left) / 2; //��ֹ���ݹ��������
		if (nums[mid] == target)
		{
			return mid;
		}
		else if (nums[mid] > target)
		{
			right = mid - 1;
		}
		else if (nums[mid] < target)
		{
			left = mid + 1;
		}

	}

	return -1;
}

int main(void)
{

	int arr[]= {1,6,8,12,16,18,22,33,66,77,79};

	int numsSize = 11;
	int target = 66;
	int res=search(arr, numsSize, target);

	printf("res=%d\n",res);

	return 0;

}

