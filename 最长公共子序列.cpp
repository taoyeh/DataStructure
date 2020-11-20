#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;
char x[8]="ABCBDAB", y[7]="BDCABA"; //两个序列
int c[8][7]={0}; 
//开始
void dp()
{
	int i,j;
	for(i=1;i<8;i++)
	{
		for(j=1;j<7;j++)
		{
			if(x[i-1]==y[j-1]) c[i][j]=c[i-1][j-1]+1;
			else c[i][j]=max(c[i-1][j],c[i][j-1]);
		}
	}
}
/* 
void findlcs()   //这个函数是求最长公共序列 
{
    int i, j, z = 0;
    char ans[8];
    i = 7, j = 6;
    while(i!=0 && j!=0)
    {
        if(x[i-1] == y[j-1])
        {
            ans[z++] = x[--i];
            j--;
        }
        else if(c[i-1][j] < c[i][j-1])
            j--;
        else if(c[i][j-1] <= c[i-1][j])
            i--;
    }
    printf("最长公共序列为：");
    for(i=z-1; i>=0; i--)
        printf("%c", ans[i]);
    printf("\n");
 
}*/ 
//输出
void  outcome()
{
	printf("最长公共子序列为：%d\n",c[7][6]);
	//findlcs();
} 
int main()
{
	dp();
	outcome(); 
	return 0;
 } 
