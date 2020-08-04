#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<set>
#include<climits>
using namespace std;
class graph{
public:
    map<int,list<int > > adjlist;
    set<int> s;
    void addedge(int u, int v)
    {
        s.insert(u);
        s.insert(v);
        adjlist[u].push_back(v);
    }
    void print()
    {
        for(map<int,list<int> >:: iterator it=adjlist.begin();it!=adjlist.end();it++)
    {
        cout<<it->first<<" -> ";
        for(list<int>::iterator it1=adjlist[it->first].begin();it1!=adjlist[it->first].end();it1++)
        {
            cout<<*it1<<" ";
        }
        cout<<endl;
    }
    }
    void distances(int src)
    {
        map<int,int> dist;
        for(set<int>::iterator it=s.begin();it!=s.end();it++)
            dist[*it]=INT_MAX;
        map<int,bool> visited;
        queue<int> q;
        q.push(src);
        dist[src]=0;
        visited[src]=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            int pdist=dist[node];
            for(list<int>::iterator it=adjlist[node].begin();it!=adjlist[node].end();it++)
            {
                if(!visited[*it])
                {
                    dist[*it]=pdist+1;
                    visited[*it]=true;
                    q.push(*it);
                }
            }
        }
        cout<<"The distances of all nodes from "<<src<<" are-> "<<endl;
        for(map<int,int>::iterator it=dist.begin();it!=dist.end();it++){

            cout<<it->first<<" -> ";
            if(it->second != INT_MAX)
                cout<<it->second<<endl;
            else
                cout<<"NOT REACHABLE"<<endl;
        }
    }
    int distance(int src, int dest)
    {
        int answer=INT_MAX;
        queue<int> q;
        q.push(src);
        map<int,int> dist;
        map<int,bool> visited;
        visited[src]=true;
        dist[src]=0;

        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            int pdist=dist[node];
            for(list<int>::iterator it=adjlist[node].begin();it!=adjlist[node].end();it++)
                {
                    if(*it == dest)
                        return (pdist+1);
                    if(!visited[*it])
                    {
                        dist[*it]=pdist+1;
                        visited[*it]=true;
                        q.push(*it);
                    }

                }

        }
        return answer;
    }
};
int main()
{	cout<<"\n\t\t\tPROGRAM TO FIND THE DISTANCES BETWEEN ALL PAIR OF VERTICES\n";
    graph g;
    cout<<"\nEnter the number of links in the graph -> ";
    int n;
    cin>>n;
    int u,v,i;
    i=1;
    while(n--)
    {	cout<<"Enter link "<<i<<":";
        cin>>u>>v;
        g.addedge(u,v);
        i++;
    }
    //g.print();
    vector<int> elements;
    for(set<int> ::iterator it=g.s.begin();it!=g.s.end();it++)
        elements.push_back(*it);
    for(int i=0;i<elements.size();i++)
    {
        for(int j=i+1;j<elements.size();j++)
        {
            cout<<"Distance between "<<elements[i]<<" and "<<elements[j]<<" is ";
            int d=g.distance(elements[i],elements[j]);
            if(d==INT_MAX)
                cout<<"INFINITE"<<endl;
            else
                cout<<d<<endl;

        }
    }

    return 0;
}

