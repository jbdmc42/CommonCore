# Minishell

*This project has been created as part of the 42 curriculum by joaobarb*

## Description

**Minishell** is a project where the student experience the difficulties of the programmers back in the days when *Windows* didn't exist. They must replicate part of the experience of the linux command console (*CMD*) based on *Bash*.

### The Heart of the project

The main and most important part of this project is the way the program will receive and interpret the input from the user. 
As a mechanism to easily separate all the elements of the input, one can use a tokenization system, dividing the elements by type.

**Token types**
- **WORD**      : a group of characters that can be written directly, in single or double quotes ('' or ""), and commands
- **PIPE**      : any separated '|' character
- **GREAT**     : any separated '>' character
- **DGREAT**    : any separated '>>' group of characters
- **LESS**      : any separated '<' character
- **DLESS**     : any separated '<<' group of characters

