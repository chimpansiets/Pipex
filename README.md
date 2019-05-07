
# Pipex

Pipex is a 48-hour project at Codam Coding college located in Amsterdam.
In this project we needed to recreate the UNIX Pipeline.
In Unix-like computer operating systems, a pipeline is a mechanism for
inter-process communication using message passing.
We recreate this by creating temporary processes inbetween, so that the output of
process 1, is directly used as input for process 2.

## Getting Started

Run make, and my makefile will compile a binary called "pipex".
run this binary, and you can now specify the files from which to read, and
the commands to use.

e.g.
```
./pipex
Usage: ./pipex file1 cmd1 cmd2 file2
```
