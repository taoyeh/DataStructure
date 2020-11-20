#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;

int inf=0x3f3f3f3f;  //表示无穷大 
int p[7]={30,35,15,5,10,20,25}; //6个矩阵的规模 
int s[7][7]; //记录括号的位置，方便保留结果
int m[7][7]; //表示代价 

//开始
void dp()
{
	int l; //表示矩阵链的长度 
	int i; //表示矩阵链的起始位置 
	int j; //表示矩阵链的终止位置 
	int k; //表示分割点的位置
	int q; //表示代价 
	for(l=2;l<7;l++)
	{
		for(i=1;i<7-l+1;i++)
		{
			m[i][i]=0;
			j=l+i-1 ;// 其实就是 l=j-i+1 
			m[i][j]=inf;
			for(k=i;k<j;k++)
			{
				q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j]; 
				if(q<m[i][j])
				{
					m[i][j]=q;
					s[i][j]=k;        //保存分割点 
				}
			}
		}
	 } 
}
// 递归找括号
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
//输出
void  outcome()
{
	printf("最小计算次数为：%d\n",m[1][6]);
	printf("其中顺序为:");
	find(1,6);
} 
int main()
{
	dp();
	outcome(); 
	return 0;
 } 
