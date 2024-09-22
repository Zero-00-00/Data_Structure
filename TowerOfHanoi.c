#include <stdio.h>

void tower(int n, char src, char dert,  char Aux)
{
    if (n==1)
    printf("MOVE DISK %d FROM %c TO %c\n", n, src, dert);
    else
    {
        tower(n-1, src, Aux, dert);
        printf("MOVE DISK %d FROM %c TO %c\n", n, src, dert);
        tower(n-1, Aux, dert, src);
    }
}

int main()
{
    int n;
    char src, dert, Aux;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    getchar();
    printf("Enter the source, destination and auxilary: : ");
    scanf("%c %c %c", &src, &dert, &Aux);
    tower(n, src, dert, Aux);
}
