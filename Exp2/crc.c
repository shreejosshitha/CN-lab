#include <stdio.h>
#include <string.h>

int main() {
    char data[100], div[30], temp[100];
    int n, m, i, j;

    printf("Enter data bits: ");
    scanf("%99s", data);
    printf("Enter divisor bits: ");
    scanf("%29s", div);

    n = strlen(data);
    m = strlen(div);

    if (m < 2 || m > n) {
        printf("Invalid input\n");
        return 1;
    }

    strcpy(temp, data);

    for (i = 0; i <= n - m; i++) {
        if (temp[i] == '1') {
            for (j = 0; j < m; j++)
                temp[i + j] = (temp[i + j] == div[j]) ? '0' : '1';
        }
    }

    printf("Remainder: ");
    for (i = n - m + 1; i < n; i++)
        printf("%c", temp[i]);

    printf("\n");
    return 0;
}
