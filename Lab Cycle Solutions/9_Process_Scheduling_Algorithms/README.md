# AIM
Input a list of processes, their CPU burst times (integral values), arrival times, and
priorities. Then simulate FCFS, SRTF, non-preemptive priority (a larger priority number
implies a higher priority), and RR (quantum = 3 units) scheduling algorithms on the process mix, determining which algorithm results in the minimum average waiting time
(over all processes).     

# ALGORITHM

**Step 1:** Start the overall simulation program.     

**Step 2:** Prompt the user to enter the total number of processes to be simulated and store this value.

**Step 3:** Iterate through the total number of processes to accept and store the details for each individual process, specifically its ID, Arrival Time, Burst Time, and Priority.

**Step 4:** Begin the First-Come, First-Served (FCFS) scheduling evaluation by passing the process list.

**Step 5:** Inside the FCFS evaluation, sort a copy of the processes in ascending order based strictly on their arrival times.

**Step 6:** For each process in the sorted FCFS list, calculate its completion time, turnaround time, and waiting time sequentially, while recording the sequence of process IDs to build a Gantt chart.

**Step 7:** Print the FCFS scheduling table, display the generated Gantt chart, and calculate the overall average waiting and turnaround times.      

**Step 8:** Begin the Non-Preemptive Priority scheduling evaluation using the original process list.

**Step 9:** Inside the Priority evaluation, iteratively scan the processes to find the one that has already arrived, is not yet completed, and has the highest priority value (largest integer).

**Step 10:** Process the selected highest-priority task to completion by calculating its completion, turnaround, and waiting times, recording its ID for the Gantt chart, updating the system time, and marking it as complete.

**Step 11:** Print the Priority scheduling table, display its generated Gantt chart, and calculate the overall average waiting and turnaround times.

**Step 12:** Begin the Round Robin scheduling evaluation using the original process list and a predefined time quantum of 3 units.

**Step 13:** Inside the Round Robin evaluation, continuously loop through the available processes, allocating CPU time up to the maximum limit of the time quantum, and reducing their remaining burst times accordingly.

**Step 14:** When a process completes its execution in Round Robin, calculate its final completion, turnaround, and waiting times, track its execution segments for the Gantt chart, and increment the count of completed processes.

**Step 15:** Print the Round Robin scheduling table, display its generated Gantt chart, and calculate the overall average waiting and turnaround times.

**Step 16:** Begin the Shortest Remaining Time First (SRTF) scheduling evaluation using the original process list.

**Step 17:** Inside the SRTF evaluation, check every single time unit to find the arrived process with the absolute minimum remaining burst time. 

**Step 18:** If multiple processes have the exact same minimum remaining time in SRTF, resolve the tie by selecting the one with the earliest arrival time, and if ties still exist, pick the one with the smaller process ID.

**Step 19:** Execute the selected SRTF process for one time unit, reduce its remaining time, track its ID for the Gantt chart, and if it finishes, calculate its scheduling metrics. Repeat this unit-by-unit simulation until all processes finish.

**Step 20:** Print the SRTF scheduling table, display its generated Gantt chart, and calculate the overall average waiting and turnaround times.

**Step 21:** Compare the newly calculated average waiting times from all four scheduling algorithms (FCFS, Priority, Round Robin, and SRTF) to find the minimum value.

**Step 22:** Print the final comparison results and explicitly state the name of the scheduling algorithm that performed the best by yielding the lowest average waiting time.

**Step 23:** Stop.