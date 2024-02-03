#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int num;
    cin >> num;

    int list[num+1];

    for(int i=1;i<=num;i++){
        if(i==1) list[i] = 0;
        else{
            if(i%3==0){
                int temp = min(list[i/3],list[i-1]) + 1;
                if(i%2==0) temp = min(temp,list[i/2]+1);
                list[i] = temp;
            }
            else if(i%2==0) list[i] = min(list[i/2],list[i-1]) + 1;
            else list[i] = list[i-1] + 1;
        }
    }

    cout << list[num];
}