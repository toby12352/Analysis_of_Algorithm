#include<iostream>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int max(int a, int b){
    return (a > b) ? a : b;
}

int knapSackDynamic(int W, int n, int wt[], int v[]){

    int K[n+1][W+1];

    for (int i = 0; i <= n; i++){
        for (int w = 0; w <= W ; w++){
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

int main(){
    ifstream fileinput;
    fileinput.open("shopping.txt");
    if(fileinput.fail()){
        cerr << "Error opening file" << endl;
        exit(1);
    }

    int T;
    int N;
    int val[30];
    int wt[30];
    int F;
    int M;
    fileinput >> T;
    for (int i = 0 ; i < T; i++){
        int total_price = 0;
        fileinput >> N;
        
        for (int j = 0; j < N; j++){
            fileinput >> val[j] >> wt[j];
        }

        fileinput >> F;

        for (int j = 0; j < F ; j++){
            fileinput >> M;
            total_price = total_price + knapSackDynamic( M, N, wt, val);
            
        }

        cout << "Test Case " << i+1 << endl;
        cout << "Total Price " << total_price << endl;
        for (int j = 0 ; j < F; j++){
            cout << j+1 << ". " << endl;
        }

        cout << endl;
    }
}