/**
 * Rust Foundations: Ownership and Borrowing
 * 
 * Rust provides memory safety without a garbage collector through its ownership system.
 * This is the modern alternative to manual C/C++ memory management.
 */

fn main() {
    println!("--- Ownership Demo ---");
    let s1 = String::from("Hello Rust");
    let s2 = s1; // s1 is MOVED to s2. s1 is no longer valid.
    
    // println!("{}", s1); // Error: value borrowed here after move
    println!("s2: {}", s2);

    println!("\n--- Borrowing Demo ---");
    let s3 = String::from("Memory Safety");
    
    // Immutable borrow
    let len = calculate_length(&s3); 
    println!("The length of '{}' is {}.", s3, len);

    // Mutable borrow
    let mut s4 = String::from("Hello");
    change(&mut s4);
    println!("Modified string: {}", s4);
}

fn calculate_length(s: &String) -> usize {
    s.len()
} // s goes out of scope, but it doesn't have ownership, so nothing happens

fn change(some_string: &mut String) {
    some_string.push_str(", World!");
}
