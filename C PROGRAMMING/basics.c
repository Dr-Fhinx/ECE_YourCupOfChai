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

// CONTROL FLOW :
// IF- ELSE STATEMENT:
/*
#include<stdio.h>
void main(){
    int num;
    printf("Enter a number : ");
    scanf("%d",&num);
    if(num%2==0){
        printf("The number is even");
    }
    else{
        printf("The number is odd");
    }
}
*/
// SWITCH CASE STATEMENT:
/*
#include<stdio.h>
void main(){
    int day;
    printf("Enter a number between 1 to 7 : ");
    scanf("%d",&day);
    switch(day){
        case 1:
            printf("Monday");
            break;
        case 2:
            printf("Tuesday");
            break;
        case 3:
            printf("Wednesday");
            break;
        case 4:
            printf("Thursday");
            break;
        case 5:
            printf("Friday");
            break;
        case 6:
            printf("Saturday");
            break;
        case 7:
            printf("Sunday");
            break;
        default:
            printf("Invalid Input");
    }
} 
*/
// LOOPS IN C PROGRAMMING:
// FOR LOOP:
/*
#include<stdio.h>
void main(){
    int i;
    for(i=1;i<=10;i++){
        printf("%d\n",i);
    }
} 
*/
// WHILE LOOP:
/*
#include<stdio.h>
void main(){
    int i=1;
    while(i<=10){
        printf("%d\n",i);
        i++;
    }
} 
*/
// DO WHILE LOOP:
/*
#include<stdio.h>
void main(){
    int i=1;
    do{
        printf("%d\n",i);
        i++;
    }while(i<=10);
} 
*/
// NESTED LOOPS:
/*
#include<stdio.h>
void main(){
    int i,j;
    for(i=1;i<=5;i++){
        for(j=1;j<=i;j++){
            printf("*");
        }
        printf("\n");
    }
} 
*/
// QUESTON 001 : PATTERN GENERATOR
// Write a C program to generate the following pattern:
/*
*
*****
***********
***************
*****************
*/

//solution :
/*
#include<stdio.h>
void main(){
    int i;
    for(i=1;i<6;i++){
        switch(i){
            case 1: printf("*\n"); break;
            case 2: printf("*****\n");  break;
            case 3: printf("***********\n"); break;
            case 4: printf("***************\n"); break;
            case 5: printf("*****************\n"); break;
        }
    }
}
    */
   // QUESTION 002 : MENU DRIVEN APPLICATION USING SWITCH CASE
    // Write a C program that displays a menu to the user and performs different operations based on the user's choice using switch-case statements. The menu should include options for addition, subtraction, multiplication, and division of two numbers.
    // solution :
/*
#include<stdio.h>
void main(){
    int choice;
    float a,b;
    printf("Menu:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter your choice (1-4): ");
    scanf("%d",&choice);
    printf("Enter two numbers: ");
    scanf("%f %f",&a,&b);
    switch(choice){
        case 1:
            printf("Addition: %0f\n",a+b);
            break;
        case 2:
            printf("Subtraction: %0f\n",a-b);
            break;
        case 3:
            printf("Multiplication: %0f\n",a*b);
            break;
        case 4:
            if(b!=0){
                printf("Division: %0f\n",a/b);
            }
            else{
                printf("Error: Division by zero is not allowed.\n");
            }
            break;
        default:
            printf("Invalid choice.\n");
    }
} 
*/

