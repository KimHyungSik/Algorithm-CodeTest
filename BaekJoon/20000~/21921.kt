import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val (N, X) = readLine()!!.split(" ").map { it.toInt() }
    val arr = IntArray(N)

    readLine()!!.split(" ").mapIndexed { index, s ->
        arr[index] = s.toInt()
    }

    var visitors = arr.filterIndexed { index, i -> index < X }.sum()
    var dayCount = 1
    var L = 0
    var R = X
    var tempVisitors = visitors
    while (R < N) {
        tempVisitors -= arr[L]
        tempVisitors += arr[R]
        if (tempVisitors > visitors) {
            visitors = tempVisitors
            dayCount = 0
        }
        if (tempVisitors == visitors) {
            dayCount++
        }
        L++
        R++
    }
    if(visitors == 0){
        print("SAD")
        return
    }
    println(visitors)
    println(dayCount)
}
