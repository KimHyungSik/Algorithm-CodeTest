import java.util.*

val xY = intArrayOf(1, -1, 0, 0)
val yX = intArrayOf(0, 0, 1, -1)
var N = 0
var M = 0
lateinit var arr: Array<IntArray>
lateinit var result: Array<BooleanArray>
lateinit var visit: Array<Array<BooleanArray>>

fun thing1(dir: Int): Int {
    return if (dir == 0 || dir == 1) -1 else dir
}

fun thing2(dir: Int): Int {
    return if (dir == 2 || dir == 3) -1 else dir
}

fun thing3(dir: Int): Int {
    return when (dir) {
        0 -> 3
        1 -> 2
        2 -> 1
        3 -> 0
        else -> 0
    }
}

fun thing4(dir: Int): Int {
    return when (dir) {
        0 -> 2
        1 -> 3
        2 -> 0
        3 -> 1
        else -> 0
    }
}

fun Solution(x: Int, y: Int, direction: Int) {
    if (x < 0 || x >= M || y < 0 || y >= N) return
//    println("x : $x , y : $y, dir : $direction")
    if(visit[y][x][direction]) return
    visit[y][x][direction] = true
    result[y][x] = true
    val dir: Int = when (arr[y][x]) {
        0 -> {
            direction
        }
        1 -> {
            thing1(direction)
        }
        2 -> {
            thing2(direction)
        }
        3 -> {
            thing3(direction)
        }
        4 -> {
            thing4(direction)
        }
        9 -> {
            direction
        }
        else -> -1
    }
    if (dir == -1) return
    Solution(x + xY[dir], y + yX[dir], dir)
}

fun main() = with(Scanner(System.`in`)) {
    val NM = readLine()!!.split(" ").map { it.toInt() }
    N = NM[0]
    M = NM[1]
    arr = Array(N) { IntArray(M) }
    result = Array(N) { BooleanArray(M) { false } }
    visit = Array(N) { Array(M) { booleanArrayOf(false, false, false, false) } }
    val air = mutableListOf<Pair<Int, Int>>()
    for (n in 0 until N) {
        readLine()!!.split(" ").mapIndexed { index, s ->
            arr[n][index] = s.toInt()
            if (arr[n][index] == 9)
                air.add(Pair(n, index))
        }
    }

    for (n in air) {
        for (m in 0..3)
            Solution(n.second, n.first, m)
    }

    var count = 0

    result.map {
        it.filter { it }.map {
            count++
        }
    }

    print(count)

}
