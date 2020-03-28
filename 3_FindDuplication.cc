#include <memory.h>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
//const int MAXVALUE=104;//题干是长度为n的数组包含0~n-1的数字
const int MAXN=100+5;

#if 0
//计算重复数组//这个方法不行，不是真正的hash数组，并且当重复2次以上时会重复输出
void hash1(int * p,int n){
    cout<<"hash1..."<<endl;
    if(p==nullptr){
        cerr<<"error1:输入为空!"<<endl;
        return;
    }
    int hs[MAXN];
    int repeated[MAXN];
    int count=0,h=0;
    memset(hs,-1,MAXN*sizeof(int));
    for(int i=0;i<n;i++){
        int j=0;
        if(p[i]>MAXVALUE){
            cerr<<"error2:输入值超出范围!"<<endl;
            return;
        }
        for(j=0;j<count;j++){
            if(p[i]==hs[j]){
                repeated[h++]=p[i];
               cout<<p[i]<<" ";
               break;
            }
        }
        if(j==count){
            hs[count++]=p[i];
        }
    }
#if 0
    for(int j=0;j<h;j++){
        cout<<repeated[j]<<" ";
    }//应该尽量减少循环
#endif
    cout<<endl;
}

#endif

//计算每个数字重复次数
#if 0
void hash2(int * p,int n){
    if(p==nullptr){
        cerr<<"error1:输入为空!"<<endl;
        return;
    }
    int hs[MAXN-1]={0};
    for(int i=0;i<n;i++){
        if(p[i]>n-1){
            cerr<<"error2:输入值超出范围!"<<endl;
            return;
        }
        hs[p[i]]++;
    }
    for(int j=0;j<=n-1;j++){
        if(hs[j]>1){
            cout<<j<<" ";
        }
    }
    cout<<endl;
}
#endif

//交换算法
void swap(int & a,int & b)
{
    int temp=a;
    a=b;
    b=temp;
}

void hash2(int * a,int n){
    if(a==nullptr){
        cout<<"error1：输入为空！"<<endl;
        return;
    }
    //int n=sizeof(a)/sizeof(int);
    for(int i=0;i<n;++i){
        if(a[i]>n-1)    {cout<<"error2：输入值超出范围！"<<endl;
        return;
    }}
    for(int i=0;i<n;i++){
        while(a[i]!=i){
            if(a[i]==a[a[i]]){
                cout<<a[i]<<endl;
                return;
            }else{
                swap(a[i],a[a[i]]);
            }
        }
    }
}

void test1()
{
    cout<<"1"<<"    ";
    int a[]={2,4,3,1,2};
    //int * a=nullptr;
//    hash1(a,sizeof(a)/sizeof(int));
    hash2(a,sizeof(a)/sizeof(int));
}

void test2()
{
    cout<<"2"<<"    ";
    int * a=nullptr;
    hash2(a,sizeof(a)/sizeof(int));
}

void test3()
{
    cout<<"3"<<"    ";
    int a[]={1,1,1,3,4};
    hash2(a,sizeof(a)/sizeof(int));
}

void test4()
{
    cout<<"4"<<"    ";
    int a[]={1,2,3,4,4};
    hash2(a,sizeof(a)/sizeof(int));
}

void test5()
{
    cout<<"5"<<"    ";
    int a[]={1,2,3,4,10};
    hash2(a,sizeof(a)/sizeof(int));
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
}