// ARRAYS AND STRINGS :
// ARRAYS IN C:
// An array is a collection of elements of the same data type stored in contiguous memory locations. Arrays are used to store multiple values in a single variable, making it easier to manage and manipulate related data. Each element in an array can be accessed using its index, which starts from 0 for the first element.
// Declaring and Initializing an Array:
/*
#include<stdio.h>
void main(){
    int numbers[5]; // Declaration of an integer array of size 5
    // Initialization of the array
    numbers[0] = 10;
    numbers[1] = 20;
    numbers[2] = 30;
    numbers[3] = 40;
    numbers[4] = 50;

    // Accessing and printing array elements
    for(int i=0;i<5;i++){
        printf("Element at index %d: %d\n",i,numbers[i]);
    }
} 
*/
// 1D ARRAY:
/*
#include<stdio.h>
void main(){
    int arr[5] = {1,2,3,4,5}; // Declaration and initialization of a 1D array
    for(int i=0;i<5;i++){
        printf("%d\n",arr[i]); // Accessing and printing elements of the array
    }
} 
*/
// 2D ARRAY:
/*
#include<stdio.h>
void main(){
    int matrix[2][3] = { {1,2,3}, {4,5,6} }; // Declaration and initialization of a 2D array
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            printf("%d ",matrix[i][j]); // Accessing and printing elements of the 2D array
        }
        printf("\n");
    }
} 
*/ // First square brackets represent rows and second represent columns.
// Character Arrays :
/*
#include<stdio.h>
void main(){
    char str[20] = "Hello, World!"; // Declaration and initialization of a character array (string)
    printf("%s\n",str); // Printing the string
} 
*/
// STRINGS IN C:
// A string in C is an array of characters terminated by a null character ('\0'). Strings are used to represent text and can be manipulated using various string handling functions provided in the <string.h> header file.
// Declaring and Initializing a String:
/*
#include<stdio.h>
void main(){
    char str[20] = "Hello, World!"; // Declaration and initialization of a string
    printf("%s\n",str); // Printing the string
} 
*/
// String Input using scanf():
/*
#include<stdio.h>
void main(){
    char name[50];
    printf("Enter your name: ");
    scanf("%s",name); // Reading a string input
    printf("Hello, %s!\n",name); // Printing the string
} 
*/
// String Input using fgets():
/*
#include<stdio.h>
void main(){
    char name[50];
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin); // Reading a string input with spaces
    // if scanf is used instead of fgets, it will take input only till the first space.
    printf("Hello, %s!\n",name); // Printing the string
} 
*/
// String Functions:
/*
#include<stdio.h>
#include<string.h>
void main(){
    char str1[50] = "Hello";
    char str2[50] = "World";
    // String Length
    printf("Length of str1: %lu\n",strlen(str1));
    // String Concatenation
    strcat(str1, " ");
    strcat(str1, str2);
    printf("Concatenated String: %s\n",str1);
    // String Copy
    char str3[50];
    strcpy(str3, str1);
    printf("Copied String: %s\n",str3);
    // String Comparison
    int result = strcmp(str1, str3);
    if(result == 0){
        printf("str1 and str3 are equal.\n");
    } else {
        printf("str1 and str3 are not equal.\n");
    }
} 
*/
// User-Defined String Functions:
/*
#include<stdio.h>
#include<string.h>
void reverseString(char str[]){
    int n = strlen(str);
    for(int i=0;i<n/2;i++){
        char temp = str[i];
        str[i] = str[n-i-1];
        str[n-i-1] = temp;
    }
}
void main(){
    char str[50];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    // Remove newline character if present
    str[strcspn(str, "\n")] = 0; //strcspn finds the first occurrence of '\n' and replaces it with '\0' this is done to avoid newline character in the string.
    reverseString(str);
    printf("Reversed String: %s\n",str);
} 
*/

//FUNCTIONS IN C:
// A function in C is a block of code that performs a specific task. Functions help in modularizing the code, making it more organized and reusable. A function typically consists of a function declaration (prototype), a function definition, and a function call.
// Function Declaration (Prototype):
// A function declaration specifies the function's name, return type, and parameters (if any) without providing the actual implementation. It informs the compiler about the function's existence before its usage.
// return_type function_name(parameter_list);
// Function Definition:
// A function definition provides the actual implementation of the function. It includes the function's body, which contains the statements that define what the function does.
// return_type function_name(parameter_list) {
//     // function body
// }
// Function Call:
// A function call is used to invoke or execute a function. When a function is called, the program control is transferred to the function, and after the function completes its task, control returns to the point where the function was called.
// function_name(arguments);
// Example of a Function in C:
/*
#include<stdio.h>
// Function Declaration
int add(int a, int b);
// Function Definition
int add(int a, int b) {
    return a + b;
}
void main() {
    int num1, num2, sum;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    // Function Call
    sum = add(num1, num2);
    printf("Sum: %d\n", sum);
} 
*/


// cALL BY VALUE AND CALL BY REFERENCE IN C:
// Call by Value:
/*
#include<stdio.h>
void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}
void main() {
    int x = 10, y = 20;
    printf("Before swap (Call by Value): x = %d, y = %d\n", x, y);
    swapByValue(x, y);
    printf("After swap (Call by Value): x = %d, y = %d\n", x, y);
} 
*/
// Call by Reference:
/*
#include<stdio.h>
void swapByReference(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void main() {
    int x = 10, y = 20;
    printf("Before swap (Call by Reference): x = %d, y = %d\n", x, y);
    swapByReference(&x, &y);
    printf("After swap (Call by Reference): x = %d, y = %d\n", x, y);
} 
*/
// Difference between Call by Value and Call by Reference:
// Call by Value:
// A copy of the actual parameter's value is passed to the function.
// Changes made to the parameter inside the function do not affect the original argument.
// Used for simple data types like int, float, char, etc.
// Call by Reference:
// The address of the actual parameter is passed to the function.
// Changes made to the parameter inside the function affect the original argument.
// Used for complex data types like arrays, structures, etc.

// RECURSION IN C:
// Recursion is a programming technique where a function calls itself to solve a smaller instance of the same problem. It is often used to solve problems that can be broken down into smaller, similar subproblems. A recursive function typically has two main components: the base case and the recursive case.
// Base Case:
// The base case is a condition that stops the recursion. It defines when the function should stop calling itself and return a value.
// Recursive Case:
// The recursive case is where the function calls itself with a modified argument, moving closer to the base case.
// Example of a Recursive Function to Calculate Factorial:
/*
#include<stdio.h>
int factorial(int n) {
    // Base Case
    if(n == 0) {
        return 1;
    }
    // Recursive Case
    return n * factorial(n - 1);
}
void main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    int result = factorial(num);
    printf("Factorial of %d is %d\n", num, result);
} 
*/

