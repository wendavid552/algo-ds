/*
Date:2020/10/07
Author:WenDavid552
Description:The most basic heap.
You should first input n and m in standard input, means the number of initial numbers in the heap and the number of 
I x = insert number x.
G = Get the biggest number in the heap
E = Erase the biggest number in the heap
*/
#include<cstdio>
#include<algorithm>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int maxn = 1e5+10;
inline int
readint()
{
    int x=0; char c=getchar();
    for(;c<'0'||c>'9';c=getchar());
    for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
    return x;
}
int heap[maxn*4],pos=0;
int a[maxn];
void
heap_insert(int x)
{
    heap[++pos]=x;
    for(int p=pos;p!=1;p>>=1){
        if(heap[p] < heap[p>>1])
            swap(heap[p],heap[p>>1]);
        else
            break;
    }
}
void
heap_pop()
{
    swap(heap[1],heap[pos]); --pos;
    int p=1;
    while((p<<1)<=pos){
        if(heap[p<<1] > heap[p]){
            swap(heap[p<<1],heap[p]);
            p=(p<<1);
        }
        if((p<<1|1)<=pos && heap[p<<1|1] > heap[p]){
            swap(heap[p<<1|1],heap[p]);
            p=(p<<1|1);
        }
    }
}
int n,m;
main()
{
    scanf("%d%d",&n,&m);
    fo(i,1,n) a[i]=readint();
    fo(i,1,m){
        char op; scanf("%c",&op);
        if(op == 'I'){
            int num; num=readint();
            heap_insert(num);
        }
        else if (op == 'G'){
            printf("%d\n",heap[1]);
        }
        else if (op == 'E'){
            heap_pop();
        }
    }
    return 0;
}
