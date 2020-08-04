#include<bits/stdc++.h>
#define For(i,n) for(int i=0;i<n;i++)
#define tr(v,it) for(typeof(v.begin()) it=v.begin();it!=v.end();it++)
using namespace std;
int main()
{	string ele;
	
	cout<<"\n\t\t MAKING ADJACENCY LIST OF A GRAPH...";
	cout<<"\nEnter the number of vertices in your graph:";
	int n;
	cin>>n;
	cout<<"\nENTER THE NAMES OF THE ELEMENTS:\n";
	vector< string > v;
	For(i,n)
	{ cout<<"Element "<<i<<":";
	 cin>>ele;
	  v.push_back(ele);
	}
	cout<<"\nThe vertex list is:\n";
	For(i,n)
	{ cout<<"Element "<<i<<":"<<v[i]<<endl;
	}
	char type;
	cout<<"\nEnter the graph type (U/D):";
	cin>>type;
	vector <int> edge[n];
	string v1,v2;
	cout<<"\nEnter 1 to insert more and -1 for exit:";
	int elem,i,j;
	while(true)
	{	cout<<"\nENTER THE CHOICE:";
		cin>>elem;
		if(elem==-1) break;
		cout<<"\nEnter starting node:";
		cin>>v1;
		cout<<"\nEnter terminal node:";
		cin>>v2;
		 i= find(v.begin(),v.end(),v1)-v.begin();
		 j= find(v.begin(),v.end(),v2)-v.begin();
		if(type=='D')
			edge[i].push_back(j);
		else
		{
			if(find(edge[i].begin(),edge[i].end(),j)==edge[i].end())
				edge[i].push_back(j);
			if(find(edge[j].begin(),edge[j].end(),i)==edge[j].end())
				edge[j].push_back(i);
		}
		
	}
	for(int i=0;i<n;i++)
	{	cout<<"\nVertex "<<i<<", "<<v[i]<<" connnections:";
		for(int j=0;j<edge[i].size();j++)
			{
				cout<<v[edge[i][j]]<<" ";
			}
		cout<<endl;
	}
	
		return 0;
	
	}
