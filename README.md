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
- **Compile the program using the cmd** &nbsp;&nbsp;`make
- **Run a test case like the example below:**

```
#include "ft_printf.h"

int main() {
    ft_printf("Hello, %s! You have %d new messages.\n", "User", 3);
    return 0;
}
```

