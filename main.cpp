#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include "matrix.h"

using namespace std;

int main() {
    ifstream input("/home/mikhail/test/input.txt");
    auto *m = new matrix(input);
    int start, finish;
    input >> start >> finish;

    auto begin = clock();
    for(int t=0; t<1000000; t++) {
        auto sort = m->topological_sort();
        auto paths = m->find_paths(start - 1, sort);
    }
    auto end = clock();
    cout << double(end - begin) / CLOCKS_PER_SEC;
//
//    auto result = new int[m->size];
//    int cur, ptr = 0, vertex = finish - 1;
//    do{
//        if(vertex == -1){
//            cout << "N";
//            return 0;
//        }
//        result[ptr++] = vertex;
//        vertex = paths[vertex];
//    }while(vertex != start - 1);
//
//    cout << "Y\n" << start;
//    for(int i=ptr-1; i>=0; i--)
//        cout << " " << result[i] + 1;
}