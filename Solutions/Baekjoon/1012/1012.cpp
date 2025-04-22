#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int board[51][51];
bool vis[51][51];

int m, n, k;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

queue<pair<int, int>> Q;

void bfs(int y, int x) {
  vis[y][x] = true;

  Q.push({y, x});

  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();

    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];

      if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
        continue;
      }

      if (vis[nx][ny] || board[nx][ny] != 1) {
        continue;
      }

      vis[nx][ny] = true;

      Q.push({nx, ny});
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;

  cin >> t;

  while (t--) {
    cin >> m >> n >> k;
    int x, y;
    for (int i = 0; i < k; i++) {
      cin >> x >> y;
      board[y][x] = 1;
    }

    int res = 0;

    for (int y = 0; y < n; y++) {
      for (int x = 0; x < m; x++) {
        if (board[y][x] == 1 && !vis[y][x]) {
          bfs(y, x);
          res++;
        }
      }
    }

    cout << res << "\n";

    for (int i = 0; i < n; i++) {
      fill(board[i], board[i] + m, 0);
      fill(vis[i], vis[i] + m, false);
    }
  }

  return 0;
}
