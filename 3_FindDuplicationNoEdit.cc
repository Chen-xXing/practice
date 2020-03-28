
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int find(int * a,int n){
    if(a==nullptr){
        cout<<"输入为空！"<<endl;
        return -1;
    }
    //int n=sizeof(a)/sizeof(int)-1;
    n--;
    for(int i=0;i<=n;i++){
        cout<<"a[i]"<<a[i]<<endl;
        if(a[i]<0||a[i]>n){
            cout<<"不在限定范围!"<<endl;
            return -2 ;
        }
    }
    int p=1,q=n,m;
    while(p!=q-1&&p!=q){
    int count=0;
        m=(int)((p+q)/2);
        //return -3;
        for(int i=0;i<=n;i++){
            if(a[i]<=m&&a[i]>=p){
                count++;
            }
        }
        if(count>(m-p+1))   q=m;
        else p=m;
    }
    //手写代码的时候没有写下面这个循环导致答案错误，心算代码一定要算到最后
    int countp=0,countq=0;
    for(int i=0;i<=n;i++){
        if(a[i]==p) countp++;
        else if(a[i]==q) countq++;
    }
    if(countp>1) return p;
    else return q;
}

int main()
{
    //int a[]={2,3,5,4,3,2,6,7};
   // int a[]={3,2,1,4,4,5,6,7};
    //int a[]={1,2,3,4,5,6,7,1,8};
    int * a;
    //int a[]={1,7,3,4,5,6,8,2,8};
    //int a[]{1,1};
    //int a[]={3,2,1,3,4,5,6,7};
    /////int a[]={1,2,2,6,4,5,6};
   // int a[]={1,2,2,6,4,5,2};
    //int a[]={1,2,6,4,5,3};
    cout<<find(a,sizeof(a)/sizeof(int))<<endl;
    return 0;
   


    return 0;
}

