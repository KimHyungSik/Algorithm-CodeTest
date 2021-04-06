// 이분 탐색 을 dfs로 구현하여 문제 해결

#include <iostream>
#include <cstring>
#include <vector>
#define MAXV 20001

using namespace std;

int n, m;   // 정점의 개수, 간선의 개수
int visited[MAXV];

void dfs(int start, int col, vector<int> graph[MAXV]){
    visited[start] = col;
    for(int i = 0; i < graph[start].size() ;i++){
        if(visited[graph[start][i]] == -1){
            dfs(graph[start][i], !col, graph);
        }
    }
}

bool searchGraph(vector<int> graph[MAXV]){
    for(int i = 1; i <= n; i++){
        for(int x : graph[i]){
            // 인접 노드가 자신과 같은 색인경우 이분 그래프가 아니다
            if(visited[i] == visited[x]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int t;
    cin >> t;
    
    while(t--){
        vector<int> graph[MAXV];
        memset(visited, -1, sizeof(visited)); // 방문했는지 확인
        cin >> n >> m;
        
        for(int i = 0; i < m; i++)
        {
            int v, e;
            cin >> v >> e;
            graph[v].push_back(e);
            graph[e].push_back(v);
        }
        for(int i = 1; i <= n; i++){
            if(visited[i] == -1){
                dfs(i, 0, graph);
            }
        }
        
//        for(int i = 1; i <= n; i++)
//        cout << visited[i] << " ";
//        cout << endl;
        if(searchGraph(graph)){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    
}
