#include <bits/stdc++.h>
typedef struct{
	int *elem;
	int TableLen;
}SSTable;
// ˳����� 
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
	if(Search_Seq(ST,x)) printf("���ҵ�%d\n",ST.elem[x]);
	else printf("δ�ҵ�%d\n",x);
	return 0;
}
