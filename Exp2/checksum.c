#include <stdio.h>

int calculate(int data[], int n) {
    int sum = 0, i;

    for (i = 0; i < n; i++)
        sum += data[i];

    while (sum >> 8)
        sum = (sum & 255) + (sum >> 8);

    return (~sum) & 255;
}

int main() {
    int choice, n, i, data[100], checksum, sum;

    do {
        printf("\nChecksum\n");
        printf("1. Transmitting side\n");
        printf("2. Receiving side\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 3)
            break;

        if (choice != 1 && choice != 2) {
            printf("Invalid choice!\n");
            continue;
        }

        printf("Enter number of data bytes: ");
        scanf("%d", &n);

        if (n < 1 || n > 100) {
            printf("Invalid input!\n");
            continue;
        }

        printf("Enter data bytes (0-255): ");
        for (i = 0; i < n; i++) {
            scanf("%d", &data[i]);
            if (data[i] < 0 || data[i] > 255) {
                printf("Invalid byte!\n");
                break;
            }
        }

        if (i != n)
            continue;

        if (choice == 1) {
            checksum = calculate(data, n);
            printf("Checksum: %d\n", checksum);
            printf("Data sent: ");
            for (i = 0; i < n; i++)
                printf("%d ", data[i]);
            printf("%d\n", checksum);
        } else {
            printf("Enter received checksum: ");
            scanf("%d", &checksum);

            if (checksum < 0 || checksum > 255) {
                printf("Invalid checksum!\n");
                continue;
            }

            sum = checksum;
            for (i = 0; i < n; i++)
                sum += data[i];

            while (sum >> 8)
                sum = (sum & 255) + (sum >> 8);

            if (sum == 255)
                printf("Data is error-free.\n");
            else
                printf("Error detected!\n");
        }

    } while (choice != 3);

    return 0;
}
