#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int,int> &a, pair<int,int> &b)
{
	return (a.second>b.second);
}
void dikSolve(int s,vector < pair<int,int> > edges[], int V)
{	//pq is using zero based indexing but not the edges ->be careful
	vector < pair<int,int> > pq,res; // first->vertex, second->weight
	for(int i=1;i<=V;i++)
		{if(i==s) pq.push_back({s,0}); // storing 0 in the source vertex
		 else pq.push_back({i,INT_MAX}); // storing int_max in others
		}
	make_heap(pq.begin(),pq.end(),comp);
	int map[V+1],u,v,w;
	map[0]=-1;
	for(int i=0;i<=V;i++)	
		map[pq[i].first] = i;
	while(pq.size()>0)
	{   cout<<"Current shortest paths :";
		for(typeof(pq.begin()) it=pq.begin();it!=pq.end();it++)
		{
			cout<<it->first<<":"<<it->second<<endl;
		}
		cout<<endl;
		u = pq[0].first; // getting the minimum value vertex
		// insert in the set and remove from vector
		for (int i=0;i<edges[u].size();i++) // adjacency list of u.
		{    v = edges[u][i].first; 
			 w = edges[u][i].second;//weight of(u,v)
			if( pq[map[v]].second == pq[map[u]].second && pq[map[v]].second==INT_MAX)
				continue;
			if( pq[map[v]].second > pq[map[u]].second  + w )// w(u,v) 
				pq[map[v]].second = pq[map[u]].second  + w ;
		}
		pop_heap(pq.begin(),pq.end());//deleting the minimum element from pq
		res.push_back({pq.back()}); // removing from the pq and storing in result
		pq.pop_back();
		make_heap(pq.begin(),pq.end(),comp);//making heap again
		
		
		for(int i=0;i<=V;i++)	 // updating the index array.
			map[pq[i].first] = i;	
	}
	cout<<"\nFinal paths are:\n";
	for(typeof(res.begin()) it = res.begin() ; it!=res.end();it++)
		{if(it->second!=INT_MAX)
		cout<<it->first<<","<<it->second<<" ";	
		else
		cout<<it->first<<","<<"unreachable"<<" ";
}
}
int main()
{
	cout<<"\nDijkstra's Algorithm.\n";
	cout<<"\nEnter the no. of vertices in graph:";
	int v;
	cin>>v;
	cout<<"\nEnter D for directed or U for undirected:";
	char ch;
	cin>>ch;
	cout<<"\nEnter edges (start,end,weight)(start = -1 for termination):\n";
	vector  < pair<int,int> > edges[v+1];
	int start,weight,end;
	while(true)
	{
	g:cin>>start;
	cin>>end>>weight;
	if(start==-1)
	{ break;
	}
	if(start<0 || end<0 || weight<0)
		{
		cout<<"Invalid entries.\nEnter again";
		goto g;}
	if(ch == 'U')
	{	// one based indexing in edges
		edges[start].push_back({end,weight});
		edges[end].push_back({start,weight});
	}
	if (ch == 'D')
	{
		edges[start].push_back({end,weight});
	}
	}
	cout<<"\nYour graph is :\n";
	for(int i=1;i<=v;i++)
	{	cout<<"Vertex "<<i<<":";
		for(typeof(edges[i].begin()) it =edges[i].begin();it!=edges[i].end();it++)
		{ cout<<it->first<<","<<it->second<<" ";
		}
		cout<<endl;
	}
	cout<<"\nEnter the source vertex from which you want the paths:";
	int s;
	cin>>s;
	dikSolve(s,edges,v);
	return 0;
}
