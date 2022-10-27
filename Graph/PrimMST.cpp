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
#define INF 0X7FFFFFFF

struct EDGE {
    int node;
    int cost;

    EDGE(int n, int c)
    {
        node = n;
        cost = c;
    }
};

struct compare
{
    bool operator()(pii &a, pii &b)
    {
        return a.first > b.first;
    }
};

vector<EDGE> adjList[MAX];

void clearAll()
{
    for (int i = 0; i < MAX; i++) {
        adjList[i].clear();
    }
}

int PrimMST(int source, int nodes)
{
    priority_queue<pii, vector<pii>, compare> PQ;
    vector<int> key(nodes + 1, INF);
    vector<bool> inMST(nodes + 1, false);
    int u, v, w, ans = 0;

    key[source] = 0;
    PQ.push(make_pair(key[source], source));

    while (!PQ.empty()) {
        u = PQ.top().second;
        inMST[u] = true;
        PQ.pop();

        for (int i = 0; i < adjList[u].size(); i++) {
            v = adjList[u][i].node;
            w = adjList[u][i].cost;
            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                PQ.push(make_pair(key[v], v));
            }
        }
    }

    for (u = 0; u < nodes; u++) {
        ans += key[u];
    }

    return ans;
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
            adjList[u].push_back(EDGE(v, c));
            adjList[v].push_back(EDGE(u, c));
            sumOfAllEdgeCost += c;
        }

        cout << sumOfAllEdgeCost - PrimMST(0, numberOfNodes) << endl;
    }

    return 0;
}
