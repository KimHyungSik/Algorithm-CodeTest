class Solution {
    val INF = 5000000
    val Dist = Array(201){IntArray(201) }

    fun solution(n: Int, s: Int, a: Int, b: Int, fares: Array<IntArray>): Int {
        var answer: Int = INF

        for(i in 1..200){
            for(j in 1..200){
                if(i == j)Dist[i][j] = 0
                else Dist[i][j] = INF
            }
        }

        for(arr in fares){
            Dist[arr[0]][arr[1]] = arr[2]
            Dist[arr[1]][arr[0]] = arr[2]
        }

        for(i in 1..n){
            for(j in 1..n){
                for(k in 1..n){
                    if(Dist[j][k] > Dist[j][i] + Dist[i][k]){
                        Dist[j][k] = Dist[j][i] + Dist[i][k]
                    }
                }
            }
        }

        for(i in 1..n){
            if(answer > Dist[s][i] + Dist[i][a] + Dist[i][b]){
                answer = Dist[s][i] + Dist[i][a] + Dist[i][b]
            }
        }

        return answer
    }
}
