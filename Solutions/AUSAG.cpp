#include<bits/stdc++.h>
#define    MAX   100009
using namespace std;
int failure[MAX];

void build_failure_function(char *pattern, int m)
{
    failure[0] = 0;
    failure[1] = 0;
    for(int i = 2; i <= m; i++)
    {
        int j = failure[i - 1];
        while(true)
        {
            if(pattern[j] == pattern[i - 1])
            {
                failure[i] = j + 1;
                break;
            }
            if(j == 0)
            {
                failure[i] = 0;
                break;
            }
            j = failure[j];
        }
    }
}

int kmp(char *ch,char *ch2)
{
    int v=0;
    int n = strlen(ch);
    int m = strlen(ch2);
    build_failure_function(ch2, m);
    int i = 0,j = 0;
    while(true)
    {
        if(j == n)break;
        if(ch[j] == ch2[i])
        {
            i++;j++;
            if(i == m)v++;
        }
        else
        {
            if (i == 0)j++;
            else i = failure[i];
        }
    }
    return v;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        string s,p;
        char ch[MAX],ch2[MAX],cc[MAX];
        scanf("%[^\n]",cc);
        getchar();
        scanf("%[^\n]",cc);
        int z=strlen(cc),k=0;
        for(int j=0;j<z;j++)
        {
            if(cc[j]==' ')continue;
            else ch[k++]=cc[j];
        }
        ch[k]='\0';
        scanf("%s",ch2);
        int val=kmp(ch,ch2);
        printf("Case %d: %d\n",i,val);
    }



    return 0;
}
