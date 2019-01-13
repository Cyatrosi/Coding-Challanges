#include<iostream>
#include<set>
using namespace std;
void findTargetSum(int a[],int n,int sum){
    set<int> s;
    for(int i=0;i<n;++i){
        if(s.find(sum-a[i]) != s.end()){
            cout<<a[i]<<" + "<<sum-a[i]<<" = "<<sum<<endl;
            break;
        }
        s.insert(a[i]);
    }
}
int main(){
int a[] = {4,5,12,-2,8,9};
int n = sizeof(a)/sizeof(a[0]);
int targetSum = 10;
findTargetSum(a,n,targetSum);
return 0;
}
