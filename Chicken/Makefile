CXX = g++

TARGET = Chicken

Object = Chicken.o

all: $(TARGET)

$(TARGET): $(Object)
	$(CXX) $(Object) -o $(TARGET)

%.o: %.cpp
	$(CXX) -g -c $< -o $@

clean:
	rm -f $(TARGET) $(Object)

.PHONY: all clean