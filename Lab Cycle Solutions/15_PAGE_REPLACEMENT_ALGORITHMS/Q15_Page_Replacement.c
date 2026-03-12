#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PAGES 1000
#define PAGE_RANGE 10
#define MAX_FRAMES 7

int search(int frames[], int frameCount, int page)
{
    for (int i = 0; i < frameCount; i++)
    {
        if (frames[i] == page)
            return i;
    }
    return -1;
}

void printMatrix(int matrix[][MAX_PAGES], int pages[], int frameCount, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", pages[i]);

    printf("\n");

    for (int i = 0; i < n * 2; i++)
        printf("_");

    printf("\n");

    for (int i = 0; i < frameCount; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == -1)
                printf("- ");
            else
                printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void populateMatrixColumn(int matrix[][MAX_PAGES], int frames[], int frameCount, int columnNumber)
{
    for (int i = 0; i < frameCount; i++)
        matrix[i][columnNumber] = frames[i];
}

int fifo(int pages[], int n, int frameCount, int matrix[][MAX_PAGES])
{
    int frames[MAX_FRAMES];
    int faults = 0;
    int index = 0;

    for (int i = 0; i < frameCount; i++)
        frames[i] = -1;

    for (int i = 0; i < frameCount; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = -1;

    for (int i = 0; i < n; i++)
    {
        if (search(frames, frameCount, pages[i]) == -1)
        {
            frames[index] = pages[i];
            index = (index + 1) % frameCount;
            faults++;
        }

        populateMatrixColumn(matrix, frames, frameCount, i);
    }

    return faults;
}

int lru(int pages[], int n, int frameCount, int matrix[][MAX_PAGES])
{
    int frames[MAX_FRAMES], time[MAX_FRAMES];
    int faults = 0, counter = 0;

    for (int i = 0; i < frameCount; i++)
    {
        frames[i] = -1;
        time[i] = 0;
    }

    for (int i = 0; i < frameCount; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = -1;

    for (int i = 0; i < n; i++)
    {
        int pos = search(frames, frameCount, pages[i]);

        if (pos != -1)
        {
            time[pos] = ++counter;
        }
        else
        {
            int minTime = time[0], replaceIndex = 0;

            for (int j = 0; j < frameCount; j++)
            {
                if (frames[j] == -1)
                {
                    replaceIndex = j;
                    break;
                }

                if (time[j] < minTime)
                {
                    minTime = time[j];
                    replaceIndex = j;
                }
            }

            frames[replaceIndex] = pages[i];
            time[replaceIndex] = ++counter;
            faults++;
        }

        populateMatrixColumn(matrix, frames, frameCount, i);
    }

    return faults;
}

int optimal(int pages[], int n, int frameCount, int matrix[][MAX_PAGES])
{
    int frames[MAX_FRAMES];
    int faults = 0;

    for (int i = 0; i < frameCount; i++)
        frames[i] = -1;

    for (int i = 0; i < frameCount; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = -1;

    for (int i = 0; i < n; i++)
    {
        if (search(frames, frameCount, pages[i]) == -1)
        {
            int replaceIndex = -1;
            int farthest = i;

            for (int j = 0; j < frameCount; j++)
            {
                int k;

                for (k = i + 1; k < n; k++)
                {
                    if (frames[j] == pages[k])
                        break;
                }

                if (k == n)
                {
                    replaceIndex = j;
                    break;
                }

                if (k > farthest)
                {
                    farthest = k;
                    replaceIndex = j;
                }
            }

            if (replaceIndex == -1)
                replaceIndex = 0;

            frames[replaceIndex] = pages[i];
            faults++;
        }

        populateMatrixColumn(matrix, frames, frameCount, i);
    }

    return faults;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <reference_length> <number_of_frames>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int frameCount = atoi(argv[2]);

    if (frameCount < 1 || frameCount > 7 || n <= 0 || n > MAX_PAGES)
    {
        printf("Invalid arguments.\n");
        return 1;
    }

    printf("Number of Frames: %d\n\n", frameCount);

    int pages[MAX_PAGES];

    // For removing the problem of pseudo random repeated values
    srand(time(NULL));

    // Generates random reference string
    printf("Reference String:\n");
    for (int i = 0; i < n; i++)
    {
        pages[i] = rand() % PAGE_RANGE;
        printf("%d ", pages[i]);
    }
    printf("\n");

    int matrix[MAX_FRAMES][MAX_PAGES];

    printf("\nFIFO:\n");
    int fifoFaults = fifo(pages, n, frameCount, matrix);
    printMatrix(matrix, pages, frameCount, n);

    printf("\nLRU:\n");
    int lruFaults = lru(pages, n, frameCount, matrix);
    printMatrix(matrix, pages, frameCount, n);

    printf("\nOptimal:\n");
    int optimalFaults = optimal(pages, n, frameCount, matrix);
    printMatrix(matrix, pages, frameCount, n);

    printf("\nSummary:\n\n");
    printf("FIFO Page Faults: %d\n", fifoFaults);
    printf("LRU Page Faults: %d\n", lruFaults);
    printf("Optimal Page Faults: %d\n\n", optimalFaults);

    return 0;
}
