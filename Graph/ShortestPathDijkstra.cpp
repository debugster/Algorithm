/// UVa OJ - 10986

#include <bits/stdc++.h>

using namespace std;

#define INF 0x7FFFFFFF

typedef pair<int, int> PII;

struct compare
{
    bool operator()(const PII& x, const PII& y)
    {
        return x.first > y.first;
    }
};

vector<int>adjList[20000];
int cost[20000][20000];
int dist[20000];

void fastScan(int &number);
void initialize(int node);
void shortestPath(int source);

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, kase, n, m, s, t, u, v, w, i, j, ans;

    scanf("%d", &test);
    for (kase = 1; kase <= test; kase++) {
        scanf("%d%d%d%d", &n, &m, &s, &t);

        initialize(n);

        while (m--) {
            scanf("%d%d%d", &u, &v, &w);

            adjList[u].push_back(v);
            adjList[v].push_back(u);

            if (cost[u][v] > w) {
                cost[u][v] = w;
                cost[v][u] = w;
            }
        }

        printf("Case #%d: ", kase);
        shortestPath(s);
        if (dist[t] == INF) {
            printf("unreachable\n");
        }
        else {
            printf("%d\n", dist[t]);
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

void initialize(int node)
{
    int i, j;

    for (i = 0; i < node; i++) {
        dist[i] = INF;
        adjList[i].clear();
        for (j = 0; j < node; j++) {
            cost[i][j] = INF;
        }
    }
}

void shortestPath(int source)
{
    priority_queue<PII, vector<PII>, compare>PQ;
    PII u, v;
    int i;

    /// First refers to Weight/Cost
    /// Second refers to Node

    u.first = 0;
    u.second = source;

    PQ.push(u);
    cost[source][source] = 0;
    dist[source] = 0;

    while (!PQ.empty()) {
        u = PQ.top();
        PQ.pop();

        for (i = 0; i < adjList[u.second].size(); i++) {
            v.second = adjList[u.second][i];
            if (dist[v.second] > dist[u.second] + cost[u.second][v.second]) {
                v.first = dist[v.second] = dist[u.second] + cost[u.second][v.second];
                PQ.push(v);
            }
        }
    }
}
