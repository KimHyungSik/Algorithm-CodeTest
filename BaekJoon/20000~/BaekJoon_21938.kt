fun main() = with(Scanner(System.`in`)) {
    val (N, M) = readLine()!!.split(" ").map { it.toInt() }
    val graph = Array(N + 1) { Array(M) { 0 } }
    val visited = Array(N + 1) { Array(M) { false }}
    for (n in 0 until N) {
        val array = readLine()!!.split(" ").map { it.toInt() }
        for (m in 0 until M) {
            val s = m * 3
            val sum = array[s] + array[s + 1] + array[s + 2]
            graph[n][m] = sum / 3
        }
    }

    val T = readLine()!!.toInt()

    val xy = listOf(1, -1, 0, 0)
    val yx = listOf(0, 0, 1, -1)
    var result = 0
    fun BFS(x : Int, y : Int){
        visited[y][x] = true
        for(n in 0..3){
            val curX = x + xy[n]
            val curY = y + yx[n]
            if(curX < 0 || curX >= M || curY < 0 || curY >= N){
                continue
            }
            if(!visited[curY][curX] && graph[curY][curX] >= T){
                BFS(curX, curY)
            }
        }
    }


    for (n in 0 until N) {
        for (m in 0 until M) {
            if(!visited[n][m] && graph[n][m] >= T){
                result += 1
                BFS(m, n)
            }
        }
    }
    println(result)
}
