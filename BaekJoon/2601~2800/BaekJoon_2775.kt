import java.io.BufferedReader
import java.io.InputStreamReader

/**
 * 평소 반상회에 참석하는 것을 좋아하는 주희는 이번 기회에 부녀회장이 되고 싶어 각 층의 사람들을 불러 모아 반상회를 주최하려고 한다.
 *
 * 이 아파트에 거주를 하려면 조건이 있는데, “a층의 b호에 살려면 자신의 아래(a-1)층의 1호부터 b호까지 사람들의 수의 합만큼 사람들을 데려와 살아야 한다” 는 계약 조항을 꼭 지키고 들어와야 한다.
 *
 * 아파트에 비어있는 집은 없고 모든 거주민들이 이 계약 조건을 지키고 왔다고 가정했을 때, 주어지는 양의 정수 k와 n에 대해 k층에 n호에는 몇 명이 살고 있는지 출력하라. 단, 아파트에는 0층부터 있고 각층에는 1호부터 있으며, 0층의 i호에는 i명이 산다.
 *
 * 첫 번째 줄에 Test case의 수 T가 주어진다. 그리고 각각의 케이스마다 입력으로 첫 번째 줄에 정수 k, 두 번째 줄에 정수 n이 주어진다
 *
 * input        output
 * 2            6
 * 1            10
 * 3
 * 2
 * 3
 */

fun main() {
    val MAX_N = 14
    val br = BufferedReader(InputStreamReader(System.`in`))

    val testCase = br.readLine().toInt()

    val firstFloor = IntArray(MAX_N) { it + 1 }
    val apartment = mutableListOf(firstFloor)

    repeat(testCase) {
        val k = br.readLine().toInt()
        val n = br.readLine().toInt()

        while (apartment.size < k + 1) {
            var tempN = 0
            val nextFloor = mutableListOf<Int>()

            for (i in 0 until MAX_N) {
                val currentN = tempN + apartment[apartment.size - 1][i]
                tempN = currentN
                nextFloor.add(currentN)
            }
            apartment.add(nextFloor.toIntArray())
        }
        println("${apartment[k][n - 1]}")
    }
}
