# 定义编译器
CXX = g++

# 目标文件
TARGET = hello

Object = hello.o

# 默认目标
all: $(TARGET)
	@echo "dont change tab!!!"

# 生成可执行文件
$(TARGET): $(Object)
	$(CXX) $(Object) -o $(TARGET)

# 生成目标文件
%.o: %.cpp
	$(CXX) -c $< -o $@

# 清理生成的文件
clean:
	rm -f $(TARGET) $(Object)

.PHONY: all clean