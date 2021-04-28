class Solution {

    val language = arrayOf("java", "python", "cpp")
    val position = arrayOf("backend", "frontend")
    val career = arrayOf("junior", "senior")
    val food = arrayOf("pizza", "chicken")
    val person = Array(4) { Array(3) { Array(3) { Array(3) { mutableListOf<Int>() } } } }

    fun solution(info: Array<String>, query: Array<String>): IntArray {
        var answer = ArrayList<Int>()

        for (str in info) {
            val arr = str.split(" ")
            val point: Int = arr[4].toInt()

            var l = arrayOf(3, 0)
            var p = arrayOf(2, 0)
            var c = arrayOf(2, 0)
            var f = arrayOf(2, 0)
            language.forEachIndexed { index, value ->
                if (arr[0] == value) {
                    l[1] = index
                }
            }

            position.forEachIndexed { index, value ->
                if (arr[1] == value) {
                    p[1] = index
                }
            }

            career.forEachIndexed { index, value ->
                if (arr[2] == value) {
                    c[1] = index
                }
            }

            food.forEachIndexed { index, value ->
                if (arr[3] == value) {
                    f[1] = index
                }
            }

           for(i in 0..1){
               for(j in 0..1){
                   for(k in 0..1){
                       for(t in 0..1){
                           person[l[i]][p[j]][c[k]][f[t]].add(point)
                           person[l[i]][p[j]][c[k]][f[t]].sort()
                          // println("${l[i]}, ${p[j]}, ${c[k]}, ${f[t]}")
                       }
                   }
               }
           }
            //println()
        }
        //println()
        for(str in query){
            val arr = str.split(" ")
            val point: Int = arr[7].toInt()
            var l = 3
            var p = 2
            var c = 2
            var f = 2
            language.forEachIndexed { index, value ->
                if (arr[0] == value) {
                    l = index
                }
            }

            position.forEachIndexed { index, value ->
                if (arr[2] == value) {
                    p = index
                }
            }

            career.forEachIndexed { index, value ->
                if (arr[4] == value) {
                    c = index
                }
            }

            food.forEachIndexed { index, value ->
                if (arr[6] == value) {
                    f = index
                }
            }
            var count = 0
            //println("$l, $p, $c, $f")

            var st = 0
            var en =person[l][p][c][f].size
            var mid:Int = 0
            while(st < en){
                mid = (st + en) / 2
                if (person[l][p][c][f][mid]  >= point) en = mid
                else st = mid + 1
            }
            answer.add(person[l][p][c][f].size - st)
        }

        return answer.toIntArray()
    }
}
