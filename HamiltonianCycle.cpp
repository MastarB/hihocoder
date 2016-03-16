#include<vector>
#include<stack>
#include<utility>
#include<iostream>
using namespace std;

int findn(int node, int dep, vector<bool>&tags,vector<vector<int> > &gra,int n)
{
	int sum = 0;
	if(dep ==n-1)
	{
		for(int i = 0; i < gra[node].size(); i++)
		{
			if(gra[node][i]==0)sum++;
		}
	}
	else
	{
	
		tags[node]=true;
		
		for(int i = 0; i < gra[node].size(); i++)
		{
			if(tags[gra[node][i]]==false)
				
					sum += findn(gra[node][i],dep+1,tags,gra,n);
					
		}
		tags[node]=false;
	}
		return sum;
	
}

int main()
{
	int n,m;
	int num = 0;
	stack<pair<int,int> > s;
	vector<bool>tag;
	cin>>n>>m;
	vector<vector<int> >gra;
	for(int  i =0; i<n; i++)
	{
		tag.push_back(false);
		vector<int>temp;
		gra.push_back(temp);
	}
	for(int i =0; i < m; i++)
	{
		int p,q;
		cin>>p>>q;
		gra[p-1].push_back(q-1);
	}
	s.push(make_pair(0,0));
	 cout<<findn(0,0,tag,gra,n)<<endl;
	

}
