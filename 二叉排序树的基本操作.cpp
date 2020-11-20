#include <bits/stdc++.h>
#define MaxSize 100
using namespace std;
typedef struct BSTNode
{
	int data;
	struct BSTNode  *left,*right;
}BSTNode,*BSTree;
void insert(BSTNode *&root,int x)  
{  
    if(root==NULL)  
    {  
    	root=new BSTNode();   
    	root->left=root->right=NULL; 
    	root->data=x;
    	return ;  
    }  
    if(root->data<x)   
    insert(root->left,x);  
    else if(root->data>x)  
    insert(root->right,x);  
      
}
void PreOrder(BSTNode *T)
{
	if(T!=NULL)
	{
		printf("%d",T->data);
		PreOrder(T->left);
		PreOrder(T->right);
	}
}
BSTNode *BST_Search(BSTree T, int x)
{
	while(T!=NULL&& T->data!=x)
	{
		if(T->data>x) T=T->left;
		else T=T->right;
	}
	return T;
 } 
//  数据 4    5 8 7 4
int main()
{
	BSTree T=NULL;
	int x,n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)  
    {  
        scanf("%d",&x);
        insert(T,x);  
    }  
	PreOrder(T);
	if(BST_Search(T,5)==NULL) printf("\n未找到此数\n");
	else 
	printf("\n查找数字为：%d\n",BST_Search(T,5)->data);
	return 0;
 } 
