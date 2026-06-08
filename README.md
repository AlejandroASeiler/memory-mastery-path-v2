# Mastery of Memory: C, C++, and Rust 🚀

Este repositorio está diseñado para ayudarte a entender las bases de la programación de sistemas, el manejo de memoria y la optimización de servicios. El dominio de estos lenguajes te permitirá crear aplicaciones escalables, SaaS de alto rendimiento y sistemas robustos.

## 📂 Estructura del Repositorio

### 1. [C Basics](./c_basics/)
El fundamento de todo. Desde punteros hasta manipulación de bajo nivel.
- **`pointers_basics.c`**: Direcciones de memoria, aritmética de punteros y manipulación directa.
- **`dynamic_memory.c`**: Gestión manual con `malloc`, `realloc` y `free`.
- **`advanced_c.c`**: Manipulación de bits y Punteros a Funciones (Callbacks).

### 2. [C++ Mastery](./cpp_mastery/) 🛠️
Desde conceptos básicos hasta optimización avanzada para sistemas y servicios.
- **`01_basics_lifecycle.cpp`**: Referencias vs Valores y el ciclo de vida de los objetos.
- **`02_stl_optimization.cpp`**: Cómo usar `std::vector` correctamente y el poder de los Templates.
- **`03_advanced_optimization.cpp`**: Alineación de memoria (Padding) y `std::string_view` (C++17).
- **`04_concurrency_basics.cpp`**: Fundamentos de multithreading, Mutex y Atómicos.
- **`smart_pointers.cpp`**: RAII y gestión automática de recursos (`unique_ptr`, `shared_ptr`).
- **`move_semantics.cpp`**: Optimización extrema evitando copias innecesarias mediante "Move Semantics".

### 3. [Rust Foundations](./rust_foundations/) 🦀
El futuro de la programación segura y de alto rendimiento.
- **`ownership.rs`**: El sistema de Ownership y Borrowing (Básico).
- **`advanced_rust.rs`**: Traits, Generics y Concurrencia Segura con `Arc` y `Mutex`.
- **`unsafe_ptr.rs`**: Punteros crudos y bloques `unsafe` para optimización extrema.

### 4. [Logic Mastery](./logic_mastery/) 🧠
La base de todo algoritmo eficiente.
- **`01_basic_logic.c`**: Tablas de verdad, Álgebra Booleana y Cortocircuitos.
- **`02_intermediate_logic.cpp`**: Máquinas de Estado para evitar el "Callback Hell" o ifs anidados.
- **`03_advanced_logic.cpp`**: **Branchless Programming** (optimización a nivel de CPU) y Lógica en tiempo de compilación.
- **`04_rust_logic.rs`**: Pattern Matching exhaustivo y lógica funcional.

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
