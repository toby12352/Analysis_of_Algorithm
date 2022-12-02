#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

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
   
    ifstream fileinput;
    fileinput.open("data.txt");
    if(fileinput.fail()){
        cerr << "Error opening file" << endl;
        exit (1);
    }

    int total;
    int num_arr[total];

    while(fileinput >> total){
        for (int i = 0 ; i < total ; i++){
            fileinput >> num_arr[i];
        }
        
        mergeSort(num_arr,0,total - 1);
        for (int i = 0 ; i < total ; i++){
            cout << num_arr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}