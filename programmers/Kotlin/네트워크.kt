class Solution {

    var answer = 0
    val booleanArray = BooleanArray(201) { false }

    fun BFS(computers: Array<IntArray>, index :Int){
        for(n in computers[index].indices){
            if(booleanArray[n]) continue
            if(computers[index][n] != 1) continue
            booleanArray[n] = true
            BFS(computers, n)
        }
    }

    fun solution(n: Int, computers: Array<IntArray>): Int {
        for(i in computers.indices){
            if(!booleanArray[i]){
                BFS(computers, i)
                answer += 1
            }
        }
        return answer
    }
}
