#include<cstdio>
#define max 50001
char content[max];
char same[4*max];
char CMD[4];
int shift[4*max];

int sp = 0;
int n,m;
void update1(int node, int begin, int end, int left, int right, int rotate)
{
	if(begin > right || end < left)
	return;
	if(begin <= right && end >= left)
	{	
		if(same[node] != -1)
		{	
			same[node] = (same[node]+rotate+shift[node]);//to debug
			shift[node] = 0;
			if(end == begin)
			content[begin] = same[node];
		}
		else
			shift[node] += rotate;
			return;
	}
	/*pushdown*/
	if(same[node] != -1 )
	{
		if(shift[node])
		{
			same[node] += shift[node];
			same[node] %= 26;
		}
		same[node*2] = same[node];
		same[node*2+1] = same[node*2];
		shift[node*2] = shift[node*2+1] = 0;
	}
	else if(shift[node])
	{
		shift[node*2] += shift[node];
		shift [node*2] %= 26;
		shift[node*2+1] =shift[node*2];
	}
	shift[node] = 0;
	

	update1(node*2, begin,(begin+end)/2,left,right,rotate);
	update1(node*2+1, (begin+end)/2+1, end, left, right, rotate);
	/*get_frome_kids*/
	if(same[node*2] == same[node*2+1])same[node] = same[node*2];
	else same[node] = -1;	
}
void update2(int node, int begin, int end, int left, int right, char c)
{
	if(begin > right || end <left)
	return;
	if(begin >=left && end <= right)
	{
		same[node] = c;
		shift[node] = 0;
		if(begin == end)content[begin] = c;
		return;
	}
	/*pushdown*/
		if(same[node] != -1 )
	{
		if(shift[node])
		{
			same[node] += shift[node];
			same[node] %= 26;
		}
		same[node*2] = same[node];
		same[node*2+1] = same[node*2];
		shift[node*2] = shift[node*2+1] = 0;
	}
	else if(shift[node])
	{
		shift[node*2] += shift[node];
		shift [node*2] %= 26;
		shift[node*2+1] =shift[node*2];
	}
	shift[node] = 0;
	

	update2(node*2, begin,(begin+end)/2,left,right,c);
	update2(node*2+1, (begin+end)/2+1, end, left, right, c);
	/*get_frome_kids*/
	if(same[node*2] == same[node*2+1])same[node] = same[node*2];
	else same[node] = -1;	
}
void update3(int shift)
{
	sp += shift;
	sp %= n;
}

void update4(int node, int begin, int end, int left, int right,int init)
{
	int i = left;
	int j = right;
	while(init--)	
		update2(node, begin, end, left, right, 0);
	if(i > j);
	else 
	{
		update4(node, begin, end, left+1, right,0);
		update2(node, begin, end, left, right, 1);	
	} 
}
void build(int node,int begin, int end)
{
	shift[node] = 0;
	if(begin == end)
	{
		same[node] = content[begin];
		return;
	}
	build(node<<1, begin, (begin+end)/2);
	build(node<<1|1, (begin+end)/2+1, end);
	if(same[2*node] == same[2*node+1])same[node]=same[2*node];
	else same[node] = -1;
}
void query(int node,int begin, int end, int left, int right)
{
	if(begin > right || end <left)
	return;
	if(begin <= left && end >= right)
	{
		if(same[node] != -1)
		{
			same[node] = (same[node]+shift[node])%26;
			shift[node] = 0;
			for(int i = begin; i <= end; i++)
				printf("%c",same[node]);
			return;
		}
	}
	/*pushdown*/
	if(same[node] != -1 )
	{
		if(shift[node])
		{
			same[node] += shift[node];
			same[node] %= 26;
		}
		same[node*2] = same[node];
		same[node*2+1] = same[node*2];
		shift[node*2] = shift[node*2+1] = 0;
	}
	else if(shift[node])
	{
		shift[node*2] += shift[node];
		shift [node*2] %= 26;
		shift[node*2+1] =shift[node*2];
	}
	shift[node] = 0;
	query(node*2, begin,(begin+end)/2,left,right);
	query(node*2+1, (begin+end)/2+1, end, left, right);
	/*get_frome_kids*/
 	
	if(same[node*2] == same[node*2+1])same[node] = same[node*2];
	else same[node] = -1;
}

int main()
{
	int type;
	int arg[3];
	scanf("%d%d",&n,&m);
	scanf("%s",&content[1]);
	while(m--)
	{
		scanf("%s",CMD);
		scanf("%d",&type);
		scanf("%d",&arg[0]);
		
		switch(type)
		{
			case 1:
				scanf("%d%d",&arg[1],&arg[2]);
				if((arg[0]-1 + sp)%n > (arg[1] -1 +sp)%n)
				{
					update1(1,1,n,(arg[0]-1+sp)%n+1,n,arg[2]);
					update1(1,1,n,1,(arg[1]-1+sp)%n+1,arg[2]);
				} 
				else
				update1(1,1,n,(arg[0]-1+sp)%n+1,(arg[1]-1+sp)%n+1,arg[2]);
				break;
			case 2:
				scanf("%d%d",&arg[1],&arg[2]);
				if((arg[0]-1 + sp)%n > (arg[1] -1 +sp)%n)
				{
					update2(1,1,n,(arg[0]-1+sp)%n+1,n,arg[2]);
					update2(1,1,n,1,(arg[1]-1+sp)%n+1,arg[2]);
				} 
				else
				update2(1,1,n,(arg[0]-1+sp)%n+1,(arg[1]-1+sp)%n+1,arg[2]);
				break;
			case 3:
				update3(arg[0]);
				break;
			case 4:
				scanf("%d",&arg[1]);
				if((arg[0]-1 + sp)%n > (arg[1] -1 +sp)%n)
				{
					update4(1,1,n,(arg[0]-1+sp)%n+1,n,0);
					update4(1,1,n,1,(arg[1]-1+sp)%n+1,n-(arg[0]-1+sp)%n-1);
				} 
				else
				update4(1,1,n,(arg[0]-1+sp)%n+1,(arg[1]-1+sp)%n+1,0);
				break;
		}
	}
	if((arg[0]-1 + sp)%n > (arg[1] -1 +sp)%n)
	{
		query(1,1,n,(arg[0]-1+sp)%n+1,n);
		query(1,1,n,1,(arg[1]-1+sp)%n+1);
	} 
	else
		query(1,1,n,(arg[0]-1+sp)%n+1,(arg[1]-1+sp)%n+1);
		printf("\n");
}





