/// UVa OJ - 10653
/// GUIDE - http://www.shafaetsplanet.com/planetcoding/?p=604

#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

int fx[] = {1, -1, 0, 0}; /// Direction array
int fy[] = {0, 0, 1, -1}; /// Direction array

int cell[1000][1000]; /// If cell[x][y] = -1, then there is a mine
int dist[1000][1000];
bool visited[1000][1000];

int row;
int col;

void BFS(int sourceX, int sourceY, int desX, int desY);
void Initialize();

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int bombRows, i, j, bombR, c, bombC, sX, sY, dX, dY;

    while (scanf("%d%d", &row, &col)) {
        if (row == 0 && col == 0) {
            break;
        }

        Initialize();

        scanf("%d", &bombRows);
        for (i = 1; i <= bombRows; i++) {
            scanf("%d%d", &bombR, &c);
            for (j = 1; j <= c; j++) {
                scanf("%d", &bombC);
                cell[bombR][bombC] = -1;
            }
        }

        scanf("%d%d%d%d", &sX, &sY, &dX, &dY);
        BFS(sX, sY, dX, dY);
        printf("%d\n", dist[dX][dY]);
    }
    return 0;
}

void Initialize()
{
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            cell[r][c] = dist[r][c] = 0;
            visited[r][c] = false;
        }
    }
}

void BFS(int sourceX, int sourceY, int desX, int desY)
{
    visited[sourceX][sourceY] = true;

    queue<pii>Q;
    Q.push(pii(sourceX, sourceY));

    while (!Q.empty()) {
        pii top = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int tx = top.first + fx[i];
            int ty = top.second + fy[i];

            /// Checking whether the neighbor is valid and not visited before
            if (tx >= 0 && tx < row && ty >= 0 && ty < col && cell[tx][ty] != -1 && visited[tx][ty] == false) {
                /// Marking it visited
                visited[tx][ty] = true;
                /// Any movement means Total Moves = Previous Moves + 1
                dist[tx][ty] = dist[top.first][top.second] + 1;
                /// Pushing the new pair in the Q
                Q.push(pii(tx, ty));

                if (tx == desX && ty == desY) return;
            }
        }
    }
}
