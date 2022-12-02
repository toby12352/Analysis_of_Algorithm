#include <iostream>
#include <stdlib.h>
#include <chrono>

using namespace std;

int max(int a, int b){
    return (a > b) ? a : b;
}

int knapSackDynamic(int W, int wt[], int v[], int n){
    int i, w;
    int K[n+1][W+1];

    for (i = 0; i <= n; i++){
        for (w = 0; w <= W ; w++){
            if (i == 0 || w == 0)
                K[i][w] = 0;
            
            else if (wt[i-1] <= w)
                K[i][w] = max(v[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]);
            
            else   
                K[i][w] = K[i-1][w];
        }
    }
    return K[n][W];
}

int knapSackRecursive(int W, int wt[], int val[], int n){
    if (n == 0 || W == 0)
        return 0;

    if (wt[n-1] > W)
        return knapSackRecursive(W, wt, val, n-1);
    
    else
        return max(
            val[n-1] + knapSackRecursive(W - wt[n-1], wt, val, n-1), knapSackRecursive(W, wt, val, n-1));
}


int main(){
    srand(time(0));
    int n = 10;
    int length = 7;

    for (int i = 0 ; i < length ; i++){
        int W = 100;
        int val[50];
        int wt[50];
        for (int j = 0 ; j < n ; j++){
            val[j] = rand() % 25 + 1;
            wt[j] = rand() % 35 + 1;
        }

        auto startdp = std::chrono::high_resolution_clock::now();
        int max_dp = knapSackDynamic(W,wt,val,n);
        auto stopdp = std::chrono::high_resolution_clock::now();
        auto durationdp = std::chrono::duration_cast<std::chrono::milliseconds>(stopdp - startdp);

        auto startrc = std::chrono::high_resolution_clock::now();
        int max_rc = knapSackRecursive(W,wt,val,n);
        auto stoprc = std::chrono::high_resolution_clock::now();
        auto durationrc = std::chrono::duration_cast<std::chrono::milliseconds>(stoprc - startrc);

        cout << "N = " << n << " W = " << W << " Rec time = " << durationrc.count() << " ms"<< " DP time = " << durationdp.count() << " ms";
        cout << " max Rec = " << max_rc << " max DP = " << max_dp << endl;
        n += 5; 
    }

    return 0;
}