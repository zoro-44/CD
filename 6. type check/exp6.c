
#include <stdio.h>

typedef enum {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_CHAR
} Type;

typedef struct {
    Type type;
    void *value;
} TypedVar;

int add(int a, int b)
{
    return a + b;
}

float multiply(float a, float b)
{
    return a * b;
}

float divide(int a, int b)
{
    if (b != 0)
        return (float)a / b;
    else
        return 0.0f;
}

float average(int arr[], int n)
{
    float sum = 0;
    int i;

    for (i = 0; i < n; i++)
        sum += arr[i];

    return sum / n;
}

void print_var(TypedVar var)
{
    switch (var.type) {
        case TYPE_INT:
            printf("Integer: %d\n", *(int *)var.value);
            break;

        case TYPE_FLOAT:
            printf("Float: %.2f\n", *(float *)var.value);
            break;

        case TYPE_CHAR:
            printf("Character: %c\n", *(char *)var.value);
            break;
    }
}

int main()
{
    int a = 20, x = 5, y = 10;
    int arr[5] = {1, 2, 3, 4, 5};

    float b = 2.718f, m = 2.5f, n = 4.0f;
    char c = 'Z';

    TypedVar va = {TYPE_INT, &a};
    TypedVar vb = {TYPE_FLOAT, &b};
    TypedVar vc = {TYPE_CHAR, &c};

    print_var(va);
    print_var(vb);
    print_var(vc);

    printf("Sum of %d and %d = %d\n", x, y, add(x, y));
    printf("Product of %.2f and %.2f = %.2f\n",
           m, n, multiply(m, n));
    printf("Division result = %.2f\n", divide(a, 2));
    printf("Average of integer array = %.2f\n",
           average(arr, 5));

    return 0;
}

