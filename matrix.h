#ifndef GRAPH3_MATRIX_H
#define GRAPH3_MATRIX_H

#include <string>
#include <fstream>

class matrix {
public:
    const int MAX_WEIGHT = 32767;

    int **array;
    int size;
    explicit matrix(std::ifstream &input);

    bool is_connected(int start, int finish);
    int incoming_power(int vertex);
    int* topological_sort();
    int* find_paths_acyclic(int start, int *sorted);
    int* find_paths_dijkstra(int start);
};


#endif
