/*
	24.11.13.
	1, 2, 3 더하기 5
	15990
*/
#include <iostream>

using namespace std;

long long dp[100001] = {0};
long long arr1[100001] = {0};
long long arr2[100001] = {0};
long long arr3[100001] = {0};


int main(){
    
        
    int TC; cin >> TC;

    arr1[3] = 1;    arr1[4] = 2;    arr1[5] = 1;
    arr2[3] = 1;    arr2[4] = 0;    arr2[5] = 2;
    arr3[3] = 1;    arr3[4] = 1;    arr3[5] = 1;
    
    dp[0] = 1; dp[1] = 1; dp[2] = 1;
    for(int i = 3; i<=5; i++) {dp[i] = (arr1[i] + arr2[i] + arr3[i]) % 1000000009;}
    
    for(int i = 6; i<=100000; i++){
        arr1[i] = (arr2[i-1] + arr3[i-1]) % 1000000009;
        arr2[i] = (arr1[i-2] + arr3[i-2]) % 1000000009;
        arr3[i] = (arr1[i-3] + arr2[i-3]) % 1000000009;
        dp[i] = (arr1[i] + arr2[i] + arr3[i]) % 1000000009;
    }
    
    
    for(int t = 0; t<TC; t++){
        
        int n;
        cin>>n;
        
        cout << dp[n] << "\n";
        
        
    }
    
    
    return 0;
}