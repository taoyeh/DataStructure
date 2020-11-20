#include <bits/stdc++.h>
#define MaxSize 50
typedef struct 
{
	int data[MaxSize];
	int front,rear;
}SqQueue;

void InitQueue(SqQueue &Q)
{
	Q.front=Q.rear=0;
}
bool EnQueue(SqQueue &Q,int x)
{
	if((Q.rear+1)%MaxSize==Q.front) return false;
	Q.data[Q.rear]=x;
	Q.rear=(Q.rear+1)%MaxSize;
	return true;
}
bool DeQueue(SqQueue &Q,int &x)
{
	if(Q.front==Q.rear) return false;
	x=Q.data[Q.front];
	Q.front=(Q.front+1)%MaxSize;
	return true;
}
bool GetHead(SqQueue &Q,int &x)
{
	if(Q.front==Q.rear) return false;
	x=Q.data[Q.front];
	return true;
}
int main()
{
	SqQueue Q;
	int x;
	InitQueue(Q);
	EnQueue(Q,12);EnQueue(Q,13);DeQueue(Q,x);
	GetHead(Q,x);
	printf("%d\n",x);
	return 0;
}
