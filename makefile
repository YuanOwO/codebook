CC = g++
SRC = test.cpp
DST = a.out
FLAG = -o $(DST) -fsanitize=undefined -std=c++17 -O1 -O2 -Wall -Wextra -Wshadow

all:
	$(CC) $(SRC) $(FLAG)
	@echo "編譯完成!"

d:FLAG += -DDEBUG
d:all

run:all
run:
	@echo "##### start runing #####"
	@./$(DST)

clean:
	@rm $(DST)

cls:
	@clear

r:run
