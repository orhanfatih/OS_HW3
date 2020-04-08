
int arrays(int a[], int b[])
{

    int n, i;

    for (i = 0; i < 200; i++)
    {
        n = rand() % 50;
        a[i] = n;
        n = rand() % 50;
        b[i] = n;
    }
}