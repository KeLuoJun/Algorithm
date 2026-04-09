import sys

class Solution:
    def add(self, a: int, b: int) -> int:
        return a + b

for line in sys.stdin:
    a, b = map(int, line.split())
    result = Solution().add(a, b)
    print(result)