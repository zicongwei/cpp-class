all:
	g++ -c -g -Wall ./part1/part1.cpp
	g++ -c -g -Wall ./part1/main.cpp
	g++ -o ./part1/part1 ./main.o ./part1.o
	g++ -c -g -Wall ./part2/part2.cpp
	g++ -c -g -Wall ./part2/main.cpp
	g++ -o ./part2/part2 ./main.o ./part2.o ./part1.o
	g++ -c -g -Wall ./part3/part3.cpp
	g++ -c -g -Wall ./part3/main.cpp
	g++ -o ./part3/part3 ./main.o ./part3.o ./part2.o ./part1.o

part1: ./part1/main.o ./part1/part1.o
	g++ -o ./part1/part1 ./part1/main.o ./part1/part1.o
	./part1/./part1

part1.o: ./part1/part1.cpp ./part1/part1.hpp
	g++ -c -g -Wall ./part1/part1.cpp

main.o: ./part1/main.cpp ./part1/part1.hpp
	g++ -c -g -Wall ./part1/main.cpp

part2: ./part2/main.o ./part2/part2.o ./part1/part1.o
	g++ -o ./part2/part2 ./part2/main.o ./part2/part2.o ./part1/part1.o
	./part2/./part2

part2.o: ./part2/part2.cpp ./part2/part2.hpp ./part1/part1.hpp
	g++ -c -g -Wall ./part2/part2.cpp

main.o: ./part2/main.cpp ./part2/part2.hpp ./part1/part1.hpp
	g++ -c -g -Wall ./part2/main.cpp

part3: ./part3/main.o ./part3/part3.o ./part1/part1.o ./part2/part2.o
	g++ -o ./part3/part3 ./part3/main.o ./part3/part3.o ./part2/part2.o ./part1/part1.o
	./part3/./part3

part3.o: ./part3/part3.cpp ./part3/part3.hpp ./part1/part1.hpp ./part2/part2.hpp
	g++ -c -g -Wall ./part3/part3.cpp

main.o: ./part3/main.cpp ./part3/part3.hpp ./part2/part2.hpp ./part1/part1.hpp
	g++ -c -g -Wall ./part3/main.cpp

clean:
	rm -f ./*.opp ./*.o
	rm -f ./part1/*.opp ./part1/*.o ./part1/part1
	rm -f ./part2/*.opp ./part2/*.o ./part2/part2
	rm -f ./part3/*.opp ./part3/*.o ./part3/part3

run:
	./part3/./part3

.PHONY: clean run
