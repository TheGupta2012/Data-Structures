
#include<bits/stdc++.h>
#include<iostream>
#include"BST.h"
using namespace std;
int main()
{	bnode *root;
	root=NULL;		
    int ch,a,b;
	cout<<"\nProgram to implement BinarySearchTree...\n:\n1 for insertion \n2 for search\n 3 for minimum element\n4 for maximum element \n5 For the height of the tree \n6 For BFS of the tree\n";
	cout<<"Depth First Searches-\n7 Preorder Traversal\n8 Inorder traversal";
	cout<<" \n9 Postorder traversal \n10 Check if tree is BST\n11 Delete a Node.\n12 Inorder successor or not.\n(-1) for exit.";
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
		case 2:cout<<"\nEnter the item to be searched:";
				cin>>b;
				if(search(root,b)==false)
					cout<<"\nElement not found.";
				else
					cout<<"\nElement found.";
				break;
		case 3:cout<<"\nMinimun element is:";
				if(findminR(root)==-1)
					cout<<"Empty tree.";
				else
					cout<<"Minimum element is:"<<findminR(root);
				break;
		case 4:cout<<"Maximum element is:";
				if(findmaxR(root)==-1)
					cout<<"Empty tree.";
				else
					cout<<"Maximum element is:"<<findmaxR(root);
				break;
		case 5:cout<<"Height of the tree is:"<<height(root);
				break;
		case 6:{cout<<"\nThe Level Order Traversal of the current BST is:";
				BFStree(root);
				vector <int> r=BFSv(root);
				for(int i=0;i<r.size();i++)
					cout<<r[i]<<":";
				break;}
		case 7:cout<<"\nThe preorder traversal of tree is:";
				preorder(root);
				break;
		case 8: {cout<<"\nThe inorder traversal of tree is:";
				vector<int> k ;
				inorder(root);
				inorderV(root,k);
				cout<<endl;
				cout<<"By the vector:";
				for(int i=0;i<k.size();i++)
					cout<<k[i]<<":";
				break;}
		case 9:cout<<"\nThe postorder traversal of tree is:";
				postorder(root);
				break;
		case 10:if(isBSTornot(root)==true)
					cout<<"\nIt is a BST.";
				else
					cout<<"\nIt is not a BST.";
				break;
		case 11:int val;
				cout<<"Enter the value to delete:";
				cin>>val;
				if(search(root,val))
					{root=deleteNode(root,val);
					 cout<<"\nNode "<<val<<" deleted.";
					}
				else
						cout<<"\nNode is not present.";
				break;
		case 12:cout<<"\nEnter the data for which you want Inorder Successor:";
				int f;
				cin>>f;
				if(InorderS(root,f)==-1)
					cout<<"\nNo IOS found.";
				else
					cout<<"\nIOS is:"<<InorderS(root,f);
				break;
		default:cout<<"\nWrong choice.";
				goto k;
				 
	}
	
}
}
return 0;
}
