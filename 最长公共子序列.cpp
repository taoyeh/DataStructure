#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;
char x[8]="ABCBDAB", y[7]="BDCABA"; //��������
int c[8][7]={0}; 
//��ʼ
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
void findlcs()   //�������������������� 
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
    printf("���������Ϊ��");
    for(i=z-1; i>=0; i--)
        printf("%c", ans[i]);
    printf("\n");
 
}*/ 
//���
void  outcome()
{
	printf("�����������Ϊ��%d\n",c[7][6]);
	//findlcs();
} 
int main()
{
	dp();
	outcome(); 
	return 0;
 } 