// STORAGE CLASSES IN C:
// Storage classes in C define the scope, visibility, and lifetime of variables and functions within a program. C provides four primary storage classes: auto, register, static, and extern.
// 1. auto:
// The auto storage class is the default storage class for local variables. Variables declared with auto are created when the block in which they are defined is entered and destroyed when the block is exited. They have automatic storage duration and are not initialized by default.
/*
#include<stdio.h>
void main() {
    auto int x = 10; // auto storage class
    printf("Value of x: %d\n", x);
} 
*/
// 2. register:
// The register storage class is used to suggest that a variable be stored in a CPU register for faster access. However, the compiler may ignore this suggestion. Register variables have automatic storage duration and are typically used for frequently accessed variables.
/*
#include<stdio.h>
void main() {
    register int count; // register storage class
    for(count = 0; count < 10; count++) {
        printf("%d ", count);
    }
    printf("\n");
} 
*/
// 3. static:
// The static storage class is used to declare variables that retain their value between function calls. Static variables are initialized only once and have a lifetime that lasts for the duration of the program. They can be declared inside functions or outside functions (global scope).
/*
#include<stdio.h>
void counter() {
    static int count = 0; // static storage class
    count++;
    printf("Count: %d\n", count);
}
void main() {
    counter();
    counter();
    counter();
} 
*/
// 4. extern:
// The extern storage class is used to declare variables that are defined in another file or outside the current scope. It allows access to global variables across multiple files. Extern variables have static storage duration.
/*
#include<stdio.h>
extern int globalVar; // extern storage class
void main() {
    printf("Value of globalVar: %d\n", globalVar);
} 
*/
// In another file, you would define the global variable:
/*
#include<stdio.h>
int globalVar = 100; // Definition of the extern variable
// Rest of the code
*/ // NOTE : extern variable is accessed in another file only if both files are compiled together using a command like: gcc file1.c file2.c -o outputExecutable and are there in same directory.

// QUESTION : STUDENT MARKS MANAGEMENT SYSTEM
// Write a C program to manage student marks. The program should allow the user to input student names and their corresponding marks, calculate the average marks, and display the names of students who scored above the average.
// Solution :
/*
#include<stdio.h>
#include<string.h>
#define MAX_STUDENTS 100 // define : this is used to define a constant value that can be used throughout the program.
void main(){
    int n,i;
    char names[MAX_STUDENTS][50];
    float marks[MAX_STUDENTS];
    float sum=0,average;

    printf("Enter number of students: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Enter name of student %d: ",i+1);
        scanf("%s",names[i]);
        printf("Enter marks of student %d: ",i+1);
        scanf("%f",&marks[i]);
        sum += marks[i];
    }

    average = sum/n;
    printf("Average Marks: %.2f\n",average);
    printf("Students scoring above average:\n");
    for(i=0;i<n;i++){
        if(marks[i]>average){
            printf("%s\n",names[i]);
        }
    }
}
*/

// QUESTION :STRING ENCRYPTION DECRYPTION PROGRAM
// Write a C program that encrypts and decrypts a given string using a simple Caesar cipher technique. The program should allow the user to input a string and a shift value for encryption and decryption.
// Solution :
/*
#include<stdio.h>
#include<string.h>
void encrypt(char str[], int shift){
    for(int i=0;str[i]!='\0';i++){
        char ch = str[i];
        if(ch>='a' && ch<='z'){
            ch = (ch - 'a' + shift)%26 + 'a';
            str[i] = ch;
        }
        else if(ch>='A' && ch<='Z'){
            ch = (ch - 'A' + shift)%26 + 'A';
            str[i] = ch;
        }
    }
}
void decrypt(char str[], int shift){
    for(int i=0;str[i]!='\0';i++){
        char ch = str[i];
        if(ch>='a' && ch<='z'){
            ch = (ch - 'a' - shift + 26)%26 + 'a';
            str[i] = ch;
        }
        else if(ch>='A' && ch<='Z'){
            ch = (ch - 'A' - shift + 26)%26 + 'A';
            str[i] = ch;
        }
    }
}
void main(){
    char str[100];
    int shift,choice;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // Remove newline character
    printf("Enter shift value: ");
    scanf("%d",&shift);
    printf("Choose an option:\n1. Encrypt\n2. Decrypt\n");
    scanf("%d",&choice);
    if(choice==1){
        encrypt(str,shift);
        printf("Encrypted String: %s\n",str);
    }
    else if(choice==2){
        decrypt(str,shift);
        printf("Decrypted String: %s\n",str);
    }
    else{
        printf("Invalid choice.\n");
    }
} 
*/

