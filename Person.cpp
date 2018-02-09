#include <set>
#include <algorithm>

class Person {

    public:
        Person() {}
        Person(int person_id) {
            id = person_id;
        }

        /* Getter for Person's ID */
        int getID() {
            return id;
        }

        /* Getter for Friends List */
        std::set<Person*> getFriends() {
            return friends;
        }

        /* Adds a friend(Person) to this Persons friends list */
        void addFriend(Person *f) {
            // printf("\n\tPerson %d Adding Person %d", id, f->getID());
            if (friends.count(f) == 0) {
                // printf(" - Were not already Friends.");
                friends.insert(f);
            }
        }

        void printFriends() {
            printf("\n Person %d Friends:", id);
            for (Person *f: friends) {
                printf("\n %d", f->getID());
            }
        }
    
    private:
        int id;
        std::set<Person*> friends;
        
};