#include<iostream>
#include "queue.h"
using namespace std;

int main(){

    Queue<int> q;
    for(int i=1;i<=8;i++){
        q.push(i);
    }
    q.pop();
    q.push(10);

    while(!q.isEmpty()){
        cout<<q.getFront()<<" ";
        q.pop();
    }


return 0;
}
