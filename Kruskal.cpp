 #include <iostream>
 #include <algorithm> 
using namespace std;
int inf=0x3f3f3f3f; //���ֵ 
int n;// ������ 
int m;// ���� 
int cost;//���� 
struct node 
{
	int from,to,w;//�����㣬Ŀ�ĵأ�Ȩ�� 
}e[150];
int parent[12];
bool cmp(node a,node b)
{
      return a.w<b.w;
 } 
 int find(int x)
 {
 	while(x!=parent[x])  x=parent[x];
 	return x;
 }
 bool join(int x,int y)
 {
 	int fx=find(x);
 	int fy=find(y);
 	if(fx==fy) return false;
 	else  parent[fx]=fy;return true;
 }
void Kruskal()
{
	int i,j,cnt=0;cost=0;
	for(i=1;i<=n;i++) parent[i]=i;
	for(i=1;i<=m;i++)
	{
		if(join(e[i].from,e[i].to)==true)  cost+=e[i].w,cnt++;
		if(cnt==n-1) break;
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
        	e[i].from=x;e[i].to=y;e[i].w=z; 
		}	
		sort(e+1,e+m+1,cmp);
		Kruskal();
		printf("%d\n",cost);
	}
	return 0;
 } 
