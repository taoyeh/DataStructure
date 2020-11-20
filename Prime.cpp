 #include <iostream>
using namespace std;
int map[12][12]; //图 
int dist[12]; //距离
bool visit[12];//判断是否被放入树中 
int inf=0x3f3f3f3f; //最大值 
int n;// 顶点数 
int m;// 边数 
int cost;//代价 

void Prime(int u)
{
	int i,v;
	//初始化 
	for(i=1;i<=n;i++) visit[i]=false;
	for(i=1;i<=n;i++) dist[i]=inf;
	for(i=1;i<=n;i++) dist[i]=map[u][i];
	visit[u]=true;
	for(v=0;v<n-1;v++)
	{
		int k=-1,mmin=inf;
	    for(i=1;i<=n;i++) 
		{
			if(dist[i]<mmin && visit[i]==false)  k=i,mmin=dist[i];
		}
		visit[k]=true;
		for(i=1;i<=n;i++)
		{
			if(dist[i]>map[k][i] && visit[i]==false)  dist[i]=map[k][i];
		}
	}
}
int main()
{
	int i,j,x,y,z;
	while(scanf("%d %d",&n,&m)!=-1)  //输入数据 
	{
		if(n==0 && m==0) break;
		//初始化 
        for(i=1;i<=m;i++)
        {
        	scanf("%d %d %d",&x,&y,&z);
        	map[x][y]=map[y][x]=z;
		}	
		Prime(1);
		cost=0;
		for(i=1;i<=n;i++) cost+=dist[i];
		printf("%d\n",cost);
	}
	return 0;
 } 
