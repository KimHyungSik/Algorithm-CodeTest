import java.util.*
import kotlin.collections.HashMap

data class Question(
    val num: Int,
    val difficulty: Int
) : Comparable<Question> {
    override fun toString(): String {
        return "${this.num}"
    }
    override fun compareTo(other: Question): Int {
        return if(this.difficulty != other.difficulty) other.difficulty - this.difficulty else  other.num - this.num
    }

}

fun main(): Unit = with(Scanner(System.`in`)) {
    val ts = TreeSet<Question>()
    val hm = HashMap<Int, Int>()
    val N = readLine()!!.toInt()

    for (n in 0 until N) {
        val (P, L) = readLine()!!.split(" ").map { it.toInt() }
        ts.add(Question(P, L))
        hm[P] = L
    }

    val M = readLine()!!.toInt()
    val s = Scanner(System.`in`)
    for (n in 0 until M) {
        val P = s.next()
        val L = s.next().toInt()
        when (P) {
            "recommend" -> {
                if (L == 1) {
                    println(ts.first())
                } else {
                    println(ts.last())
                }
            }
            "add" -> {
                val R = s.next().toInt()
                ts.add(Question(L, R))
                hm[L] = R
            }
            "solved" -> {
                ts.remove(Question(L, hm[L]!!.toInt()))
                hm.remove(L)
            }
        }
    }
}
