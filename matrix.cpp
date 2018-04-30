#include <stack>
#include "matrix.h"

matrix::matrix(std::ifstream &input){
    input >> size;
    array = new int*[size];
    for(int i=0; i<size; i++){
        array[i] = new int[size];
        for(int j=0; j<size; j++)
            input >> array[i][j];
    }
}

bool matrix::is_connected(int start, int finish){
    return array[start][finish] != MAX_WEIGHT;
}

int matrix::incoming_power(int vertex){
    int c = 0;
    for(int i=0; i<size; i++)
        if(is_connected(i, vertex))
            c++;
    return c;
}

int* matrix::topological_sort(){
    auto *powers = new int[size];
    for(int i=0; i<size; i++)
        powers[i] = incoming_power(i);

    auto *result = new int[size];
    int ptr = 0;
    std::stack<int> s;
    for(int i=0; i<size; i++)
        if(powers[i] == 0)
            s.push(i);

    while(!s.empty()){
        int current = s.top();
        s.pop();
        result[ptr++] = current;
        for(int i=0; i<size; i++)
            if(is_connected(current, i))
                if(--powers[i] == 0)
                    s.push(i);
    }
    if(ptr != size)
        return nullptr;
    return result;
}

int* matrix::find_paths(int start, int* sorted){
    auto prev = new int[size];
    auto len = new int[size];
    int vertex, i = 0;
    do{
        vertex = sorted[i++];
        prev[vertex] = -1;
        len[vertex] = MAX_WEIGHT;
    }while(vertex != start);
    len[vertex] = 0;

    for(i; i<size; i++){
        vertex = sorted[i];
        len[vertex] = MAX_WEIGHT;
        prev[vertex] = -1;
        for(int t=0; t<i; t++) {
            int other = sorted[t];
            if(is_connected(other, vertex)){
                int distance = len[other] + array[other][vertex];
                if (distance < len[vertex]) {
                    len[vertex] = distance;
                    prev[vertex] = other;
                }
            }
        }
    }
    return prev;
}

int* matrix::find_paths(int start) {
    auto prev = new int[size];
    auto len = new int[size];
    for(int i=0; i<size; i++){
        len[i] = MAX_WEIGHT;
        prev[i] = -1;
    }
    len[start] = 0;

    auto s = std::stack<int>();
    s.push(start);
    while(!s.empty()){
        int vertex = s.top();
        s.pop();
        for(int other=0; other<size; other++)
            if(is_connected(vertex, other)){
                int distance = len[vertex] + array[vertex][other];
                if(distance < len[other]){
                    len[other] = distance;
                    prev[other] = vertex;
                    s.push(other);
                }
            }
    }
    return prev;
}
