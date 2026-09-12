#include <stdio.h>

void sort(long long *a, long long *b, long long *c) {
    long long temp;
    if (*a > *b) { temp = *a; *a = *b; *b = temp; }
    if (*b > *c) { temp = *b; *b = *c; *c = temp; }
    if (*a > *b) { temp = *a; *a = *b; *b = temp; }
}

int main() {
    long long a, b, c;
    if (scanf("%lld %lld %lld", &a, &b, &c) != 3) return 0;

    long long ronde = 0;

    sort(&a, &b, &c);

    while (a != b && b != c) {
        c--;
        a++;
        ronde++;
        sort(&a, &b, &c);
    }

    printf("%lld\n", ronde);

    return 0;
}