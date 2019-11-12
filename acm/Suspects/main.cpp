#include <iostream>
#include <cstdio>

//https://vjudge.net/problem/POJ-1611

using namespace std;

int students[30000];
int groupStudents[30000];
void unitInit(int n){
    for(int i=0;i<n;i++){
        students[i]=i;
    }
}
int unitFind(int a){
    if(students[a]==a) return a;
    else{
        return students[a] = unitFind(students[a]);
    }
}
void unitMerge(int a, int b){
    int rootA=unitFind(a);
    int rootB=unitFind(b);
    if(rootA==rootB) return;
    //不可取，因为1和2作为一个小组时，2并没有和0建立关系，而在下一个输入时候则建立了关系
    //并查集的关键就是要全部记录，不要试图舍去一些信息
    else{
        if(rootA==0) students[rootB]=0;
        else if(rootB==0) students[rootA]=0;
        else students[rootA] = rootB;
    }
//    else{
//        students[rootA] = rootB;
//    }
}

int main()
{
    int n, m;
    int sum=0;
    int memberNumber;
    while(scanf("%d%d",&n,&m)!=EOF&&(n||m)){
        unitInit(n);
        sum=0;
        if(n==1&&m==0)
        {
          cout<<1<<"\n";
          continue;
        }
        while(m--){
            cin>>memberNumber;
            for(int i=0;i<memberNumber;i++){
                cin>>groupStudents[i];
                if(i>0){
                    unitMerge(groupStudents[i-1],groupStudents[i]);
                }
            }
        }
        for(int i=0;i<n; i++){
               if(!unitFind(i))sum++;
        }
        cout<<sum<<"\n";
    }
    return 0;
}
