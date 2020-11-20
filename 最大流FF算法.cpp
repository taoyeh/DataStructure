
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
 
int map[405][405];
int used[405];
int n,m;
const int INF= 0x3f3f3f3f;
 
int DFS(int s, int t, int f)
{
    if(s==t)
        return f;//�ҵ��յ��ˣ���ʱʣ�µ����������ܻ�õ�����
    int i;
    for(i=1;i<=n+m+2;i++)
    {
        if(map[s][i] >0 && used[i] ==0)//��s��ʼ��
        {
            used[i]=1;
            int d=DFS(i, t, min(f, map[s][i]));//����û������·
            if(d>0)
            {
                map[s][i] -=d;
                map[i][s] +=d;
                return d;
            }
        }
    }
    return 0;
}
 
int maxflow(int s, int t)
{
    int flow=0;
    while(true)
    {
        memset(used, 0, sizeof(used));
        int f= DFS(s,t, INF);//������s��t������·
        if(f == 0)
            return flow; //�Ҳ����˾ͻ�ȥ
        flow += f;//�ҵ�һ������f�ľ�׬��
    }
}
 
void init()
{
    memset(map, 0, sizeof(map));
    return ;
}
 
int main()
{
    while(scanf("%d %d", &n, &m) != EOF)
    {
        init();
        int num, cap;
        int i,j,k;
        for(i=1;i<=n;i++)
		{
			scanf("%d", &num);
			for(j=0;j<num;j++)
			{
				scanf("%d", &k);
				map[i+1][k+n+1]=1;
			} 
		 } 
		for(i=1;i<=n;i++) map[1][i+1]=1;
		for(i=1;i<=m;i++) map[n+1+i][n+m+2]=1;
		
        int ans=maxflow(1,n+m+2);
        printf("%d\n", ans);
    }
    return 0;
}
