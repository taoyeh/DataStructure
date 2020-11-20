#include <stdio.h>
#include <string>
#include <iostream>
using namespace std; 
#define MaxSize 50
typedef struct 
{
	char data[MaxSize];
	int top;
}SqStack;
bool Push(SqStack &S,char e) 
{
	if(S.top==MaxSize-1) return false;
	S.data[++S.top]=e;
	return true;
}
bool Pop(SqStack &S,char &e) 
{
	if(S.top==-1) return false;
	e=S.data[S.top--];
	return true;
}
bool judge(SqStack &S,string s)
{
	int i;
	char ch;
	for(i=0;i<s.size();i++)
	{
		if(s[i]=='('|| s[i]=='[') Push(S,s[i]);
		else 
		{
			if(S.top==-1) return false;
			Pop(S,ch);
			if (s[i]==')' && ch!='('  )  return false;
			if (s[i]==']' && ch!='['  )  return false;
		}
	}
	return S.top==-1;
}
int main()
{
	string s;
	while(cin>>s)
	{
		SqStack S;
		S.top=-1;
		if(judge(S,s)) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
