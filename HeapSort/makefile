CXX = g++

CXXFLAGS = -g -O2

LDFLAGS = -lstdc++

TARGET = test

Headers = HeapSort.h

Sources = test.cpp 

Objects = $(Sources:.cpp=.o) 

all: $(TARGET)

$(TARGET): $(Objects) $(Headers)
	$(CXX) $(LDFLAGS) $(Objects) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS)  -c $< -o $@

clean:
	rm -f $(TARGET) $(Objects) *.aux *.log *.out *.toc *.pdf 

run: $(TARGET)
	./$(TARGET) 

report:
	xelatex report.tex

.PHONY: all clean run report