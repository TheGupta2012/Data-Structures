#include<iostream>
#include"BST.h"
int main()
{	bnode *root;
	root=NULL;		
    int ch,a,b;
	cout<<"\nProgram to implement BinarySearchTree...\n:\n1 for insertion \n2 for search\n 3 for minimum element\n4 for maximum element \n5 For the height of the tree \n6 For BFS of the tree(-1) for exit.";
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
		case 6:cout<<"\nThe BFS of the current BST is:";
				BFStree(root);
				break;
		default:cout<<"\nWrong choice enter again.";
				goto k;
	}
	
}
}
return 0;
}
