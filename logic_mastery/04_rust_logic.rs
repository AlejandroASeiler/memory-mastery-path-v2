/**
 * Logic Mastery: Rust's Advanced Pattern Matching
 * 
 * Rust's logic is "exhaustive", meaning you cannot forget a case.
 * This prevents bugs in complex SaaS business logic.
 */

enum Message {
    Quit,
    Move { x: i32, y: i32 },
    Write(String),
    ChangeColor(i32, i32, i32),
}

fn process_message(msg: Message) {
    // The compiler forces you to handle ALL cases
    match msg {
        Message::Quit => println!("Quit message"),
        Message::Move { x, y } => println!("Move to x: {}, y: {}", x, y),
        Message::Write(text) => println!("Text message: {}", text),
        Message::ChangeColor(r, g, b) => println!("Color change: R={}, G={}, B={}", r, g, b),
    }
}

fn main() {
    println!("--- Rust Exhaustive Logic ---");
    let msg = Message::Move { x: 10, y: 20 };
    process_message(msg);

    // Boolean logic with Option (Functional style)
    let some_value: Option<i32> = Some(5);
    let is_greater_than_two = some_value
        .map(|v| v > 2)
        .unwrap_or(false);

    println!("Is value > 2? {}", is_greater_than_two);
}
