/// UVa OJ - 12086

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200001;

vector<int>OHM(MAX, 0);
vector<int>TREE(MAX * 4, 0);

void fastScan(int &number);
void buildTree(int node, int beg, int end);
void updateTree(int node, int beg, int end, int x, int newValue);
int queryTree(int node, int beg, int end, int x, int y);

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test = 1, n, i, x, y, ans;
    char op[5];

    while (true) {
        //scanf("%d", &n);
        fastScan(n);

        if (!n) {
            break;
        }

        for (i = 1; i <= n; i++) {
            //scanf("%d", &OHM[i]);
            fastScan(OHM[i]);
        }

        buildTree(1, 1, n);

        if (test != 1) {
            printf("\n");
        }

        printf("Case %d:\n", test++);

        while (true) {
            scanf("%s", op);
            getchar();
            if (op[0] == 'E') {
                break;
            }

            //scanf("%d%d", &x, &y);
            fastScan(x);
            fastScan(y);

            switch (op[0]) {
                case 'S':
                    updateTree(1, 1, n, x, y);
                    break;

                case 'M':
                    ans = queryTree(1, 1, n, x, y);
                    printf("%d\n", ans);
                    break;
            }
        }
    }

    return 0;
}

void fastScan(int &number)
{
    /// Variable to indicate sign of input number
    bool negative = false;
    register int c;

    number = 0;

    /// Extract current character from buffer
    c = getchar();
    if (c == '-')
    {
        /// Number is negative
        negative = true;

        /// Extract the next character from the buffer
        c = getchar();
    }

    /// Keep on extracting characters if they are integers
    /// i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c > 47 && c < 58); c = getchar())
        number = number *10 + c - 48;

    /// If scanned input has a negative sign,
    /// Negate the value of the input number
    if (negative)
        number *= -1;
}

void buildTree(int node, int beg, int end)
{
    if (beg == end) {
        TREE[node] = OHM[beg];
        return;
    }

    int Left = node * 2;
    int Right = Left + 1;
    int mid = (beg + end) / 2;

    buildTree(Left, beg, mid);
    buildTree(Right, mid + 1, end);

    TREE[node] = TREE[Left] + TREE[Right];
}

void updateTree(int node, int beg, int end, int x, int newValue)
{
    if (x > end || x < beg) {
        return;
    }
    if (beg >= x && end <= x) {
        TREE[node] = newValue;
        return;
    }

    int Left = node * 2;
    int Right = Left + 1;
    int mid = (beg + end) / 2;

    updateTree(Left, beg, mid, x, newValue);
    updateTree(Right, mid + 1, end, x, newValue);

    TREE[node] = TREE[Left] + TREE[Right];
}

int queryTree(int node, int beg, int end, int x, int y)
{
    if (x > end || y < beg) {
        return 0;
    }
    if (beg >= x && end <= y) {
        return TREE[node];
    }

    int Left = node * 2;
    int Right = Left + 1;
    int mid = (beg + end) / 2;

    int sumLeft = queryTree(Left, beg, mid, x, y);
    int sumRight = queryTree(Right, mid + 1, end, x, y);

    return sumLeft + sumRight;
}
