#include <stdio.h>
#include <stdlib.h>

void
f(void)
{
    int a[4];
    int *b = malloc(16);
    int *c;
    int i;

    printf("1: a = %p, b = %p, c = %p\n", a, b, c);
    // a, b, c addresses, c is random or null


    c = a;
    for (i = 0; i < 4; i++)
	a[i] = 100 + i;
    // a: 100, 101, 102, 103
    c[0] = 200;
    // c: 200
    // a: 200, 101, 102, 103
    printf("2: a[0] = %d, a[1] = %d, a[2] = %d, a[3] = %d\n",
	   a[0], a[1], a[2], a[3]);
    // 2: 200, 101, 102, 103

    c[1] = 300;
    *(c + 2) = 301;
    3[c] = 302;
    printf("3: a[0] = %d, a[1] = %d, a[2] = %d, a[3] = %d\n",
	   a[0], a[1], a[2], a[3]);
    // a: 200, 300, 301, 302

    c = c + 1;
    *c = 400;
    printf("4: a[0] = %d, a[1] = %d, a[2] = %d, a[3] = %d\n",
	   a[0], a[1], a[2], a[3]);
    // 200, 400, 301, 302

    c = (int *) ((char *) c + 1);
    // c is first converted to point to 1 byte,
    // c + 1 points to a[1] + 1 byte
    // c then is converted to point to 4 bytes
    *c = 500;
    printf("5: a[0] = %d, a[1] = %d, a[2] = %d, a[3] = %d\n",
	   a[0], a[1], a[2], a[3]);
    // 500: 0x1f4
    // a: 200, 0x1f490, 0x100, 302

    b = (int *) a + 1;
    c = (int *) ((char *) a + 1);
    printf("6: a = %p, b = %p, c = %p\n", a, b, c);
    // a, a + 4 bytes, a + 1 byte
}

int
main(int ac, char **av)
{
    f();
    return 0;
}

