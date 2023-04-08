#include <stdio.h>
/* multibly by 7 using bitwise operators*/
int main(void)
{
    int x;
    scanf("%d", &x);
    x = (x << 3) - x;
    printf("%d\n", x);

    return 0;
}