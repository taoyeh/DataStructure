#include <bits/stdc++.h>
// 直接插入排序 
void InsertSort(int A[],int n)
{
	int i,j;
	for(i=2;i<=n;i++)
	{
		if(A[i]<A[i-1])
		{
			A[0]=A[i];
			for(j=i-1;A[j]>A[0];j--)
			A[j+1]=A[j];
		}
		A[j+1]=A[0];
	}
}
// 折半插入排序 
void Binary_InsertSort(int A[],int n)
{
	int i,j,low,high,mid;
	for(i=2;i<=n;i++)
	{
		if(A[i]<A[i-1])
		{
			A[0]=A[i];
			low=1,high=i-1;
			while(high>=low)
			{
				mid=(low+high)/2;
				if(A[mid]>A[0]) high=mid-1;
				else low=mid+1;
			}
			for(j=i-1;j>=high+1;j--)
		    	A[j+1]=A[j];
			A[high+1]=A[0];
		}	
	}
}
// 初始化 
void Init(int A[])
{
	int B[9]={0,49,38,65,97,76,13,27,49};
	memcpy(A,B,sizeof(B)); //把B赋给A 
}
int main()
{
	int A[9],n=8,i;
	Init(A);
	printf("这是直接插入排序： ");
	InsertSort(A,n);
	for(i=1;i<=n;i++) printf("%d ",A[i]);printf("\n");
	Init(A);
	printf("这是折半插入排序： ");
	Binary_InsertSort(A,n);
	for(i=1;i<=n;i++) printf("%d ",A[i]);printf("\n");
	return 0;
}
