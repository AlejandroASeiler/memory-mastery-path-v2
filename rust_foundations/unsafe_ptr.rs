/**
 * Rust Foundations: Unsafe and Raw Pointers
 * 
 * To optimize systems or interface with C, Rust allows "unsafe" blocks
 * where you can use raw pointers, similar to C.
 */

fn main() {
    let mut num = 5;

    // Creating raw pointers is safe
    let r1 = &num as *const i32;
    let r2 = &mut num as *mut i32;

    println!("--- Unsafe Block Demo ---");
    // Dereferencing raw pointers must be in an unsafe block
    unsafe {
        println!("r1 points to: {}", *r1);
        *r2 = 10;
        println!("Value modified via r2: {}", *r2);
    }

    println!("Final value of num: {}", num);

    // Memory optimization: Zero-cost abstractions
    let vec = vec![1, 2, 3, 4, 5];
    let slice = &vec[1..4];
    println!("\nSlice (no allocation): {:?}", slice);
}
