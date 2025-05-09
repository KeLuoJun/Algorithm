# 数组的最小偏移量
# 给你一个由n个正整数组成的数组nums
# 你可以对数组的任意元素执行任意次数的两类操作：
# 如果元素是偶数，除以2
# 例如如果数组是[1,2,3,4]
# 那么你可以对最后一个元素执行此操作，使其变成[1,2,3,2]
# 如果元素是奇数，乘上2
# 例如如果数组是[1,2,3,4]
# 那么你可以对第一个元素执行此操作，使其变成[2,2,3,4]
# 数组的偏移量是数组中任意两个元素之间的最大差值
# 返回数组在执行某些操作之后可以拥有的最小偏移量
# 测试链接 : https://leetcode.cn/problems/minimize-deviation-in-array/

from typing import List
import sys
import bisect

def minimumDeviation(nums: List[int]):
    processed = []
    for num in nums:
        if num % 2 == 1:
            processed.append(num * 2)
        else:
            processed.append(num)
    processed.sort()

    ans = processed[-1] - processed[0]

    while ans > 0 and processed[-1] % 2 == 0:
        max_val = processed.pop()
        bisect.insort(processed, max_val//2)
        ans = min(ans, processed[-1] - processed[0])

    return ans 


def main() -> None:
    n = int(sys.stdin.readline().strip())
    nums = list(map(int, sys.stdin.readline().strip().split()))
    print(minimumDeviation(nums))


if __name__ == '__main__':
    main()

