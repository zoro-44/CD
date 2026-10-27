
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr;
    int n;
    int i;

    printf("Enter no of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of elements\n");
        return 1;
    }

    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    int fake_address = 100;

    printf("\nElement\tValue\tSimulated Address\n");

    for (i = 0; i < n; i++) {
        arr[i] = (i + 1) * 10;

        printf("arr[%d]\t%d\t%d\n",
               i, arr[i], fake_address);

        fake_address += sizeof(int);
    }

    free(arr);

    return 0;
}

