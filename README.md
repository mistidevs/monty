<h1>Monty Bytecode 0.98 Interpreter</h1>
<h2><b>Disclaimer</b></h2>
<p>Even though this project is Open Source and under Creative Commons it is <b>strictly forbidden</b> to use this code for the ALX Project- 0x19. C - Stacks, Queues - LIFO, FIFO<br>
As of October 2023 the code meets the requirements of the checker. Notwithstanding, it is immoral to plagiarise this work in order to get 200% in the project. Morality, is more important than some crazy high score. Kimba is watching.<br>
Nonetheless, after you have completed the project and for those not affiliated in any way to an ALX Software Engineering program the code is open for modification as your heart and mind pleases. </p>

<h2>Abstract</h2>
<p>
  The interpreter is built using the C programming language. It is built in collaboration with ALX Africa hence is Betty Compliant and uses C90 standard code. There is a precompiled interpreter that handles almost all(I desire to claim all but as we all know software fails) edge cases. It outputs sensible code errors in case a coomand if invalid Monty syntax. To compile your code in case you modify the source code:

```
 gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```

To check if your changes are Betty Compliant
```
betty *.c monty.h
```

The code is implemented using stacks and queues in C. There are no memory leaks present.<br>
The v1 folder holds my version of the interpreter that stops if it encounters an empty line. Moreover, rather than using the getline function and FILE pointers it reads a file into a char pointer. As the first iteration of the interpreter it lacks opcodes like pchar, pstr and the ability to switch from a stack to queue. Should anyone be interested in adding these features to the v1 do feel free to do so. The code is open source and under Creative Commons Attributions 3.0. Create a pull request or clone the repo for your personal use. The repo may reinvent the wheel but it will allow you to implement a low level abstraction version of the interpreter that perfectly intergrates with whatever hardware you are using.
</p>

<h2>Notes</h2>
<p>Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.</p>

<h3>Monty byte code files</h3>

<p>Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:</p>

```
julien@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
julien@ubuntu:~/monty$
```

<p>Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:</p>

```
julien@ubuntu:~/monty$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
julien@ubuntu:~/monty$
```
