CXX = g++

CXXFLAGS = -g

LDFLAGS = -lstdc++

TARGET = test

Headers = LinkedList.h

Sources = main.cpp 

Objects = $(Sources:.cpp=.o) 

all: $(TARGET)

$(TARGET): $(Objects) $(Headers)
	$(CXX) $(LDFLAGS) $(Objects) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS)  -c $< -o $@

clean:
	rm -f $(TARGET) $(Objects)

.PHONY: all clean