#include <stdio.h>
#include <stdlib.h>
#include "maxsumrec.h"
#include "maxsummem.h"
#include "maxsumdp.h"

int main( void ) {
    int n,m;     
    scanf("%d %d", &n, &m);

    int **arr;
    arr = (int **) malloc((n+1)*sizeof(int *));
    for(int i=0;i<=n;i++)
	    arr[i] = (int *) malloc((m+1)*sizeof(int));


    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            scanf("%d", &arr[i][j]);

    solve(n, m, arr);

    return 0;
}