# Readers - Writers Algorithm (Writer Priority)

## 1. Main Method
* **Step 1:** Start.
* **Step 2:** Allocate memory for a shared data structure containing reader/writer counts and semaphores.
* **Step 3:** Initialize reader count (`rc`) and writer count (`wc`) to 0, and all semaphores (`mutex`, `w_mutex`, `rw_mutex`, `r_mutex`) to 1.
* **Step 4:** Create multiple Reader and Writer threads concurrently using thread identifiers.
* **Step 5:** Wait for all spawned threads to finish their execution using the join operation.
* **Step 6:** Destroy all initialized semaphores and free the allocated memory for the data structure.
* **Step 7:** Stop.

---

## 2. Function: Readers
* **Step 1:** Wait on the `r_mutex` and immediately signal it to pass through the turnstile.
* **Step 2:** Wait on `mutex` to safely access the reader count.
* **Step 3:** Increment the reader count (`rc`).
* **Step 4:** If the current thread is the first reader, wait on `rw_mutex` to lock the file from writers.
* **Step 5:** Signal `mutex` to allow other readers to update the count.
* **Step 6:** Enter the critical section and perform the reading operation.
* **Step 7:** Wait on `mutex` to safely decrement the reader count.
* **Step 8:** Decrement the reader count (`rc`).
* **Step 9:** If the current thread is the last reader, signal `rw_mutex` to unlock the file for writers.
* **Step 10:** Signal `mutex` and exit the function.

---

## 3. Function: Writers
* **Step 1:** Wait on `w_mutex` to safely access the writer count.
* **Step 2:** Increment the writer count (`wc`).
* **Step 3:** If the current thread is the first writer, wait on `r_mutex` to block new readers from entering the turnstile.
* **Step 4:** Signal `w_mutex` to allow other writers to update the count.
* **Step 5:** Wait on `rw_mutex` to obtain exclusive access to the file.
* **Step 6:** Enter the critical section and perform the writing operation.
* **Step 7:** Signal `rw_mutex` to release the file lock.
* **Step 8:** Wait on `w_mutex` to safely decrement the writer count.
* **Step 9:** Decrement the writer count (`wc`).
* **Step 10:** If the current thread is the last writer, signal `r_mutex` to reopen the turnstile for readers.
* **Step 11:** Signal `w_mutex` and exit the function.
