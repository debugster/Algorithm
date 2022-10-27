// UVa OJ - 11631

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

/* macro ends */

/* function starts */

/// calculates n-th (0-based) Gray Code
template<typename dataType>
dataType nthGrayCode(dataType n)
{
    return (n ^ (n >> 1));
}

/// generates all possible subsets for the given set
template<typename dataType>
void generateAllSubset(vector<dataType> &data)
{
    int i, j, n;
    n = data.size();

    for (i = 0; i < (1 << n); i++) {
        for (j = 0; j < n; j++) {
            if (i & (1 << j)) {
                cout << data[j] << " ";
            }
        }
        cout << "\n";
    }
}

/* function ends */

#define MAX 200005

struct EDGE
{
    int u;
    int v;
    int cost;

    EDGE()
    {
        u = v = cost = 0;
    }

    EDGE(int x, int y, int c)
    {
        u = x;
        v = y;
        cost = c;
    }

    bool operator<(const EDGE &a) const
    {
        return cost < a.cost;
    }
};

vector<EDGE> allEdge;
int parent[MAX];
int nodeRank[MAX];

void clearAll()
{
    for (int i = 0; i < MAX; i++) {
        parent[i] = i;
        nodeRank[i] = 1;
    }
    allEdge.clear();
}

int findParent(int n)
{
    if (parent[n] == n) {
        return n;
    }

    parent[n] = findParent(parent[n]);
    return parent[n];
}

int KruskalMST(int nodes)
{
    int _count, a, b, pA, pB, minCost;
    EDGE e;

    sort(allEdge.begin(), allEdge.end());
    _count = minCost = 0;
    for (int i = 0; i < allEdge.size(); i++) {
        e = allEdge[i];
        a = e.u;
        b = e.v;

        pA = findParent(a);
        pB = findParent(b);

        if (pA != pB) {
            if (nodeRank[pA] >= nodeRank[pB]) {
                parent[pB] = pA;
                nodeRank[pA] += nodeRank[pB];
            }
            else {
                parent[pA] = pB;
                nodeRank[pB] += nodeRank[pB];
            }

            _count++;
            minCost += e.cost;
        }

        if (_count == nodes - 1) {
            break;
        }
    }

    return minCost;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif

    fastIO;

    int numberOfNodes, numberOfEdges, u, v, c, sumOfAllEdgeCost;

    while (cin >> numberOfNodes >> numberOfEdges && numberOfNodes) {
        
        clearAll();
        sumOfAllEdgeCost = 0;
        for (int i = 1; i <= numberOfEdges; i++) {
            cin >> u >> v >> c;
            allEdge.push_back(EDGE(u, v, c));
            sumOfAllEdgeCost += c;
        }

        cout << sumOfAllEdgeCost - KruskalMST(numberOfNodes) << endl;
    }

    return 0;
}
