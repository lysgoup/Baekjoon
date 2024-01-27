#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    int N;
    cin >> N;

    if(N==1){
        cout << 3;
        return 0;
    }
    else if(N==2){
        cout << 7;
        return 0;
    }

    unsigned int result[N];
    result[0] = 3;
    result[1] = 7;

    for(int i=2;i<N;i++){
        result[i] = (result[i-2]*3 + (result[i-1]-result[i-2])*2)%9901;
    }
    cout << result[N-1];
    return 0;
}