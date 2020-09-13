# Time: O(n)
# Space: O(n)
class Solution:
    def calculate(self, s: str) -> int:
        num, stack, sign = 0, [], "+"
        for i in range(len(s)):
            if s[i].isdigit():
                # if we see digit, we update num (single or multi-digit number)
                num = num*10 + ord(s[i]) - ord("0")
            if s[i] in "+-/*" or (len(s)-1 == i):
                # if we see a new operator or it is last char, we
                # perform operation using the previous
                # operator and push into stack
                if sign == "+":
                    # single operand
                    stack.append(num)
                elif sign == "-":
                    # single operand
                    stack.append(-num)
                elif sign == "*":
                    # double operand
                    stack.append(stack.pop()*num)
                else:
                    stack.append(int(stack.pop()/num))
                    # can use // (floor) as -1.5 becomes -2 instead of -1
                # reset num
                num = 0
                # update sign
                sign = s[i]
        return sum(stack)

"""
We delay addition/subtraction to a later time and only do multiplication/division
while iterating the string, which helps us in implementating DMAS
"""
