"""
Given two strings containing backspaces (identified by the character ‘#’), check if the two strings are equal.
Example-1

```
Input: str1="xy#z", str2="xzz#"
Output: true
Explanation: After applying backspaces the strings become "xz" and "xz" respectively.
```

Example-2:

```
Input: str1="xy#z", str2="xyz#"
Output: false
Explanation: After applying backspaces the strings become "xz" and "xy" respectively.
```

Example-3:

```
Input: str1="xp#", str2="xyz##"
Output: true
Explanation: After applying backspaces the strings become "x" and "x" respectively.
In "xyz##", the first '#' removes the character 'z' and the second '#' removes the character 'y'.
```

Example-4:

```
Input: str1="xywrrmp", str2="xywrrmu#p"
Output: true
Explanation: After applying backspaces the strings become "xywrrmp" and "xywrrmp" respectively.
```
"""


class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        ptr_s, ptr_t = (len(s) - 1), (len(t) - 1)
        skip_s, skip_t = 0, 0

        while(ptr_s >= 0 or ptr_t >= 0):
            while(ptr_s >= 0):
                if s[ptr_s] == "#":
                    skip_s += 1
                    ptr_s -= 1
                elif skip_s > 0:
                    skip_s -= 1
                    ptr_s -= 1
                else:
                    break
            while(ptr_t >= 0):
                if t[ptr_t] == "#":
                    skip_t += 1
                    ptr_t -= 1
                elif skip_t > 0:
                    skip_t -= 1
                    ptr_t -= 1
                else:
                    break

            if ((ptr_s >= 0) and (ptr_t >= 0)) and (
                    s[ptr_s] != t[ptr_t]):
                return False
            if (ptr_s >= 0) != (ptr_t >= 0):
                return False
            ptr_s -= 1
            ptr_t -= 1

        return True
