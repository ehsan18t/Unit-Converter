#include <stdio.h>
#include <string.h>

void inst();
long long multiply(long long a, int x, int y);
long long divide(long long a, int x, int y);
int numbering(char x[]);

typedef struct
{
    long long num;
    char type[7];
} time;

int main()
{
    inst();
    time time;
    int x = 0, y = 0;
    printf("Input: ");
    scanf("%ld %s", &time.num, &time.type);
    strlwr(time.type);
    char temp[4];

    strncpy(temp, time.type, 3);
    x = numbering(temp);
    strcpy(temp, &time.type[4]);
    y = numbering(temp);
    if (x - y > 0)
    {
        printf("Output: %lld %s\n", multiply(time.num, x, y), temp);
    }
    else if (x - y < 0)
    {
        printf("Output: %lld %s\n", divide(time.num, x, y), temp);
    }
    else
    {
        printf("Output: %lld %s\n", time.num, temp);
    }
    return 0;
}

long long multiply(long long a, int x, int y)
{
    int mul[] = {1000, 60, 60, 24, 7};
    long long result = a;
    for (int i = y; i < x; i++)
    {
        result *= mul[i];
    }
    return result;
}

long long divide(long long a, int x, int y)
{
    int mul[] = {1000, 60, 60, 24, 7};
    long long result = a;
    for (int i = x; i < y; i++)
    {
        result /= mul[i];
    }
    return result;
}

int numbering(char x[])
{
    int res;
    if (strcmp(x, "mil") == 0)
        res = 0;
    else if (strcmp(x, "sec") == 0)
        res = 1;
    else if (strcmp(x, "min") == 0)
        res = 2;
    else if (strcmp(x, "hrs") == 0)
        res = 3;
    else if (strcmp(x, "day") == 0)
        res = 4;
    else if (strcmp(x, "wek") == 0)
        res = 5;
    return res;
}

void inst()
{
    printf("\n            ***********************\n");
    printf("            **  Time Conversion  **\n");
    printf("            ***********************\n");
    printf("  -> Millisecond = mil      -> Second = sec\n  -> Minute = min           -> Hour = hrs\n");
    printf("  -> Day = day              -> Week = wek\n\n");
    printf("  USES: [AMOUNT] [UNIT]-[UNIT]\n  EXAMPLE: 1 day-hrs    ('-' is used as 'to')\n\n");
}