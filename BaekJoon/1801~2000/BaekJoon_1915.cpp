#include <iostream>
#define MAXV 1001
using namespace std;

int n, m;
int map[MAXV][MAXV];
int x[4] = {0, 1, 0, 1};
int y[4] = {0, 0, 1, 1};

int main(){
    int result = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%1d", &map[i][j]);
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int min = 0;
            for(int k = 0; k < 4; k++){
                int temp =map[i + y[k]][j + x[k]];
               
                if(!temp){
                    break;
                }
                if(k != 3){
                    if(!min)min = temp;
                    min = min < temp ? min : temp;
                }
                
                if(k == 3){
                    map[i+1][j+1] = min+1;
                }
            }
            result = result > map[i][j] ?result : map[i][j];
        }
    }
    
    printf("%d\n", result * result);
    return 0;
}
