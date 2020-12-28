# This is the default target, which will be built when
# you invoke make
.PHONY: all
all: directories bin/ut_all

bin/ut_all: obj/ut_main.o
	g++ -std=c++11  -o bin/ut_all obj/ut_main.o -lgtest -lpthread
	
obj/ut_main.o: test/ut_main.cpp test/ut_vector.h  src/vector.h src/bubbleSort.h src/circle.h src/polygon.h src/shape.h
	g++ -std=c++11 -c test/ut_main.cpp -o obj/ut_main.o -Wfatal-errors

# This rule create the bin and obj directory if they do not exist
directories:
	mkdir -p bin obj

# This rule tells make to delete hello and hello.o
.PHONY: clean
clean:
	rm -f bin/*
	rm -f obj/*

stat:
	wc src/* test/*
