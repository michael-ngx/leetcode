class Solution:
    def isHappy(self, n: int) -> bool:
        prev = set()
        while (n != 1):
            if (n in prev):
                return False
            prev.add(n)
            n = sum([int(x)**2 for x in str(n)])
        return True