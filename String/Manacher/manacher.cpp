/*
you should input a string consisting of ONLY lower letters.
*/
#include<cstring>
#include<cstdio>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int maxl = 1e6+10;
char s[maxl]; int l;
int p[maxl];
int
main()
{
    scanf("%s",s+1); l=strlen(s+1);
    fo(i,1,l) p[l<<1]='#',p[l<<1|1]=s[i]-'a';
    
    return 0;
}
