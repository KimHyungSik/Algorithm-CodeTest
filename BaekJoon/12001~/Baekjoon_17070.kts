import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

val map = Array<IntArray>(18){IntArray(18)}
var n = 0
var answer = 0
fun DFS(mode: Int, x: Int, y:Int){
    if(x >= n || y >= n) return
    if(x == n-1 && y == n-1){
        answer += 1
        return
    }
    when(mode){
        // 가로
        1 ->{
            if(map[y][x+1] == 0) DFS(1, x+1, y)
            if(map[y][x+1] == 0 && map[y+1][x] == 0 && map[y+1][x+1] == 0)DFS(2, x+1, y+1)
        }
        // 대각선
        2->{
            if(map[y][x+1] == 0 && map[y+1][x] == 0 && map[y+1][x+1] == 0)DFS(2, x+1, y+1)
            if(map[y][x+1] == 0) DFS(1, x+1, y)
            if(map[y+1][x] == 0) DFS(3, x, y+1)
        }
        // 세로
        3->{
            if(map[y][x+1] == 0 && map[y+1][x] == 0 && map[y+1][x+1] == 0)DFS(2, x+1, y+1)
            if(map[y+1][x] == 0) DFS(3, x, y+1)
        }
    }
}

fun main(){
    val br = BufferedReader(InputStreamReader(System.`in`))
    var st = StringTokenizer(br.readLine())

    n = st.nextToken().toInt()
    for(i in 0 until n)
    {
        var str = br.readLine()
        str = str.replace(" ", "")
        for(j in 0 until str.length){
            map[i][j] = Character.getNumericValue(str[j])
        }
    }
    DFS(1, 1, 0)
    println(answer)
}
