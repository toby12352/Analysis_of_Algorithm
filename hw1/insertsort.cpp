#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

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

int main(int argc, char** argv){
    ifstream fileinput;
    fileinput.open("data.txt");
    if(fileinput.fail()){
        cerr << "Error opening file" << endl;
        exit (1);
    }

    int total;
    int num_arr[total];

    // cout << "Insert Sort\n" << endl;
    while(fileinput >> total){
        for (int i = 0 ; i < total ; i++){
            fileinput >> num_arr[i];
        }
        
        insert_sort(num_arr, total);
        for (int i = 0 ; i < total ; i++){
            cout << num_arr[i] << " ";
        }
        cout << endl;
    }

    fileinput.close();

    return 0;
}