#include <stdio.h>
#include <stdlib.h>
#define max(x, y) (((x) > (y)) ? (x) : (y))

void solve(int n, int m, int **arr){
printf("Running maxsumdp\n");

int **dp;
dp = (int **)malloc((n+1)*sizeof(int *));
for(int i=0;i<=n;i++)
	dp[i] = (int *)malloc((m+1)*sizeof(int));

for(int j=1; j<=m; j++) dp[1][j]=arr[1][j];

for(int i=2; i<=n; i++)
    for(int j=1; j<=m; j++){
        if(j==1)
            dp[i][j]=max(dp[i-1][m], max(dp[i-1][1], dp[i-1][2])) + arr[i][j];
    
        if(j>1 && j<m)
            dp[i][j]=max(dp[i-1][j-1], max(dp[i-1][j], dp[i-1][j+1])) + arr[i][j];

        if(j==m)
            dp[i][j]=max(dp[i-1][m-1], max(dp[i-1][m], dp[i-1][1])) + arr[i][j];
    }

int ans=0, x=n, y;
for(int j=1; j<=m; j++)
    if(dp[n][j]>ans) ans=dp[n][j];

printf("Max sum is %d\n", ans);

#ifdef PATH
int path[n+1];
for(int j=1; j<=m; j++) if(dp[n][j]==ans) path[n]=arr[n][j], y=j;

while(x>1){
    if(y==1){
        if(dp[x-1][m] >= dp[x-1][1] && dp[x-1][m] >= dp[x-1][2]) path[x-1]=arr[x-1][m], y=m;
        if(dp[x-1][1] >= dp[x-1][m] && dp[x-1][1] >= dp[x-1][2]) path[x-1]=arr[x-1][1], y=1;
        if(dp[x-1][2] >= dp[x-1][m] && dp[x-1][2] >= dp[x-1][1]) path[x-1]=arr[x-1][2], y=2;
    }else if(y>1 && y<m){
        if(dp[x-1][y-1] >= dp[x-1][y] && dp[x-1][y-1] >= dp[x-1][y+1]) path[x-1]=arr[x-1][y-1], y=y-1;
        if(dp[x-1][y] >= dp[x-1][y-1] && dp[x-1][y] >= dp[x-1][y+1]) path[x-1]=arr[x-1][y];
        if(dp[x-1][y+1] >= dp[x-1][y] && dp[x-1][y+1] >= dp[x-1][y-1]) path[x-1]=arr[x-1][y+1], y=y+1;
    }else if(y==m){
        if(dp[x-1][m-1] >= dp[x-1][m] && dp[x-1][m-1] >= dp[x-1][1]) path[x-1]=arr[x-1][m-1], y=m-1;
        if(dp[x-1][m] >= dp[x-1][m-1] && dp[x-1][m] >= dp[x-1][1]) path[x-1]=arr[x-1][m], y=m;
        if(dp[x-1][1] >= dp[x-1][m] && dp[x-1][1] >= dp[x-1][m-1]) path[x-1]=arr[x-1][1], y=1;
    }
x--;
}
for(int i=1; i<n; i++) printf("%d->", path[i]); printf("%d\n", path[n]);
#endif

}