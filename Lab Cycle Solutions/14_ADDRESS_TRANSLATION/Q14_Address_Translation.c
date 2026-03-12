// Address Translation #include <stdio.h>
int main() { long virt_addr_size; long page_size; long virt_add;
printf("Enter the virtual address space size (in mb): ");
scanf("%ld", &virt_addr_size);

printf("Enter the page size (in kb): ");
scanf("%ld", &page_size);

long total_pages = (virt_addr_size * 1024 * 1024) / (page_size * 1024);
// check for page hit / miss
// page table
int page_table[total_pages];
for (int i = 0; i < total_pages; i++)
{
    page_table[i] = 0; // 0 means page is not in memory
}


while (1)
{
    printf("Enter a virtual address (in dec) or -1 to exit: ");
    scanf("%ld", &virt_add);

    if (virt_add == -1)
    {
        break;
    }

    long page_number = virt_add / (page_size * 1024);
    long offset = virt_add % (page_size * 1024);

    if (page_number >= total_pages)
    {
        printf("Invalid virtual address! Please try again.\n");
        continue;
    }

    if (page_table[page_number] == 0)
    {
        printf("Page miss! Loading page into memory...\n");
        page_table[page_number] = 1;
    }
    else
    {
        printf("Page hit! Page is already in memory.\n");
    }

    printf("Virtual Address: 0x%ld, Page Number: %ld, Offset: %ld\n", virt_add, page_number, offset);
}

return 0;
}
