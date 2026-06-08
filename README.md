# 🚀 Mastery Path: C, C++ & Rust

Bienvenido a la guía definitiva para dominar la programación de sistemas, el manejo de memoria y la optimización de alto rendimiento. Este repositorio está diseñado para llevarte desde los conceptos más básicos de la lógica hasta las técnicas avanzadas utilizadas en la industria para crear SaaS, motores y sistemas escalables.

---

## 🗺️ Hoja de Ruta de Aprendizaje

### 🧠 Fase 1: Lógica de Programación (El Motor)
Antes de tocar la memoria, debes dominar cómo piensa el procesador.
- **[Basic Logic](./logic_mastery/01_basic_logic.c)**: Tablas de verdad y álgebra booleana.
- **[Intermediate Flow](./logic_mastery/02_intermediate_logic.cpp)**: Máquinas de estado para lógica compleja.
- **[Advanced Logic](./logic_mastery/03_advanced_logic.cpp)**: **Branchless Programming** (optimización a nivel de CPU).
- **[Rust Logic](./logic_mastery/04_rust_logic.rs)**: Pattern Matching exhaustivo y seguridad lógica.

### 💾 Fase 2: El Fundamento de C (La Base)
Entiende cómo funciona la memoria real, sin abstracciones.
- **[Pointers Basics](./c_basics/pointers_basics.c)**: Direcciones, punteros y aritmética.
- **[Dynamic Memory](./c_basics/dynamic_memory.c)**: `malloc`, `realloc` y `free` (Gestión manual).
- **[Advanced C](./c_basics/advanced_c.c)**: Manipulación de bits y punteros a funciones.

### 🛠️ Fase 3: Maestría en C++ (La Optimización)
Aprende a usar abstracciones de costo cero para crear servicios rápidos.
- **[Lifecycle & Refs](./cpp_mastery/01_basics_lifecycle.cpp)**: Referencias vs Valores.
- **[STL & Templates](./cpp_mastery/02_stl_optimization.cpp)**: Optimización de contenedores.
- **[Advanced Memory](./cpp_mastery/03_advanced_optimization.cpp)**: Alineación de memoria y `string_view`.
- **[Concurrency](./cpp_mastery/04_concurrency_basics.cpp)**: Multithreading, Mutex y Atómicos.
- **[Smart Pointers](./cpp_mastery/smart_pointers.cpp)**: RAII y gestión automática.
- **[Move Semantics](./cpp_mastery/move_semantics.cpp)**: Evitar copias innecesarias.

### 🦀 Fase 4: Rust Foundations (La Seguridad)
El futuro de los sistemas seguros y de alto rendimiento.
- **[Ownership](./rust_foundations/ownership.rs)**: El corazón de Rust (Básico).
- **[Advanced Rust](./rust_foundations/advanced_rust.rs)**: Traits, Generics y Concurrencia segura.
- **[Unsafe Rust](./rust_foundations/unsafe_ptr.rs)**: Bajando al nivel de C cuando es necesario.

---

## 🚀 Cómo Empezar

### Requisitos
- **C/C++**: `gcc` o `clang`.
- **Rust**: `rustc` y `cargo`.
- **Build**: `make` instalado.

### Compilación Rápida
Puedes compilar todos los ejemplos de una vez usando el Makefile:
```bash
make
```

O individualmente:
```bash
# Ejemplo C
gcc c_basics/pointers_basics.c -o pointers && ./pointers

# Ejemplo C++
g++ -std=c++17 cpp_mastery/smart_pointers.cpp -o smart && ./smart

# Ejemplo Rust
rustc rust_foundations/ownership.rs -o ownership && ./ownership
```

---

## 💡 Consejos de Optimización para SaaS/Sistemas
1. **Data Locality**: Mantén tus datos juntos para que el CPU no tenga que esperar a la RAM.
2. **Avoid Allocations**: En el "hot path" de tu código, evita pedir memoria. Usa pools o reserva previamente.
3. **Branchless**: Si una condición es impredecible, intenta eliminarla con lógica matemática.
4. **Zero-Cost**: Usa abstracciones que el compilador pueda eliminar, no pagues por lo que no usas.

---
*Creado para construir el futuro de los sistemas de alto rendimiento.*
