#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;
int e[3]={0,2,4}; //进入装配线的时间 
int x[3]={0,3,2}; //退出装配线的时间
int f_outcome,l_outcome;   // 最终结果 
int f[3][7]; // 到达加工步骤的时间 
int l[3][7]; // 底盘所经过的路径 
int a[3][7]={{0,0,0,0,0,0,0},{0,7,9,3,4,8,4},{0,8,5,6,4,5,7}};  //给底盘加工所需时间 
int t[3][7]={{0,0,0,0,0,0},{0,2,3,1,3,4},{0,2,1,2,2,1}};        //切换不同装配线所需要的时间 

//开始加工 
void dp()
{
	//初始化 
	f[1][1]=a[1][1]+e[1];
	f[2][1]=a[2][1]+e[2];
	//开始dp 
	int j;
	for(j=2;j<7;j++)
	{		
		//第一条装配线 
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
		//第二条装配线
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
	//最终结果
	f_outcome=min(f[1][6]+x[1],f[2][6]+x[2]);
	if(f[1][6]+x[1]<f[2][6]+x[2])
	l_outcome=1;
	else l_outcome=2;
	//f[1][j]=min(f[1][j-1]+a[1][j],f[2][j-1]+a[1][j]+t[2][j-1]);
    //f[2][j]=min(f[2][j-1]+a[2][j],f[1][j-1]+a[2][j]+t[1][j-1]);
}
//输出
void  outcome()
{
	int i,j;
	printf("第一条装配线时间：");
	for(i=1;i<7;i++)
	printf("%d ",f[1][i]);printf("\n");
	printf("第二条装配线时间：");
	for(i=1;i<7;i++)
	printf("%d ",f[2][i]);printf("\n");
	printf("底盘装配路径：");
	for(i=2;i<7;i++)
	printf("%d ",l[1][i]);printf("\n");
	printf("底盘装配路径：");
	for(i=2;i<7;i++)
	printf("%d ",l[2][i]);printf("\n");
	printf("最终时间结果为%d：\n",f_outcome);
	i=l_outcome;
    printf("装配线为 %d,工序为 %d\n",i,6);
    for(j=6;j>=2;j--)
    {
        i=l[i][j];
        printf("装配线为 %d,工序为 %d\n",i,j-1);
	}
}
int main()
{
	dp();
	outcome(); 
	return 0;
 } 
