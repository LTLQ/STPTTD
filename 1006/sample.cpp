#include <stdio.h>
int main() {
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF) {
        while(m != n) {
            if(m < n) {
                putchar('L');
                n -= m;
            } else {
                putchar('R');
                m -= n;
            }
        }
        putchar('\n');
    }
    return 0;
}
