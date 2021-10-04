#include <stdlib.h>
#include <stdio.h>

void main(int argc, char const *argv[])
{
    FILE *arq;
    int result;
    char Str[50];

    arq = fopen(argv[1], "r");
    printf("o caminho do arquivo é: %s\n",argv[1]);

    if (arq == NULL)
    {
        printf("dando erro");
    }
    else
    {
        while (!feof(arq))
        {
            fscanf(arq, "%s", Str);
            printf("%s\n", Str);
        }
    }
}
