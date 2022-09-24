fn example_01() {
    let a = 4;
    let b = 3;

    println!("Operand 1:{}, Operand 2:{}", a, b);
    println!("Addition:{}", a + b);
    println!("Subtraction:{}", a - b);
    println!("Multiplication:{}", a * b);
    println!("Division:{}", a / b);
    println!("Modulus:{}", a % b);
}

fn example_02() {
    let a = true;
    let b = false;
    println!("Operand 1:{}, Operand 2:{}", a, b);
    println!("AND:{}", a && b);
    println!("OR:{}", a || b);
    println!("NOT:{}", !a);
}

fn example_1() {
    // comparison operators
    let a = 2;
    let b = 3;
    println!("Operand 1:{}, Operand 2:{}", a, b);
    println!("a > b:{}", a > b);
    println!("a < b:{}", a < b);
    println!("a >= b:{}", a >= b);
    println!("a <= b:{}", a <= b);
    println!("a == b:{}", a == b);
    println!("a != b:{}", a != b);
}

fn example_2() {
    // bitwise operators
    let a = 5;
    let b = 6;
    println!("Operand 1: {}, Operand 2: {}", a, b);
    println!("AND: {}", a & b);
    println!("OR: {}", a | b);
    println!("XOR: {}", a ^ b);
    println!("NOT a: {}", !a);
    println!("Left shift: {}", a << 2);
    println!("Right shift: {}", a >> 1);
}

fn example_3() {
    // compound assingment operators
    let mut a = 2;
    println!("a:{}", a);
    a += 1;
    println!("a+=1:{}", a);
    println!("a:{}", a);
    a -= 1;
    println!("a-=1:{}", a);
    println!("a:{}", a);
    a /= 1;
    println!("a/=1:{}", a);
    println!("a:{}", a);
    a *= 3;
    println!("a*=3:{}", a);
}

fn example_4() {
    // type casting operator
    /*
      What data types can be type casted?

    Integer can be type casted to floating-point and vice versa.
    Integer can be typecasted to String
    What data types cannot be type casted?

    String (&str) or character cannot be type casted to the data type of type integer or float.
    Character cannot be type casted to String type and vice versa.
      */
    let a = 15;
    let b = (a as f64) / 2.0;
    println!("a: {}", a);
    println!("b: {}", b);
}

fn example_5() {
    /*
    Note: Mutable references(mutable borrow operations) are moved while immutable references(shared borrow operations) are copied.
    */
    let x = 10;
    let mut y = 13;
    //immutable reference to a variable
    let a = &x;
    println!("Value of a:{}", a);
    println!("Value of x:{}", x); // x value remains the same since it is immutably borrowed
                                  //mutable reference to a variable
    let b = &mut y;
    println!("Value of b:{}", b);

    *b = 11; // derefencing
    println!("Value of b:{}", b); // updated value of b
    println!("Value of y:{}", y); // y value can be changed as it is mutuably borrowed
}

fn example_6() {
    //mutable reference to a variable
    let mut x = 10;
    println!("Value of x:{}", x);
    let a = &mut x;
    println!("Value of a:{}", a);
    //dereference a variable
    *a = 11;
    println!("Value of a:{}", a);
    println!("Value of x:{}", x); // Note that value of x is updated
}

/*

Precedence
The precedence of an operator determines which operation is performed first in an expression with more than one operators.

Operators are listed below in the order of their precedence from highest to lowest :

Unary
Logical/Bitwise NOT - !
Derereference - *
Borrow - &, &mut

Binary
Typecast - as
Multiplication- *,Division - /, Remainder - %
Addition -+, Subtraction - -
Left Shift - <<, Right Shift - >>
Bitwise AND - &
Bitwise XOR - ^
Bitwise OR - |
Comparison - == != < > <= >=
Logical AND - &&
Logical OR - ||
Range - start .. stop
Assignment/Compound Assignment - = += -= *= /= %= &= |= ^= <<= >>=

Note: The operators that are written in the same row have the same order of precedence.

Note: The range operator will be further explored while we discuss the for loop in the Loops chapter.
*/

/*
Associativity#
If two or more operators of the same precedence appear in a statement, then which operator will be evaluated first is defined by the associativity.

Left to Right Associativity#
Left associativity occurs when an expression is evaluated from left to right. An expression such as a ~ b ~ c, in this case, would be interpreted as (a ~ b) ~ c where ~ can be any operator.

The operators below can be chained as left associative.

as
*, /, %
+, -
<< >>
&
^
|
&&
||
Note: The comparison, assignment, and the range operator cannot be chained at all.
*/

fn example_7() {
    println!("Answer : {}", (3 + 5) * 9 / 7 & 8);
}

fn example_8() {
    println!("{}", 2 + 3 / 5 ^ 7 & 8 | 9);
}

fn main() {
    example_01();
    example_02();
    example_1();
    example_2();
    example_3();
    example_4();
    example_5();
    example_6();
    example_7();
    example_8();
}
