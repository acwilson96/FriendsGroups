#include <stdio.h>
#include <vector>
#include "Solver.cpp"

int main() {
    int num_tests = 5;
    int test_results[num_tests];

    Solver *solver = new Solver();
    std::vector<std::vector<int>> tests = {
        { 1, 1 },
        { 1, 2, 2 },
        { 1, 2, 3, 4 },
        { 1, 2, 3, 4, 5 },        
        { /* NOTHING */ }
    };

    int i = 0;
    int numPerms;
    for (auto test: tests) {
        printf("\nTest %d", i);
        numPerms = solver->numberOfPermutations(test);
        printf("\n%d Permutation(s)\n", numPerms);
        i++;
    }
}

