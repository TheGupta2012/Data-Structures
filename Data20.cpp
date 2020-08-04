#include<bits/stdc++.h>
#include<iostream>
using namespace std;
struct bnode
{
	int data;
	bnode *left,*right;
};

bnode * insert(bnode *root, int dat)
{
	if(root==NULL)
		{
			bnode *temp= new bnode;
			temp->data=dat;
			temp->left=temp->right=NULL;
			root=temp;
		}
	else
	{
		if(dat<=root->data)
			root->left=insert(root->left,dat);
			
		else
			root->right=insert(root->right,dat);
		
	}
	return root;
}
void preorder(bnode *root)
{
	if(root==NULL)	return;
	else
	{
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(bnode *root)
{
	if(root==NULL)	return;
	else
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}
void postorder(bnode *root)
{
	if(root==NULL)	return;
	else
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<" ";
	}
}

int main()
{	bnode *root;
	root=NULL;		
    int ch,a,b;
	cout<<"\n\t\t\t\tProgram to implement Binary Tree...\n\nPress\n1 For insertion\n";
	cout<<"2. Preorder Traversal\n3. Inorder traversal";
	cout<<" \n4. Postorder traversal\n(-1) for exit.";
	while(1)
	{
	k:cout<<"\nEnter the choice:";
	cin>>ch;
	if(ch==-1)
	break;
	else
	{
	switch(ch)
	{
		case 1: cout<<"Enter the data to be inserted:";
				cin>>a;
				root=insert(root,a);
				cout<<endl<<a<<" inserted.";
				break;
		case 2:cout<<"\nThe preorder traversal of tree is:";
				preorder(root);
				break;
		case 3: {cout<<"\nThe inorder traversal of tree is:";
				inorder(root);
				break;}
		case 4:{cout<<"\nThe postorder traversal of tree is:";
				postorder(root);
				break;}
		
		default:cout<<"\nWrong choice.";
				goto k;
				 
	}
	
}
}
return 0;
}
