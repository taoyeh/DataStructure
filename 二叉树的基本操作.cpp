#include <bits/stdc++.h>
#define MaxSize 100
using namespace std;
// 顺序存储 
struct TreeNode
{
	char value;
	bool isEmpty;
};
	//TreeNode t[MaxSize] ;
typedef struct BiTNode
{
	char data;
	struct BiTNode *left ,*right;
}BiTNode,*BiTree;
//线索二叉树 
typedef struct ThreadNode 
{
	char data;
	struct BiTNode *left ,*right;
	int ltag,rtag; //1表示是线索，0表示是孩子 
}ThreadNode,*ThreadTree;
BiTree build()  
{  
   char ch;  
   scanf("%c",&ch); 
   if(ch=='*')  
   return NULL;  
   BiTNode *root=new BiTNode();  
   root->data=ch;  
   root->left=build();  
   root->right=build();  
   return root;  
} 
void PreOrder(BiTNode *T)
{
	if(T!=NULL)
	{
		printf("%c",T->data);
		PreOrder(T->left);
		PreOrder(T->right);
	}
}
void InOrder(BiTNode *T)
{
	if(T!=NULL)
	{
		InOrder(T->left);
		printf("%c",T->data);
		InOrder(T->right);
	}
}
void PostOrder(BiTNode *T)
{
	if(T!=NULL)
	{
		PostOrder(T->left);
		PostOrder(T->right);
		printf("%c",T->data);
	}
}
int TreeDepth(BiTNode *T) 
{
	if(T==NULL) return 0;
    int l,r;
    l=TreeDepth(T->left);
    r=TreeDepth(T->right);
    return l>r ? l+1:r+1; 
}
void LevelOrder(BiTree T)
{
	queue<BiTNode*>q;  
	q.push(T);
	while(!q.empty())
	{
		BiTNode *node=q.front(); q.pop();
		printf("%c",node->data);
		if(node->left!=NULL) q.push(node->left) ;
		if(node->right!=NULL) q.push(node->right) ;
	}
}
// 测试数据   HDA**C*B**GF*E*** 
// 题目链接 http://acm.usx.edu.cn/AspNet/question.aspx?qid=9538 
int main()
{
	BiTree root =NULL;
	root =build();
	printf("先序遍历为：");PreOrder(root);printf("\n");
	printf("中序遍历为：");InOrder(root);printf("\n");
	printf("后序遍历为：");PostOrder(root);printf("\n");
	printf("树深度为：%d\n",TreeDepth(root));
	printf("层次遍历为：");LevelOrder(root);printf("\n");
	
	return 0; 
}






