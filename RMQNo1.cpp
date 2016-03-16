#include<cstdio>
using namespace std;
int min(int , int);

int minw[4000010];
void build(int node, int begin, int end)
{
	if(begin == end)
	{	
		scanf("%d",&minw[node]);
		return;
	}
	build(node*2,begin,begin+end>>1);
	build(node*2+1,(begin+end>>1)+1,end);
	minw[node] = min(minw[node*2],minw[node*2+1]);
}

void update(int node, int begin, int end, int idx, int weight)
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
int query(int node, int begin,int end,int left, int right)
{
	if(right < begin || left > end)
	return -1;
	if(right >= end && left <= begin)
	return minw[node];
	int p1 = query(node*2,begin,begin+end>>1,left,right);
	int p2 = query(node*2+1,(begin+end>>1)+1,end,left,right);
	if(p1 == -1)return p2;
	if(p2 == -1)return p1;
	if(p1 > p2) return p2;
	return p1;
}

int main()
{

	int n;
	scanf("%d",&n);
	build(1,1,n);
	int m;
	scanf("%d",&m);
	int  cmd;
	int arg[2];
	for(int i = 0;i < m; i++)
	{
		
		scanf("%d%d%d",&cmd,&arg[0],&arg[1]);
		if(cmd)update(1,1,n,arg[0],arg[1]);
		else 
		{
			int q = query(1,1,n,arg[0],arg[1]);
			printf("%d\n",q);
		}
	}
	
}
int min(int a, int b)
{
	return (a > b)?b : a;
}	

