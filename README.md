# Pipex Project

## Overview
This project is part of the 42 school curriculum, focusing on understanding UNIX mechanisms like pipes and process management. The "pipex" program simulates the behavior of the shell's pipe mechanism, using the `|` operator to pass the output of one command as the input to another command.

## Mandatory Part

### Description
The mandatory part of the project requires creating a program named `pipex`, which should be executed as follows:
```bash
./pipex file1 cmd1 cmd2 file2
```
This should behave like the following shell command:

```bash
< file1 cmd1 | cmd2 > file2
```
pipex takes four arguments: input file (file1), first command (cmd1), second command (cmd2), and output file (file2). It reads from file1, applies cmd1, pipes the result to cmd2, and writes the result to file2.

## Usage
1. Clone the repository:
```bash
git clone <repository-url>
```

2. Compile the program:
```bash
   make
```

3. Execute Pipex:
  ```bash
  ./pipex file1 "cmd1" "cmd2" file2
  ```

## Bonus Part

## Description
The bonus part of the project enhances the functionality of the pipex program to handle multiple pipes. It should be able to handle an arbitrary number of commands:
bash
```
./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```
This should mimic the behavior of:
```bash
< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
```

### Additional Features
Support for multiple pipes.
Implementation of the here_doc feature:
```bash
./pipex here_doc LIMITER cmd1 cmd2 file2
```
This behaves similarly to:
```bash
cmd1 << LIMITER | cmd2 > file2
```
### Usage
Follow the same steps as in the Mandatory part to compile and run the program, adjusting the command line as needed for multiple commands or the here_doc functionality.
Contributions

Contributions to improve or enhance pipex are welcome. Feel free to fork this project and submit pull requests for any improvements.
