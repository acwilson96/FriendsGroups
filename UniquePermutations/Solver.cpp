#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

class Solver {

    public:
        Solver() {}


        /*
         *  Takes a Vector and prints all the unique permutations and
         *  returns the number of unique permutations.
         */
        int numberOfPermutations(std::vector<int> nums) {
            std::vector<std::vector<int>> permutations = getPermutations(nums);
            for (std::vector<int> permutation: permutations) {
                printVector(permutation);
            }
            return permutations.size();
        }


    private:

            std::vector<std::vector<int>> getPermutations(std::vector<int> list) {
                std::vector<std::vector<int>> output;
                if (list.size() == 1) {
                    output.push_back(list);
                    return output;
                }
                int head;
                std::set<int> headsSeen;
                
                for (int i = 0; i < list.size(); i++) {
                    head                                    = list[i];                  // Get new "head" of this list.
                    if (headsSeen.count(head) != 0) continue;                          // Skip this head if we have already seen it.
                    headsSeen.insert(head);
                    
                    std::vector<int> tail                        = getTail(i, list);         // Get new "tail" of this set.
                    std::vector<std::vector<int>> tailPermutations    = getPermutations(tail);    // Get permutations of the "tail".
                    
                    
                    
                    // For each permutation of the tail, append it to the head.
                    for (std::vector<int> tailPermutation: tailPermutations) {
                        output.push_back(concatVector(head, tailPermutation));
                    }
                }
                return output;
            }
            
            // Removed element from list with index rmvIdx
            std::vector<int> getTail(int rmvIdx, std::vector<int> list) {
                std::vector<int> output;
                for (int i = 0; i < list.size(); i++) {
                    if (i == rmvIdx) continue;
                    output.push_back(list[i]);
                }
                return output;
            }
            
            // Appends a new head to the list.
            std::vector<int> concatVector(int head, std::vector<int> vect) {
                std::vector<int> output;
                output.push_back(head);
                for (int elem: vect)
                    output.push_back(elem);
                return output;
            }

            void printVecVector(std::vector<std::vector<int>> input) {
                printf("[\n");
                for (std::vector<int> vect: input) {
                    printVector(vect);
                }
                printf("\n]");
            }
            void printVector(std::vector<int> input) {
                printf("\n\t[");
                for (int i = 0; i < input.size(); i++) {
                    printf("%d", input[i]);
                    if (i != input.size() - 1) printf(", ");
                }
                // for (int elem: input) {
                //     printf("%d, ", elem);
                // }
                printf("]");
            }

        

};