#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include "matrix.h"

using namespace std;

int main() {
    ifstream input(".\\input.txt");
    auto m = new matrix(input);
    int start, finish;
    input >> start >> finish;
    input.close();

    auto sort = m->topological_sort();
    auto paths = m->find_paths_acyclic(start - 1, sort);

    ofstream output(".\\output.txt");

    auto result = new int[m->size];
    int cur, ptr = 0, vertex = finish - 1;
    do{
        if(vertex == -1){
            output << "N";
            return 0;
        }
        result[ptr++] = vertex;
        vertex = paths[vertex];
    }while(vertex != start - 1);


    output << "Y\n" << start;
    for(int i=ptr-1; i>=0; i--)
        output << " " << result[i] + 1;
    output.close();
    return 0;
}