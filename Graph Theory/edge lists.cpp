#include<bits/stdc++.h>
#define tr(v,it) for(typeof(v.begin()) it=v.begin();it!=v.end();it++)
using namespace std;
int main()
{	ios::sync_with_stdio(false);
	//making graphs-> implementation?
	//EDGE LIST
	cout<<"\nGRAPHS....implementing edge lists...";
	int n;
	cout<<"\nEnter the no. of vertices:";
	cin>>n;
	string ele;
	vector < pair <string,int> > V;
	cout<<"\nEnter the name of node:\n";
	for(int i=0;i<n;i++)
	{	cout<<"Vertex "<<i+1<<":";
		cin>>ele;
		V.push_back(make_pair(ele,i));
		cout<<endl;
	} 
	cout<<"\nYour vertices are:\n";
	tr(V,it)
	{cout<<it->second<<":"<<it->first<<endl;
	}
	cout<<"\nOkay! \nEnter the edge list( 0 based indexing ):\n";
	int edges[n*(n-1)/2][2];
	int ch;
	int i=0;
	int count=0;
	while(true)
	{	if(i==n*(n-1)/2)
			{cout<<"\nMax number of edges reached.\n";
			break;}
		e:cout<<"V1:";
		cin>>edges[i][0];
		cout<<"V2:";
		cin>>edges[i][1];
		if(edges[i][0]>=n || edges[i][1]>=n)
			{cout<<"\nInvalid edge numbers.\nEnter again";
			goto e;}
		count+=1;
		i+=1;
		cout<<"\nEnter 1 to enter more else press 0:";
		cin>>ch;
		if(ch==0) break;
	}
	cout<<"\nThe edges are:\n";
	for(int j=0;j<count;j++)
	{
		cout<<"V1:"<<edges[j][0]<<" V2:"<<edges[j][1]<<endl;
	}
	cout<<"\nFUNCTIONS\n 1. FIND ALL ADJACENT NODES TO A VERTEX\n 2. FIND IF EDGE EXISTS BETWEEN VERTICES.";
	int choice;
	x:cout<<"\nEnter choice:";
	cin>>choice;
	if(choice==1)
	{	string name;
		cout<<"\nEnter the vertex name:";
		cin>>name;
		int vertex;
		bool valid=false;
		tr(V,it)
		{
			if(it->first==name) {
			vertex=it->second;
			valid = true;
			break;}
		}
		if(!valid) cout<<"\nInvalid vertex name.";
		else
		{	int adjacent[n-1];
			int m=0;
			for(int k=0;k<count;k++)
			{
				if(edges[k][0]==vertex) {
				adjacent[m]=edges[k][1];
				m+=1;}
				else if(edges[k][1]==vertex) {
				adjacent[m]=edges[k][0];
				m+=1;}
				else continue;
			}
			cout<<"\nAdjacent nodes are:";
			for(int y=0;y<m;y+=1)
			{ cout<<y+1<<",";
			}
		}
	}
	else if(choice==2)
	{	int v1,v2;
		cout<<"\nEnter V1:";
		cin>>v1;
		cout<<"Enter V2:";
		cin>>v2;
		bool found=false;
		for(int k=0;k<count;k++)
		{
			if((edges[k][0]==v1 && edges[k][1]==v2) || (edges[k][0]==v2 && edges[k][1]==v1) )
				{cout<<"CONNECTION EXISTS.";
				found=true;
				break;
				}
		}
		if(!found) cout<<"\nNO CONNECTION.";
	}
	else 
	{cout<<"\nInvalid. Enter again";
	goto x;}
	return 0;
	
}
