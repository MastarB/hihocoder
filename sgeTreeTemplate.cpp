#include<iostream>
using namespace std;


short minw[4000004];
void build(int node, int begin, int end)
{
	if(begin == end)
	{	
		cin >> minw[node];
		return;
	}
	build(node*2,begin,begin+end>>1);
	build(node*2+1,(begin+end>>1)+1,end);
	minw[node] = min(minw[node*2],minw[node*2+1]);
}

void update(int node, int begin, int end, int idx, short weight)
{
	if(idx < begin || idx > end)return;
	if(begin == end)
	{
	 	minw[node]= weight;
	 	return;
	}
	/*Update Downside*/
	update(node<<1,begin,(begin+end)>>1,idx,weight);
	update(node<<1|1,(begin+end>>1)+1,end,idx,weight);
	/*Update itself*/
	minw[node] = min(minw[node<<1|1],minw[node<<1]);
}
short query(int node, int begin,int end,int left, int right)
{
	if(right < begin || left > end)
	return -1;
	if(right >= end && left <= begin)
	return minw[node];
	short p1 = query(node*2,begin,begin+end>>1,left,right);
	short p2 = query(node*2+1,(begin+end>>1)+1,end,left,right);
	if(p1 == -1)return p2;
	if(p2 == -1)return p1;
	if(p1 > p2) return p2;
	return p1;
}
short min(short, short);
int main()
{

	int n;
	cin>>n;
	build(1,1,n);
	int m;
	cin>>m;
	bool cmd;
	short arg[2];
	for(int i = 0;i < m; i++)
	{
		
		cin>>cmd>>arg[0]>>arg[1];
		if(cmd)update(1,1,n,arg[0],arg[1]);
		else cout<<query(1,1,n,arg[0],arg[1]);
		
	}
	
}
short min(int a, int b)
{
	return (a > b)?b : a;
}	

