class Solution {
    var answer : ArrayList<String> = arrayListOf()
    val booleanArray = BooleanArray(10001){false}
    val hashSet = HashSet<String>()

    fun comparator(arrayList: ArrayList<String>,arrayList2: ArrayList<String>): ArrayList<String>{
        val list = hashSet.toList().sorted()
        for(n in arrayList.indices){
            val str1 = list.indexOf(arrayList[n])
            val str2 = list.indexOf(arrayList2[n])
            if(str1 > str2) return arrayList2
            if(str1 < str2) return arrayList
        }
        return arrayList
    }

    fun DFS(tickets: Array<Array<String>>, now: String, counter: Int, result: ArrayList<String>){
        if(counter == tickets.size + 1){
            if(answer.isEmpty()) answer = result
            answer = comparator(answer, result)
            return
        }
        for(n in tickets.indices){
            if(!booleanArray[n] && tickets[n][0] == now){
                booleanArray[n] = true
                DFS(tickets, tickets[n][1], counter + 1, (result + tickets[n][1]) as ArrayList<String>)
                booleanArray[n] = false
            }
        }
    }
    fun solution(tickets: Array<Array<String>>): Array<String> {
        for(n in tickets){
            hashSet.add(n[0])
            hashSet.add(n[1])
        }
        for(n in tickets){
            if(n[0] == "ICN")
                DFS(tickets, n[0], 1, arrayListOf(n[0]))
        }

        return answer.toTypedArray()
    }
}
