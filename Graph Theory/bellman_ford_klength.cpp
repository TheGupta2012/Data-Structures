#include<bits/stdc++.h>
using namespace std;
struct Graph
{
	int s,e,w;
};
void bell_fordk(int source, int v, int e, Graph edges[],int k)
{
	int paths[v];
	paths[source-1]=0;
	for(int i=0;i<v;i++)
	{if(i==(source-1)) continue;
	 else paths[i]=INT_MAX;
	}
	int iter = k;
	int T[v+1];
	for(int i=0;i<=v;i++)
		T[i]=INT_MIN;
	int change; // this is used for the detection of the changes occuring in the
	         // weights of the nodes
	for(int i = 0;i<iter;i++)
	{	change = 0;
		for(int j=0;j<e;j++)
		{	if(paths[edges[j].s-1]== INT_MAX && paths[edges[j].e-1]== INT_MAX)
				continue;
			if(( paths[edges[j].s-1] + edges[j].w )< paths[edges[j].e-1])
				{T[edges[j].e-1] = paths[edges[j].s-1]+ edges[j].w;
				change+=1;}
		}

		//only updating after the edges have been passed for a particular iteration.
		for(int kw=0;kw<v;kw++)
		{if(T[kw]!=INT_MIN)
			paths[kw] = T[kw];
		}
		if(change==0)
			break;
	}
	bool flag = true;
	// below code checks for negative weight cycle.
	if(k==v-1)
	{
	for(int j=0;j<e;j++)
	{
		if((paths[edges[j].s-1] + edges[j].w)<paths[edges[j].e-1])
				{ flag=false; // negative weight cycle detected.
				}
		if(flag==false) break;
	}
	}
	if(flag == false)
	{ cout<<"\nNegative weight cycle detected.\nAlgorithm won't work";
	}
	else
	{
		cout<<"\nAll the paths from "<<source<<" are:\n";
		for(int i=0;i<v;i++)
			cout<<"Vertex "<<i+1<<":"<<paths[i]<<endl;

	}
}
int main()
{	int e,v;
	cout<<"\nBELLMAN-FORD ALGORITHM FOR SINGLE SOURCE SHORTEST PATHS.";
	cout<<"\nEnter the number of vertices:";
	cin>>v;
	cout<<"\nEnter the number of edges:";
	cin>>e;
	Graph edges[e];
	cout<<"\nEnter the edges(start,end,weight):\n";
	for(int i=0;i<e;i++)
	{
		cout<<"Edge "<<i+1<<":";
		cin>>edges[i].s>>edges[i].e>>edges[i].w;

	}
	cout<<"\nEdges are-\n";
	for(int i=0;i<e;i++)
	{
		cout<<"Edge "<<i+1<<":";
		cout<<edges[i].s<<" "<<edges[i].e<<" "<<edges[i].w<<endl;
	}
	cout<<"\nEnter the source vertex :";
	int source;
	cin>>source;
	int k;
	z:cout<<"\nEnter the maximum path length :";
	cin>>k;
	if(k>v-1)
		{
		cout<<"\nMaximum length exceeded.\nEnter again.";
		goto z;}
	bell_fordk(source,v,e,edges,k);
	return 0;
}
