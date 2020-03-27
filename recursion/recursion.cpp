#include<iostream>
using namespace std;

void decreasingincreasing(int n)
{

    if(n==0)
    {
        cout<<"base"<<n<<endl;
        return;
    }
 cout<<"hi"<<n<<endl;
 decreasingincreasing(n-1);
 cout<<"bye"<<n<<endl;
}

void decreasing(int n)
{

    if(n==0)
    {
        cout<<"base"<<n<<endl;
        return;
    }
 cout<<"hi"<<n<<endl;
 decreasing(n-1);
 
}
void increasing(int n)
{

    if(n==0)
    {
        cout<<"base"<<n<<endl;
        return;
    }
 
 increasing(n-1);
 cout<<"bye"<<n<<endl;
}

void evenodd(int n)
{   
    if(n==0)
    {   cout<<n<<endl;
        return;
    }
    if((n&1)==0)
    {
    cout<<n<<endl;
    }
    evenodd(n-1);
    if((n&1)!=0)
    {
    cout<<n<<endl;
    }
    
}

int main()
{
    //decreasingincreasing(8);
    //increasing(8);
    //decreasing(8);
    evenodd(10);
    return 0;
}