/*
Given  a  graph,each  node  A  knows  the shortest  path  to  node  Z  and  node  A  can determine its shortest path to Z by calculating the minimum cost. Now when packet 
flows through a path it incurs some cost to the network,find shortest paths from src to all nodes in the given graph using Bellman Ford 
Algorithm.The graph may contain negative weight edges.
*/
#include <stdio.h>
#include <stdlib.h>
int Bellman_Ford(int G[20][20] , int V, int E, int edge[20][2])
{
    int i,u,v,k,distance[20],parent[20],S,flag=1;
    for(i=0;i<V;i++)
        distance[i] = 1000 , parent[i] = -1 ;
        printf("Enter source: ");
        scanf("%d",&S);
        distance[S-1]=0 ;
    for(i=0;i<V-1;i++)
    {
        for(k=0;k<E;k++)
        {
            u = edge[k][0] , v = edge[k][1] ;
            if(distance[u]+G[u][v] < distance[v])
                distance[v] = distance[u] + G[u][v] , parent[v]=u ;
        }
    }
    
    //Loop checks if negative weight cycle exists in graph
    for(k=0;k<E;k++)
    {
        u = edge[k][0] , v = edge[k][1] ;
        if(distance[u]+G[u][v] < distance[v])
            flag = 0 ;
    }
    if(flag)
        for(i=0;i<V;i++)
            printf("Vertex %d -> cost = %d parent = %d\n",i+1,distance[i],parent[i]+1);

    return flag;
}
int main()
{
    int V,edge[20][2],G[20][20],i,j,k=0;
    printf("BELLMAN FORD\n");
    printf("Enter no. of vertices: ");
    scanf("%d",&V);
    printf("Enter graph in matrix form:\n");
    for(i=0;i<V;i++)
        for(j=0;j<V;j++)
        {
            scanf("%d",&G[i][j]);
            //G[j][i]=G[i][j];   if you are given an undirected graph
            if(G[i][j]!=0)
            {
                edge[k][0]=i,edge[k++][1]=j;
                //edge[k][0]=j,edge[k++][1]=i;     if you are given an undirected graph
            }
        }

    if(Bellman_Ford(G,V,k,edge))
        printf("\nNo negative weight cycle\n");
    else printf("\nNegative weight cycle exists\n");
    return 0;
}