//QUESTION : LIBRARY FUNCTION REPLICATION ( strlen, strcpy, strcmp )
// Write a C program that replicates the functionality of standard library string functions such as strlen, strcpy, and strcmp without using the <string.h> header file.
// Solution :
/*
#include<stdio.h>
int myStrlen(char str[]){
    int length = 0;
    while(str[length]!='\0'){
        length++;
    }
    return length;
}
void myStrcpy(char dest[], char src[]){
    int i=0;
    while(src[i]!='\0'){
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; // Null-terminate the destination string
}
int myStrcmp(char str1[], char str2[]){
    int i=0;
    while(str1[i]!='\0' && str2[i]!='\0'){
        if(str1[i]!=str2[i]){
            return str1[i]-str2[i];
        }
        i++;
    }
    return str1[i]-str2[i];
}
void main(){
    char str1[100], str2[100];
    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove newline character
    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0; // Remove newline character

    // Testing myStrlen
    printf("Length of first string: %d\n", myStrlen(str1));
    printf("Length of second string: %d\n", myStrlen(str2));

    // Testing myStrcpy
    char copy[100];
    myStrcpy(copy, str1);
    printf("Copied string: %s\n", copy);

    // Testing myStrcmp
    int cmpResult = myStrcmp(str1, str2);
    if(cmpResult == 0){
        printf("Strings are equal.\n");
    } else if(cmpResult < 0){
        printf("First string is less than second string.\n");
    } else {
        printf("First string is greater than second string.\n");
    }
} 
*/
// pointers in C
// A pointer in C is a variable that stores the memory address of another variable. Pointers are used to directly access and manipulate memory locations, allowing for efficient memory management and dynamic data structures. Pointers are declared using the asterisk (*) symbol, and the address-of operator (&) is used to obtain the address of a variable.
// Declaring and Using Pointers:
/*
#include<stdio.h>
void main(){
    int num = 42; // Declare an integer variable
    int *ptr; // Declare a pointer to an integer
    ptr = &num; // Assign the address of num to the pointer
    printf("Value of num: %d\n", num);
    printf("Value at ptr: %d\n", *ptr);
    printf("Address of num: %p\n", (void*)&num);
    printf("Address stored in ptr: %p\n", (void*)ptr);
    *ptr = 100; // Change the value at the address pointed to by ptr
    printf("New value of num: %d\n", num);
}
*/

// POINTER ARITHMETIC IN C:
/*
#include<stdio.h>
void main(){
    int arr[] = {10, 20, 30, 40, 50}; // Declare and initialize an array
    int *ptr = arr; // Pointer to the first element of the array
    for(int i=0;i<5;i++){
        printf("Element %d: %d\n", i, *(ptr + i)); // Accessing array elements using pointer arithmetic
        // Basically, when we add 1 to a pointer, it adds 4 bytes of space to whatever it is pointing to this implies it's address is shifted by 4 bytes. If we are using this in arrays then we are acctually moving to the next element.

    }
}       
*/
// POINTERS AND ARRAYS IN C:
/*
#include<stdio.h>
void main(){
    int arr[] = {1,2,3,4,5}; // Declare and initialize an array
    int *ptr = arr; // Pointer to the first element of the array
    for(int i=0;i<5;i++){
        printf("Element %d: %d\n", i, *(ptr + i)); // Accessing array elements using pointer arithmetic
    }
}       
*/
// POINTERS AND FUNCTIONS IN C:
/*
#include<stdio.h>
void increment(int *num){
    (*num)++; // Increment the value at the address pointed to by num
}
void main(){
    int value = 10;
    printf("Before increment: %d\n", value);
    increment(&value); // Pass the address of value to the function
    printf("After increment: %d\n", value);
}
*/
// POINTERS TO POINTERS IN C:
/*
#include<stdio.h>
void main(){
    int num = 42; // Declare an integer variable
    int *ptr = &num; // Pointer to the integer variable
    int **ptrToPtr = &ptr; // Pointer to the pointer
    printf("Value of num: %d\n", num);
    printf("Value at ptr: %d\n", *ptr);
    printf("Value at ptrToPtr: %d\n", **ptrToPtr);
}
*/

// QUESTIONS : Dynamic Array Implementation
// Write a C program to implement a dynamic array using pointers. The program should allow the user to input the size of the array, input elements into the array, and then display the elements of the array.
// Solution :
/*
#include<stdio.h>
void main(){
    int arrSize;
    printf("ENter size of Array: \n");
    scanf("%d",&arrSize);
    int arr[arrSize];
    int *ptr = arr;
    for(int i = 0; i<arrSize; i++){
        printf("Enter element %d: \n",i+1);
        scanf("%d",(ptr+i));
    }
    printf("ARRAY ELEMENTS ARE : ",arr);


}
*/

// QUESTION : FUNTION POINTER_BASED MENU SYSTEM
// Write a C program that implements a menu system using function pointers. The program should allow the user to choose from different operations (e.g., addition, subtraction, multiplication, division) and execute the corresponding function based on the user's choice.
// Solution :
/*
#include<stdio.h>
void add(){
    int a,b;
    printf("Enter two numbers to add: ");
    scanf("%d %d",&a,&b);
    printf("Sum: %d\n",a+b);
}
void subtract(){
    int a,b;
    printf("Enter two numbers to subtract: ");
    scanf("%d %d",&a,&b);
    printf("Difference: %d\n",a-b);
}
void multiply(){
    int a,b;
    printf("Enter two numbers to multiply: ");
    scanf("%d %d",&a,&b);
    printf("Product: %d\n",a*b);
}
void divide(){
    int a,b;
    printf("Enter two numbers to divide: ");
    scanf("%d %d",&a,&b);
    if(b!=0){
        printf("Quotient: %d\n",a/b);
    }
    else{
        printf("Error: Division by zero is not allowed.\n");
    }
}
void main(){
    void (*operations[4])() = {add, subtract, multiply, divide}; // Array of function pointers
    int choice;
    printf("Menu:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n"); 
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter your choice (1-4): ");
    scanf("%d",&choice);
    if(choice>=1 && choice<=4){
        operations[choice-1](); // Call the selected function
    }
    else{
        printf("Invalid choice.\n");
    }
} 
*/

