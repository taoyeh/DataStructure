#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;
// ��ʼʱ��ͽ���ʱ�� 
int s[12]={0,1,3,0,5,3,5,6,8,8,2,12};
int f[12]={0,4,5,6,7,8,9,10,11,12,13,14};
// �����Լ�д��sort cmp 
int main()
{
	int i,j,ans=0,time=0;
	for(i=1;i<13;i++)
	{
		if(s[i]>=time) 
		{
			ans++;
			time=f[i];
			// ��߿��Լ�¼ʱ�ļ��ֻ 
		}
	}
	printf("���Ļ����Ϊ��%d\n",ans);
	return 0;
 } 
