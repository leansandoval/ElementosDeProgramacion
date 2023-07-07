void UnionVectores(int[],int[],int);

void UnionVectores(int a[],int b[],int ce)
{
    int v[ce*2],i;
    for(i=0;i<=ce-1;i++)
    {
        v[i]=a[i];
        v[i+ce]=b[i];
    }

}
