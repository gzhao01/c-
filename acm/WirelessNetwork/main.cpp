//#include <iostream>
//#include <cstdio>
//#include <cmath>
//#include <cstring>
////Wireless network
////https://vjudge.net/problem/POJ-2236
////����ֻ��һ����·���������޸����ҿ��������ĵ��ԣ����������е��ԣ����������Ϊ�������鴢��ɹ��������е��ԣ�ÿ��һ�����Ա��޸�������Щ���޸������м����һ�������������������Ϳ����������п������ӵĵ����ˡ�
////��ô�ж�ʱֻҪ�жϸ���Ԫ���Ƿ���ͬһ���ͺá�
//
//using namespace std;
//
//int computerRoot[1002];
//int computerX[1002], computerY[1002];
//int isWorking[1002];
//
//int unitFind(int a){
//    if(a==computerRoot[a]) return a;
//    else return computerRoot[a] = unitFind(computerRoot[a]);
//}
//void unitMerge(int a,int b){
//    a=unitFind(a);
//    b=unitFind(b);
//    if(a==b) return;
//    else computerRoot[a]=b;
//}
//int main()
//{
//    memset(isWorking,0,sizeof(isWorking));
//    int len=0;
//    int n, distance;
//    int xi, yi;
//    char pre;
//    int a,b;
//    scanf("%d%d",&n,&distance);
//    //init
//    for(int i=1;i<=n;i++){
//        computerRoot[i]=i;
//        //coordinate
//        scanf("%d%d",&xi,&yi);
//        computerX[i]=xi;
//        computerY[i]=yi;
//    }
//
//    while(cin>>pre){
//        if(pre=='O'){
//            scanf("%d",&a);
//            isWorking[len++]=a;
//            for(int i=0;i<len;i++){
//                int minu = pow((computerX[a]-computerX[isWorking[i]]),2)
//                +pow((computerY[a]-computerY[isWorking[i]]),2);
//                if(sqrt(minu)<=distance) unitMerge(a,isWorking[i]);
//            }
//        }
//        if(pre=='S'){
//            scanf("%d%d",&a,&b);
//            if(unitFind(a)==unitFind(b)) cout<<"SUCCESS\n";
//            else cout<<"FAIL\n";
//        }
//    }
//    return 0;
//}


#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
//Wireless network
//https://vjudge.net/problem/POJ-2236
//����ֻ��һ����·���������޸����ҿ��������ĵ��ԣ����������е��ԣ����������Ϊ�������鴢��ɹ��������е��ԣ�ÿ��һ�����Ա��޸�������Щ���޸������м����һ�������������������Ϳ����������п������ӵĵ����ˡ�
//��ô�ж�ʱֻҪ�жϸ���Ԫ���Ƿ���ͬһ���ͺá�

using namespace std;

int computerRoot[1002];
int computerX[1002], computerY[1002];
bool isWorking[1002];

int unitFind(int a){
    if(a==computerRoot[a]) return a;
    else return computerRoot[a] = unitFind(computerRoot[a]);
}
void unitMerge(int a,int b){
    a=unitFind(a);
    b=unitFind(b);
    if(a==b) return;
    else computerRoot[a]=b;
}
int main()
{
    memset(isWorking,0,sizeof(isWorking));
    int len=0;
    int n, distance;
    int xi, yi;
    char pre;
    int a,b;
    scanf("%d%d",&n,&distance);
    //init
    for(int i=1;i<=n;i++){
        computerRoot[i]=i;
        //coordinate
        scanf("%d%d",&xi,&yi);
        computerX[i]=xi;
        computerY[i]=yi;
    }

    while(scanf("%c",&pre)!=EOF){
        if(pre=='O'){
            scanf("%d",&a);
            isWorking[a]=true;
            for(int i=1;i<=n;i++){
                int minu = pow((computerX[a]-computerX[i]),2)+pow((computerY[a]-computerY[i]),2);
                if(sqrt(minu)<=distance&&isWorking[i]) unitMerge(a,i);
            }
        }
        if(pre=='S'){
            scanf("%d%d",&a,&b);
            if(unitFind(a)==unitFind(b)) cout<<"SUCCESS\n";
            else cout<<"FAIL\n";
        }
    }
    getchar();
    return 0;
}
