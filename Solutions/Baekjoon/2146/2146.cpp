#include <bits/stdc++.h>

#include <queue>

#define X first
#define Y second

using namespace std;

int board[101][101];
bool vis[101][101];
int dist[101][101];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n;

bool OOB(int a, int b) {
    return a < 0 or a >= n or b < 0 or b >= n;
}

void island() {
    int idx = 1;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (vis[x][y] || board[x][y] == 0) {
                continue;
            }

            queue<pair<int, int>> Q;
            Q.push({x, y});

            vis[x][y] = true;

            while (!Q.empty()) {
                auto cur = Q.front();
                Q.pop();

                board[cur.X][cur.Y] = idx;

                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if (OOB(nx, ny) || vis[nx][ny] || board[nx][ny] == 0) {
                        continue;
                    }

                    Q.push({nx, ny});

                    vis[nx][ny] = true;
                }
            }

            idx++;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    island();

    for (int i = 0; i < n; i++) {
        fill(dist[i], dist[i] + n, -1);
    }

    queue<pair<int, int>> Q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] != 0) {
                dist[i][j] = 0;
                Q.push({i, j});
            }
        }
    }

    int ans = 999999;

    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (OOB(nx, ny) || board[nx][ny] == board[cur.X][cur.Y]) {
                continue;
            }

            if (board[nx][ny] != 0) {
                ans = min(ans, dist[nx][ny] + dist[cur.X][cur.Y]);
            } else {
                board[nx][ny] = board[cur.X][cur.Y];
                dist[nx][ny]  = dist[cur.X][cur.Y] + 1;
                Q.push({nx, ny});
            }
        }
    }

    cout << ans;

    return 0;
}