#include <stdio.h>

int main() {
    int n, a[100], sum = 0, i, checksum;

    printf("Enter number of data bytes: ");
    scanf("%d", &n);

    if (n < 1 || n > 100) {
        printf("Invalid input\n");
        return 1;
    }

    printf("Enter data bytes (0-255): ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] < 0 || a[i] > 255) {
            printf("Invalid byte\n");
            return 1;
        }
        sum += a[i];
    }

    while (sum > 255)
        sum = (sum & 255) + (sum >> 8);

    checksum = (~sum) & 255;

    printf("Checksum: %d\n", checksum);
    printf("Data sent: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("%d\n", checksum);

    return 0;
}
