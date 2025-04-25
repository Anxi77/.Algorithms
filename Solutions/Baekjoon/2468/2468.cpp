#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int board[102][102];
int vis[102][102];

int n, maxheight, maxcnt;

void bfs(int i, int j, int height) {
    queue<pair<int, int>> q;
    vis[i][j] = 1;
    q.push({i, j});
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;

            if (vis[nx][ny] == 0 && board[nx][ny] > height) {
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
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
            maxheight = max(board[i][j], maxheight);
        }
    }

    for (int height = 0; height < maxheight; height++) {
        for (int i = 0; i < n; i++) {
            fill(vis[i], vis[i] + n, 0);
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] > height && vis[i][j] == 0) {
                    bfs(i, j, height);
                    cnt++;
                }
            }
        }
        maxcnt = max(cnt, maxcnt);
    }

    cout << maxcnt;
}