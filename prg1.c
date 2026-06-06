# include <stdio.h>
int cost[10][10],n;
void kruskal(){
    int par[n];
    int a=0,b=0,u=0,v=0,min,mincost=0,ne=0;
    for(int i=0;i<n;i++){
        par[i]=-1;
    }
    printf("the edges of the minimum cost spanning tree are\n");
    while(ne<n-1){
        min=999;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(cost[i][j]<min && cost[i][j]!=0){
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
                while(par[u]!=-1){
                    u=par[u];
                }
                while(par[v]!=-1){
                    v=par[v];
                }
                if(u!=v){
                    printf("From the vertex %d to vertex %d and the cost = %d \n",a,b,min);
                    mincost+=min;
                    ne++;
                    par[v]=u;
                }
                cost[a][b]=cost[b][a]=999;
            }
        }
    }
    printf("the minimum cost is %d\n",mincost);
}
int main(){
    printf("Enter the number of vertices:");
    scanf("%d",&n);
    printf("Enter the cost matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&cost[i][j]);
        }
    }
    kruskal();
    return 0;
}