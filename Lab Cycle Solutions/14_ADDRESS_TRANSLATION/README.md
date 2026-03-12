# ALGORITHM

**Step 1:** Start

**Step 2:** Prompt the user to enter the size of the virtual address space in megabytes and store this value.

**Step 3:** Prompt the user to enter the page size in kilobytes and store this value.

**Step 4:** Calculate the total number of pages by converting the virtual address space size into bytes and dividing it by the page size converted into bytes.

**Step 5:** Create a page table array sized to hold the total number of pages and initialize all of its entries to zero to indicate that no pages are currently loaded in memory.

**Step 6:** Begin a continuous loop to process virtual addresses.

**Step 7:** Inside the loop, prompt the user to input a virtual address in decimal format, or enter negative one to exit the process.

**Step 8:** Check if the user entered the exit value; if so, break out of the continuous loop.

**Step 9:** Calculate the targeted page number by dividing the entered virtual address by the page size in bytes.

**Step 10:** Calculate the page offset by finding the remainder when the virtual address is divided by the page size in bytes.

**Step 11:** Verify if the calculated page number is greater than or equal to the total number of valid pages. If it is, display an error message stating the address is invalid and restart the loop to ask for a new input.

**Step 12:** Check the page table entry corresponding to the calculated page number.

**Step 13:** If the page table entry is zero, report a page miss to the console and update the entry to one, simulating loading the page into memory.

**Step 14:** If the page table entry is already one, report a page hit to the console, indicating the page is already loaded in memory.

**Step 15:** Print the requested virtual address, the calculated page number, and the calculated offset to the console.

**Step 16:** Repeat the loop from step 7 until the user chooses to exit.

**Step 17:** Stop.
