#include <bits/stdc++.h>
#define MaxSize 100
using namespace std;
// ˳��洢 
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
//���������� 
typedef struct ThreadNode 
{
	char data;
	struct BiTNode *left ,*right;
	int ltag,rtag; //1��ʾ��������0��ʾ�Ǻ��� 
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
// ��������   HDA**C*B**GF*E*** 
// ��Ŀ���� http://acm.usx.edu.cn/AspNet/question.aspx?qid=9538 
int main()
{
	BiTree root =NULL;
	root =build();
	printf("�������Ϊ��");PreOrder(root);printf("\n");
	printf("�������Ϊ��");InOrder(root);printf("\n");
	printf("�������Ϊ��");PostOrder(root);printf("\n");
	printf("�����Ϊ��%d\n",TreeDepth(root));
	printf("��α���Ϊ��");LevelOrder(root);printf("\n");
	
	return 0; 
}






