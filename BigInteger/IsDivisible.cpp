#include <bits/stdc++.h>

using namespace std;

bool isDivisible(char *num, int div);

int main()
{
    char number[1000];
    int dividend;

    strcpy(number, "6613");
    dividend = 17;
    isDivisible(number, dividend) ? printf("%s is divisible by %d.\n", number, dividend) : printf("%s is not divisible by %d.\n", number, dividend);
}

bool isDivisible(char *num, int div)
{
    int i, Len, x = 0;

    Len = strlen(num);
    for (i = 0; i < Len; i++) {
        x = x * 10 + num[i] - '0';
        x %= div;
    }

    if (x == 0) {
        return true;
    }

    return false;
}
