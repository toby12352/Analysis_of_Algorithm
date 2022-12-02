#include <iostream>
#include <string>
#include <stdlib.h>
#include <chrono>

using namespace std;

//Code from CS162 class
void merge(int num_arr[], int l, int m, int r)
{
    int left = m - l + 1;
    int right = r - m;

    int l_arr[left];
    int r_arr[right];

    for (int i = 0; i < left; i++)
        l_arr[i] = num_arr[l + i];
    for (int i = 0; i < right; i++)
        r_arr[i] = num_arr[m + 1 + i];
 
    int first = 0;
 
    int second = 0;
 
    int x = l;
 
    while (first < left && second < right) {
        if (l_arr[first] <= r_arr[second]) {
            num_arr[x] = l_arr[first];
            first++;
        }
        else {
            num_arr[x] = r_arr[second];
            second++;
        }
        x++;
    }
 
    while (first < left) {
        num_arr[x] = l_arr[first];
        first++;
        x++;
    }
 
    while (second < right) {
        num_arr[x] = r_arr[second];
        second++;
        x++;
    }
}
 
void mergeSort(int num_arr[],int l,int r){
    if(l>=r){
        return;
    }
    int m = (l+r-1)/2;
    mergeSort(num_arr,l,m);
    mergeSort(num_arr,m+1,r);
    merge(num_arr,l,m,r);
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
        mergeSort(num_arr, 0 ,new_val-1);
        auto stop = std::chrono::high_resolution_clock::now();
        //std::chrono::duration<double> duration = stop - start;
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

        cout << "n = " << new_val << "       " << duration.count() << "ms" << endl;
    }

    return 0;
}