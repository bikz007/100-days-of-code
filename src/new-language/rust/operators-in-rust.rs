fn example_1() {
    let a = 4;
    let b = 3;

    println!("Operand 1:{}, Operand 2:{}", a, b);
    println!("Addition:{}", a + b);
    println!("Subtraction:{}", a - b);
    println!("Multiplication:{}", a * b);
    println!("Division:{}", a / b);
    println!("Modulus:{}", a % b);
}

fn example_2() {
    let a = true;
    let b = false;
    println!("Operand 1:{}, Operand 2:{}", a, b);
    println!("AND:{}", a && b);
    println!("OR:{}", a || b);
    println!("NOT:{}", !a);
}

fn main() {
    example_1();
    example_2();
}