// DYNAMIC MEMORY ALLOCATION IN C:
// Dynamic memory allocation in C allows programs to request memory at runtime using functions from the <stdlib.h> header file. This is useful for creating data structures whose size may not be known at compile time. The primary functions for dynamic memory allocation are malloc(), calloc(), realloc(), and free().
//1. malloc():
// The malloc() function allocates a specified number of bytes of memory and returns a pointer to the allocated memory. The memory is not initialized.
/*
#include<stdio.h>
#include<stdlib.h>
void main(){
    int n;
    printf("Enter number of integers: ");
    scanf("%d",&n);
    int *arr = (int*)malloc(n * sizeof(int)); // Allocate memory for n integers
    if(arr == NULL){
        printf("Memory allocation failed.\n");
        return;
    }
    for(int i=0;i<n;i++){
        printf("Enter element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Array elements are:\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    free(arr); // Free the allocated memory
} 
*/

// 2. calloc():
// The calloc() function allocates memory for an array of elements, initializes all bytes to zero, and returns a pointer to the allocated memory.
/*
#include<stdio.h>
#include<stdlib.h>
void main(){
    int n;
    printf("Enter number of integers: ");
    scanf("%d",&n); 
    int *arr = (int*)calloc(n, sizeof(int)); // Allocate memory for n integers and initialize to zero
    if(arr == NULL){
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Array elements are (initialized to zero):\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    free(arr); // Free the allocated memory
} 
*/
// 3. realloc():
// The realloc() function changes the size of previously allocated memory. It can be used to increase or decrease the size of the memory block.
/*
#include<stdio.h>
#include<stdlib.h>
void main(){
    int n;
    printf("Enter initial number of integers: ");
    scanf("%d",&n); 
    int *arr = (int*)malloc(n * sizeof(int)); // Allocate memory for n integers
    if(arr == NULL){
        printf("Memory allocation failed.\n");
        return;
    }
    for(int i=0;i<n;i++){
        arr[i] = i + 1; // Initialize array elements
    }
    printf("Array elements are:\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    // Resize the array
    int newSize;
    printf("Enter new size of the array: ");
    scanf("%d",&newSize);
    arr = (int*)realloc(arr, newSize * sizeof(int)); // Resize the memory block
    if(arr == NULL){
        printf("Memory reallocation failed.\n");
        return;
    }
    for(int i=n;i<newSize;i++){
        arr[i] = i + 1; // Initialize new elements
    }
    printf("Resized array elements are:\n");
    for(int i=0;i<newSize;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");   
    free(arr); // Free the allocated memory
} 
*/
// 4. free():
// The free() function deallocates previously allocated memory, making it available for future allocations. It is important to free dynamically allocated memory to avoid memory leaks.
/*
#include<stdio.h>   
#include<stdlib.h>
void main(){
    int *ptr = (int*)malloc(10 * sizeof(int)); // Allocate memory for 10 integers
    if(ptr == NULL){
        printf("Memory allocation failed.\n");
        return;
    }   
    // Use the allocated memory
    free(ptr); // Free the allocated memory
} 
*/
// MEMORY LEAKS IN C:
// A memory leak occurs when a program allocates memory dynamically but fails to deallocate it using the free() function. This can lead to increased memory usage over time and can eventually exhaust available memory, causing the program to crash or behave unexpectedly. To prevent memory leaks, it is essential to free all dynamically allocated memory when it is no longer needed.

//DANGLING POINTERS IN C:
// A dangling pointer is a pointer that points to a memory location that has been deallocated or freed. Accessing or dereferencing a dangling pointer can lead to undefined behavior, crashes, or data corruption. To avoid dangling pointers, it is important to set pointers to NULL after freeing the memory they point to.
/*
#include<stdio.h>
#include<stdlib.h>
void main(){
    int *ptr = (int*)malloc(sizeof(int)); // Allocate memory
    *ptr = 42; // Use the allocated memory
    printf("Value: %d\n", *ptr);
    free(ptr); // Free the allocated memory
    ptr = NULL; // Set pointer to NULL to avoid dangling pointer
} 
*/

// QUESTION : MATRIX MULTIPLICATION USING DYNAMIC MEMORY ALLOCATION
// Write a C program to perform matrix multiplication using dynamic memory allocation. The program should allow the user to input the dimensions and elements of two matrices, perform the multiplication, and display the resulting matrix.
// Solution :
/*
#include<stdio.h>
#include<stdlib.h>
void main(){
    int row1, col1, row2, col2;
    printf ("ENTER ROWS AND COLOUMNS OF FIRST MATRIX: \n");
    scanf ("%d %d", &row1, &col1);
    printf ("ENTER ROWS AND COLOUMNS OF SECOND MATRIX: \n");
    scanf ("%d %d", &row2, &col2);
    if (col1 != row2){
        printf ("MATRIX MULTIPLICATION NOT POSSIBLE\n");
        return;
    }

    int * matrix1 = malloc(row1*col1*sizeof(int));
    int * matrix2 = malloc(row2*col2*sizeof(int));
    int * result = malloc(row1*col2*sizeof(int));
    printf ("ENTER ELEMENTS OF FIRST MATRIX: \n");
    for (int i=0; i<row1; i++){
        for (int j=0; j<col1; j++){
            scanf ("%d", (matrix1 + i*col1 + j));
        }
    }

    printf ("ENTER ELEMENTS OF SECOND MATRIX: \n");
    for (int i=0; i<row2; i++){
        for (int j=0; j<col2; j++){
            scanf ("%d", (matrix2 + i*col2 + j));
        }
    }

    // Perform matrix multiplication
    for (int i=0; i<row1; i++){
        for (int j=0; j<col2; j++){
            *(result + i*col2 + j) = 0; // Initialize result element
            for (int k=0; k<col1; k++){
                *(result + i*col2 + j) += *(matrix1 + i*col1 + k) * *(matrix2 + k*col2 + j);
            }
        }
    }

    // Display the resulting matrix
    printf ("RESULTING MATRIX: \n");
    for (int i=0; i<row1; i++){
        for (int j=0; j<col2; j++){
            printf ("%d ", *(result + i*col2 + j));
        }
        printf ("\n");
    }

    // Free allocated memory
    free(matrix1);
    free(matrix2);
    free(result);
}
*/

