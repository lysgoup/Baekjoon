#include <iostream>

using namespace std;

int find_max_sum(int *numbers, size_t size){
    int max_sum = numbers[0];
    int temp_sum[size];

    for(int i=0;i<size;i++){
        if(i==0){
            max_sum = temp_sum[i] = numbers[i];
        }
        else{
            if(temp_sum[i-1] < 0) temp_sum[i] = numbers[i];
            else temp_sum[i] = temp_sum[i-1] + numbers[i];

            if(temp_sum[i] > max_sum) max_sum = temp_sum[i];
        }
    }
    return max_sum;
}

int main(){
    int n;
    cin >> n;
    int numbers[n];
    for(int i=0;i<n;i++){
        int buf;
        scanf("%d",&numbers[i]);
    }

    printf("%d\n",find_max_sum(numbers,n));
}