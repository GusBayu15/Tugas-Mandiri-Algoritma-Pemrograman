#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int compare(const void *a, const void *b) {
    long long valA = *(const long long *)a;
    long long valB = *(const long long *)b;
    if (valA < valB) return -1;
    if (valA > valB) return 1;
    return 0;
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    long long *A = (long long *)malloc(N * sizeof(long long));
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }

    qsort(A, N, sizeof(long long), compare);

    long long total_pairs = ((long long)N * (N - 1) / 2);
    
    long long same_pairs = 0;
    long long freq = 1;

    for (int i = 1; i < N; i++) {
        if (A[i] == A[i - 1]) {
            freq++;
        } else {
            same_pairs += (freq * (freq - 1) / 2);
            freq = 1;
        }
    }
    
    same_pairs += (freq * (freq - 1) / 2);

    long long valid_pairs = total_pairs - same_pairs;

    
    long long ans = valid_pairs % MOD;

    printf("%lld\n", ans);

    free(A);
    return 0;
}