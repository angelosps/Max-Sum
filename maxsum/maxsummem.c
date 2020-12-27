#include <stdio.h>
#include <stdlib.h>
#define max(x, y) (((x) > (y)) ? (x) : (y))

int process(int n, int m, int **arr, int **mem, int i, int j){
    if(i==1) {return arr[1][j];}
    if(j==1) {
        if(!mem[i-1][m]) mem[i-1][m]=process(n, m, arr, mem, i-1, m);
        if(!mem[i-1][1]) mem[i-1][1]=process(n, m, arr, mem, i-1, 1);
        if(!mem[i-1][2]) mem[i-1][2]=process(n, m, arr, mem, i-1, 2);
        return max(mem[i-1][m], max(mem[i-1][1], mem[i-1][2])) + arr[i][j];
    }
    if(i>1 && j>1 && j<m) {
        if(!mem[i-1][j-1]) mem[i-1][j-1]=process(n, m, arr, mem, i-1, j-1);
        if(!mem[i-1][j]) mem[i-1][j]=process(n, m, arr, mem, i-1, j);
        if(!mem[i-1][j+1]) mem[i-1][j+1]=process(n, m, arr, mem, i-1, j+1);
        return max(mem[i-1][j-1], max(mem[i-1][j], mem[i-1][j+1])) + arr[i][j];
    }
    
    if(j==m) {
        if(!mem[i-1][m-1]) mem[i-1][m-1]=process(n, m, arr, mem, i-1, m-1);
        if(!mem[i-1][m]) mem[i-1][m]=process(n, m, arr, mem, i-1, m);
        if(!mem[i-1][1]) mem[i-1][1]=process(n, m, arr, mem, i-1, 1);
        return max(mem[i-1][m-1], max(mem[i-1][m], mem[i-1][1])) + arr[i][j];
    }
}

void solve(int n, int m, int **arr){
    printf("Running maxsummem\n");
    int ans=0;
    int **mem;
    mem = (int **)malloc((n+1)*sizeof(int *));

    for(int i=0;i<=n;i++)
        mem[i] = (int *)malloc((m+1)*sizeof(int));
        for(int i=0; i<=n; i++)
        for(int j=0; j<=m; j++)
            mem[i][j]=0;
        for(int j=1; j<=m; j++) 
            mem[n][j]=process(n, m, arr, mem, n, j), ans=max(ans, mem[n][j]);

    printf("Max sum is %d\n", ans);

    #ifdef PATH
    int path[n+1]; int x=n ,y;
    for(int j=1; j<=m; j++) if(mem[n][j]==ans) path[n]=arr[n][j], y=j;

    while(x>1){
        if(y==1){
            if(mem[x-1][m] >= mem[x-1][1] && mem[x-1][m] >= mem[x-1][2]) path[x-1]=arr[x-1][m], y=m;
            if(mem[x-1][1] >= mem[x-1][m] && mem[x-1][1] >= mem[x-1][2]) path[x-1]=arr[x-1][1], y=1;
            if(mem[x-1][2] >= mem[x-1][m] && mem[x-1][2] >= mem[x-1][1]) path[x-1]=arr[x-1][2], y=2;
        }else if(y>1 && y<m){
            if(mem[x-1][y-1] >= mem[x-1][y] && mem[x-1][y-1] >= mem[x-1][y+1]) path[x-1]=arr[x-1][y-1], y=y-1;
            if(mem[x-1][y] >= mem[x-1][y-1] && mem[x-1][y] >= mem[x-1][y+1]) path[x-1]=arr[x-1][y];
            if(mem[x-1][y+1] >= mem[x-1][y] && mem[x-1][y+1] >= mem[x-1][y-1]) path[x-1]=arr[x-1][y+1], y=y+1;
        }else if(y==m){
            if(mem[x-1][m-1] >= mem[x-1][m] && mem[x-1][m-1] >= mem[x-1][1]) path[x-1]=arr[x-1][m-1], y=m-1;
            if(mem[x-1][m] >= mem[x-1][m-1] && mem[x-1][m] >= mem[x-1][1]) path[x-1]=arr[x-1][m], y=m;
            if(mem[x-1][1] >= mem[x-1][m] && mem[x-1][1] >= mem[x-1][m-1]) path[x-1]=arr[x-1][1], y=1;
        }
        x--;
    }
    for(int i=1; i<n; i++) printf("%d->", path[i]); printf("%d\n", path[n]);
    #endif
}