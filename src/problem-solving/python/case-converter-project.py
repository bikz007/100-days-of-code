"""
In programming, there are five common cases: camelCase, snakecase, kebab-case, PascalCase and UPPER_CASE_SNAKE_CASE. For this project, you are to Write a function that takes in a sentence and a desired case as the inputs, and then converts the sentence into the desired case.

**Examples**:

```
convert("Hello, World.", "camel")
Output: helloWorld

convert("Hello, World.", "snake")
Output: hello_world

convert("Hello, World.", "kebab")
Output: hello-world

convert("Hello, World.", "pascal")
Output: HelloWorld

convert("Hello, World.", "uppercasesnake")
Output: HELLO_WORLD
```

"""

from enum import Enum
import re
 
class Cases(Enum):
    camel = 1
    snake = 2
    kebab = 3
    pascal = 4
    uppercasesnake = 5

def convert(text,case):
    text = str(text)
    # regex to split sentence into words, removing punctuations and whitespace
    words = re.findall(r"[a-zA-Z]+",text)

    if not words:
        return "Invalid input"

    if case == Cases.camel.name:
        return convert_to_camel_or_pascal(words,True)
    elif case == Cases.snake.name:
        return convert_to_snake_or_kebab(words,True)
    elif case == Cases.kebab.name:
        return convert_to_snake_or_kebab(words,False)
    elif case == Cases.pascal.name:
        return convert_to_camel_or_pascal(words,False)
    elif case == Cases.uppercasesnake.name:
        return convert_to_uppercasesnake(words)
    else:
        return "Invalid case option"

def convert_to_camel_or_pascal(words,is_camel):
    if len(words) == 1:
        return words[0].lower() if is_camel else words[0].capitalize()

    result = words[0].lower() if is_camel else words[0].capitalize()

    for i in range(1,len(words)):
        result += words[i].capitalize()
            
    return result

def convert_to_snake_or_kebab(words,is_snake):
    if len(words) == 1:
        return words[0].lower()

    result = words[0].lower()
    seperator = "_" if is_snake else "-" 
    for i in range(1,len(words)):
        result += seperator + words[i].lower()
            
    return result


def convert_to_uppercasesnake(words):
    if len(words) == 1:
        return words[0].upper()

    result = words[0].upper()

    for i in range(1,len(words)):
        result += "_" + words[i].upper()

    return result

print(convert("Hello, World","camel"))
print(convert("Hello, World","snake"))
print(convert("Hello, World","kebab"))
print(convert("Hello, World","pascal"))
print(convert("Hello, World","uppercasesnake"))
print(convert("","uppercasesnake"))