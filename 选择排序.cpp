#include <bits/stdc++.h>
using namespace std;
// 简单选择排序 
void SelectSort(int A[],int n)
{
	int i,j,minn;
	for(i=0;i<n-1;i++)
	{
		minn=i;
		for(j=i+1;j<n;j++)
		{
			if(A[j]<A[minn]) minn=j;
		}
		if(i!=minn) swap(A[minn],A[i]);
	}
}

// 堆排序
// 调整元素k为根的子树 
void HeadAdjust(int A[],int k,int len)
{
	A[0]=A[k];
	for(int i=2*k;i<=len;i=i*2)
	{
		if(i<len && A[i]<A[i+1]) i++;
		if(A[0]>A[i])  break;
	    else 
	    {
	    	A[k]=A[i];
	    	k=i;
		}
	}
	A[k]=A[0];
}
// 先建立一个大根堆 
void BuildMaxHeap(int A[],int len)
{
	for(int i=len/2;i>0;i--)  HeadAdjust(A,i,len);
}
void HeapSort(int A[],int len)
{
	BuildMaxHeap(A,len);
	for(int i=len;i>1;i--)
	{
		swap(A[i],A[1]);
		HeadAdjust(A,1,i-1);
	}
}
int main()
{
	int A[8]={49,38,65,97,76,13,27,49},n=8,i;
	printf("这是简单选择排序： ");
	SelectSort(A,n);
	for(i=0;i<n;i++) printf("%d ",A[i]);printf("\n");
	int B[9]={0,87,45,78,32,17,65,53,9};
	printf("这是堆排序： ");
	HeapSort(B,8);
	for(i=1;i<9;i++) printf("%d ",B[i]);printf("\n");
	return 0;
}
