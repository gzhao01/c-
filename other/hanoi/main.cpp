#include <iostream>

using namespace std;

void hanoi(int n,int from,int tmp,int to);
int main()
{
    hanoi(3,1,2,3);
}
void hanoi(int n,int from,int tmp,int to){
    if(n==0){
        return;
    }
    else if(n==1){
        std::cout<<n<<"->"<<to<<"\n";
    }
    else{
        //move n-1 hanoi to tmp
        hanoi(n-1,from,to,tmp);
        //move n to target
        std::cout<<n<<"->"<<to<<"\n";
        //move n-1 from tmp to target
        hanoi(n-1,tmp,from,to);
    }
}

