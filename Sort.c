#include <stdio.h>
#include <stdlib.h>

//�������� -leetCode


//ð������  ---��ʱ
int* sortArray1(int* nums, int numsSize, int* returnSize) {

	returnSize = &numsSize; //*returnSize = numsSize;  leetcode����ʱ��Ҫ�ĳ���δ��룬��Ȼ�޷�ͨ��
	printf("��ʼ����\n");
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


//ѡ������ ---��ʱ
int* sortArray2(int* nums, int numsSize, int* returnSize) {

	returnSize = &numsSize;

	int i = 0;
	int j = 0;

	for ( i = 0; i < numsSize-1; i++)
	{
		int minIndex = i; //�������Сֵ���ȴ�����ѡ����������Сֵ����
		int minData = nums[i];
		for ( j = i+1; j < numsSize; j++)
		{
			if (nums[j] < minData)
			{
				//����ѡ���������Сֵ������һ������������Сֵ��������ȼ��������С��
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


//�������� --��ʱ

int* sortArray3(int* nums, int numsSize, int* returnSize) {

	
	int j;

	for ( j=1; j < numsSize; j++) //���������
	{
		int temp = j - 1; //ָ�����������һ��Ԫ�أ�Ҳ���������ͷ��ǰһ��Ԫ��
		
		if (nums[j] < nums[temp]) //�������������Ҫ����������Ҳ����λ��
		{

			int cur=nums[j];
			//for (temp; temp >= 0; temp--)
			//{
			//	if (cur < nums[temp])
				//{
				//	nums[temp+1] = nums[temp]; //����

				//}
				//else {

				//	break;
			//	}
				
			//}
			//nums[temp + 1] = cur; //����

			//ѭ��Ѱ�Ҳ����
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
			nums[temp + 1] = cur; //����
		}


	}

	return nums;


}


//����

//�һ�׼ֵ�ģ��±꣩
int getPoint(int* nums,int left,int right)
{

	//�����׼ֵ�ǵ�һ�����Ԫ��
	int p = nums[left];

	while (left < right) //����һ��Ҫ����ѭ���ж�,��Ȼ��˼����ֵ�Ƚ�һ��
	{
		//�ȱȽ��ұ�
		while (left < right && nums[right] >= p)
		{
			right--;
		}
		//���н���
		if (left < right)
		{
			int temp = nums[right];
			nums[right] = nums[left];
			nums[left] = temp;
		}
		//�ٱȽ����
		while (left < right && nums[left] <= p)
		{
			left++;
		}
		//���н���
		if (left < right)
		{
			int temp = nums[right];
			nums[right] = nums[left];
			nums[left] = temp;
		}

	}

	return left; //���ػ�׼ֵ�±�

}


void quickSort(int *nums,int left,int right)
{

	if (left < right)
	{
		int point=getPoint(nums, left, right);

		quickSort(nums,left,point-1); //�Ի�׼ֵ����߽��еݹ�
		quickSort(nums, point + 1, right);//�Ի�׼ֵ���ұ߽��еݹ�

	}
	 

}

int* sortArray4(int* nums, int numsSize, int* returnSize) {

	printf("��ʼ����\n");
	quickSort(nums,0,numsSize-1);

	returnSize = &numsSize;
	
	printf("�������\n");
	return nums;

}


int main(void)
{

	int arr[] = { 12,36,22,8,63,11,12,16,5,33,50,27 };
	int numsSize = 12;
	printf("����ǰ\n");

	int i = 0;
	for ( i = 0; i < numsSize; i++)
	{
		printf("%d  ",arr[i]);
	}
	printf("\n");

	//����������
	int* returnSize = -1;
	
	//int *resArr =sortArray1(arr, numsSize, returnSize);
	 
	//int* resArr = sortArray2(arr, numsSize, returnSize);


	int* resArr = sortArray3(arr, numsSize, returnSize);

	//int* resArr = sortArray4(arr, numsSize, returnSize);


	printf("�����\n");

	int j = 0;
	for (j = 0; j < numsSize; j++)
	{
		printf("%d  ", resArr[j]);
	}
	printf("\n");

}