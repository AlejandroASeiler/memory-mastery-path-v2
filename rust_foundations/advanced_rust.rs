use std::thread;
use std::sync::{Arc, Mutex};

/**
 * Advanced Rust: Traits, Generics, and Fearless Concurrency
 * 
 * 1. Traits: Defining shared behavior (Polymorphism).
 * 2. Arc & Mutex: Thread-safe shared state.
 */

// Traits and Generics
trait Summary {
    fn summarize(&self) -> String;
}

struct Article {
    title: String,
    author: String,
}

impl Summary for Article {
    fn summarize(&self) -> String {
        format!("{} by {}", self.title, self.author)
    }
}

fn notify<T: Summary>(item: &T) {
    println!("Breaking news: {}", item.summarize());
}

// Concurrency
fn concurrency_demo() {
    println!("\n--- Fearless Concurrency ---");
    // Arc: Atomic Reference Counted (to share between threads)
    // Mutex: Mutual Exclusion (to allow mutation)
    let counter = Arc::new(Mutex::new(0));
    let mut handles = vec![];

    for _ in 0..10 {
        let counter = Arc::clone(&counter);
        let handle = thread::spawn(move || {
            let mut num = counter.lock().unwrap();
            *num += 1;
        });
        handles.push(handle);
    }

    for handle in handles {
        handle.join().unwrap();
    }

    println!("Result: {}", *counter.lock().unwrap());
}

fn main() {
    let article = Article {
        title: String::from("Rust for Systems"),
        author: String::from("Manus"),
    };

    println!("--- Traits & Generics ---");
    notify(&article);

    concurrency_demo();
}
