#include <stdio.h>

int dot_product_array(int a[])
{
    int i, product;
    // printf("%d ddot product\n", product);
    // size = sizeof(&a) / sizeof(&a[0]); //Method

    for (i = 0; i < 100; i++)
    {
        product += a[i] * a[i + 100];
    }

    printf("%d ddot product\n", product);
    return product;
}
