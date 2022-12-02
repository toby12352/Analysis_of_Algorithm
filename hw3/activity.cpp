#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

void insert_sort(int n[],int s[], int f[], int T)
{
    int i,start ,finish ,number , j;
    for (i = 1; i < T; i++)
    {
        finish = f[i];
        start = s[i];
        number = n[i];
        j = i - 1;
 
        while (j >= 0 && n[j] > number)
        {
            s[j + 1] = s[j];
            f[j + 1] = f[j];
            n[j + 1] = n[j];
            j = j - 1;
        }
        s[j + 1] = start;
        f[j + 1] = finish;
        n[j + 1] = number;
    }
}

void last_to_start(int s[],int n[], int f[], int T)
{
    int count = 1;
    int i = 1;
    int array[30];
    array[0] = n[i];
 
    for (int j = 0; j < T; j++){
      if (s[j] >= f[i]){
        array[count] = n[j];
        i = j;
        count += 1;
      }
    }
    cout << "Maximum number of activities = " << count << endl;
    for (int l = 0; l < count; l++){
        cout << " " << array[l];
    }
    cout << endl << endl;
}

int main()
{
    ifstream fileinput;
    fileinput.open("act.txt");
    if (fileinput.fail()){
        cerr << "Error opening file" << endl;
        exit(1);
    }
    int T;
    int n[30];
    int s[30];
    int f[30];
    int set = 1;
    for (int i = 0; i < 3; i++){
        fileinput >> T;
        for (int j = 0; j < T; j++){
            fileinput >> n[j] >> s[j] >> f[j];
        }
        insert_sort(n, s, f, T);
        cout << "Set " << set << endl;
        last_to_start(s,n,f,T);
        set += 1;
    }
    return 0;
}
//nlogn