#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;
int e[3]={0,2,4}; //����װ���ߵ�ʱ�� 
int x[3]={0,3,2}; //�˳�װ���ߵ�ʱ��
int f_outcome,l_outcome;   // ���ս�� 
int f[3][7]; // ����ӹ������ʱ�� 
int l[3][7]; // ������������·�� 
int a[3][7]={{0,0,0,0,0,0,0},{0,7,9,3,4,8,4},{0,8,5,6,4,5,7}};  //�����̼ӹ�����ʱ�� 
int t[3][7]={{0,0,0,0,0,0},{0,2,3,1,3,4},{0,2,1,2,2,1}};        //�л���ͬװ��������Ҫ��ʱ�� 

//��ʼ�ӹ� 
void dp()
{
	//��ʼ�� 
	f[1][1]=a[1][1]+e[1];
	f[2][1]=a[2][1]+e[2];
	//��ʼdp 
	int j;
	for(j=2;j<7;j++)
	{		
		//��һ��װ���� 
		if(f[1][j-1]+a[1][j]<f[2][j-1]+a[1][j]+t[2][j-1]) 
		{
			f[1][j]=f[1][j-1]+a[1][j];
			l[1][j]=1;
		}
		else 
		{
			f[1][j]=f[2][j-1]+a[1][j]+t[2][j-1];
			l[1][j]=2;
		}
		//�ڶ���װ����
		if(f[2][j-1]+a[2][j]<f[1][j-1]+a[2][j]+t[1][j-1]) 
		{
			f[2][j]=f[2][j-1]+a[2][j];
			l[2][j]=2;
		}
		else 
		{
			f[2][j]=f[1][j-1]+a[2][j]+t[1][j-1];
			l[2][j]=1;
		}
	} 
	//���ս��
	f_outcome=min(f[1][6]+x[1],f[2][6]+x[2]);
	if(f[1][6]+x[1]<f[2][6]+x[2])
	l_outcome=1;
	else l_outcome=2;
	//f[1][j]=min(f[1][j-1]+a[1][j],f[2][j-1]+a[1][j]+t[2][j-1]);
    //f[2][j]=min(f[2][j-1]+a[2][j],f[1][j-1]+a[2][j]+t[1][j-1]);
}
//���
void  outcome()
{
	int i,j;
	printf("��һ��װ����ʱ�䣺");
	for(i=1;i<7;i++)
	printf("%d ",f[1][i]);printf("\n");
	printf("�ڶ���װ����ʱ�䣺");
	for(i=1;i<7;i++)
	printf("%d ",f[2][i]);printf("\n");
	printf("����װ��·����");
	for(i=2;i<7;i++)
	printf("%d ",l[1][i]);printf("\n");
	printf("����װ��·����");
	for(i=2;i<7;i++)
	printf("%d ",l[2][i]);printf("\n");
	printf("����ʱ����Ϊ%d��\n",f_outcome);
	i=l_outcome;
    printf("װ����Ϊ %d,����Ϊ %d\n",i,6);
    for(j=6;j>=2;j--)
    {
        i=l[i][j];
        printf("װ����Ϊ %d,����Ϊ %d\n",i,j-1);
	}
}
int main()
{
	dp();
	outcome(); 
	return 0;
 } 