// STRUCTURES IN C:
// A structure in C is a user-defined data type that allows grouping of related variables of different data types under a single name. Structures are used to represent complex data entities and facilitate organized data management. A structure is defined using the struct keyword, and its members can be accessed using the dot (.) operator.
// Defining and Using Structures:
/*
#include<stdio.h>
struct Student {
    char name[50];
    int age;
    float marks;
};  
void main(){
    struct Student student1; // Declare a structure variable
    // Assign values to structure members
    printf("Enter name: ");
    fgets(student1.name, sizeof(student1.name), stdin);
    printf("Enter age: ");
    scanf("%d",&student1.age);
    printf("Enter marks: ");
    scanf("%f",&student1.marks);
    // Access and print structure members
    printf("Student Details:\n");
    printf("Name: %s",student1.name);
    printf("Age: %d\n",student1.age);
    printf("Marks: %.2f\n",student1.marks);
} 
*/
// NESTED STRUCTURES IN C:
/*
#include<stdio.h>
struct Date {
    int day;
    int month;
    int year;
};
struct Student {
    char name[50];
    int age;
    struct Date dob; // Nested structure
};
void main(){
    struct Student student1; // Declare a structure variable
    // Assign values to structure members
    printf("Enter name: ");
    fgets(student1.name, sizeof(student1.name), stdin);
    printf("Enter age: ");  
    scanf("%d",&student1.age);
    printf("Enter date of birth (day month year): ");
    scanf("%d %d %d",&student1.dob.day, &student1.dob.month, &student1.dob.year);
    // Access and print structure members
    printf("Student Details:\n");
    printf("Name: %s",student1.name);
    printf("Age: %d\n",student1.age);
    printf("Date of Birth: %02d/%02d/%04d\n",student1.dob.day, student1.dob.month, student1.dob.year); // You need not define one more structure for date of birth, you can simply nest it inside student structure.
} 
*/
//ARRAY OF STRUCTURES IN C:
/*
#include<stdio.h>
struct Student {
    char name[50];
    int age;
    float marks;
};
void main(){
    int n;
    printf("Enter number of students: ");   
    scanf("%d",&n);
    struct Student students[n]; // Declare an array of structures
    for(int i=0;i<n;i++){
        printf("Enter details for student %d:\n",i+1);
        printf("Name: ");
        getchar(); // To consume the newline character left by previous scanf
        fgets(students[i].name, sizeof(students[i].name), stdin);
        printf("Age: ");
        scanf("%d",&students[i].age);
        printf("Marks: ");
        scanf("%f",&students[i].marks);
    }
    // Display student details
    printf("Student Details:\n");
    for(int i=0;i<n;i++){
        printf("Student %d:\n",i+1);
        printf("Name: %s",students[i].name);
        printf("Age: %d\n",students[i].age);
        printf("Marks: %.2f\n",students[i].marks);
    }
}
*/

// UNION IN C:
// A union in C is a user-defined data type that allows storing different data types in the same memory location. Unlike structures, where each member has its own memory space, all members of a union share the same memory. This means that at any given time, only one member of the union can hold a value. Unions are useful for memory optimization when you need to store different types of data but only one type at a time.
// Defining and Using Unions:
/*
#include<stdio.h>
union Data {
    int intValue;
    float floatValue;
    char charValue;
};
void main(){
    union Data data;
    data.intValue = 5;
    printf("Integer: %d\n",data.intValue);
    data.floatValue = 3.14;
    printf("Float: %.2f\n",data.floatValue); // Note: Assigning a new value to floatValue overwrites intValue.
    data.charValue = 'A';
    printf("Character: %c\n",data.charValue);
}
*/

// BITFIELDS IN C:
// A bitfield in C is a special type of structure member that allows the allocation of a specific number of bits for a variable. Bitfields are used to optimize memory usage when you need to store multiple boolean or small integer values within a single byte or word. Bitfields are defined using a colon (:) followed by the number of bits to be allocated.
// Defining and Using Bitfields:
/*
#include<stdio.h>
struct Flags {
    unsigned int isActive : 1; // 1 bit
    unsigned int isAdmin : 1;  // 1 bit
    unsigned int accessLevel : 3; // 3 bits
};
void main(){
    struct Flags userFlags;
    userFlags.isActive = 1;
    userFlags.isAdmin = 0;
    userFlags.accessLevel = 5; // Max value for 3 bits is 7
    printf("isActive: %u\n",userFlags.isActive);
    printf("isAdmin: %u\n",userFlags.isAdmin);
    printf("accessLevel: %u\n",userFlags.accessLevel);
} 
*/

