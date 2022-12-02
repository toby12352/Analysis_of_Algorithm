#include <iostream>
#include <string>
#include <stdlib.h>
#include <chrono>

using namespace std;

//Code from CS162 class
void swap (int num_arr[], int a)
{
    int x = num_arr[a];
    num_arr[a] = num_arr[a+1];
    num_arr[a+1] = x;
}

void insert_sort(int num_arr[], int total){
    for (int i = 0 ; i < total; i++){
        for (int j = 0 ; j < total-1 ; j++)
        if (num_arr[j] > num_arr[j+1])
            swap(num_arr, j);
    }
}

int main(){
    int n[] = {5000, 10000, 15000, 20000, 25000, 30000, 35000, 40000, 45000, 50000};
    int size = sizeof(n)/sizeof(int);

    for(int i = 0; i < size; i++){
        int new_val = n[i];
        int num_arr[new_val];

        for (int j = 0; j < new_val; j++){
            int v = rand() % 10000 + 1;
            num_arr[j] = v;
        }

        auto start = std::chrono::high_resolution_clock::now();
        insert_sort(num_arr,new_val);
        auto stop = std::chrono::high_resolution_clock::now();
        //std::chrono::duration<double> duration = stop - start;
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

        cout << "n = " << new_val << "       " << duration.count() << "ms" << endl;
    }

    return 0;
}