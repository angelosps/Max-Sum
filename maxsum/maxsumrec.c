#include <stdio.h>
#define max(x, y) (((x) > (y)) ? (x) : (y))

int process(int n, int m, int **arr, int i, int j){
    if(i==1) {return arr[1][j];}
    if(j==1) {return max(process(n, m, arr, i-1, m), max(process(n, m, arr, i-1, 1), process(n, m, arr, i-1, 2))) + arr[i][j];}
    if(i>1 && j>1 && j<m) {return max(process(n, m, arr, i-1, j-1), max(process(n, m, arr, i-1, j), process(n, m, arr, i-1, j+1)))+ arr[i][j];}
    if(j==m) {return max(process(n, m, arr, i-1, m-1), max(process(n, m, arr, i-1, m), process(n, m, arr, i-1, 1))) + arr[i][j];}
}

void solve(int n, int m, int **arr){
    printf("Running maxsumrec\n");
    int ans=0;
    for(int j=1; j<=m ; j++) 
        ans=max(ans,process(n, m, arr, n, j));
    printf("Max sum is %d\n", ans);
}