# Time: O(n)
# Space: O(1)
class Solution:
    def myAtoi(self, str: str) -> int:
        sign, num, i = 1, 0, 0
        max_value = 2**31 - 1
        min_value = -2**31

        if not str:
            return num

        while i < len(str) and str[i].isspace():
            i += 1
            # or str.strip()

        if len(str) == i:
            return num


        if str[i] == '-' or str[i] == '+':
            sign = 1 - 2*(str[i] == '-')
            i += 1

        while i < len(str):
            digit = ord(str[i]) - ord('0')
            if digit < 0 or digit > 9:
                break
            if max_value//10 < num or (num == max_value//10 and digit > max_value%10):
                return max_value if sign == 1 else min_value
            num = num*10 + digit
            i += 1
        return num*sign
        # max(-2**31, min(sign * num,2**31-1))
