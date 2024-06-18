import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.min

/**
 * n가지 종류의 동전이 있다.
 * 이 동전들을 적당히 사용해서, 그 가치의 합이 k원이 되도록 하고 싶다.
 * 그러면서 동전의 개수가 최소가 되도록 하려고 한다. 각각의 동전은 몇 개라도 사용할 수 있다.
 *
 * 첫째 줄에 n, k가 주어진다. (1 ≤ n ≤ 100, 1 ≤ k ≤ 10,000) 다음 n개의 줄에는 각각의 동전의 가치가 주어진다.
 * 동전의 가치는 100,000보다 작거나 같은 자연수이다. 가치가 같은 동전이 여러 번 주어질 수도 있다.
 */

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val (n, k) = readLine().split(" ").map { it.toInt() }
    val array = IntArray(n) { -1 }
    val results = IntArray(10001) { -1 }
    for (i in 0 until n) {
        val value = readLine().toInt()
        if (value <= k){
            array[i] = value
            results[value] = 1
        }
    }
    for (i in 0..k) {
        val result = results[i]
        if (result != -1) {
            for (j in 0 until n) {
                val value = array[j]
                val nextTemp = i + value
                if (nextTemp <= k) {
                    results[nextTemp] =
                        min(if (results[nextTemp] == -1) Int.MAX_VALUE else results[nextTemp], results[i] + 1)
                }
            }
        }
    }

    println(results[k])
}
