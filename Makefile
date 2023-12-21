all:

1:
	g++ 1.cpp -o 1
	./1
	rm 1

2:
	g++ 2.cpp -o 2
	./2
	rm 2

3:
	g++ 3.cpp -o 3
	./3
	rm 3

4:
	g++ 4.cpp -o 4
	./4
	rm 4

5:
	g++ 5.cpp -o 5
	./5
	rm 5

6:
	g++ 6.cpp -o 6
	./6
	rm 6

clean:
	rm 1
	rm 2
	rm 3
	rm 4
	rm 5
	rm 6