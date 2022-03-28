import java.util.*

val INF = 10000000

fun main() = with(Scanner(System.`in`)) {
    val (N, M) = readLine()!!.split(" ").map { it.toInt() }
    val graph = Array(N + 1) { IntArray(N + 1) { INF } }

    for (n in 1..M) {
        val (A, B, T) = readLine()!!.split(" ").map { it.toInt() }
        graph[A][B] = T
    }

    for (n in 1..N) graph[n][n] = 0

    val K = readLine()!!.map { it.toInt() }
    val C = readLine()!!.split(" ").map { it.toInt() }

    for (k in 1..N) {
        for (i in 1..N) {
            for (j in 1..N) {
                graph[i][j] = Math.min(graph[i][k] + graph[k][j], graph[i][j])
            }
        }
    }

    var maxCost = INF
    val result = mutableListOf<Int>()

    for(n in 1..N){
        var cost = 0
        for(m in C){
            cost = Math.max(cost, graph[m][n] + graph[n][m])
        }
        if(maxCost == cost) result.add(n)
        if(maxCost > cost){
            result.clear()
            result.add(n)
            maxCost = cost
        }
    }
    result.forEach {
        print("$it ")
    }
}
