#include<iostream>
using namespace std;


float squareRoot(int n,int p){

    int s = 0,e = n-1;
    float ans=0;

    while(s<=e){
        int mid = (s+e)/2;
        if(mid*mid==n){
            ans = mid;
            break;
        }
        else if(mid*mid<n){
            ans = mid;
            s = mid +1;
        }
        else{
            e = mid-1;
        }

    }
    ///Floating Part ?
    float inc = 0.1;

    for(int times=1;times<=p;times++){

        while(ans*ans<=n){
            ans += inc;
        }
        ans = ans - inc;
        inc = inc/10;

    }

    return ans;
}

int main(){
    int n,p;
    cin>>n>>p;
    cout<<squareRoot(n,p)<<endl;


}
