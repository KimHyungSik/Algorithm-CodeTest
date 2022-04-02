import java.lang.Integer.max
import java.util.*


fun main() = with(Scanner(System.`in`)) {
    val N = readLine()!!.toInt()
    val list = readLine()!!.split(" ").map { it.toInt() }
    //연산자의 개수 P와 곱하기 연산자의 개수 Q
    val (P, Q) = readLine()!!.split(" ").map { it.toInt() }
    var result = 0

    fun BFS(index: Int, array: IntArray){
        if(index == N){
            for( n in array) {
                if(n == 0) return
            }
            var a = 1
            array.forEach {
                a *= it
            }
            result = max(result, a)
            return
        }
        for( n in 0..Q){
            array[n] = array[n] + list[index]
            BFS(index+1, array)
            array[n]  = array[n] - list[index]
        }
    }
    BFS(0, IntArray(Q+1))
    println(result)
}
