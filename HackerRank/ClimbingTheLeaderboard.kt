package hacker_rank

import java.io.*
import java.math.*
import java.security.*
import java.text.*
import java.util.*
import java.util.concurrent.*
import java.util.function.*
import java.util.regex.*
import java.util.stream.*
import kotlin.collections.*
import kotlin.comparisons.*
import kotlin.io.*
import kotlin.jvm.*
import kotlin.jvm.functions.*
import kotlin.jvm.internal.*
import kotlin.ranges.*
import kotlin.sequences.*
import kotlin.text.*

/*
 * Complete the 'climbingLeaderboard' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY ranked
 *  2. INTEGER_ARRAY player
 */

fun binarySearch(
    value: Int,
    arr: Array<Int>
): Int {
    var low = 0
    var high = arr.lastIndex
    var mid = 0

    while (low < high) {
        mid = (low + high) / 2
        if (arr[mid] <= value) {
            low = mid + 1
        } else {
            high = mid
        }
    }
    return high
}

fun climbingLeaderboard(ranked: Array<Int>, player: Array<Int>): Array<Int> {

    val result = Array(player.size) { 0 }
    val rank = Array<Int>(ranked.size) { 0 }

    rank[0] = 1

    ranked.mapIndexed { index, i ->
        if (index != 0) {
            if (i < ranked[index - 1]) rank[index] = rank[index - 1] + 1
            else rank[index] = rank[index - 1]
        }
    }

    ranked.reverse()
    rank.reverse()

    player.mapIndexed { index, p ->
        val i = binarySearch(p, ranked)
        if(p == ranked[i]) result[index] = rank[i]
        else if(p > ranked[i]){
            if(rank[i] == 1) result[index] = 1
            else result[index] = rank[i]
        }
        else result[index] = rank[i] + 1
    }

    return result
}

fun main(args: Array<String>) {
    val rankedCount = readLine()!!.trim().toInt()

    val ranked = readLine()!!.trimEnd().split(" ").map { it.toInt() }.toTypedArray()

    val playerCount = readLine()!!.trim().toInt()

    val player = readLine()!!.trimEnd().split(" ").map { it.toInt() }.toTypedArray()

    val result = climbingLeaderboard(ranked, player)

    println(result.joinToString("\n"))
}
