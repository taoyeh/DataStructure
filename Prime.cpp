 #include <iostream>
using namespace std;
int map[12][12]; //ͼ 
int dist[12]; //����
bool visit[12];//�ж��Ƿ񱻷������� 
int inf=0x3f3f3f3f; //���ֵ 
int n;// ������ 
int m;// ���� 
int cost;//���� 

void Prime(int u)
{
	int i,v;
	//��ʼ�� 
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
	while(scanf("%d %d",&n,&m)!=-1)  //�������� 
	{
		if(n==0 && m==0) break;
		//��ʼ�� 
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
