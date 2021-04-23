-   To generate .o File
    -   `g++ -c person.cpp`
        -   `-c`  stop the compiling process after the assembling stage, translating our files from .c to .o
        -   generates .o file

-   To Run Client Code
    -   `g++ q2.cpp *.o`
        -   `*` is a wildcard, this compiles q2.cpp with all the .o files in folder linked 