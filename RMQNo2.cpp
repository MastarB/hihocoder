#include<cstdio>
using namespace std;
int min(int , int);
int add[400100];
int sum[400100];
void build(int node, int begin, int end)
{
	add[node] = -1;
	if(begin == end)
	{	
		scanf("%d",&sum[node]);
		return;
	}
	build(node*2,begin,begin+end>>1);
	build(node*2+1,(begin+end>>1)+1,end);
	sum[node] = sum[node*2]+sum[node*2+1];
}

void update(int node, int begin, int end, int idx, int weight)
{
	if(idx < begin || idx > end)return;
	if(begin == end)
	{
	 	sum[node]= weight;
	 	return;
	}
	/*Update Downside*/
	update(node<<1,begin,(begin+end)>>1,idx,weight);
	update(node<<1|1,(begin+end>>1)+1,end,idx,weight);
	/*Update itself*/
	sum[node] = sum[node<<1|1]+sum[node<<1];
}

void update(int node, int begin, int end, int left, int right,int weight)
{
			if(right < begin || left > end)
			{
				return;
			}
			if(begin >= left && end <= right)
			{
				sum[node] = weight*(end-begin+1);
				add[node] = weight;
				return ;
			}
			if(add[node] != -1)
			{
				add[node*2] = add[node];
				add[node*2+1] = add[node];
				sum[node*2] = add[node]*((begin+end)/2-begin+1);
				sum[node*2+1] = add[node]*(end-(begin+end)/2);
				add[node] = -1;
			}
			update(node*2,begin,(begin+end)/2,left,right,weight);
			update(node*2+1,(begin+end)/2+1,end,left,right,weight);
			
			sum[node] = sum[node<<1|1]+sum[node<<1];
						
}
int query(int node, int begin,int end,int left, int right)
{
	if(right < begin || left > end)
	return 0;
	if(add[node] != -1)
	{
		add[node*2] = add[node];
		add[node*2+1] = add[node];
		sum[node*2] = add[node]*((begin+end)/2-begin+1);
		sum[node*2+1] = add[node]*(end-(begin+end)/2);
		add[node] = -1;
	}
	
	if(right >= end && left <= begin)
	return sum[node];
	int p1 = query(node*2,begin,(begin+end)/2,left,right);
	int p2 = query(node*2+1,(begin+end)/2+1,end,left,right);
	return p1+p2;
}

int main()
{

	int n;
	scanf("%d",&n);
	build(1,1,n);
	int m;
	scanf("%d",&m);
	int  cmd;
	int arg[3];
	for(int i = 0;i < m; i++)
	{
		
		scanf("%d",&cmd);
		if(cmd)
		{
		scanf("%d%d%d",&arg[0],&arg[1],&arg[2]);
		update(1,1,n,arg[0],arg[1],arg[2]);
		}
		else 
		{
			scanf("%d%d",&arg[0],&arg[1]);
			int q = query(1,1,n,arg[0],arg[1]);
			printf("%d\n",q);
			
		}
	}
	
}


