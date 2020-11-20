#include <bits/stdc++.h>
typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode,*LinkList;
LinkList List_HeadInsert(LinkList &L)
{
	L=new LNode();
	L->next=NULL;
	int x;
	while(scanf("%d",&x))
	{
		if(x==0) break;
		LNode *s=new LNode();
		s->next=L->next;
		L->next=s;
		s->data=x;
	}
	return L; 
}
LinkList List_TailInsert(LinkList &L)
{
	L=new LNode();
	L->next=NULL;
	LNode *r=L;
	int x;
	while(scanf("%d",&x))
	{
		if(x==0) break;
		LNode *s=new LNode();
		r->next=s;
		s->data=x;
		s->next=NULL;
		r=s;
	}
	return L;
}
void LocateElem(LinkList L)
{
	LNode *p=L->next;
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
}
void ListInsert(LinkList &L,int i,int e)
{
	LNode *p=L;
	int cnt=0;
	while(cnt<i-1)
	{
		p=p->next;
		cnt++;
	}
	LNode *s=new LNode();
	s->data=e;
	s->next=p->next;
	p->next=s;	
}
void ListDelete(LinkList &L,int i)
{
	LNode *p=L;
	LNode *q=new LNode();
	int cnt=0;
	while(cnt<i-1)
	{
		p=p->next;
		cnt++;
	}
	q=p->next;
	p->next=q->next;
	delete(q);
}
int main()
{
	LinkList L= List_TailInsert(L);
	LocateElem(L);
	return 0;
 } 
