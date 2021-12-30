import java.util.*


fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    var lambda = { a: Int, b: Int ->
        when {
            a > b -> 1
            a < b -> -1
            else -> 0
        }
    }
    var pq = PriorityQueue(Comparator<Pair<Int, Int>> { a, b ->
        when {
            a.first != b.first -> lambda(a.first, b.first)
            else -> lambda(a.second, b.second)
        }
    })

    val n = nextInt()

    for(i in 0 until n){
        val number = nextInt()
        if(number == 0)
            if(pq.isEmpty())
                println(0)
            else
                println(pq.poll().second)
        else
            pq.add(Pair(Math.abs(number), number))
    }
}
