all: hw2_2
hw2_2: main.o hw2-2.o
	g++ main.o hw2-2.o -o hw2_2
main.o: main.cpp hw2-2.h
	g++ main.cpp -c
hw2-2.o: hw2-2.cpp hw2-2.h
	g++ hw2-2.cpp -c
clean:
	rm hw2_2
	rm *.o

