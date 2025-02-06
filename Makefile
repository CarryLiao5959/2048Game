# 编译器
CC = g++

# 编译器选项
CFLAGS = -Wall

# 链接器选项
LDFLAGS = 

# 可执行文件名
EXECUTABLE = 2048

# 头文件
DEPS = matrix.h util.h

# 对象文件
OBJECTS = main.o matrixop.o

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

main.o: main.cpp $(DEPS)
	$(CC) $(CFLAGS) -c main.cpp

matrixop.o: matrixop.cpp $(DEPS)
	$(CC) $(CFLAGS) -c matrixop.cpp

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

rebuild: clean all
