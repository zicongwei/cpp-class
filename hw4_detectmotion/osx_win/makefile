
TARGET2 := part2
TARGET1 := part1

CXX = g++

SOURCES1 := ./src/main_part1.cpp
SOURCES2 := ./src/context.cpp ./src/frame_function.cpp ./src/ps3eye.cpp ./src/main_part2.cpp
OBJECTS1 := $(patsubst %.cpp,%.o,$(SOURCES1))
OBJECTS2 := $(patsubst %.cpp,%.o,$(SOURCES2))


SDL_INC=-I/usr/local/include/SDL2
USB_INC=-I/usr/local/include/libusb-1.0

CXXFLAGS := -std=c++11 -g -Wall
CXXFLAGS += -I./include -I./hw/include -I/usr/local/Cellar/opencv/2.4.13.2/include
CXXFLAGS += $(SDL_INC)
CXXFLAGS += $(USB_INC)


LIBS := -L/usr/local/lib
LIBS += -L/usr/local/lib -L/usr/local/Cellar/libusb/1.0.21/lib -lusb-1.0 -L/usr/local/lib -lSDL2 -L/usr/local/Cellar/opencv/2.4.13.2/lib -lopencv_calib3d -lopencv_contrib -lopencv_core -lopencv_features2d -lopencv_flann -lopencv_gpu -lopencv_highgui -lopencv_imgproc -lopencv_legacy -lopencv_ml -lopencv_nonfree -lopencv_objdetect -lopencv_ocl -lopencv_photo -lopencv_stitching -lopencv_superres -lopencv_ts -lopencv_video -lopencv_videostab
LIBS += $(shell sdl2-config --libs)

.DEFAULT_TARGET := all

all: $(TARGET2)

$(TARGET1): $(OBJECTS1)
	$(CXX) -o $@ $(OBJECTS1) $(LIBS)

$(TARGET2): $(OBJECTS2)
	$(CXX) -o $@ $(OBJECTS2) $(LIBS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@
run:  $(TARGET1) $(TARGET2)
	./$(TARGET2)

clean:
	rm -rf *.o *~ part1 part2 *.dSYM src/*.o
