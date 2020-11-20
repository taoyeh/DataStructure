#include <bits/stdc++.h>
#define MaxSize 50
typedef struct 
{
	int data[MaxSize];
	int top;
}SqStack;
typedef struct Linknode
{
	int data;
	struct Linknode *next;
}  *LiStack;

void InitStack(SqStack &S)
{
	S.top=-1;
}
bool Push(SqStack &S,int e) 
{
	if(S.top==MaxSize-1) return false;
	S.data[++S.top]=e;
	return true;
}
bool Pop(SqStack &S,int &e) 
{
	if(S.top==-1) return false;
	e=S.data[S.top--];
	return true;
}
bool GetTop(SqStack &S,int &x)
{
	if(S.top==-1) return false;
	x=S.data[S.top];
	return true;
}
int main()
{
	SqStack S;
	int x;
	InitStack(S);
	Push(S,1);Push(S,13);Pop(S,x);
	GetTop(S,x);
	printf("%d\n",x);
	return 0;
}
