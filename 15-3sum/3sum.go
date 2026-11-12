func threeSum(nums []int) [][]int {
    n := len(nums)
    slices.Sort(nums)

    ans := [][]int{}
    // pin on element
    // search between left...right
    for i := 0 ; i < n-2 ; i++{
        // skip the same triplets
        if i > 0 && nums[i] == nums[i-1] { continue }
        left := i+1
        right := n - 1
        for left < right{
            sum := nums[i] + nums[left] + nums[right]
            if sum > 0{
                right--
            }else if sum < 0 {   
                left++
            }else {
                ans = append(ans, []int{nums[i],nums[left],nums[right]})
                // skip the duplicates
                for left < right && nums[left] == nums[left + 1] {
                    left++
                }
                for left < right && nums[right] == nums[right - 1]{
                    right--
                }
                // if there no duplicates we should move left and right eventually
                left++
                right--
            }
        }        
    } 
    return ans
}