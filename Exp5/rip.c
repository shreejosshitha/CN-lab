#include <stdio.h>

int main() {
    int n, id[20], cost[20], hop[20], i;

    printf("Enter number of entries: ");
    scanf("%d", &n);

    if (n < 1 || n > 20) {
        printf("Invalid input!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Enter network ID, cost and hop: ");
        scanf("%d%d%d", &id[i], &cost[i], &hop[i]);
    }

    printf("\nRouting Table\n");
    printf("Network\tCost\tHop\n");

    for (i = 0; i < n; i++)
        printf("%d\t%d\t%d\n", id[i], cost[i], hop[i]);

    printf("\nUpdated Routing Table\n");
    for (i = 0; i < n; i++)
        printf("%d\t%d\t%d\n", id[i], cost[i] + 1, hop[i]);

    return 0;
}