//typedef IN C:
// The typedef keyword in C is used to create new type names (aliases) for existing data types. This can improve code readability and make it easier to manage complex data types such as structures and pointers. The syntax for using typedef is as follows:
// typedef existing_type new_type_name;

// QUESTION : CUSTOM MEMORY MANAGEMENT 
// Write a C program that implements a simple custom memory management system using dynamic memory allocation. The program should allow the user to allocate and deallocate memory blocks of varying sizes and keep track of the allocated memory.
// Solution :
/*
#include<stdio.h>
#include<stdlib.h>
#define MAX_BLOCKS 100
typedef struct {
    void *address;
    size_t size;
} MemoryBlock;
MemoryBlock allocatedBlocks[MAX_BLOCKS];
int blockCount = 0; 
void* customMalloc(size_t size){
    if(blockCount >= MAX_BLOCKS){
        printf("Memory limit reached.\n");
        return NULL;
    }
    void *ptr = malloc(size);
    if(ptr != NULL){
        allocatedBlocks[blockCount].address = ptr;
        allocatedBlocks[blockCount].size = size;
        blockCount++;
    }
    return ptr;
}
void customFree(void *ptr){
    for(int i=0;i<blockCount;i++){
        if(allocatedBlocks[i].address == ptr){
            free(ptr);
            // Shift remaining blocks
            for(int j=i;j<blockCount-1;j++){
                allocatedBlocks[j] = allocatedBlocks[j+1];
            }
            blockCount--;
            return;
        }
    }
    printf("Pointer not found in allocated blocks.\n");
}
void displayAllocatedBlocks(){
    printf("Allocated Memory Blocks:\n");
    for(int i=0;i<blockCount;i++){
        printf("Block %d: Address = %p, Size = %zu bytes\n",i+1, allocatedBlocks[i].address, allocatedBlocks[i].size);
    }
}
void main(){
    int choice;
    do{
        printf("Menu:\n1. Allocate Memory\n2. Deallocate Memory\n3. Display Allocated Blocks\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: {
                size_t size;
                printf("Enter size of memory to allocate (in bytes): ");
                scanf("%zu",&size);
                void *ptr = customMalloc(size);
                if(ptr != NULL){    
                    printf("Memory allocated at address: %p\n",ptr);
                }
                break;
            }
            case 2: {   
                void *ptr;
                printf("Enter address of memory to deallocate: ");
                scanf("%p",&ptr);
                customFree(ptr);
                break;
            }
            case 3:
                displayAllocatedBlocks();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:    
                printf("Invalid choice.\n");
        }
    }while(choice != 4);
} 
*/

// QUESTION : PACKET PARSER USING STRUCTURES AND UNIONS
// Write a C program that simulates a simple packet parser using structures and unions. The program should define a packet structure with different fields (e.g., header, payload, checksum) and use a union to represent different types of payloads (e.g., text, binary data). The program should allow the user to input packet data and display the parsed information.
// Solution :
/*
#include<stdio.h>
#include<string.h>
#define MAX_PAYLOAD_SIZE 256
typedef struct {
    char text[MAX_PAYLOAD_SIZE];
} TextPayload;
typedef struct {
    unsigned char data[MAX_PAYLOAD_SIZE];
    size_t length;
} BinaryPayload;
typedef union {
    TextPayload textPayload;
    BinaryPayload binaryPayload;
} Payload;
typedef struct {
    unsigned int header;
    Payload payload;
    unsigned int checksum;
    int isText; // 1 for text, 0 for binary
} Packet;
unsigned int calculateChecksum(Packet *packet){
    unsigned int sum = packet->header;
    if(packet->isText){
        for(size_t i=0;i<strlen(packet->payload.textPayload.text);i++){
            sum += packet->payload.textPayload.text[i];
        }
    } else {
        for(size_t i=0;i<packet->payload.binaryPayload.length;i++){
            sum += packet->payload.binaryPayload.data[i];
        }
    }
    return sum;
}
void main(){
    Packet packet;
    printf("Enter packet header (unsigned int): ");
    scanf("%u",&packet.header);
    printf("Is the payload text or binary? (1 for text, 0 for binary
): ");
    scanf("%d",&packet.isText);
    if(packet.isText){
        printf("Enter text payload: ");
        getchar(); // Consume newline character
        fgets(packet.payload.textPayload.text, sizeof(packet.payload.textPayload.text), stdin);
        packet.payload.textPayload.text[strcspn(packet.payload.textPayload.text, "\n")] = 0; // Remove newline character
    } else {
        printf("Enter length of binary payload: ");
        scanf("%zu",&packet.payload.binaryPayload.length);
        printf("Enter binary payload (as space-separated bytes): ");
        for(size_t i=0;i<packet.payload.binaryPayload.length;i++){
            int byte;
            scanf("%d",&byte);
            packet.payload.binaryPayload.data[i] = (unsigned char)byte;
        }
    }
    packet.checksum = calculateChecksum(&packet);
    printf("Parsed Packet Information:\n");
    printf("Header: %u\n",packet.header);
    if(packet.isText){
        printf("Text Payload: %s\n",packet.payload.textPayload.text);
    } else {    
        printf("Binary Payload: ");
        for(size_t i=0;i<packet.payload.binaryPayload.length;i++){
            printf("%02X ",packet.payload.binaryPayload.data[i]);
        }
        printf("\n");
    }
    printf("Checksum: %u\n",packet.checksum);
} 
*/

