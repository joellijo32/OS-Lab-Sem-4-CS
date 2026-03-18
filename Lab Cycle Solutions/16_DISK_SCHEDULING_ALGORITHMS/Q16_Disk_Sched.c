#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CYLINDERS  5000
#define NUM_REQUESTS   10


void printRequests(int requests[], int n)
{
    printf("Disk requests: ");
    for (int i = 0; i < n; i++)
        printf("%d%s", requests[i], (i < n - 1) ? ", " : "\n");
}



int sstf(int requests[], int n, int head)
{
    int served[NUM_REQUESTS] = {0};   /* tracks which requests are done */
    int current = head;
    int totalMovement = 0;

    printf("\nSSTF order: %d", current);

    for (int count = 0; count < n; count++)
    {
        int minDist  = NUM_CYLINDERS + 1;
        int bestIdx  = -1;

        for (int i = 0; i < n; i++)
        {
            if (!served[i])
            {
                int dist = abs(requests[i] - current);
                if (dist < minDist)
                {
                    minDist = dist;
                    bestIdx = i;
                }
            }
        }

        served[bestIdx] = 1;
        totalMovement  += minDist;
        current         = requests[bestIdx];
        printf(" -> %d", current);
    }

    printf("\n");
    return totalMovement;
}

int look(int requests[], int n, int head)
{
    /* Sort a local copy of the requests */
    int sorted[NUM_REQUESTS];
    for (int i = 0; i < n; i++) sorted[i] = requests[i];

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (sorted[i] > sorted[j])
            {
                int tmp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = tmp;
            }

    /* Find insertion point for the head */
    int splitIdx = 0;
    while (splitIdx < n && sorted[splitIdx] < head)
        splitIdx++;

    int totalMovement = 0;
    int current       = head;

    printf("\nLOOK order: %d", current);

    /* Service requests >= head (moving upward first) */
    for (int i = splitIdx; i < n; i++)
    {
        totalMovement += abs(sorted[i] - current);
        current = sorted[i];
        printf(" -> %d", current);
    }

    /* Reverse and service requests < head (moving downward) */
    for (int i = splitIdx - 1; i >= 0; i--)
    {
        totalMovement += abs(sorted[i] - current);
        current = sorted[i];
        printf(" -> %d", current);
    }

    printf("\n");
    return totalMovement;
}

int cscan(int requests[], int n, int head)
{
    int sorted[NUM_REQUESTS];
    for (int i = 0; i < n; i++) sorted[i] = requests[i];

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (sorted[i] > sorted[j])
            {
                int tmp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = tmp;
            }

    int splitIdx = 0;
    while (splitIdx < n && sorted[splitIdx] < head)
        splitIdx++;

    int totalMovement = 0;
    int current       = head;

    printf("\nC-SCAN order: %d", current);

    /* Service requests >= head going upward */
    for (int i = splitIdx; i < n; i++)
    {
        totalMovement += abs(sorted[i] - current);
        current = sorted[i];
        printf(" -> %d", current);
    }


    if (splitIdx > 0)
    {
        /* Head moves to end of disk (4999), then wraps to 0 */
        totalMovement += (NUM_CYLINDERS - 1 - current) + (NUM_CYLINDERS - 1);
        current = 0;
        printf(" -> 0 (wrap)");

        for (int i = 0; i < splitIdx; i++)
        {
            totalMovement += abs(sorted[i] - current);
            current = sorted[i];
            printf(" -> %d", current);
        }
    }

    printf("\n");
    return totalMovement;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <initial_head_position>\n", argv[0]);
        return 1;
    }

    int head = atoi(argv[1]);

    if (head < 0 || head >= NUM_CYLINDERS)
    {
        fprintf(stderr, "Error: head position must be between 0 and %d.\n",
                NUM_CYLINDERS - 1);
        return 1;
    }

    srand((unsigned int)time(NULL));

    int requests[NUM_REQUESTS];
    for (int i = 0; i < NUM_REQUESTS; i++)
        requests[i] = rand() % NUM_CYLINDERS;

    printf("Disk cylinders : 0 – %d\n", NUM_CYLINDERS - 1);
    printf("Initial head   : %d\n", head);
    printRequests(requests, NUM_REQUESTS);
    printf("\n");

    int sstfMovement  = sstf (requests, NUM_REQUESTS, head);
    int lookMovement  = look (requests, NUM_REQUESTS, head);
    int cscanMovement = cscan(requests, NUM_REQUESTS, head);


    printf("\n%-30s %d cylinders\n", "SSTF total head movement:",  sstfMovement);
    printf("\n%-30s %d cylinders\n", "LOOK total head movement:",  lookMovement);
    printf("\n%-30s %d cylinders\n", "C-SCAN total head movement:", cscanMovement);


   printf("\n");

    return 0;
}
