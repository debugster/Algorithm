/// ISBN Checker - UVa - 333

#include <bits/stdc++.h>

char s1[100];
char s2[100];
bool invalid[100];
int partialValues[10];
int Len1;
int Len2;

void trimString();
bool isValid();
int countPartialValue();
void printWithoutWhiteSpace();

int main()
{
    /// freopen("in.txt", "r", stdin);
    /// freopen("out.txt", "w", stdout);

    while (gets(s1)) {

        Len1 = strlen(s1);

        trimString();

        if (isValid() == true) {
            if (countPartialValue() % 11 == 0) {
                printWithoutWhiteSpace();
                printf(" is correct.\n");
            }
            else {
                printWithoutWhiteSpace();
                printf(" is incorrect.\n");
            }
        }
        else {
            printWithoutWhiteSpace();
            printf(" is incorrect.\n");
        }
    }

    return 0;
}

void trimString()
{
    int i, j;

    for (i = 0; i < 100; i++) {
        invalid[i] = true;
    }

    for (i = 0; i < Len1; i++) {
        if (s1[i] == ' ' || s1[i] == '-') {
            invalid[i] = false;
        }
    }

    Len2 = 0;
    for (i = 0, j = 0; i < Len1; i++) {
        if (invalid[i] == true) {
            s2[j++] = s1[i];
            Len2++;
        }
    }
    s2[j] = '\0';
}

bool isValid()
{
    bool valid = true;
    int i;

    if (Len2 == 10) {
        for (i = 0; i <= 8; i++) {
            if (!(s2[i] >= '0' && s2[i] <= '9')) {
                valid = false;
            }

            if (!(s2[9] >= '0' && s2[9] <= '9' || s2[9] == 'X')) {
                valid = false;
            }
        }
    }
    else {
        valid = false;
    }

    return valid;
}

int countPartialValue()
{
    int i, sum;

    partialValues[0] = (int) (s2[0] - 48);

    for (i = 1; i < 10; i++) {
        if (i == 9 && s2[i] == 'X') {
            sum = 10;
        }
        else {
            sum = (int) (s2[i] - 48);
        }

        partialValues[i] = partialValues[i - 1] + sum;
    }

    sum = 0;
    for (i = 0; i < 10; i++) {
        sum += partialValues[i];
    }

    return sum;
}

void printWithoutWhiteSpace()
{
    int i, first, last;

    if (Len1 != 0) {

        for (i = 0; i < Len1; i++) {
            if (s1[i] != ' ') {
                first = i;
                break;
            }
        }

        for (i = Len1 - 1; i >= 0; i--) {
            if (s1[i] != ' ') {
                last = i;
                break;
            }
        }

        for (i = first; i <= last; i++) {
            printf("%c", s1[i]);
        }
    }
}
