import java.io.BufferedReader
import java.io.InputStreamReader

val directions = listOf(
    Pair(-1, 0),  // 위로 이동
    Pair(1, 0),   // 아래로 이동
    Pair(0, -1),  // 왼쪽으로 이동
    Pair(0, 1)    // 오른쪽으로 이동
)

lateinit var map: Array<IntArray>
lateinit var dpMap: Array<IntArray>
var N = 0
var M = 0

fun canMove(currentHeight: Int, x: Int, y: Int): Boolean {
    if (y < 0 || y >= N) return false
    if (x < 0 || x >= M) return false
    return currentHeight > map[y][x]
}

fun dfs(x: Int, y: Int): Int {
    if (x == M - 1 && y == N - 1) return 1
    if (dpMap[y][x] != -1) return dpMap[y][x]

    var paths = 0
    for (direction in directions) {
        val nextX = x + direction.first
        val nextY = y + direction.second
        if (canMove(map[y][x], nextX, nextY)) {
            paths += dfs(nextX, nextY)
        }
    }

    dpMap[y][x] = paths
    return paths
}

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val (n, m) = readLine().split(" ").map { it.toInt() }
    N = n
    M = m
    map = Array(N) { IntArray(M) { 0 } }
    dpMap = Array(N) { IntArray(M) { -1 } }

    for (i in 0 until N) {
        readLine().split(" ").map { it.toInt() }.forEachIndexed { j, value ->
            map[i][j] = value
        }
    }

    println(dfs(0, 0))
}
