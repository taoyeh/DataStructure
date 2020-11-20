#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;

double inf=0x3f3f3f3f;//����� 
double p[6]={-1,0.15,0.1,0.05,0.10,0.20};  //�ؼ��ָ��� 
double q[6]={0.05,0.10,0.05,0.05,0.05,0.10};  //���������
double e[7][7]; //�������� 
double w[7][7];//�����ܺ� 
int root[6][6];//��¼���ڵ� 
//��ʼ
void dp()
{
	int i,j,l,r;// i����ʼλ�ã�j����ֹλ�ã�lΪ���� ,rΪ���������±� 
	//��ʼ��ֻ���������������
 	for(i=1;i<7;i++)
	{
	 	w[i][i-1]=q[i-1];
	 	e[i][i-1]=q[i-1];
	} 
	
	for(l=1;l<6;l++)
	{
		for(i=1;i<=5-l+1;i++)
		{
			j=i+l-1;
			e[i][j]=inf;
			w[i][j]=w[i][j-1]+p[j]+q[j];
			for(r=i;r<=j;r++)
			{				
				double temp=e[i][r-1]+e[r+1][j]+w[i][j];
				if(temp<e[i][j])
				{
					e[i][j]=temp;
					root[i][j]=r;
				}
			}
		}
	}
}
void  printfroot(int i,int j,int r)
{
	if(j<i-1) return ;
	if(j==i-1) //���������
	{
		if (j < r) printf("d%d��k%d������\n",j,r);
		else printf("d%d��k%d���Һ���\n",j,r);
	    return ; 
	}
	else //���ڲ��ڵ� 
	{
		if(root[i][j]<r) printf("k%d��k%d������\n",root[i][j],r);
		if(root[i][j]>r) printf("k%d��k%d���Һ���\n",root[i][j],r);
	}
	printfroot(i,root[i][j] - 1,root[i][j]); 
	printfroot(root[i][j] + 1,j,root[i][j]);
}
//��� 
void  outcome()
{
	int i,j;
	printf("�������Ϊ��%.2lf \n",e[1][5]);
	printf("k%d�Ǹ�\n",root[1][5]);
	printfroot(1,5,root[1][5]);
} 
int main()
{
	dp();
	outcome(); 
	return 0;
 } 
