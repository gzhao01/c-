#include <iostream>
#include <stdio.h>
int root[9999];
int depth[9999];

void init(int n, int m){
    for(int i=1;i<=n;i++){
        root[i] = i;
        depth[i] = 0;
    }
}

int findRoot(int r){
    if(r==root[r]) return r;
    else return root[r]=findRoot(root[r]);
}

void unionMerge(int a, int b){
    int rootA = findRoot(a);
    int rootB = findRoot(b);
    if(rootA==rootB)
        return;
    else {
        if(depth[rootA]<depth[rootB])
            root[rootA] = rootB;
        else if(depth[rootA]>depth[rootB])
            root[rootB] = rootA;
        else{
            root[rootB] = rootA;
            depth[rootA]++;
        }
//    root[rootA] = rootB;
    }
}


int main(){
    int n,m,a,b;
    while(std::cin>>n,n){
        std::cin>>m;
        int sum = 0;
        init(n,m);
        while(m--){
            std::cin>>a>>b;
            unionMerge(a,b);
        }
        for(int i=1;i<=n;i++)
            if(root[i]==i) sum++;

        std::cout<<sum-1<<"\n";
    }

    getchar();
    getchar();
    return 0;
}
