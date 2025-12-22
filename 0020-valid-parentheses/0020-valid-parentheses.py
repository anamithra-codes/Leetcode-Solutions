class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        parantheses_mapping = {")": "(", "}": "{", "]": "["}

        for i in s:
            if i in parantheses_mapping:
                top = stack.pop() if stack else '#'
                if parantheses_mapping[i] != top:
                    return False
            else:
                stack.append(i)
        return not stack
        