# Basics of C++
revisiting the fundamentals of c++

# What do the files contain

| File Name      | Topic     |
| :------------- | :---------- |
| hello-world | your first basic program|
| data-types   | data types and their sizes with your hardware |
| input-output | basic input/output streams and un/buffered streams|
| data-type-errors| shows common loop errors for built-in types|
| preprocessors | Macros, File Inclusion, Conditional Compilation, and Other directives |
| classes | basic introduction to classes and inheritance |
| classes2 | basic program with classes, references, and inheritance |

# How to run a .cpp file

- compile to a binary file
```bash
$ sudo g++ -o hello-world hello-world.cpp
```
- run the binary file
```bash
$ ./hello-world
[output]
Hello World%
```

# Data Types

__Primary__
- integer, character, boolean, floating point (float and double), void, wide character (wchar_t)

datatype modifiers
- signed, unsigned, short, long
- these modify storage length
- note that the compiler type is assumed to be GCC 64 bit for many applications, but *may* vary!

__Derived__
- function, array, pointer, reference

__User Defined__ (abstract or user-defined)
- class, structure, union, enum, typedef

