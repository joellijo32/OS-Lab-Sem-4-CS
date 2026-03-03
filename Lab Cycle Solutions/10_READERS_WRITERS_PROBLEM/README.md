# AIM
Use semaphores to solve the readers-writers problem with writers being given priority
over readers.    

#  ALGORITHM     
       
**Step 1:** Start      

**Step 2:** Declare global synchronization objects (semaphores) to manage access to the shared resource, queue read/write attempts, and provide mutual exclusion for the reader counter.

**Step 3:** Declare global integer variables to keep track of the number of active readers and to represent the shared data itself, initializing both to zero.

**Step 4:** Begin the main execution block by initializing all three synchronization objects to an initial value of one.    

**Step 5:** Create three separate reader threads, assigning each a unique numerical identifier, and start their execution.

**Step 6:** Create two separate writer threads, assigning each a unique numerical identifier, and start their execution.

**Step 7:** Define the reader's routine. Inside this routine, set up a loop to repeat the reading process a fixed number of times.

**Step 8:** Within the reader's loop, wait for permission to attempt reading (which blocks if a writer is waiting) and lock the mutual exclusion object to safely update the reader count.

**Step 9:** Increase the active reader count by one. If this is the very first reader, lock the main resource to prevent any writers from accessing the shared data.

**Step 10:** Unlock the mutual exclusion object and release the read attempt permission so other readers or writers can queue up.

**Step 11:** Enter the critical section, read the current value of the shared data, print a message indicating which reader is reading what value, and pause execution briefly.

**Step 12:** Lock the mutual exclusion object again to safely decrease the active reader count by one, and print a message indicating the reader is exiting the critical section.

**Step 13:** If the active reader count drops to zero (meaning it is the last reader), unlock the main resource to allow any waiting writers to enter.

**Step 14:** Unlock the mutual exclusion object and pause execution briefly before starting the next iteration.

**Step 15:** Define the writer's routine. Inside this routine, set up a loop to repeat the writing process a fixed number of times.

**Step 16:** Within the writer's loop, wait for permission to attempt writing (which prevents new readers from entering) and lock the main resource to ensure exclusive access to the shared data.

**Step 17:** Enter the critical section, increment the value of the shared data by one, print a message indicating which writer is writing the new value, and pause execution briefly.

**Step 18:** Print a message indicating the writer is exiting the critical section.

**Step 19:** Unlock the main resource and release the read/write attempt permission, allowing others to enter, then pause execution briefly before the next iteration.

**Step 20:** Back in the main execution block, wait for all reader threads and all writer threads to completely finish their tasks.

**Step 21:** Destroy all synchronization objects to clean up and free system resources.

**Step 22:** Stop.
