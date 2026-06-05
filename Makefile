CC = gcc
CXX = g++
RUSTC = rustc
CFLAGS = -Wall -Wextra -O2
CXXFLAGS = -Wall -Wextra -O2 -std=c++17

C_SRCS = $(wildcard c_basics/*.c)
CPP_SRCS = $(wildcard cpp_mastery/*.cpp)
RUST_SRCS = $(wildcard rust_foundations/*.rs)

C_BINS = $(C_SRCS:.c=)
CPP_BINS = $(CPP_SRCS:.cpp=)
RUST_BINS = $(RUST_SRCS:.rs=)

all: $(C_BINS) $(CPP_BINS) $(RUST_BINS)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

%: %.rs
	$(RUSTC) $< -o $@

clean:
	rm -f $(C_BINS) $(CPP_BINS) $(RUST_BINS)

.PHONY: all clean
