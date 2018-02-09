CC = g++
CFLAGS = -std=c++14

all: friends_group.out

friends_group.out: friends_group.cpp
	$(CC) $(CFLAGS) friends_group.cpp -o friends_group.out

clean:
	rm -f *.out