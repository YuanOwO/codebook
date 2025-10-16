UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Darwin) # macOS
	CXX = clang++
	SANITIZE = -fsanitize=address # macOS does not support ubsan
else # Linux, Windows, ...
	CXX = g++
	SANITIZE = -fsanitize=undefined,address
endif

SRC = test.cpp
DST = a.out
FLAGS = -std=c++17 -O1 -O2 -Wall -Wextra -Wshadow ${SANITIZE} -Iinclude/stdc++.h

all:
	$(CXX) $(FLAGS) -o $(DST) $(SRC)
	@echo "編譯完成!"

d:FLAGS += -DDEBUG
d:all

run:all
run:
	@echo "##### start runing #####"
	@./$(DST)

clean:
	@rm $(DST)

r:run
