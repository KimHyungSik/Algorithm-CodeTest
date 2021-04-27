import java.lang.StringBuilder

class Solution {
    private fun check(ch: Char): Boolean{
        return ch.isLetterOrDigit() || ch == '-' || ch == '_' || ch == '.'
    }

    fun solution(new_id: String): String {
        var answer = StringBuilder("")
        var flag = false
        for(ch in new_id) {
            if (!check(ch)) continue;
            flag = if (ch == '.') {
                if (flag) continue
                true
            } else {
                false
            }
            answer.append(ch.toLowerCase())
        }

        if(answer.isNotEmpty())
            if(answer[0] == '.')
                answer.deleteCharAt(0)

        if(answer.isNotEmpty())
            if(answer[answer.length - 1] == '.')
                answer.deleteCharAt(answer.length - 1)

        if(answer.isEmpty())  answer.append("a")

        if(answer.length > 15) {
            answer = StringBuilder(answer.substring(0..14))
            if(answer[answer.length - 1] == '.')
                answer.deleteCharAt(answer.length - 1)
        }

        if(answer.length < 3){
            val temp = answer[answer.length-1]
            while(answer.length < 3){
                answer.append(temp)
            }
        }

        return answer.toString()
    }
}
