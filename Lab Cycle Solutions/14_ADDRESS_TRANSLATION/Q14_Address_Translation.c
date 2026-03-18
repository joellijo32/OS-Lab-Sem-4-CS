#include <stdio.h>

int main(void)
{
    long virt_addr_size;
    long page_size;
    long virt_addr;

    printf("Enter the virtual address space size (in MB): ");
    scanf("%ld", &virt_addr_size);

    printf("Enter the page size (in KB): ");
    scanf("%ld", &page_size);

    long page_size_bytes  = page_size * 1024;
    long total_pages      = (virt_addr_size * 1024 * 1024) / page_size_bytes;

    /* Page table: 0 = not in memory, 1 = in memory */
    int page_table[total_pages];
    for (int i = 0; i < total_pages; i++)
    {
        page_table[i] = 0;
    }

    while (1)
    {
        printf("\nEnter a virtual address (decimal) or -1 to exit: ");
        scanf("%ld", &virt_addr);

        if (virt_addr == -1)
        {
            break;
        }

        long page_number = virt_addr / page_size_bytes;
        long offset      = virt_addr % page_size_bytes;

        if (page_number >= total_pages || page_number < 0)
        {
            printf("Error: Invalid virtual address! Please try again.\n");
            continue;
        }

        if (page_table[page_number] == 0)
        {
            printf("Page MISS! Loading page %ld into memory...\n", page_number);
            page_table[page_number] = 1;
        }
        else
        {
            printf("Page HIT! Page %ld is already in memory.\n", page_number);
        }

        printf("  Virtual Address : 0x%lx (%ld)\n", virt_addr, virt_addr);
        printf("  Page Number     : %ld\n", page_number);
        printf("  Offset          : %ld\n", offset);
    }

    printf("\nExiting simulator.\n");
    return 0;
}