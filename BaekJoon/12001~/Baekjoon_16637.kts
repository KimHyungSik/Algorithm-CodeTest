import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.max

var answer:Int? = null

fun op(a: Int, b: Char, c: Int):Int{
    when(b){
        '+'->return a + c
        '-'->return a - c
        '*'->return a * c
    }
    return 0
}

fun DFS(index: Int, result: Int, p: String){
    if(index > p.length-1){
        if(answer == null) answer = result
        answer = max(answer!!, result)
        return
    }

    var c = '+'
    if(index > 0) c = p[index-1]

    if(index + 2 < p.length){
        val temp = op(Character.getNumericValue(p[index]), p[index+1], Character.getNumericValue(p[index+2]))
        DFS(index+4, op(result, c, temp), p)
    }
    DFS(index+2, op(result, c, Character.getNumericValue(p[index])),p)
}

fun main(){
    val br = BufferedReader(InputStreamReader(System.`in`))
    var st = StringTokenizer(br.readLine())

    val N = st.nextToken().toInt()
    st = StringTokenizer(br.readLine())
    val str = st.nextToken()
    DFS(0, 0, str)
    println(answer)
}
