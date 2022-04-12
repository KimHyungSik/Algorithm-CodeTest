import kotlin.math.max

class Solution {
    fun solution(distance: Int, rocks: IntArray, n: Int): Int {
        rocks.sort()
        return binerySearch(distance, rocks, n)
    }

    fun binerySearch(distance: Int, rocks: IntArray, n: Int): Int{
        var ans = 0L
        var left = 1L
        var right = distance.toLong()
        var mid = 0L
        while(left <= right){
            var cnt = 0
            var prev = 0
            mid = (left + right) / 2
            for(r in rocks){
                if(r - prev < mid) cnt += 1
                else prev = r
            }
            if(distance - prev < mid) cnt += 1
            if(cnt <= n){
                ans = max(mid, ans)
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans.toInt()
    }
}
