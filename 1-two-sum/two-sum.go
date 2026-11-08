func twoSum(nums []int, target int) []int {
    ans := []int{-1,-1};
    n := len(nums)
    for i:= 0 ; i < n ; i++{
        for j:= i +1 ; j < n ; j++{
            if nums[i] + nums[j] == target{
                ans[0] = i
                ans[1] = j
                break
            }
        }
    }
    return ans 
}