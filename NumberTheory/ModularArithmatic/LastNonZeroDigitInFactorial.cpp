/// UVa OJ - 568

#include <bits/stdc++.h>

using namespace std;

int DIGIT[10001];

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int i, d;
    long long prod, temp;

    DIGIT[0] = DIGIT[1] = 1;
    prod = 1;

    for (i = 2; i <= 10000; i++) {
        prod = (prod * i);

        if (prod % 10 == 0) {
            while (prod % 10 == 0) {
                prod /= 10;
            }
        }

        prod %= 1000000;

        d = prod % 10;
        DIGIT[i] = d;
    }

    while (scanf("%d", &i) != EOF) {
        printf("%5d -> %d\n", i, DIGIT[i]);
    }
    return 0;
}
