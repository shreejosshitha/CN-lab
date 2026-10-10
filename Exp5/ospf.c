#include <stdio.h>
#define INF 9999

int main() {
    int n, a[10][10], d[10], v[10] = {0};
    int i, j, src, u, min;

    printf("Enter number of routers: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("Enter source router: ");
    scanf("%d", &src);

    for (i = 0; i < n; i++)
        d[i] = a[src][i];

    d[src] = 0;
    v[src] = 1;

    for (i = 1; i < n; i++) {
        min = INF;
        u = -1;

        for (j = 0; j < n; j++)
            if (!v[j] && d[j] < min)
                min = d[j], u = j;

        if (u == -1) break;
        v[u] = 1;

        for (j = 0; j < n; j++)
            if (!v[j] && a[u][j] < INF &&
                d[u] + a[u][j] < d[j])
                d[j] = d[u] + a[u][j];
    }

    printf("Shortest paths from router %d:\n", src);
    for (i = 0; i < n; i++) {
        if (d[i] == INF)
            printf("To router %d: Unreachable\n", i);
        else
            printf("To router %d: %d\n", i, d[i]);
    }

    return 0;
}
