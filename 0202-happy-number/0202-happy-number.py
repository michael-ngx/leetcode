class Solution:
    def isHappy(self, n: int) -> bool:
        visited = set()
        def happy(m):
            if m == 1:
                return True
            if m in visited:
                return False
            visited.add(m)
            summ = 0
            while m // 10 >0:
                digit = m %10
                
                summ += digit*digit
                m = m//10
            summ += (m%10)**2
            return happy(summ)


        return happy(n)
        