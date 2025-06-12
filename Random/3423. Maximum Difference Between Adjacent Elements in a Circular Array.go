func maxAdjacentDistance(nums []int) int {
    var ans int = 0
    for i := 0; i < len(nums); i++ {
        var d int
        c := nums[i]
        if i == len(nums) - 1 {
            d = nums[0]
        } else {
            d = nums[i + 1]
        }
        c -= d
        if c < 0 {
            c = -c
        }
        if ans < c {
            ans = c
        }

    }
    return ans
}
