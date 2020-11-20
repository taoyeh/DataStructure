#include <bits/stdc++.h>
using namespace std;
//ð������ 
void BubbleSort(int A[],int n)
{
	int i,j;
	bool flag;
	for(i=0;i<n-1;i++)
	{
		flag=false;
		for(j=n-1;j>i;j--)
		{
			if(A[j-1]>A[j])  swap(A[j-1],A[j]),flag=true;
		}
		if(flag==false) return ;
	}
}

//�������� 
int Partition(int A[],int low,int high)
{
	int pivot=A[low];
	while(low<high)
	{
		while(low<high && A[high]>=pivot) high--;
		A[low]=A[high];
		while(low<high && A[low]<=pivot) low++;
		A[high]=A[low];
	}
	A[low]=pivot;
	return low;
}
void QucikSort(int A[],int low,int high)
{
	if(low<high)
	{
		int pivotpos=Partition(A,low,high);
		QucikSort(A,low,pivotpos-1);
		QucikSort(A,pivotpos+1,high); 
	}
	
}
// ��ʼ�� 
void Init(int A[])
{
	int B[8]={49,38,65,97,76,13,27,49};
	memcpy(A,B,sizeof(B)); //��B����A 
}
int main()
{
	int A[8],n=8,i;
	Init(A);
	printf("����ð������ ");
	BubbleSort(A,n);
	for(i=0;i<n;i++) printf("%d ",A[i]);printf("\n");
	Init(A);
	printf("���ǿ������� ");
	QucikSort(A,0,n-1);
	for(i=0;i<n;i++) printf("%d ",A[i]);printf("\n");
	
	return 0;
}
