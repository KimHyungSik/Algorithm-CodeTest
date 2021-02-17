#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int N, M;
int lap[9][9];
int visited[9][9];
int result = 0;
int one = 0;
deque<int>X;
deque<int>Y;

void Vbfs() {
    int count = 0;
    deque<int>Qx;
    deque<int>Qy;
    for(int i : X){
      Qx.push_back(i);
    }
    for(int j : Y){
      Qy.push_back(j);
    }
    while (!Qx.empty()) {
        int x = Qx.front();
        Qx.pop_front();
        int y = Qy.front();
        Qy.pop_front();
        if(lap[x][y] == 0)
            lap[x][y] = 3;
        if (x > 0) {
            if (lap[x - 1][y] == 0) {
                Qx.push_back(x - 1);
                Qy.push_back(y);
            }
        }
        if (y > 0) {
            if (lap[x][y - 1] == 0) {
                Qx.push_back(x);
                Qy.push_back(y - 1);
            }
        }
        if (x < N) {
            if (lap[x + 1][y] == 0) {
                Qx.push_back(x + 1);
                Qy.push_back(y);
            }
        }
        if (y < M) {
            if (lap[x][y + 1] == 0) {
                Qx.push_back(x);
                Qy.push_back(y + 1);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (lap[i][j] == 0) {
                count++;
            }if(lap[i][j] == 3) {
              lap[i][j] = 0;
            }
        }
    }

    result = result > count ? result : count;
  return;
}

void dfs(int count) {
    if (count == 3) {
        Vbfs();
        return;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (lap[i][j] == 0) {
                lap[i][j] = 4;
                dfs(count+1);
                lap[i][j] = 0;
            }
        }
    }
}

int main() {

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &lap[i][j]);
            if (lap[i][j] == 2) {
                X.push_back(i);
                Y.push_back(j);
            }
        }
    }


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (lap[i][j] == 0) {
                lap[i][j] = 4;
                dfs(1);
                lap[i][j] = 0;
            }
        }
    }

    printf("%d", result);
    return 0;
}