// 순수하게 구현 해서 문제 해결
// 다음 부터는 DFS같은 탐색 알고리즘을
// 사용하자 ㅎㅎ

#include <iostream>
#include <cstring>
#define MAXNM 52
 
using namespace std;

int grid[MAXNM][MAXNM];
int n, m;
int x, y, pos;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);

    cin >> n >> m;
    cin >> y >> x >> pos;
    x++;
    y++;
    memset(grid, 1, sizeof(grid));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }

    int result = 0;

    if (grid[y][x] == 0) {
        grid[y][x] = 2;
        result++;
    }
    

    int tx[] = { 1, -1, 0, 0 };
    int ty[] = { 0, 0, 1, -1 };
    bool whFlag = true;

    while (whFlag) {
        bool flag = false;

        // 모든방향이 막혀있는지 확인
        for (int i = 0; i < 4; i++) {
            if (!grid[y + ty[i]][x + tx[i]]) { 
                flag = true;
                break; 
            }
        }

        // 현재 바라보는 방향을 확인
        switch (pos) {
        case 0: // 북
            pos = 3;
            // 왼쪽 방향이 청소 되지 않았고 
            // 벽이 아니라면 외쪽으로 회전후 전진
            if (!grid[y][x - 1]) {
                grid[y][x - 1] = 2;
                x--;
                result++;
            }
            // 모든 방향이 막혔을 경우
            if (!flag) {
                // 뒤로 갈수 있
                if (grid[y + 1][x] == 2) {
                    y++;
                    pos = 0;
                }else //뒤로갈수 없는 경우
                    whFlag = false;
            }
            break;
        case 1: // 동
            pos = 0;
            if (!grid[y-1][x]) {
                grid[y-1][x] = 2;
                y--;
                result++;
            }
            if (!flag) {
                if (grid[y][x-1] == 2) {
                    x--;
                    pos = 1;
                }else
                    whFlag = false;
            }
            break;
        case 2: // 남
            pos = 1;
            if (!grid[y][x + 1]) {
                grid[y][x + 1] = 2;
                x++;
                result++;
            }
            if (!flag) {
                if (grid[y - 1][x] == 2) {
                    y--;
                    pos = 2;
                }else
                    whFlag = false;
            }
            break;
        case 3: // 서
            pos = 2;
            if (!grid[y+1][x]) {
                grid[y+1][x] = 2;
                y++;
                result++;
            }
            if (!flag) {
                if (grid[y][x+1] == 2) {
                    x++;
                    pos = 3;
                }
                else {
                    whFlag = false;
                }
            }
        }
    }
    cout << result << '\n';
    return 0;
}