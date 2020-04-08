#include <stdio.h>

int dot_product_array(int a[])
{
    int i, product;

    for (i = 0; i < 100; i++)
    {
        product += a[i] * a[i + 100];
    }

    // printf("%d dot product\n", product);
    return product;
}
