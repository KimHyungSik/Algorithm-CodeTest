import java.lang.StringBuilder

class Solution {

    private val combination = mutableListOf<MutableMap<String, Int>>()
    private var maxItem = mutableListOf<Int>()

    private fun comb(str: String, pos: Int, combiStr: String) {
        val len = combiStr.length

        if (pos >= str.length) {
            if (len > 1) {
                val value = combination[len][combiStr]
                if (!combination[len].containsKey(combiStr)) {
                    combination[len][combiStr] = 1
                } else {
                    combination[len][combiStr] =  combination[len][combiStr]!! + 1
                    if (maxItem[len] < combination[len][combiStr]!!) {
                        maxItem[len] = combination[len][combiStr]!!
                    }
                }
            }
            return
        }

        val tempStr = StringBuilder(combiStr)

        comb(str, pos + 1, tempStr.toString())
        comb(str, pos + 1, tempStr.append(str[pos]).toString())
    }

    fun solution(orders: Array<String>, course: IntArray): Array<String> {
        var answer: Array<String> = arrayOf<String>()
        for(i in 0..11){
            combination.add(mutableMapOf())
            maxItem.add(0)
        }

        for (str in orders) {
            val arr = str.toCharArray()
            arr.sort()
            comb(arr.joinToString(""), 0, "")
        }

        for (x in course) {
            combination[x].forEach { (str, v) ->
                if (v > 1 && v == maxItem[x])
                    answer += str
            }
        }
        answer.sort()
        return answer
    }
}
