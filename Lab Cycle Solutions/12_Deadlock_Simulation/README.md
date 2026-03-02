# AIM
Obtain a process mix and determine if the system is deadlocked.    

# ALGORITHM

**Step 1:** Start

**Step 2:** Read the number of processes P and the number of resource types R.

**Step 3:** Read the matrices Allocation[P][R], Max[P][R], and the vector Available[R]. 

**Step 4:** For each process i, set finished[i] = false.

**Step 5:** Set count = 0.

**Step 6:** Compute the Need matrix using Need[i][j] = Max[i][j] - Allocation[i][j] for all processes i and resources j.

**Step 7:** Repeat the following steps until count = P.

**Step 8:** Set found = false.

**Step 9:** For each process i such that finished[i] = false, perform the following checks.

**Step 10:** Check whether for every resource j, Need[i][j] <= Available[j].

**Step 11:** If the condition is satisfied, simulate execution of process i by setting Available[j] = Available[j] + Allocation[i][j] for all resources j.

**Step 12:** Set safeSequence[count] = i.

**Step 13:** Set finished[i] = true.

**Step 14:** Increment count by 1.

**Step 15:** Set found = true.

**Step 16:** After checking all processes in the current pass, if found = false, terminate and report that the system is not in a safe state.

**Step 17:** If count = P, report that the system is in a safe state and print the safe sequence.

**Step 18:** Stop.
