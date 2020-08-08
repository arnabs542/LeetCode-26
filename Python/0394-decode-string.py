# Tags: String, Stack
# Time:  O(n)
# Space: O(n)
class Solution:
    def decodeString(self, s: str) -> str:
        stack = []
        cur_num = 0
        cur_string = ''
        for c in s:
            if c == '[':
                # record cur string
                stack.append(cur_string)
                # record cur num
                stack.append(cur_num)
                # reset
                cur_string = ''
                cur_num = 0

            elif c == ']':
                num = stack.pop()
                prev_string = stack.pop()
                cur_string = prev_string + num*cur_string
            elif c.isdigit():
                cur_num = cur_num*10 + int(c)
                # or cur_num*10 + ord(c) - ord('0')
            else:
                # isalpha()
                cur_string += c

        return cur_string
