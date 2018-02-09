#include <stdio.h>
#include <vector>
#include "Solver.cpp"

int main() {
    Solver *solver = new Solver();

    std::vector<std::vector<int>> test1 = {  
        { 1, 1, 0, 0 },
        { 1, 1, 1, 0 },
        { 0, 1, 1, 0 },
        { 0, 0, 0, 1 },
    };

    std::vector<std::vector<int>> test2 = {  
        { 1, 0, 0, 0 },
        { 0, 1, 0, 0 },
        { 0, 0, 1, 0 },
        { 0, 0, 0, 1 },
    };

    solver->numberOfGroups(test1);
    solver->numberOfGroups(test2);
}