//FILE HANDLING IN C:
// File handling in C allows programs to read from and write to files stored on disk. The standard library <stdio.h> provides functions for file operations such as opening, closing, reading, writing, and manipulating files. Files can be opened in different modes (e.g., read, write, append) depending on the desired operation.
// Opening and Closing Files:
/*
#include<stdio.h>
void main(){
    FILE *file; // Declare a file pointer
    // Open a file in write mode
    file = fopen("example.txt", "w");
    if(file == NULL){
        printf("Error opening file.\n");
        return;
    }
    // Write to the file
    fprintf(file, "Hello, World!\n");
    // Close the file
    fclose(file);
} 
*/
// Reading from a File:
/*
#include<stdio.h>
void main(){
    FILE *file; // Declare a file pointer
    char buffer[100];
    // Open a file in read mode
    file = fopen("example.txt", "r");
    if(file == NULL){
        printf("Error opening file.\n");
        return;
    }
    // Read from the file
    while(fgets(buffer, sizeof(buffer), file) != NULL){
        printf("%s", buffer);
    }
    // Close the file
    fclose(file);   
} 
*/
// Writing to a File:
/*
#include<stdio.h>
void main(){
    FILE *file; // Declare a file pointer
    // Open a file in append mode
    file = fopen("example.txt", "a");
    if(file == NULL){
        printf("Error opening file.\n");
        return;
    }
    // Write to the file
    fprintf(file, "Appending a new line.\n");
    // Close the file
    fclose(file);
}
*/
// File Modes in C:
// "r" - Read mode: Opens a file for reading. The file must exist.
// "w" - Write mode: Opens a file for writing. If the file exists, it is truncated to zero length. If the file does not exist, it is created.
// "a" - Append mode: Opens a file for writing at the end of the file. If the file does not exist, it is created.
// "r+" - Read and write mode: Opens a file for both reading and writing. The file must exist.
// "w+" - Write and read mode: Opens a file for both reading and writing. If the file exists, it is truncated to zero length. If the file does not exist, it is created.
// "a+" - Append and read mode: Opens a file for both reading and writing at the end of the file. If the file does not exist, it is created.


// RANDOM ACCESS FILE HANDLING IN C:
/*
#include<stdio.h>
void main(){
    FILE *file; // Declare a file pointer
    int numbers[5] = {10, 20, 30, 40, 50};
    // Open a file in binary write mode
    file = fopen("numbers.bin", "wb");
    if(file == NULL){
        printf("Error opening file.\n");
        return;
    }
    // Write the array to the file
    fwrite(numbers, sizeof(int), 5, file);
    fclose(file);
    // Open the file in binary read mode
    file = fopen("numbers.bin", "rb");
    if(file == NULL){
        printf("Error opening file.\n");
        return;
    }
    int num;
    // Seek to the third integer (index 2)
    fseek(file, 2 * sizeof(int), SEEK_SET);
    // Read the integer
    fread(&num, sizeof(int), 1, file);
    printf("The third number is: %d\n", num);
    fclose(file);
} 
*/
// If you want to read or write at a specific position in a file, you can use the fseek() function to move the file pointer to the desired location before performing read or write operations.
// If you want to open a file from different directory you can provide the full path of the file while opening it using fopen() function.


// QUESTION : EMLOYEE DATABASE MANAGER
// Write a C program to manage an employee database using structures. The program should allow the user to add, display, and search for employees based on their ID.
// Solution :
/*
#include<stdio.h>
#include<string.h>
#define MAX_EMPLOYEES 100
struct Employee {
    int id;
    char name[50];
    float salary;
};
struct Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;
void addEmployee(){
    if(employeeCount >= MAX_EMPLOYEES){
        printf("Employee database is full.\n");
        return;
    }
    struct Employee emp;
    printf("Enter Employee ID: ");
    scanf("%d",&emp.id);
    printf("Enter Employee Name: ");
    getchar(); // Consume newline character
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = 0; // Remove newline character
    printf("Enter Employee Salary: ");
    scanf("%f",&emp.salary);
    employees[employeeCount++] = emp;
    printf("Employee added successfully.\n");
}
void displayEmployees(){
    printf("Employee Database:\n");
    for(int i=0;i<employeeCount;i++){
        printf("ID: %d, Name: %s, Salary: %.2f\n",employees[i].id, employees[i].name, employees[i].salary);
    }
}
void searchEmployee(){
    int id;
    printf("Enter Employee ID to search: ");
    scanf("%d",&id);
    for(int i=0;i<employeeCount;i++){
        if(employees[i].id == id){
            printf("Employee Found: ID: %d, Name: %s, Salary: %.2f\n",employees[i].id, employees[i].name, employees[i].salary);
            return;
        }
    }
    printf("Employee with ID %d not found.\n",id);
}
void main(){
    int choice;
    do{
        printf("Menu:\n1. Add Employee\n2. Display Employees\n3. Search
    Employee\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }while(choice != 4);
} 
*/
//**********************************************  THE END  ******************************************************** */
