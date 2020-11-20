#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;

double inf=0x3f3f3f3f;//无穷大 
double p[6]={-1,0.15,0.1,0.05,0.10,0.20};  //关键字概率 
double q[6]={0.05,0.10,0.05,0.05,0.05,0.10};  //虚拟键概率
double e[7][7]; //期望代价 
double w[7][7];//概率总和 
int root[6][6];//记录根节点 
//开始
void dp()
{
	int i,j,l,r;// i是起始位置，j是终止位置，l为长度 ,r为子树根的下标 
	//初始化只包括虚拟键的子树
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
	if(j==i-1) //遇到虚拟键
	{
		if (j < r) printf("d%d是k%d的左孩子\n",j,r);
		else printf("d%d是k%d的右孩子\n",j,r);
	    return ; 
	}
	else //是内部节点 
	{
		if(root[i][j]<r) printf("k%d是k%d的左孩子\n",root[i][j],r);
		if(root[i][j]>r) printf("k%d是k%d的右孩子\n",root[i][j],r);
	}
	printfroot(i,root[i][j] - 1,root[i][j]); 
	printfroot(root[i][j] + 1,j,root[i][j]);
}
//输出 
void  outcome()
{
	int i,j;
	printf("最低期望为：%.2lf \n",e[1][5]);
	printf("k%d是根\n",root[1][5]);
	printfroot(1,5,root[1][5]);
} 
int main()
{
	dp();
	outcome(); 
	return 0;
 } 
