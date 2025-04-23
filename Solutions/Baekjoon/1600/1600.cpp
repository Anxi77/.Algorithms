#include <bits/stdc++.h>
using namespace std;

const int INF   = 0x7f7f7f7f;
const int MAX_N = 202;
const int MAX_K = 32;

int board[MAX_N][MAX_N];
int vis[MAX_K][MAX_N][MAX_N];

int dmx[4] = {0, 0, 1, -1};
int dmy[4] = {1, -1, 0, 0};
int dkx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dky[8] = {1, -1, 2, -2, 2, -2, 1, -1};

queue<tuple<int, int, int>> Q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K, W, H;
    cin >> K >> W >> H;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> board[i][j];
        }
    }

    Q.push({0, 0, 0});
    vis[0][0][0] = 1;

    while (!Q.empty()) {
        int k, x, y;
        tie(k, x, y) = Q.front();
        Q.pop();

        if (k < K) {
            for (int i = 0; i < 8; i++) {
                int nx = x + dkx[i], ny = y + dky[i];

                if (nx < 0 || ny < 0 || nx >= H || ny >= W)
                    continue;
                if (board[nx][ny] == 1)
                    continue;
                if (vis[k + 1][nx][ny])
                    continue;

                vis[k + 1][nx][ny] = vis[k][x][y] + 1;
                Q.push({k + 1, nx, ny});
            }
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dmx[i], ny = y + dmy[i];

            if (nx < 0 || ny < 0 || nx >= H || ny >= W)
                continue;
            if (board[nx][ny] == 1)
                continue;
            if (vis[k][nx][ny])
                continue;

            vis[k][nx][ny] = vis[k][x][y] + 1;

            Q.push({k, nx, ny});
        }
    }

    int ans = INF;

    for (int i = 0; i <= K; i++) {
        if (vis[i][H - 1][W - 1]) {
            ans = min(ans, vis[i][H - 1][W - 1]);
        }
    }

    cout << (ans == INF ? -1 : ans - 1);
}