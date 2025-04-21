#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n , m;
int board[1002][1002];
int dist[1002][1002];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

template<size_t R, size_t C>
void printarray(const int (&array)[R][C], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << array[i][j] << ' ';
        }
        if(i < rows - 1) {
            cout << endl;
        }  
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    queue<pair<int,int> > Q;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
        cin >> board[i][j];
        if(board[i][j] == 1){
            Q.push({i,j});
        }   
        if(board[i][j] == 0){
            dist[i][j] = -1;
        } 
        }
    }

    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(dist[nx][ny] >= 0) continue;
        dist[nx][ny] = dist[cur.X][cur.Y]+1;
        Q.push({nx,ny});
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
        if(dist[i][j] == -1){
            cout << -1;
            return 0;
        }
        ans = max(ans, dist[i][j]);
        }
    }
    
    cout << ans;

    return 0;
}