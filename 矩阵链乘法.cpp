#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;

int inf=0x3f3f3f3f;  //��ʾ����� 
int p[7]={30,35,15,5,10,20,25}; //6������Ĺ�ģ 
int s[7][7]; //��¼���ŵ�λ�ã����㱣�����
int m[7][7]; //��ʾ���� 

//��ʼ
void dp()
{
	int l; //��ʾ�������ĳ��� 
	int i; //��ʾ����������ʼλ�� 
	int j; //��ʾ����������ֹλ�� 
	int k; //��ʾ�ָ���λ��
	int q; //��ʾ���� 
	for(l=2;l<7;l++)
	{
		for(i=1;i<7-l+1;i++)
		{
			m[i][i]=0;
			j=l+i-1 ;// ��ʵ���� l=j-i+1 
			m[i][j]=inf;
			for(k=i;k<j;k++)
			{
				q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j]; 
				if(q<m[i][j])
				{
					m[i][j]=q;
					s[i][j]=k;        //����ָ�� 
				}
			}
		}
	 } 
}
// �ݹ�������
void find(int i,int j)
{
	if(i==j) printf("A%d",i);
	else 
	{
		printf("(");
		find(i,s[i][j]);
		find(s[i][j]+1,j);
		printf(")");
	}
 }
//���
void  outcome()
{
	printf("��С�������Ϊ��%d\n",m[1][6]);
	printf("����˳��Ϊ:");
	find(1,6);
} 
int main()
{
	dp();
	outcome(); 
	return 0;
 } 
