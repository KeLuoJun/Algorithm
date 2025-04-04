#include <stdio.h>

long long xorSum(int m, int n) {
    long long sum = 0;
    for (int i = m; i <= n; i++) {
        sum ^= i;
    }
    return sum;
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    long long result = xorSum(m, n);
    printf("%lld\n", result);

    return 0;
}
