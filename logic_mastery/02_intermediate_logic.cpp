#include <iostream>
#include <string>

/**
 * Logic Mastery: State Machines and Complex Flow Control
 * 
 * Instead of nested "if" statements, use State Machines. 
 * This makes the logic scalable for complex SaaS/Systems.
 */

enum class State { IDLE, PROCESSING, COMPLETED, ERROR };

class Connection {
    State current_state = State::IDLE;

public:
    void transition(std::string action) {
        std::cout << "Action: " << action << " | ";
        
        // Clean logic using switch instead of nested ifs
        switch (current_state) {
            case State::IDLE:
                if (action == "start") current_state = State::PROCESSING;
                break;
            case State::PROCESSING:
                if (action == "finish") current_state = State::COMPLETED;
                else if (action == "fail") current_state = State::ERROR;
                break;
            case State::COMPLETED:
            case State::ERROR:
                if (action == "reset") current_state = State::IDLE;
                break;
        }
        print_state();
    }

    void print_state() {
        switch (current_state) {
            case State::IDLE: std::cout << "State: IDLE\n"; break;
            case State::PROCESSING: std::cout << "State: PROCESSING\n"; break;
            case State::COMPLETED: std::cout << "State: COMPLETED\n"; break;
            case State::ERROR: std::cout << "State: ERROR\n"; break;
        }
    }
};

int main() {
    Connection conn;
    conn.transition("start");
    conn.transition("finish");
    conn.transition("reset");
    conn.transition("start");
    conn.transition("fail");
    
    return 0;
}
