#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include "Person.cpp"

class Solver {

    public:
        Solver() {}
    
        /*
         *  Takes a 2D Vector of Friendship relationships, where element (i,j) indicated
         *  if the people with ID i and ID j are friends.
         * 
         */
        int numberOfGroups(std::vector<std::vector<int> > friendships) {
            people.clear();
            // Create a pseudo array/linked-list of all users connections.
            for (int i = 0; i < friendships.size(); i++) {
                if (people[i] == NULL)
                    people[i] = new Person(i);
                visitPerson(people[i], friendships);
            }
            int numberGroups = 0;
            // Loop through all people, accounting for their friends, recursively marking if we have seen them.
            // If we see a unique user who has not been visited, then they are the start of a new friends group.
            for (int i = 0; i < friendships.size(); i++) {
                Person *currPerson = people[i];
                if (!currPerson->accountedFor) {
                    numberGroups++;
                    currPerson->determineGroup(currPerson);
                }
            }
            return numberGroups;
        }


    private:
        // Tracks all the involved people in the "Problem".
        std::map<int, Person*> people;

        /* Populates a given Person's friends list using array data using recursion. */
        void visitPerson(Person *p, std::vector<std::vector<int> > friendships) {
            int personID = p->getID();
            // Loop through this Users friendships statuses.
            for (int friendID=personID; friendID < friendships.size(); friendID++) {
                // Immediately skip your friendship with yourself.
                if (friendID == personID) continue;
                
                // Is p friends with this person.
                if (friendships[personID][friendID] == 1) {
                    // If this Person already exists.
                    if (people[friendID] != NULL) {
                        // Add to the current persons friends list.
                        people[personID]->addFriend(people[friendID]);
                        people[friendID]->addFriend(people[personID]);
                    }
                    else {
                        // Create a Person instance for the friend.
                        people[friendID] = new Person(friendID);
                        // Add to the current persons friends list.
                        people[personID]->addFriend(people[friendID]);
                        people[friendID]->addFriend(people[personID]);
                    }
                    // Now recursively check this friends friends.
                    visitPerson(people[friendID], friendships);
                }
            }
        }
};