*This project has been created as part of the 42 curriculum by 'joaobarb' and 'jpaulo-b'.*

# **Description**

Minishell is a project that challenges us to create our own mini-shell from scratch. The objective is to replicate the core behavior of Bash, handling command execution, system calls, process management, and built-in functions. 

Through this project, we dived deep into UNIX mechanisms, learning how processes are created, destroyed, and synchronized, as well as how the file system interacts with input/output streams.

### Key Features Implemented:
* **Interactive Prompt:** Displays a prompt while waiting for a new command.
* **Command History:** Working history utilizing the `readline` library.
* **Execution:** Locates and executes the correct executables (based on the `PATH` variable or absolute/relative paths).
* **Redirections:** * `<` redirects input.
    * `>` redirects output (truncates).
    * `<<` heredoc (reads input until a delimiter is seen).
    * `>>` redirects output (appends).
* **Pipes (`|`):** Connects the output of one command to the input of the next.
* **Environment Variables:** Expands `$` variables (including `$?` for the last exit status).
* **Signals:** Handles `Ctrl-C`, `Ctrl-D`, and `Ctrl-\` similarly to Bash.
* **Built-ins:** `echo`, `cd`, `pwd`, `export`, `unset`, `env`, and `exit`.

# **Instructions**

### Prerequisites
To compile and run this project, you need a UNIX-based system (Linux/macOS) and the `readline` library installed.

On Debian/Ubuntu-based systems:

`sudo apt-get install libreadline-dev`

### Compilation

Clone the repository and compile the project using make.

### Running the Shell

After compilation, launch the executable:

`./minishell`

### Usage Examples

You can test the shell with standard commands, pipes, and redirections:

```bash
minishell$ ls -la | grep "README" > output.txt
minishell$ cat < output.txt
minishell$ echo $USER status code: $?
```

# **Resources**

- Official Documentation:

>.man pages for system calls: fork(2), execve(2), waitpid(2), pipe(2), dup2(2), and sigaction(2).

- Libraries & Guides:

>.GNU Readline Library - Documentation for handling command-line editing and history.
>.The Linux Command Line by William Shotts - Great book for understanding shell behavior and scripting.

- Tutorials & Articles:

>.Write a Shell in C - Stephen Brennan's fundamental guide to shell architecture.
>.CodeVault YouTube Channel - Excellent video tutorials on UNIX processes, pipes, and signal handling.
        
- https://man7.org/linux/man-pages/man2;
- valgrind.org/docs/manual/quick-start.html;
- www.w3schools.com/c/;
- Damas, Luis; "Linguagem C"; FCA; 25ed 2025;
- Pereira, Alexandre; "C e Algoritmos"; Ed. Silabo; 3ed 2023;
- We used Chat-GPT, Gemini and CoPilot to learn the concepts and sometimes to debug (after GDB and Valgrind).



