class Solution {

    data class UserDb(
        var reportCount: Int,
        var reportTo: MutableSet<String>
    )

    fun solution(id_list: Array<String>, report: Array<String>, k: Int): IntArray {
        var answer = IntArray(id_list.size)
        val userDB = mutableMapOf<String, UserDb>()

        id_list.forEach {
            userDB[it] = UserDb(0, mutableSetOf())
        }

        report.forEach {
            val (from, to) = it.split(" ")
            userDB[from]?.let {
                if (!it.reportTo.contains(to)) {
                    it.reportTo.add(to)
                    userDB[to]!!.reportCount += 1
                }
            }
        }
        var index = 0
        userDB.forEach { t, u ->
            var mail = 0
            u.reportTo.forEach {
                if (userDB[it]!!.reportCount >= k) mail += 1
            }
            answer[index] = mail
            index += 1
        }

        return answer
    }
}
