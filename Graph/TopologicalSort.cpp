// UVa OJ - 10305

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <bitset>
#include <string>
#include <utility>
#include <iterator>
#include <fstream>
#include <sstream>
#include <numeric>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <ctime>
#include <cassert>

using namespace std;

/* typedef starts */

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

/* typedef ends */

/* macro starts */

#define PI acos(-1.0)
#define EPS 1e-9
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define sinD(degree) sin((degree * PI) / 180.0)
#define cosD(degree) cos((degree * PI) / 180.0)
#define tanD(degree) tan((degree * PI) / 180.0)
#define cotD(degree) (1.0 / tanD(degree))
#define secD(degree) (1.0 / cosD(degree))
#define cosecD(degree) (1.0 / sinD(degree))
#define asinD(value) (asin(value) * 180.0) / PI
#define acosD(value) (acos(value) * 180.0) / PI
#define atanD(value) (atan(value) * 180.0) / PI
#define MAX_NODE 105

/* macro ends */

vector<int>adjList[MAX_NODE];
int inDegree[MAX_NODE];
vector<int>order;
bool done[MAX_NODE];

void initialize(int nodes);
void TopSort(int nodes);

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, i, u, v;

    while (scanf("%d%d", &n, &m)) {
        if (!n && !m) {
            break;
        }

        initialize(n);
        for (i = 1; i <= m; i++) {
            scanf("%d%d", &u, &v);
            adjList[u].push_back(v);
            inDegree[v]++;
        }

        TopSort(n);
        for (i = 0; i < order.size() - 1; i++) {
            printf("%d ", order[i]);
        }
        printf("%d\n", order[i]);
    }

    return 0;
}

void initialize(int nodes)
{
    order.clear();
    for (int i = 1; i <= nodes; i++) {
        adjList[i].clear();
        inDegree[i] = 0;
        done[i] = false;
    }
}

void TopSort(int nodes)
{
    int _count = 0;
    int d, i, v;

    while (_count != nodes) {
        for (i = 1; i <= nodes; i++) {
            if (inDegree[i] == 0 && !done[i]) {
                d = i;
                break;
            }
        }

        for (i = 0; i < adjList[d].size(); i++) {
            v = adjList[d][i];
            inDegree[v]--;
        }

        order.push_back(d);
        done[d] = true;
        _count++;
    }
}
