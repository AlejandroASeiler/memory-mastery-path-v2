# Mastery of Memory: C, C++, and Rust 🚀

Este repositorio está diseñado para ayudarte a entender las bases de la programación de sistemas, el manejo de memoria y la optimización de servicios. El dominio de estos lenguajes te permitirá crear aplicaciones escalables, SaaS de alto rendimiento y sistemas robustos.

## 📂 Estructura del Repositorio

### 1. [C Basics](./c_basics/)
El fundamento de todo. Aquí aprenderás cómo funciona la memoria "bajo el capó".
- **`pointers_basics.c`**: Direcciones de memoria, aritmética de punteros y manipulación directa.
- **`dynamic_memory.c`**: Gestión manual con `malloc`, `realloc` y `free`. Crucial para entender fugas de memoria (memory leaks).

### 2. [C++ Mastery](./cpp_mastery/) 🛠️
Desde conceptos básicos hasta optimización avanzada para sistemas y servicios.
- **`01_basics_lifecycle.cpp`**: Referencias vs Valores y el ciclo de vida de los objetos.
- **`02_stl_optimization.cpp`**: Cómo usar `std::vector` correctamente y el poder de los Templates.
- **`03_advanced_optimization.cpp`**: Alineación de memoria (Padding) y `std::string_view` (C++17).
- **`04_concurrency_basics.cpp`**: Fundamentos de multithreading, Mutex y Atómicos.
- **`smart_pointers.cpp`**: RAII y gestión automática de recursos (`unique_ptr`, `shared_ptr`).
- **`move_semantics.cpp`**: Optimización extrema evitando copias innecesarias mediante "Move Semantics".

### 3. [Rust Foundations](./rust_foundations/) 🦀
El futuro de la programación segura.
- **`ownership.rs`**: El sistema de Ownership y Borrowing que garantiza seguridad sin Garbage Collector.
- **`unsafe_ptr.rs`**: Cómo bajar al nivel de C en Rust cuando la optimización manual es necesaria.

## 🚀 Cómo Empezar

### Requisitos
- GCC / Clang (para C y C++)
- Rustc / Cargo (para Rust)
- Make (opcional, para automatización)

### Compilación y Ejecución

#### C
```bash
gcc c_basics/pointers_basics.c -o pointers
./pointers
```

#### C++
```bash
g++ -std=c++17 cpp_mastery/smart_pointers.cpp -o smart_ptr
./smart_ptr
```

#### Rust
```bash
rustc rust_foundations/ownership.rs -o ownership
./ownership
```

## 💡 Consejos para la Optimización de Servicios
1. **Evita Allocations en el Hot Path**: En servicios de alta carga, reservar memoria dinámicamente es costoso. Usa pools de memoria o reserva por adelantado.
2. **Cache Locality**: Organiza tus datos de forma contigua en memoria para aprovechar la caché del CPU.
3. **Move en lugar de Copy**: En C++, usa `std::move` siempre que el objeto original ya no sea necesario.
4. **Zero-Cost Abstractions**: Tanto en C++ como en Rust, prefiere abstracciones que no añadan carga en tiempo de ejecución.

---
*Creado para aprender a construir el futuro de los sistemas de alto rendimiento.*
