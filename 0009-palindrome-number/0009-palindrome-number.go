func isPalindrome(x int) bool {
    str_num := strconv.Itoa(x)
    n := len(str_num)
    left := 0 
    right := n - 1

    // set left to the start
    // and right to the end
    // check if at each iteration they are the same
    // if they are not the same return false

    for left < right {
        if str_num[left] != str_num[right]{
             return false
        }

        left++;
        right--;
    }
    return true
    
}