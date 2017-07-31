/// GUIDE - http://www.shafaetsplanet.com/planetcoding/?p=604
#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

int fx[] = {2, 2, -2, -2, 1, -1, 1, -1}; /// Direction array
int fy[] = {1, -1, 1, -1, 2, 2, -2, -2}; /// Direction array

int dist[8][8];
bool visited[8][8];

int row = 8;
int col = 8;

void BFS(int sourceX, int sourceY, int desX, int desY);
void Initialize();

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    char moves[10];
    int sX, sY, desX, desY;

    while (gets(moves)) {
        sY = (int) moves[0] - 'a';
        sX = (int) moves[1] - '0' - 1;

        desY = (int) moves[3] - 'a';
        desX = (int) moves[4] - '0' - 1;

        Initialize();

        BFS(sX, sY, desX, desY);
        printf("To get from %c%c to %c%c takes %d knight moves.\n", moves[0], moves[1], moves[3], moves[4], dist[desX][desY]);
    }

    return 0;
}

void Initialize()
{
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            dist[r][c] = 0;
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

        for (int i = 0; i < 8; i++) {
            int tx = top.first + fx[i];
            int ty = top.second + fy[i];

            /// Checking whether the square is valid and not visited before
            if (tx >= 0 && tx < row && ty >= 0 && ty < col && visited[tx][ty] == false) {
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

