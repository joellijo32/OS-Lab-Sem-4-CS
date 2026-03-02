# AIM
Write a multithreaded program that calculates the mean, median, and standard deviation
for a list of integers. This program should receive a series of integers on the command line
and will then create three separate worker threads. The first thread will determine the
mean value, the second will determine the median and the third will calculate the standard
deviation of the integers. The variables representing the mean, median, and standard
deviation values will be stored globally. The worker threads will set these values, and the
parent thread will output the values once the workers have exited.    

# ALGORITHM


**Step 1:** Start the program.

**Step 2:** Declare global variables to store the final computed values for the mean, median, and standard deviation.

**Step 3:** Define a custom data structure that will hold a collection of numbers and the total count of those numbers, which will be passed to each parallel task.

**Step 4:** Check if the user has provided numbers as command-line inputs. If not, display an error message and terminate the execution.

**Step 5:** Convert the provided text inputs into a collection of integers and print the entered numbers to the screen.

**Step 6:** Package the collection of integers and its size into the previously defined data structure.

**Step 7:** Define a designated routine to calculate the mean. Inside this routine, iterate through the numbers, sum them up, divide the total sum by the count of numbers, and store the final value in the global mean variable.

**Step 8:** Create the first independent execution thread to run the mean calculation routine, passing the data structure to it.  Pause the main program and wait for this specific thread to completely finish its execution.

**Step 9:** Define a designated routine to calculate the median. Inside this routine, create a temporary copy of the numerical collection, sort the numbers in ascending order, find the middle value (or the average of the two middle values if the count is even), save the result in the global median variable, and release the temporary copy's memory.

**Step 10:** Create the second independent execution thread to run the median calculation routine, passing the data structure to it. Pause the main program and wait for this specific thread to completely finish its execution.

**Step 11:** Define a designated routine to calculate the standard deviation. Inside this routine, compute the average of the numbers, calculate the sum of the squared differences from this average, find the square root of that sum divided by the count, and store the result in the global standard deviation variable.      

**Step 12:** Create the third independent execution thread to run the standard deviation calculation routine, passing the data structure to it. Pause the main program and wait for this specific thread to completely finish its execution.

**Step 13:** Print the final calculated values for the mean, median, and standard deviation to the console.

**Step 14:** Stop.