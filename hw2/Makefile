TARGET1 := hw1
TARGET2 := hw2

.SUFFIXES: .hpp .cpp .cc .h .c .o .opp .so

CXX := g++
CXXFLAGS := -Wall -g

CXX_HEADERS2 := hw2.h

CXX_SOURCES2 :=
CXX_SOURCES2 += main.cpp

CXX_OBJECTS2 := $(CXX_SOURCES2:.cpp=.o)

INCLUDES := -I ./hw1
INCLUDES += -I ./hw1/include
INCLUDES += -I ./hw1/part1
INCLUDES += -I ./hw1/part2
INCLUDES += -I ./hw1/part3
INCLUDES += -I ./includes

LIBS := -L./hw1 -lhw1


.DEFAULT_GOAL := all
all: $(TARGET2)

$(TARGET2): $(CXX_OBJECTS2) $(TARGET1) ./src/hw2.o
	$(CXX) -o $@ $(CXX_OBJECTS2) ./src/hw2.o $(LIBS)

hw2.o: ./src/hw2.cpp ./includes/hw2.h
	g++ -c -g -Wall ./src/hw2.cpp ./includes/hw2.h

hw1:
	make -C hw1

.cpp.o: $(CXX_HEADERS2)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f *.opp *.o $(TARGET2) ./src/hw2.o
	make -C hw1 clean

run: $(TARGET2)
	DYLD_LIBRARY_PATH=./hw1 ./$(TARGET2)
	# LD_LIBRARY_PATH=./hw1 ./$(TARGET2)

.PHONY: clean run help hw1

