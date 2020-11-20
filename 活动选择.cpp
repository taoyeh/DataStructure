#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;
// 开始时间和结束时间 
int s[12]={0,1,3,0,5,3,5,6,8,8,2,12};
int f[12]={0,4,5,6,7,8,9,10,11,12,13,14};
// 排序自己写，sort cmp 
int main()
{
	int i,j,ans=0,time=0;
	for(i=1;i<13;i++)
	{
		if(s[i]>=time) 
		{
			ans++;
			time=f[i];
			// 这边可以记录时哪几种活动 
		}
	}
	printf("最多的活动数量为：%d\n",ans);
	return 0;
 } 
