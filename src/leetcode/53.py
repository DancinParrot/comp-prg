# Kadane's Algorithm: Find subarray with largest sum


def f(nums):
    max_sum = float("-inf")
    cur = 0
    for i in range(len(nums)):
        cur += nums[i]
        max_sum = max(max_sum, cur)

        if cur < 0:
            cur = 0
    return max_sum


f([-2, 1, -3, 4, -1, 2, 1, -5, 4])
