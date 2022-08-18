## About Myshell Program

In this project, it is aimed to program a shell in C language, where we create our own commands and call different programs using the fork and exec structure. We have five programs in the project; myshell.c, process.c, sum.c, eject.c and repeat.c The command list and other programs are called through our main program myshell. Our script includes help, exit, repeat and operation commands. When the Help command is called, the commands in the shell are listed. The shell continues to run until the exit command is called. Calling exit exits the shell.

**The repeat** command takes two parameters. The first parameter tells what to write to the terminal, and the second tells how many times the first parameter will be written. When the command is called again via Myshell, a new process is created by forking and the program.c is called again.

**The operation** command takes three parameters. The first parameter is add or subtract, the second and third parameters are the numbers to be used in addition/subtraction. When the collect command is called, parameters are sent to the collect.c program by forking over myshell.c, and the result is returned to the screen by performing the add operation. Likewise, when the exit command is called, fork is made from the main program and two numbers are sent to the exit.c program as a parameter and the result of the operation is displayed on the terminal.

When **the clear** command is called, the clear command located under the bin folder in the Linux operating system is called and the codes in the terminal are cleared. When the cat command is called, the command is called from under the bin folder in the same way and the text in the file in the parameter entered with the cat command is displayed in the terminal. Echo command shows the entered parameter in the terminal in a similar way. In order to facilitate the program to compile all the files one by one, a makefile file has been prepared and the program can be run through the makefile.

In the readLine[*] function, which is a line reading function to run more than one parameter, you can enter the while loop | condition is also added, so that the two command parameters are | It works together when written separately with the sign. In order to control the gaps between the parameters entered on the terminal screen, the splitLine[*] function is tokenized.

![SS1](https://github.com/omerkucuker/MyShell/blob/main/screens/myshell_ss.png?raw=true)
![SS2](https://github.com/omerkucuker/MyShell/blob/main/screens/myshell_catkomutu.PNG?raw=true)


