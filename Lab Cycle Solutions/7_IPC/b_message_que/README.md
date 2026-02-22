# ALGORITHM 2

**Step 1:** Start

**Step 2:** Define a helper function to reverse a given text string by swapping characters from the beginning and the end until the middle is reached.

**Step 3:** In the main execution, initialize the configuration attributes for the message queues, specifying the maximum number of messages and the maximum size for each message.      
        
**Step 4:** Create and open two separate message queues with read and write permissions to allow two-way communication.

**Step 5:** Create a new child process by duplicating the current parent process.

**Step 6:** Check if the current execution stream belongs to the newly created child process.

**Step 7:** If it is the child process, wait to receive a text message from the first message queue and store it.

**Step 8:** Call the helper function to reverse the text string received from the parent.

**Step 9:** Send the newly reversed text string into the second message queue.

**Step 10:** Close the connections to both message queues in the child process and finish the child's specific tasks.

**Step 11:** If the current execution stream belongs to the parent process, prompt the user to input a text string from the console.

**Step 12:** Read the user's input string and carefully remove any trailing newline characters from the end.

**Step 13:** Send the original input string into the first message queue so the child process can read it.

**Step 14:** Pause and wait to receive the processed response from the second message queue, storing it in a separate buffer.

**Step 15:** Print the received reversed string to the console for the user to see.

**Step 16:** Compare the original input string directly with the received reversed string.

**Step 17:** If the two strings are exactly identical, print a message stating that the string is a palindrome.

**Step 18:** If the two strings are not identical, print a message stating that the string is not a palindrome.

**Step 19:** Close the connections to both message queues in the parent process.

**Step 20:** Wait for the child process to completely finish its execution to safely clean up the process.

**Step 21:** Delete and remove both message queues from the system entirely to free up operating system resources.

**Step 22:** Stop.
