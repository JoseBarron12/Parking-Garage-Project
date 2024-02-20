
CXXFLAGS += -std=c++11 -Wall -Wextra -Werror -pedantic -I.


all: parking


main: parking.cc 
	g++ $(CXXFLAGS) -o parking parking.cc 


clean:
	rm -f parking

.PHONY: all clean
