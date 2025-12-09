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

