/// UVa OJ - 10004
#include <bits/stdc++.h>

using namespace std;

#define WHITE 0
#define RED 1
#define BLUE 2

vector<vector<int> >adj;
vector<int>color;
queue<int>Q;

bool BiColorable(int source, int nodes);
void clearQ();

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n, L, i, j, u, v;

    while (scanf("%d", &n) && n != 0) {
        scanf("%d", &L);

        adj.assign(n, vector<int>());

        for (i = 1; i <= L; i++) {
            scanf("%d%d", &u, &v);

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        /*for (i = 0; i < n; i++) {
            printf("%d -> ", i);
            for (j = 0; j < adj[i].size(); j++) {
                printf("%d ", adj[i][j]);
            }
            printf("\n");
        }*/

        bool possible = BiColorable(0, n);
        if (possible) {
            printf("BICOLORABLE.\n");
        }
        else {
            printf("NOT BICOLORABLE.\n");
        }
    }

    return 0;
}

bool BiColorable(int source, int nodes)
{
    int u, v, i;

    color.assign(nodes, WHITE); /// Setting all nodes' color as WHITE initially
    clearQ(); /// As, Q is global variable, it must be cleared before using
    Q.push(source); /// At first, pushing source node into Q
    color[source] = RED; /// Source is colored RED

    while (!Q.empty()) {
        u = Q.front();
        Q.pop();

        for (i = 0; i < adj[u].size(); i++) {
            /// v will have the i-th adjacent node of u
            v = adj[u][i];

            /// If v is not colored, color it
            if (color[v] == WHITE) {
                if (color[u] == RED) {
                    color[v] = BLUE;
                }
                else {
                    color[v] = RED;
                }

                /// After coloring, push v into Q
                Q.push(v);
            }

            /// We found that u and v are adjacent nodes
            /// So, if their color is same, given graph is not bi-colorable
            if (color[u] == color[v]) {
                return false;
            }
        }
    }
    return true;
}

void clearQ()
{
    while (!Q.empty()) {
        Q.pop();
    }
}
