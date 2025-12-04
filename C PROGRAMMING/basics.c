// What is C ?
// C is a powerful, general-purpose, and procedural programming language developed by Dennis Ritchie at Bell Labs in the early 1970s. It was initially designed for developing the UNIX operating system and has since become a foundational language in computer science. 
// What is a compiler ?
// A system program that converts high level language into low-level machine language that a computer can understand and execute.
// What is a loader ?
// A software tool that combines compiled object files and libraries into a single executable program.
// What is a loader ?
// A system program that loads an executable program from storage into memory, preparing it for execution by the computer's processor.
// To understand how a c program runs and works, refer this image : https://www.scaler.com/topics/images/linker-and-loader_thumbnail.webp

/*When a C program executes, the operating system loads the program's executable binary into the computer's RAM. This memory is then divided into distinct segments, each serving a specific purpose in the program's execution:

    Text (Code) Segment:
    This segment contains the compiled machine code instructions of the program. It is typically read-only to prevent accidental modification and is often shareable, meaning multiple instances of the same program can share the same code segment in memory.
    Initialized Data Segment:
    This segment stores global and static variables that are explicitly initialized with a non-zero value in the source code.
    Uninitialized Data Segment (BSS Segment):
    This segment holds global and static variables that are either uninitialized or initialized to zero. The operating system initializes these variables to zero before the program starts execution.
    Heap Segment:
    This segment is used for dynamic memory allocation during program execution. Functions like malloc(), calloc(), and realloc() allocate memory from the heap, and free() releases it. The heap grows upwards in memory as needed.
    Stack Segment:
    This segment manages function calls and local variables. When a function is called, a new stack frame is created on the stack, containing the function's local variables, arguments, and the return address. When the function returns, its stack frame is popped off the stack. The stack grows downwards in memory. 

Execution Process:

    Loading:
    The operating system's loader loads the program's executable file into these memory segments.
    Initialization:
    Global and static variables in the data and BSS segments are initialized.
    Execution Cycle:
    The CPU then begins executing instructions from the text segment. It follows a fetch-decode-execute cycle:
        Fetch: The CPU fetches the next instruction from the memory address pointed to by the program counter (or instruction pointer).
        Decode: The fetched instruction is decoded to determine the operation to be performed. 

    Execute: The CPU performs the operation, which might involve arithmetic, data movement, or control flow changes, and updates registers and flags. 

Memory Management:
As the program runs, it interacts with the stack for function calls and local variables, and potentially with the heap for dynamic memory allocation. */
// FIRST PROGRAM 
/*
#include<stdio.h> // header file containing standard input output instructions.
int main(){ // main function in which body of the code exists.
    printf("Hello World"); // basic printin gsyntax.
    return 0; // return nothing at the end.
} // end of code.
*/

// Variables in C
// A variable is a named storage location in memory that holds a value of a specific data type. Variables are used to store and manipulate data in a program. Each variable has a name (identifier), a data type, and a value. The data type determines the kind of data the variable can hold, such as integers, floating-point numbers, characters, etc.
// Keywords to declare variables in C:
// int - for integer values
// float - for floating-point values
// char - for character values
// double - for double-precision floating-point values
// Datatypes and constants in C
// C provides several built-in data types to represent different kinds of data. Here are some of the commonly used data types in C:
// int: Used to represent integer values (whole numbers) without decimal points. Example: int age = 25;
// float: Used to represent single-precision floating-point numbers (numbers with decimal points). Example: float pi = 3.14f;
// double: Used to represent double-precision floating-point numbers (numbers with decimal points). Example: double e = 2.718281828459;
// char: Used to represent single characters. Example: char grade = 'A';
// void: Represents the absence of a value or type. It is often used for functions that do not return a value.
// Constants in C are fixed values that do not change during the execution of a program. They can be defined using the #define preprocessor directive or the const keyword. Example: #define PI 3.14159 or const int MAX_SIZE = 100;    
// Inout and Output in C
// Input and output in C are typically handled using standard library functions provided in the <stdio.h> header file. The most commonly used functions for input and output are printf() for output and scanf() for input.
// Output using printf():
/*
#include <stdio.h>
int main() {
    int age = 25;
    printf("Hello, World!\n"); // Print a string
    printf("I am %d years old.\n", age); // Print an integer
    return 0;
}
// Input using scanf():
#include <stdio.h>
int main() {
    int age;
    printf("Enter your age: ");
    scanf("%d", &age); // Read an integer input
    printf("You entered: %d\n", age);
    return 0;
}
*/
// In the scanf() function, the format specifier (e.g., %d for integers) indicates the type of data to be read, and the & operator is used to provide the address of the variable where the input value will be stored.
// Operators in C
// Operators are special symbols or keywords in C that perform specific operations on one or more operands (variables, constants, or expressions). C provides a variety of operators, which can be categorized into several types:
// Arithmetic Operators: Used for basic mathematical operations.
// + (Addition), - (Subtraction), * (Multiplication), / (Division), % (Modulus)
// Relational Operators: Used to compare two values.
// == (Equal to), != (Not equal to), > (Greater than), < (Less than), >= (Greater than or equal to), <= (Less than or equal to)
// Logical Operators: Used to combine multiple conditions.
// && (Logical AND), || (Logical OR), ! (Logical NOT)
// Assignment Operators: Used to assign values to variables.
// = (Simple assignment), += (Add and assign), -= (Subtract and assign), *= (Multiply and assign), /= (Divide and assign), %= (Modulus and assign)
// Increment and Decrement Operators: Used to increase or decrease the value of a variable by one.
// ++ (Increment), -- (Decrement)
// Bitwise Operators: Used to perform bit-level operations on integer types.
// & (Bitwise AND), | (Bitwise OR), ^ (Bitwise XOR), ~ (Bitwise NOT), << (Left shift), >> (Right shift)
// Conditional (Ternary) Operator: A shorthand for an if-else statement.
// ?: (Ternary operator) - condition ? expression_if_true : expression_if_false
// Example usage of operators in C:
/*
#include <stdio.h>
int main() {
    int a = 10, b = 5;
    int sum = a + b; // Using arithmetic operator
    int isEqual = (a == b); // Using relational operator
    int logicalAnd = (a > 0 && b > 0); // Using logical operator
    a += 5; // Using assignment operator
    a++; // Using increment operator

    printf("Sum: %d\n", sum);
    printf("Is Equal: %d\n", isEqual);
    printf("Logical AND: %d\n", logicalAnd);
    printf("Updated a: %d\n", a);

    return 0;
}
    */

// MAKING A CALCULATOR USING C PROGRAMMING:
/*
#include<stdio.h>
#include<math.h>

void main(){
    float a,b;
    scanf("Enter two numbers, a %f and b %f",&a,&b);
    printf("Additon : %0f",a+b);
    printf("Subtraction : %0f",a-b);
    printf("Multiplication : %0f",a*b);
    printf("Division : %0f",a/b);
    printf("Modulus : %0f",fmod(a,b));
    printf("Exponentiation : %0f",pow(a,b));


}
    */