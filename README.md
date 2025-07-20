# Matrix Calculator 🧮

A modular C++ matrix calculator built using a clean multifile structure. Supports:

- Matrix addition
- Matrix subtraction
- Matrix multiplication
- Scalar multiplication
- Matrix transposition

## 📁 Project Structure

calculator/
├── include/
│ ├── loading.hpp
│ ├── main_menu.hpp
│ ├── matrices.hpp
│ ├── multiple_number.hpp
│ ├── quadratic_equation.hpp
│ ├── single_number.hpp
│ ├── trigonometry.hpp
├── src/
│ ├── loading.cpp
│ ├── main.cpp
│ ├── main_menu.cpp
│ ├── matrices.cpp
│ ├── multiple_number.cpp
│ ├── quadratic_equation.cpp
│ ├── single_number.cpp
│ ├── trigonometry.cpp
├── CMakeLists.txt
└── README.md

## 🛠️ Build Instructions

Make sure you have **CMake** and a C++20 compiler installed. Then run:

```bash
mkdir build
cd build
cmake ..
make
./c
```
