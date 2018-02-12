#include <set>
#include <algorithm>

class Person {

    public:

        bool accountedFor = false;

        Person() {}
        Person(int person_id) {
            id = person_id;
        }

        void determineGroup(Person *caller) {
            counted();
            for (Person *f: friends) {
                if (!f->accountedFor)
                    f->determineGroup(this);
            }
        }

        void counted() {
            accountedFor = true;
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
            if (friends.count(f) == 0) {
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