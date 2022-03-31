import java.util.*
import kotlin.math.max

fun main() = with(Scanner(System.`in`)) {
    val str = readLine()!!
    val strsize = readLine()!!.toInt()
    val strlist = Array<Pair<String, Int>>(strsize){Pair("",0)}
    for(n in 0 until strsize){
        val (s, i)  = readLine()!!.split(" ")
        strlist[n] = Pair(s, i.toInt())
    }
    val result = IntArray(str.length+1){0}
    for(index in 0 until result.size){
        if(index != 0)
            result[index] = max(result[index], result[index-1] + 1)
        for(n in strlist){
            if(index +n.first.length> str.length )continue
            if(str.substring(index, index+ n.first.length) == n.first){
                result[index+ n.first.length] = max(result[index+ n.first.length], result[index] + n.second)
            }
        }
    }
    print(result.last())
}
