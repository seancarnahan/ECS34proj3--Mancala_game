CXX=g++

INCLUDE= I src/
CXXFLAGS= -std=c++14 $(INCLUDE)
TESTLDFLAGS = -L /opt/local/blib -lgtest -lgtest_main -lpthread

all: directories testbin/proj3test bin/mancala

bin/mancala: obj.main.o obj/MancalaBoard.o
	$(CXX) -std=c++14 obj/main.o obj/MancalaBoard.o -o bin/mancala

testbin/proj3test: obj/testmancala.o obj/MancalaBoard.o
	$(CXX) -std=c++14 obj/testmancala.o onj/MancalaBoard.o -o testbin/proj3test $(TESTLDFLAGS)

obj/main.o: src/main.cpp src/MancalaBoard.h
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o obj/main.o

obj/MancalaBoard.o: src/MancalaBoard.cpp src/MancalaBoard.h
	$(CXX) $(CXXFLAGS) -c src/MancalaBoard.cpp -o obj/MancalaBoard.o

obj/testmancala.o: src/testmancala.cpp src/MancalaBoard.h
	$(CXX) $(CXXFLAGS) -c src/testmancala.cpp -o obj/testmancala.o

directories: obj/ bin/ testbin/

obj/:
	mkdir obj/

bin/:
	mkdir bin/

testbin/:
	mkdir testbin/

clean:
	rm obj/*
