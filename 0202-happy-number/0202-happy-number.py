class Solution:
    def isHappy(self, n: int) -> bool:
        visited = set()
        def happy(m):
            if m == 1:
                return True
            if m in visited:
                return False
            visited.add(m)
            summ = sum([(int(x))**2 for x in str(m)])
            return happy(summ)

        return happy(n)
