EXE := mysteries

SRCS := main.cpp

CXX := g++
CXXFLAGS := -std=c++17 -O3 -flto
CXXFLAGS += $(shell pkg-config --cflags sdl2)

LIBS := $(shell pkg-config --libs sdl2)

all: $(SRCS) $(EXE)

$(EXE): $(SRCS:.cpp=.o)
	$(CXX) $(CXXFLAGS) $(LIBS) -o $(EXE) $(SRCS:.cpp=.o)

.cpp.o:
	$(CXX) -c $(CXXFLAGS) -o $@ $<
