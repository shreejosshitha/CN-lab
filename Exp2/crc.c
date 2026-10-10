#include <stdio.h>
#include <string.h>

int main() {
    int choice, i, j, n, m;
    char data[200], divisor[50], temp[250];

    do {
        printf("\nCRC\n");
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

        if (choice == 1) {
            printf("Enter data bits: ");
            scanf("%199s", data);
        } else {
            printf("Enter received codeword: ");
            scanf("%199s", data);
        }

        printf("Enter divisor bits: ");
        scanf("%49s", divisor);

        m = strlen(data);
        n = strlen(divisor);

        if (n < 2 || n > m) {
            printf("Invalid input!\n");
            continue;
        }

        strcpy(temp, data);

        if (choice == 1) {
            for (i = m; i < m + n - 1; i++)
                temp[i] = '0';
            temp[m + n - 1] = '\0';
        }

        int len = strlen(temp);

        for (i = 0; i <= len - n; i++) {
            if (temp[i] == '1') {
                for (j = 0; j < n; j++)
                    temp[i + j] =
                        (temp[i + j] == divisor[j]) ? '0' : '1';
            }
        }

        printf("Remainder: ");
        for (i = len - n + 1; i < len; i++)
            printf("%c", temp[i]);
        printf("\n");

        if (choice == 1) {
            printf("Codeword to send: %s", data);
            for (i = len - n + 1; i < len; i++)
                printf("%c", temp[i]);
            printf("\n");
        } else {
            int error = 0;
            for (i = len - n + 1; i < len; i++) {
                if (temp[i] != '0')
                    error = 1;
            }

            if (error)
                printf("Error detected!\n");
            else
                printf("Data is error-free.\n");
        }

    } while (choice != 3);

    return 0;
}
