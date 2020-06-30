pa3: pa3.o citybst.o
	g++ -o pa3 pa3.o citybst.o

pa3.o: pa3.cpp
	g++ -c pa3.cpp

citybst.o: citybst.cpp
	g++ -c citybst.cpp

clean:
	rm *.o