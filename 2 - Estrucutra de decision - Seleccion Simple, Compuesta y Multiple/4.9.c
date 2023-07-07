#include<stdio.h>
#include<conio.h>
#include<ctype.h>
int main()
{
    char carac;
    printf("\nIngrese un caracter alfanumerico: ");
    fflush(stdin);
    scanf("%c",&carac);
    switch(carac)
        {
            case 'a': case 'e': case 'i': case 'o': case 'u': case 'A': case 'E': case 'I': case 'O': case 'U': printf("\nVOCAL");break;
        }
    printf("\n\nASCII: %d",&carac);
    printf("\n\n");
    return 0;
    getch();
}
