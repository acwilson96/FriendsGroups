#include <stdio.h>
#include <vector>
#include "Solver.cpp"

int main() {
    int num_tests = 5;
    int test_results[num_tests];

    Solver *solver = new Solver();
    std::vector<std::vector<int>> tests = {
        { 1 },
        { 1, 2, 3 },
        { 2, 3, 1 },    
        { /* NOTHING */ }
    };

    for (auto test: tests) {
        printf("\nTest %d", i);
        numRmd = solver->numberElementsRemoved(1, solver->craftLinkedList(test));
        printf("\n\t%d Element(s) Removed", numRmd);
        printf("\nReversing Linked List");
        solver->reverseLinkedList(solver->craftLinkedList(test));
        i++;
    }
    return 1;
}