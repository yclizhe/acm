#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int mins, dx, dy, N;
bool board[305][305];
int option[8][2] = {{1,2},{-1,2},{1,-2},{-1,-2},{2,1},{-2,1},{2,-1},{-2,-1}};

inline bool next(int x, int y, int &nx, int &ny, int op[]) {
    nx = x + op[0];
    ny = y + op[1];
    if(nx<0 || ny<0 || nx>N-1 || ny>N-1)
        return false;
    else
        return true;
}

void dfs(int depth, int x, int y) {
    if(x==dx && y==dy) {
        mins = mins<depth?mins:depth;
        return;
    }
    if(depth > mins)
        return;
    for(int i=0; i<8; i++) {
        int nx, ny;
        if(!next(x,y,nx,ny,option[i]))
            continue;
        if(board[nx][ny])
            continue;
        board[nx][ny] = true;
        dfs(depth+1, nx, ny);
        board[nx][ny] = false;
    }

}

struct state{
    int x,y;
    int depth;
    state(int a, int b, int d) {
        x = a;
        y = b;
        depth = d;
    }
};
void bfs(int x, int y) {
    state s0(x,y,0);
    queue<state> Q;
    Q.push(s0);
    while(!Q.empty()) {
        state s = Q.front();
        Q.pop();
        if(s.x == dx && s.y==dy) {
            mins = s.depth;
            return;
        }

        board[s.x][s.y] = true;
        for(int i=0; i<8; i++) {
            int nx,ny;
            if(!next(s.x,s.y,nx,ny,option[i]))
                continue;
            if(board[nx][ny])
                continue;
            state ns(nx,ny,s.depth+1);
            Q.push(ns);
            board[nx][ny] = true;
        }
    }
}
int main() {
    int n;
    cin >> n;
    while(n--) {
        memset(board,0,sizeof(board));
        mins = 1<<30;
        cin >> N;
        int x,y;
        cin >> x >> y;
        cin >> dx >> dy;
//        dfs(0,x,y);
        bfs(x,y);
        cout << mins << endl;
    }
}
