//In order to run this, you need to input two numbers of argument
//Second argument being the inputfilename
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <string.h>
#include <stdio.h>

using namespace std;

struct coordinate{
    int x[100];
    int y[100];
};

//Refernce from Geeksforgeeks
int travllingSalesmanProblem(int graph[100][100], int s,int v)
{
   vector<int> vertex;
   for (int i = 0; i < v; i++)
      if (i != s)
         vertex.push_back(i);

   int min_path = INT_MAX;
   do {
      int current_pathweight = 0;

      int k = s;
      for (int i = 0; i < vertex.size(); i++) {
         current_pathweight += graph[k][vertex[i]];
         k = vertex[i];
      }
      current_pathweight += graph[k][s];

      min_path = min(min_path, current_pathweight);

   } while (
      next_permutation(vertex.begin(), vertex.end()));

return min_path;
}

int main(int argc, char* argv[]){

   if (argc != 2){
      cout << "Please input one file only to proceed." << endl;
      exit(1);
   }

   int s = 0;
   ifstream infile;
   ofstream outfile;
   infile.open(argv[1]);
   coordinate c;

   int v;
   infile >> v;
   int graph[100][100];
   for (int j = 0; j < v; j++){
      infile >> c.x[j] >> c.y[j];
   }
   for (int k = 0; k < v; k++){
      for (int l = 0; l < v; l++){
            double weight = sqrt(pow(c.x[k] - c.x[l], 2) + pow(c.y[k] - c.y[l], 2));
            int closestweight = round(weight);
            graph[k][l] = closestweight;
      }
   }
   
   char str[40];
   strcpy (str, argv[1]);
   strcat (str, ".tour");
   outfile.open(str);
   if(outfile.is_open()){
      outfile << travllingSalesmanProblem(graph, s, v) << endl;
   }

   infile.close();
   outfile.close();
   return 0;
}