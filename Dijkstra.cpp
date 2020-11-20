 #include <iostream>
 #include <algorithm> 
 #include <cstring>
 #include <cstdio>
using namespace std;
int inf=0x3f3f3f3f; //最大值 
int n;// 顶点数 
int m;// 边数 
int map[1005][1005]; //图 
void Floyd()
{
    int k,i,j;
    for(k=1;k<=n;k++)
    {
    	for(i=1;i<=n;i++)
    	{
    		for(j=1;j<=n;j++)
    		map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
		}
	}
}
int main()
{
	int i,j,x,y,z;
	scanf("%d %d",&m,&n);
	memset(map,inf,sizeof(map));
    for(i= 0;i<m;i++)
   {
       scanf("%d %d %d",&x,&y,&z);
       if(z < map[x][y])
           map[x][y] = map[y][x] = z;
   }	
	Floyd();
	printf("%d\n",map[1][n]);
	return 0;
 } 
