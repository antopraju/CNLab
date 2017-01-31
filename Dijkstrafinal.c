#include<stdio.h>

int cost[10][10];int dis[10];
int n,v;

void dik(int n,int v,int cost[10][10],int dis[10])
{
    int flag[10],i; int count; int min;
    int w,u,j;
    for(i=1;i<=n;i++)
    {
    	flag[i]=0;
    	dis[i]=cost[v][i];
    }
    count=2;
    while(count<=n)
    {
    	min=99;
    	for(w=1;w<=n;w++)
    		if(dis[w]<=min && !flag[w])
    {
    	min=dis[w];
    	u=w;
    }
    	flag[u]=1;
    	count++;
    for(w=1;w<=n;w++)
    {
    	if((dis[u]+cost[u][w]<=dis[w]) && !flag[w])
    {
    	dis[w]=dis[u]+cost[u][w];
    }
    }
    }
}
int main()
{
    int i,j;
    printf("Enter no of vertices\n");
    scanf("%d",&n);
    printf("enter dimensions of matrix\n");
    for(i=1;i<=n;i++)
    {
    for(j=1;j<=n;j++)
    {
    	scanf("%d",&cost[i][j]);
    	if(cost[i][j]==0)
    	cost[i][j]=999;
    }
    }
    printf("Enter source vertex\n");
    scanf("%d",&v);
    dik(n,v,cost,dis);
    printf("the shortest paths are as follows\n");
    for(i=1;i<=n;i++)
    {
    	if(i!=v)
    	printf("%d to %d cost is %d\n",v,i,dis[i]);
    }
    printf("\n");
    return 0;
}
