CXX = g++

CXXFLAGS = -g

LDFLAGS = -lstdc++

TARGET = test

Headers = List.h

Sources = List.cpp 

Objects = $(Sources:.cpp=.o)
 

all: $(TARGET)   

$(TARGET): $(Objects) $(Headers)
	$(CXX) $(LDFLAGS) $(Objects) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS)  -c $< -o $@


clean:
	rm -f $(TARGET) $(Objects) *.aux *.log *.out *.toc *.pdf 

report:
	xelatex report.tex

.PHONY: all clean report

