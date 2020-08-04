#include<bits/stdc++.h>
#include<algorithm>
#define tr(v,it) for(typeof(v.begin()) it=v.begin() ; it!=v.end() ; it++)
#define For(i,n) for(int i=0;i<n;i++)
using namespace std;
bool visited[100]={false};
int visitall=0;
int findmin(vector <int> keys) // finding out the minimum of the vertices.keys from the V-S cut of the graph
{	int min=INT_MAX,ind;
	for(int i=1;i<keys.size();i++)
	{ if(keys[i]<min && visited[i]==false) 
		{min=keys[i];
		ind = i;}
	}
	return ind;
}
int prims(int n, vector <pair <int,int> > edges[]) // edges is the adjacency list.
{	int minweight=0,ind,visitall;
	visitall=0;
	vector <int> parent(n+1);// parent array to store parent
	vector <int> keys(n+1); // keys array to store weights
	for(int i=1;i<=n;i++)
		{if(i==1)
		keys[i]=0;
		else
		keys[i]=INT_MAX;
		}
	parent[1]=-1;
	while(visitall!=n)
	{
		ind=findmin(keys);//finding minimum key from the vertex set V-S which has already not been visited.
		visited[ind]=true; // means ind has beeen transferred to the S cut.
		visitall++;
		for(int i=0;i<edges[ind].size();i++) // traversing through the adjacency list of the minimum key node.
		{ 
		    if(visited[edges[ind][i].first]==false && keys[edges[ind][i].first]>edges[ind][i].second) // means > "if the adjacent node of the current node is alredy not visited and its key value 
		    																									// is greater than the weight of that node then update the key value and update the parent"
		    																									
						{ keys[edges[ind][i].first] = edges[ind][i].second; //update the key of that node
						parent[edges[ind][i].first]=ind; } // make the parent of the node the current index
			
		}	
	}
	minweight=accumulate(keys.begin(),keys.end(),0);
	cout<<"\nTHE SPANNING TREE IS:\n";
	cout<<"Parent\tVertex\tWeight\n";
	for(int i=1;i<=n;i++)
	{ 
		cout<<parent[i]<<"\t"<<i<<"\t"<<keys[i]<<endl;
	}	
	return minweight;	
}
int main()
{
	cout<<"\nPRIM's ALGORITHM TO FIND MINIMUM SPANNING TREE";
	cout<<"\nEnter the number of vertices:";
	int n;
	cin>>n;
	cout<<"\nEnter the edges(Start End Weight)(Enter start as -1 to exit loop):\n";
	
	int s,e,w,k;
	k=1;
	set <int> vertex;
	vector < pair <int , int > > edges[n+1];
	while(true)
	{	cout<<"Edge "<<k<<":";
		cin>>s;
		if(s==-1) break;
		cin>>e>>w;
		vertex.insert(s);
		vertex.insert(e);
		
			edges[s].push_back(make_pair(e,w));
			edges[e].push_back(make_pair(s,w));
			
			k++;
	}
	cout<<"\nGraph connections are :-\n";
	for(int i=1;i<=n;i++)
	{	cout<<"Vertex "<<i<<":";
		for(int j=0;j<edges[i].size();j++)
		{ cout<<edges[i][j].first<<","<<edges[i][j].second<<" ";
		}
		cout<<endl;
	}
	if(vertex.size()!=n)
		cout<<"\nA spanning tree is not possible due to isolated node.";
	int min_weight= prims(n,edges);
	cout<<"\nThe minimum weight is:"<<min_weight;
	return 0;
}
