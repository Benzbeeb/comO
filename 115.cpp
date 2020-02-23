#include <bits/stdc++.h>
 
using namespace std;
int n,k,sumt,sump,sumd,sumx;
const int MAXN = 100 + 10 ;
char a[MAXN];
int main ()
{
    scanf("%d",&n);
   
    for(int i=1;i<=n;i++)
    {
        scanf("%s",a);
        k=strlen(a);
        sumd=0;
        sumt=0;
        sumx=0;
        sump=0;
        for(int j=0;j<k;j++)
        {
            if(a[j]=='T')
            {
                sumt=sumt+1;
            }
            if(a[j]=='P')
            {
                sump=sump+1;
            }
            if(a[j]=='-')
            {
                sumd=sumd+1;
            }
            if(a[j]=='X')
            {
                sumx=sumx+1;
            }
        }
        if(sumx>=1)
        printf("Case #%d: No - Runtime error\n",i);
        else if(sumt>=1)
        printf("Case #%d: No - Time limit exceeded\n",i);
        else if(sumd>=1)
        printf("Case #%d: No - Wrong answer\n",i);
        else if (sump==k)
        printf("Case #%d: Yes\n",i);
       
    }
   
 }