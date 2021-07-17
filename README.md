# OS-shell
A small OS shell program
This is a very simple OS shell.
It waits for you to enter command from a set of
commands that we will specify below. If the command is a built-in command, as indicated
below, your process will just execute it. If not, then it must do two things: fork a new process,
then uses execve to make this new child process morph to the new process. The non-built-in
commands will be basic Linux commands that you do no need to write, just launch them using
the combination for fork and execve. If the user types the word “exit” then the program ends.
Otherwise, another iteration will be executed

The Built-in Commands
If the user enters one of the following commands, then do not fork and execve but execute
them directly in your current process. You can implement each command as a function, except
exit of course, and you call that function when you compare the user input string with the
commands below. The commands are case sensitive.
 printid : print on the screen The ID of the current process is X where x is the process ID.
 exit : ends the program and exits.
 greet: prints “Hello\n” on the screen

Commands That Require fork and execve
 /bin/ls : lists the files in the current directory
 /bin/pwd : prints the path of the current working directory
 /bin/ps : prints the status of the current processes
 /bin/date : prints current date and time.
 /bin/lscpu: prints information about the current processes of the machine. 
