class Solution {
    var answer = 0
    fun BFS(numbers: IntArray, target: Int, index: Int, current: Int){
        if(index == numbers.size){
            if(current == target) answer += 1
            return
        }
        BFS(numbers, target, index + 1, current + numbers[index])
        BFS(numbers, target, index + 1, current - numbers[index])
    }
    
    fun solution(numbers: IntArray, target: Int): Int {
        
        BFS(numbers, target, 0, 0)
        
        return answer
    }
}
