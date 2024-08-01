class Solution:
    def isHappy(self, n: int) -> bool:
        if n == 1: 
            return True

        slow = n
        fast = n

        while True:
            slow = self.sumSqrDigits(slow)
            fast = self.sumSqrDigits(self.sumSqrDigits(fast))

            if slow == fast:
                break
            
        return slow == 1
    
    def sumSqrDigits(self, n):
        return sum([int(i) ** 2 for i in str(n)])