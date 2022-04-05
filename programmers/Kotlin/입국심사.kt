class Solution {
    fun solution(n: Int, times: IntArray): Long {
        return binarySearch(times, n)
    }

    fun binarySearch(array: IntArray, n: Int): Long{
        var left = 0L
        var right : Long = array.maxOrNull()!!.toLong()* n
        var mid = 0L
        while(left <= right){
            mid = (left + right) / 2
            if(isPassed(array, mid, n)){
                right = mid - 1
            }else{
                left = mid + 1
            }
        }
        return right + 1
    }

    fun isPassed(array: IntArray, mid: Long, n: Int): Boolean{
        var passed = 0L
        for(n in array){
            passed += mid/n
        }
        return passed >= n
    }
}
