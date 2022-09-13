fn example_1() {
    let language = "Rust"; // define a variable
    println!("Language: {}", language); // print the variable
}

fn example_2() {
    let mut language = "Rust"; // define a mutable variable
    println!("Language: {}", language); // print the variable
    language = "Java"; // update the variable
    println!("Language: {}", language); // print the updated value of variable
}

fn example_3() {
    let (course, category) = ("Rust", "beginner"); // assign multiple values
    println!("This is a {} course in {}.", category, course); // print the value
}

/*
Note: If a variable is kept un-assigned or unused, you’ll get a warning. 
To remove such a warning write the expression #[allow(unused_variables, unused_mut)] at the start of the program code. 
However, it’s not a good practice to keep unassigned/unused variables. 
*/

fn main() {
    example_1();
    example_2();
    example_3();
}
