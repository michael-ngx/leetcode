class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for c in s:
            if (c in [')',']','}']):
                if not stack or (stack[-1] == '(' and c != ')') or (stack[-1] == '[' and c != ']') or (stack[-1] == '{' and c != '}'):
                    return False
                else:
                    stack.pop()
            else:
                stack.append(c)
        return not stack