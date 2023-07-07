void VectoresIntercalados (int[],int[],int);

void VectoresIntercalados (int a[],int b[],int ce)
{
    int v[ce*2],i;
    for(i=0;i<=ce-1;i++)
    {
        v[2*i]=a[i];
        v[2*i+1]=b[i];
    }
}
