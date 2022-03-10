import java.util.*

fun main() = with(Scanner(System.`in`)) {

    val (N, M) = readLine()!!.split(" ").map { it.toInt() }

    val graph = Array(N + 1){ mutableListOf<Int>() }
    var counter = 0

    for(n in 0 until M){
        val ( A, B ) = readLine()!!.split(" ").map { it.toInt() }
        graph[B].add(A)
    }
    val visit = Array<Boolean>(N+1){false}
    fun DFS(x : Int){
        visit[x] = true
        graph[x].forEachIndexed { index, i ->
            if(!visit[i]){
                counter += 1
                DFS(i)
            }
        }
    }
    val X = readLine()!!.toInt()
    DFS(X)
    print(counter)
}
