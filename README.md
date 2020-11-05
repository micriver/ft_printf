# ft_printf

A C program to print a formatted string to the standard output.

## What is This?

This project is my recreation of the original C programming language printf command with custom flags.

This was a very tedious project. Thankfully, I was able to grow a lot as a programmer, working with various data structures and programming concepts to bring the command to life. I learned that planning the structure of your program ahead of time is critical.

I'd like to revisit this project someday and make a ton of changes to the code and the overall logic flow.

For now, this project represents a turning point for me a programmer and I'm grateful I stuck it out!

## Installation

Download the repository by copying and pasting the commands below.

```bash
git clone https://github.com/micriver/ft_printf.git
cd ft_printf
```

You can compile the library using the Makefile:

| Command       | Action                                  |
| :------------ | :-------------------------------------- |
| `make`        | Compile the executable.                 |
| `make clean`  | Remove object files.                    |
| `make fclean` | Remove object files and the executable. |
| `make re`     | Re-compile the executable.              |

After compilation, you can use the ft_printf function inside your C programs like so:

```C
int main(void) {
  ft_printf("Mike");
  return (0);
}
```
