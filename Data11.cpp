#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *next;
};
class links
{
	public: struct node* head=NULL;
			struct node* tail=NULL;
			void insert (int n)
			{	struct node* temp;
				temp=new node;
				temp->data=n;
				//inserting at the end
				temp->next=NULL;
				if(tail==NULL)
					{ tail=temp;
					  head=tail;
					}
				else
				{
					tail->next=temp;
					tail=temp;
				}		
			}
			void show(int degree)
			{
				cout<<"\nThe polynomial is :\n";
				int i=degree;
				node *temp;
				temp=head;
				while(temp!=NULL)
				{
					if(temp->data==0)
						{
						i--;
						temp=temp->next;
						continue;}
					else
					{
						if(temp!=tail)
						{ cout<<"("<<temp->data<<"*x^"<<i<<") + ";
						}
						else
						{
							cout<<temp->data;
							
						}
						i--;
						temp=temp->next;
					}
				}
				cout<<endl;	
			}
			int coef(int step)
			{
				node *temp=head;
				int i=0;
				while(i<step)
					{temp=temp->next;
					i++;}
				return(temp->data);
			}
};
int main()
{	links p1,p2;
	cout<<"\n\t\t ADDITION OF TWO POLYNOMIALS...";
	cout<<"\nEnter their degree:";
	int deg,c;
	cin>>deg;
	cout<<"\nEnter the coefficients of polynomial 1\n";
	for(int i=0;i<=deg;i++)
	{cout<<" Coefficient of degree "<<deg-i<<":";
	cin>>c;
	p1.insert(c);
	}
	p1.show(deg);
	cout<<"\nEnter the coefficients of polynomial 2\n";
	for(int i=0;i<=deg;i++)
	{cout<<" Coefficient of degree "<<deg-i<<":";
	cin>>c;
	p2.insert(c);
	}
	p2.show(deg);
	int res;
	cout<<"\nADDITION OF THE POLYNOMIALS IS:";
	for(int i=0;i<=deg;i++)
	{
		res=p1.coef(i)+p2.coef(i);
		if(res==0) 
		{continue;
		}
		else
		{	if(i==deg)
			cout<<"+ ("<<res<<")";
			else
			{ if(i!=0)
			cout<<"+ ("<<res<<"*x^"<<deg-i<<")";
			else
			cout<<"("<<res<<"*x^"<<deg-i<<") ";
		}
		}
	}
	return 0;
}




