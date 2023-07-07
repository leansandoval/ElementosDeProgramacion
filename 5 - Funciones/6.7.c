#include<stdio.h>
#include<windows.h>
int MayorMenor(int,int,int,int);
int EstaDentroDelRango(int,int,int);
int IngrNumVal(int,int);
int main()
{
    int i,v,v1,v2,v3,may,par=0;
    printf("\nEL PROGRAMA FINALIZA CUANDO SE INGRESAN LOS VALORES 96,97 Y 98 EN SU RESPECTIVO ORDEN");
    for(i=1;i<=3;i++)
        {
            v=IngrNumVal(1,99);
            if(i==1)
                v1=v;
            else
                if(i==2)
                    v2=v;
                else
                    v3=v;
    }
    while(!(v1==96&&v2==97&&v3==98))
    {
        printf ("\nEl menor valor de la terna es: %d\n",MayorMenor (v1,v2,v3,-1));
        printf ("\nEl mayor valor de la terna es: %d\n",MayorMenor (v1,v2,v3,1));
        printf("\n");
        for(i=1;i<=3;i++)
            {
                v=IngrNumVal(1,99);
                if(i==1)
                    v1=v;
                else
                    if(i==2)
                        v2=v;
                    else
                        v3=v;
            }
    }

    printf("\n\n");
    system("pause");
    printf("\n");
}

int EstaDentroDelRango(int num,int limi,int lims)
{
    if(num>=limi&&num<=lims)
        return 1;
    else
        return 0;
}
int IngrNumVal(int limi,int lims)
{
    int num;
    do
    {
        printf("\nIngrese un numero entre %d y %d: ",limi,lims);
        scanf("%d",&num);
    }while(EstaDentroDelRango(num,limi,lims)==0);
    return num;
}

int MayorMenor (int n1, int n2, int n3, int cfg)
{
    int ref;
    ref=n1*cfg;
    if (n2*cfg>ref)
        ref=n2*cfg;
    if(n3*cfg>ref)
        ref=n3*cfg;
    return ref*cfg;
}

