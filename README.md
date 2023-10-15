<img src="https://i.imgur.com/HG66CCx.png?raw=true" alt="CODAM" style="max-width: 50%;">

# ft_Printf

The ft_printf project is my second project as a student of the Codam coding college and a fundamental exercise in the C programming language. It is designed to replicate the functionality of the standard C library function **printf**.  
This project tasked me with creating a custom version of printf capable of handling various format specifiers and options.

In this project, we implement a function that accepts a format string and a variable number of arguments, using variadic functions. The format string contains special placeholders, such as %d for integers or %s for strings, which indicate how the arguments should be formatted and displayed.

---

### Key Objectives
- Parsing: Extract information from the format string to identify the type and order of arguments.
- Formatting: Apply the specified format to each argument before outputting it.
- Output: Display the formatted output to the console or return it as a string.
- Variadic functions in C.

---

### Usage*:

- **Clone the repository:**

  Either use the following command in your terminal: `git clone https://github.com/arommers/ft_printf.git`  
  Or Click the green "Code" button in the upper right corner to download zip file and then unzip it.
- **Compile the program using the cmd** &nbsp;&nbsp;`make`
- **Run a test case like the example below:**

```
#include "ft_printf.h"

int main() {
    ft_printf("Hello, %s! You have %d new messages.\n", "User", 3);
    return 0;
}
```

**As of now the instruction only partain to making the program on MacOS. Use on linux or windows systems at your own risk ;)*

---

## The Program

Ft_printf is designed to handle various format specifiers, allowing it to print different types of data. The format specifiers are: `cspdiuxX%`. Meaning that 'c' will print a character, 'i' an int, etc. For the specific requirements of this program I would like to refer you to the [subject file](https://cdn.intra.42.fr/pdf/pdf/99964/en.subject.pdf).  
The ft_printf function employs variadic functions to process a format string and its associated arguments. When encountering a % character in the format string, it calls [ft_converter function](https://github.com/arommers/ft_printf/blob/main/ft_printf.c) to handle the specific conversion based on the next character in the format string.

### Variadic functions

Ft_printf is a variadic function, which are a versatile toolbox in C programming. What makes them so versatile is that they possess a unique capability, akin to an ellipse that can expand or contract as needed. This is defined in the formatting of the function by the three dots as the second argument:  

 `ft_printf(const char *s, ...)`  
 
 This feature allows them to gracefully handle an undefined number of arguments. In the ft_printf project, we utilize variadic functions to process format specifiers and manage a dynamic set of arguments.
 Below is an example of the use of a variadic function:
```
 void example_function(int count, ...)
{
    va_list ap;
    va_start(ap, count); // Initialize ap to point to the first unnamed argument

    for (int i = 0; i < count; i++)
    {
        int arg = va_arg(ap, int); // Get the next argument as an integer
        printf("Argument %d: %d\n", i, arg);
    }
    va_end(ap); // End use of variable arguments
}

int main()
{
    example_function(3, 10, 20, 30); // This will print the three arguments
    return (0);
}
```

Our fundamental tools to work with variable arguments are : `va_list`, `va_start`, and `va_end`.

- **Initializing va_list:**  
  When we call `va_start(ap, s)`, it's akin to setting up an "iterator" (ap) for our arguments. This iterator is positioned at the first unnamed argument. In our case the first int '3'.

- **Accessing Variable Arguments:**  
  Once our va_list is set up, it allows us to seamlessly access each argument, making it appear as if we're iterating through them.
  At initialization the iterator is set to the first unnamed argument after the last known named argument, `count`.

- **Using va_arg to Retrieve Arguments:**   
  When we encounter a format specifier (e.g., %d), we intruct `va_arg(ap, type)` to fetch the next argument of the specified type. This is akin to advancing our "iterator" to access the next argument.
  In our case all our arguments after the last named argument are 'ints', but it could just as well be a mix of different data types.

- **Automatic Advancement of va_list:**  
  After we retrieve an argument with va_arg, our va_list is automatically moved forward, positioning us to access the next argument in line.

- **Ending Variadic Argument Usage:**  
  It's important to wrap up our work with variable arguments by calling va_end(ap). This step ensures any necessary cleanup related to variable arguments is performed.

In the context of ft_printf, these concept allowi us to process format specifiers and handle a dynamic number of arguments effectively.

---

## Remarks

It's important to note that the function doesn't have any built-in mechanism to check if the number of arguments matches the format string. It relies on the User to provide the correct number and types of arguments.

---

### Sources

- [Format specifiers in 'printf'](https://cplusplus.com/reference/cstdio/printf/)
- [Subject File](https://cdn.intra.42.fr/pdf/pdf/99964/en.subject.pdf)

