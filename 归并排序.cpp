#include <bits/stdc++.h>
int B[7];
void Merge(int A[],int low,int mid,int high)
{
	int i,j,k;
	for(k=low;k<=high;k++) B[k]=A[k];
	for(i=low,j=mid+1,k=i;i<=mid&& j<=high;k++)
	{
		if(B[i]<B[j]) A[k]=B[i++];
		else  A[k]=B[j++];
	}
	while(i<=mid) A[k++]=B[i++];
	while(j<=high) A[k++]=B[j++];
}
void MergeSort(int A[],int low,int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;
		MergeSort(A,low,mid);
		MergeSort(A,mid+1,high);
		Merge(A,low,mid,high);
	}
}
int main()
{
	int A[7]={49,38,65,97,76,13,27},n=7,i;
	printf("ÕâÊÇ¹é²¢ÅÅÐò£º ");
	MergeSort(A,0,n-1);
	for(i=0;i<n;i++) printf("%d ",A[i]);printf("\n");	
	return 0;
}
