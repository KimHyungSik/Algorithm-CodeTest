import java.lang.Integer.min

class Solution {
    val booleanArray = BooleanArray(50)
    var answer = Int.MAX_VALUE
    var checker = false

    fun comparison(str1: String, str2: String): Boolean{
        var check = false
        str1.forEachIndexed { index, c ->
            if(c != str2[index]){
                if(!check) check = true
                else return false
            }
        }
        return true
    }

    fun BFS(currentStr: String, target: String ,counter: Int, words: Array<String>){
        if(currentStr == target){
            checker = true
            answer = min(counter,answer)
            return
        }
        for (n in words.indices){
            if(comparison(words[n], currentStr) && !booleanArray[n]){
                booleanArray[n] = true
                BFS(words[n], target, counter + 1, words)
                booleanArray[n] = false
            }
        }
    }

    fun solution(begin: String, target: String, words: Array<String>): Int {
        BFS(begin, target, 0, words)
        if(!checker) return 0
        return answer
    }
}
