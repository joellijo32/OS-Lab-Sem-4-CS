# AIM
(a) Using Pipe – Evaluate the expression $\sqrt{b^2 - 4ac}$. The first process
evaluates $b^2$. The second process evaluates 4ac and sends it to the first
process which evaluates the final expression and displays it.      

(b) Using Message Queue - The first process sends a string to the second
process. The second process reverses the received string and sends it back
to the first process. The first process compares the original string and the
reversed string received from the second one and then prints whether the
string is a palindrome or not.      

(c) Using Shared Memory - The first process sends three strings to the second
process. The second process concatenates them to a single string (with
whitespace being inserted between the two individual strings) and sends it
back to the first process. The first process prints the concatenated string in
the flipped case, that is if the concatenated string is “Hello S4 Students”,
the final output should be “hELLO s4 sTUDENTS”      

# ALGORITHM 1

**Step 1:** Start 

**Step 2:** Declare an integer array `fd[2]` for the pipe file descriptors, integer variables `a`, `b`, `c` for inputs, and `pid` for the process ID.

**Step 3:** Prompt the user to enter the values for coefficients `a`, `b`, and `c` and read them using `scanf`.

**Step 4:** Create a pipe using the `pipe(fd)` system call and checks if it returns -1.

**Step 5:** If the pipe creation fails, print "Pipe failed" and terminate the program with a return status of 1.

**Step 6:** Create a child process using the `fork()` system call and store the result in `pid`.

**Step 7:** If `pid` is less than 0, print "Fork failed" and terminate the program with a return status of 1.

**Step 8:** Check if `pid` is equal to 0 to identify the child process.

**Step 9:** Inside the child process, close the read end of the pipe `fd[0]`.

**Step 10:** Calculate the value of `4 * a * c` and store it in an integer variable named `output`.

**Step 11:** Print the calculated value of `4ac` to the console.

**Step 12:** Write the value of `output` to the write end of the pipe `fd[1]`.

**Step 13:** Close the write end of the pipe `fd[1]` and terminate the child process.

**Step 14:** If `pid` is greater than 0, execute the parent process block.

**Step 15:** Inside the parent process, close the write end of the pipe `fd[1]`.

**Step 16:** Calculate `b * b` and print the result.

**Step 17:** Read the integer value sent by the child process from the read end of the pipe `fd[0]` into the variable `recieved`.

**Step 18:** Print the received value of `4ac` and close the read end of the pipe `fd[0]`.

**Step 19:** Calculate the final result as the square root of `(b * b) - recieved`.

**Step 20:** Print the final result.

**Step 21:** Wait for the child process to complete using `wait(NULL)`.

**Step 22:** Stop 
