 #include <iostream>
#include <string>
using namespace std;
struct  node
{
	char  data;
	node *left,*right;
	node() :data('0'), left(NULL), right(NULL){}
	
};
node *build()
{
   char ch;
   cin>>ch;
   if(ch=='*')
   return NULL;
   node *root=new node();
   root->data=ch;
   root->left=build();
   root->right=build();
   return root;
}
void visit2(node *root)
{

	if(root->left)
	visit2(root->left);
	if(root!=NULL)
	{
		cout<<root->data;
	};
	if(root->right)
	visit2(root->right);
}
void visit3(node *root)
{

	if(root->left)
	visit3(root->left);
	if(root->right)
	visit3(root->right);
	if(root!=NULL)
	{
		cout<<root->data;
	};
}
int main()
{
    while(1)
    {
    	node *root=build();
    	visit2(root);
    	cout<<endl;
    	visit3(root);
    	cout<<endl;
	}
	return 0;
 } 
