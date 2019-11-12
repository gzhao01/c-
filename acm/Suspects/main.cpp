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
    //����ȡ����Ϊ1��2��Ϊһ��С��ʱ��2��û�к�0������ϵ��������һ������ʱ�������˹�ϵ
    //���鼯�Ĺؼ�����Ҫȫ����¼����Ҫ��ͼ��ȥһЩ��Ϣ
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
