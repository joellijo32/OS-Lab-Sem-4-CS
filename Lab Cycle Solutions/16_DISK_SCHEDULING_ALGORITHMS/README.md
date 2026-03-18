# AIM
Simulate the SSTF, LOOK, and CSCAN disk-scheduling algorithms as follows: Your
program will service a disk with 5,000 cylinders numbered 0 to 4,999. The program will
generate a random series of 10 cylinder requests and service them according to each of the
algorithms listed earlier. The program will be passed the initial position of the disk head
(as a parameter on the command line) and will report the total number of head movements
required by each algorithm.         
             
# ALGORITHM

**Step 1:** Start

**Step 2:** Check if the user has provided exactly one command-line argument for the initial head position. If not, print an error message and terminate the program.

**Step 3:** Convert the provided command-line argument from a text string into an integer to serve as the initial disk head position.

**Step 4:** Validate the initial head position to ensure it falls within the valid cylinder range (0 to 4999). If it is out of bounds, print an error and terminate.

**Step 5:** Initialize the random number generator using the current system time to ensure the sequence of requests is unique on each run.

**Step 6:** Generate a predefined number of random disk cylinder requests (10 requests) and store them in an array.

**Step 7:** Print the total disk cylinder range, the initial head position, and the randomly generated sequence of requests to the console.

**Step 8:** Begin the Shortest Seek Time First (SSTF) scheduling simulation.

**Step 9:** In the SSTF simulation, repeatedly scan the list of pending requests to find the unserved request that is physically closest to the current head position.

**Step 10:** Move the head to this closest request, mark it as served, add the travel distance to the SSTF total movement, and record the path. Repeat this until all requests are served.

**Step 11:** Begin the LOOK scheduling simulation.

**Step 12:** In the LOOK simulation, create a local copy of the original requests and sort them in ascending order.

**Step 13:** Locate the splitting index where the initial head position fits within the sorted requests to divide them into smaller and larger target values.

**Step 14:** Move the head upward to sequentially service all requests greater than or equal to the initial head position, accumulating the travel distance.

**Step 15:** Reverse the head direction and move downward to sequentially service all remaining requests smaller than the initial head position, accumulating the travel distance.

**Step 16:** Begin the Circular SCAN (C-SCAN) scheduling simulation.

**Step 17:** In the C-SCAN simulation, sort a local copy of the requests and find the splitting index exactly as done in the LOOK algorithm.

**Step 18:** Move the head upward to sequentially service all requests greater than or equal to the initial head position, accumulating the travel distance.

**Step 19:** After servicing the highest request, jump the head to the maximum end of the disk (cylinder 4999), immediately wrap it back to cylinder 0, and accumulate this combined wrap-around seek distance.

**Step 20:** Continue moving the head upward from cylinder 0 to sequentially service the remaining lower-value requests, accumulating the final travel distance.

**Step 21:** Print the total head movements calculated for the SSTF, LOOK, and C-SCAN algorithms so they can be compared.

**Step 22:** Stop.
