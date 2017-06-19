/// ISBN Checker - UVa - 333

#include <bits/stdc++.h>

const int MAXSIZE = 100;

char s1[MAXSIZE];
char s2[MAXSIZE];
bool invalid[MAXSIZE];
int partialValues[10];
int Len1;
int Len2;

void trimString();
bool isValid();
int countPartialValue();
void printWithoutWhiteSpace();

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

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

/// Searching for non-digit characters and storing their indices
void trimString()
{
    int i, j;

    for (i = 0; i < MAXSIZE; i++) {
        invalid[i] = true;
    }

    /// Searching for indices of non-digit characters and storing them
    for (i = 0; i < Len1; i++) {
        if (s1[i] == ' ' || s1[i] == '-') {
            invalid[i] = false;
        }
    }

    /// Putting the digits of s1 only one by one inside s2 and counting Length of s2
    Len2 = 0;
    for (i = 0, j = 0; i < Len1; i++) {
        if (invalid[i] == true) {
            s2[j++] = s1[i];
            Len2++;
        }
    }
    s2[j] = '\0';
}


/// Determining whether s2 is valid or not syntactically
/// A syntactically valid ISBN must have length of 10
/// A syntactically valid ISBN can contain 0-9, White Spaces, - (Hyphens) and X only as 10th Character
bool isValid()
{
    bool valid = true;
    int i;

    if (Len2 == 10) {
        for (i = 0; i <= 8; i++) {
            if (!(s2[i] >= '0' && s2[i] <= '9')) {
                valid = false;
                break;
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


/// Counting the partial sums and final sum
int countPartialValue()
{
    int i, sum;

    /// Putting partial sums in partialValues array
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

    /// Counting the final sum adding all the values of partialValues array
    sum = 0;
    for (i = 0; i < 10; i++) {
        sum += partialValues[i];
    }

    return sum;
}


/// If there are unnecessary white spaces inside original input s1,
/// This function will print s1 without those unnecessary white spaces
void printWithoutWhiteSpace()
{
    int i, first, last;

    if (Len1 != 0) {

        /// Searching for the first valid characters in s1
        for (i = 0; i < Len1; i++) {
            if (s1[i] != ' ') {
                first = i;
                break;
            }
        }

        /// Searching for the last valid characters in s1
        for (i = Len1 - 1; i >= 0; i--) {
            if (s1[i] != ' ') {
                last = i;
                break;
            }
        }

        /// Printing s1 from the first valid character to the last valid character
        for (i = first; i <= last; i++) {
            printf("%c", s1[i]);
        }
    }
}
