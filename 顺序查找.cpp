#include <bits/stdc++.h>
typedef struct{
	int *elem;
	int TableLen;
}SSTable;
// 顺序查找 
int Search_Seq(SSTable ST,int key)
{
	ST.elem[0]=key;
	int i;
	for(i=ST.TableLen;ST.elem[i]!=key;i--);
	return i;
}
int main()
{
	int i,x=11;
	SSTable ST;ST.elem=new int[10];ST.TableLen=0;
	for(i=1;i<10;i++) 
	{
		*(ST.elem+i)=i;ST.TableLen++;
	}
	if(Search_Seq(ST,x)) printf("已找到%d\n",ST.elem[x]);
	else printf("未找到%d\n",x);
	return 0;
}
