import java.util.*

class Solution {
    fun solution(p: String): String {
        if(p.isEmpty()) return p
        val stack = Stack<Char>()
        var open = 0
        var close = 0
        var index = 0
        var flage = true
        for(c in p){
            if (c == '('){
                open += 1
                stack.push(c)
            }
            else{
                close += 1
                if(stack.isEmpty())
                    flage = false
                else
                    stack.pop()
            }
            index += 1
            if(open == close){
                break
            }
        }
        var u = p.substring(0 until index)
        var v = p.substring(index until p.length)
        if(flage){
            u += solution(v)
            return u
        }

        var answer = "("
        answer += solution(v)
        answer+=')'
        u = u.removeRange(0..0)
        u = u.removeRange(u.length-1 until u.length)

        for(c in u){
            if(c =='(')answer+=')'
            else answer+='('
        }

        return answer
    }
}
