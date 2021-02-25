// �����ϰ� ���� �ؼ� ���� �ذ�
// ���� ���ʹ� DFS���� Ž�� �˰�����
// ������� ����

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

        // �������� �����ִ��� Ȯ��
        for (int i = 0; i < 4; i++) {
            if (!grid[y + ty[i]][x + tx[i]]) { 
                flag = true;
                break; 
            }
        }

        // ���� �ٶ󺸴� ������ Ȯ��
        switch (pos) {
        case 0: // ��
            pos = 3;
            // ���� ������ û�� ���� �ʾҰ� 
            // ���� �ƴ϶�� �������� ȸ���� ����
            if (!grid[y][x - 1]) {
                grid[y][x - 1] = 2;
                x--;
                result++;
            }
            // ��� ������ ������ ���
            if (!flag) {
                // �ڷ� ���� ��
                if (grid[y + 1][x] == 2) {
                    y++;
                    pos = 0;
                }else //�ڷΰ��� ���� ���
                    whFlag = false;
            }
            break;
        case 1: // ��
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
        case 2: // ��
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
        case 3: // ��
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