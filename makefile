compile:
	g++ Cipher.cpp -c -Wall	
	g++ Queue.cpp -c -Wall
	g++ -std=c++17 Project3.cpp -Wall Queue.o Cipher.o -o project3.out
run:
	./project3.out
clean:
	rm *.out
	rm *.o
