/// This program will find the Upper Bound from a certain Data Set for a given value

#include <bits/stdc++.h>

using namespace std;

const int SIZE = 13;

int main()
{
    /// Demo array
    int data[SIZE] = {11, 23, 33, 40, 45, 45, 50, 50, 50, 90, 95, 100, 100};
    int begI, midI, endI, value;

    begI = 0;
    endI = SIZE - 1;
    midI = (begI + endI) / 2;

    /// Demo value to be searched for its Upper Bound
    value = 0;

    /// If the searched value lies between 1st and Last element of the list,
    /// then, surely begI will be equal to endI - 1, when the desired Upper Bound is found
    while (begI != endI - 1) {

        /// If value is less than the 1st element,
        /// Surely, the Upper Bound of that value is zero (0)
        /// Hence midI is set to -1,
        /// Since, we are printing midI + 1
        if (value < data[0]) {
            midI = -1;
            break;
        }

        /// If value is greater than or equal to the Last element,
        /// Surely, the Upper Bound of that value is equal to the total number of elements (i.e. SIZE)
        /// Hence midI is set to SIZE - 1,
        /// Since, we are printing midI + 1
        else if (value >= data[SIZE - 1]) {
            midI = SIZE - 1;
            break;
        }

        if (data[midI] <= value) {
            begI = midI;
        }
        else {
            endI = midI;
        }

        midI = (begI + endI) / 2;
    }

    printf("%d\n", midI + 1);

    return 0;
}
