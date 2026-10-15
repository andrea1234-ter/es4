#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    if (fork() == 0) {
        int n;
        scanf("%d", &n);

        int primo = 1;
        for (int i = 2; i < n; i++) {
            if (n % i == 0) primo = 0;
        }

        if (primo) exit(1);
        if (n % 2 == 0) exit(2);
        exit(3);
    } else {
        int status;
        wait(&status);
        int codice = WEXITSTATUS(status);

        if (codice == 1) printf("Primo\n");
        if (codice == 2) printf("Pari\n");
        if (codice == 3) printf("Dispari\n");
    }
    return 0;
}