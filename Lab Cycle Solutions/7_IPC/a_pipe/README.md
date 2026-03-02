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

# Algorithm for Interprocess Communication using Pipes

**Step 1:** Start

**Step 2:** Prompt the user to input three separate numerical values representing 'a', 'b', and 'c', and store these values.

**Step 3:** Create a unidirectional communication channel (a pipe) to allow data to be passed between processes. 
**Step 4:** Verify if the communication channel was created successfully. If it failed, display an error message and terminate the program.

**Step 5:** Create a new child process by duplicating the current parent process.

**Step 6:** Verify if the child process was created successfully. If it failed, display an error message and terminate the program.

**Step 7:** Check if the current execution stream belongs to the newly created child process.

**Step 8:** Inside the child process, close the reading end of the communication channel since the child is only responsible for sending data.

**Step 9:** Calculate the product of four, the value of 'a', and the value of 'c'.

**Step 10:** Print the calculated product to the console to indicate the child process's computation.

**Step 11:** Send this calculated product through the writing end of the communication channel to the parent process.

**Step 12:** Close the writing end of the communication channel and successfully terminate the child process.

**Step 13:** If the current execution stream belongs to the parent process, close the writing end of the communication channel since the parent is only responsible for receiving data.

**Step 14:** Calculate the square of the value 'b' and print it to the console to indicate the parent process's independent computation.

**Step 15:** Read the product previously calculated and sent by the child process from the reading end of the communication channel.

**Step 16:** Print the received product to the console to confirm successful data transfer.

**Step 17:** Close the reading end of the communication channel as it is no longer needed.

**Step 18:** Calculate the final mathematical result by subtracting the received product from the square of 'b', and then finding the square root of that resulting difference.

**Step 19:** Print the final calculated square root result to the console.

**Step 20:** Pause the parent process and wait for the child process to completely finish its execution to prevent zombie processes.

**Step 21:** Stop.