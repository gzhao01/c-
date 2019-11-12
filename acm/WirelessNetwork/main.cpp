//#include <iostream>
//#include <cstdio>
//#include <cmath>
//#include <cstring>
////Wireless network
////https://vjudge.net/problem/POJ-2236
////本题只有一条线路连接所有修复的且可以相连的电脑（不包括所有电脑）。纳入过程为，用数组储存可工作的所有电脑，每当一个电脑被修复便在这些已修复电脑中检测哪一个可以与它相连，最后就可以连接所有可以连接的电脑了。
////那么判断时只要判断父级元素是否是同一个就好。
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
//本题只有一条线路连接所有修复的且可以相连的电脑（不包括所有电脑）。纳入过程为，用数组储存可工作的所有电脑，每当一个电脑被修复便在这些已修复电脑中检测哪一个可以与它相连，最后就可以连接所有可以连接的电脑了。
//那么判断时只要判断父级元素是否是同一个就好。

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
