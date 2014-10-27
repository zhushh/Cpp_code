// some error, lost some case
#include <stdio.h>

int main() {
    int t, id;
    long int num, count, a, k;
    scanf("%d", &t);
    while (t-- > 0) {
        scanf("%d%ld", &id, &num);
        count = 0;
        for (k = 1; k*k <= num; ++k) {
            a = (2*num - k*k - k) / (2*k + 2);
            if (((2*a + k) * (k + 1)) / 2 == num) {
                count++;
                printf("%ld->%ld\n", a, a+k);
            }
        }
        printf("%d %ld\n", id, count);
    }
    return 0;
}
