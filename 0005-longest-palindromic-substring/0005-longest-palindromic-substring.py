class Solution:
    def longestPalindrome(self, s: str) -> str:
        result = ""
        
        left = 0
        while left < len(s):
            right = left + 1
            while right < len(s) and s[left] == s[right]:
                right += 1

            if (right - left > len(result)):
                result = s[left:right]

            increase = (len(result) - (right - left)) // 2
            while left - increase >= 0 and right + increase <= len(s):
                check = s[left - increase : right + increase]
                if check == check[::-1] and len(check) > len(result):
                    result = check

                increase += 1

            left += 1

        return result
