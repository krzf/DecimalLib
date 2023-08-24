FLAGS = -Wall -Wextra -Werror -std=c11
CC = gcc
LFLAGS = -fprofile-arcs -ftest-coverage
SRC := $(wildcard funcs/*.c)
OBJ := $(patsubst funcs/*.c, %.o, $(SRC))
VALGRIND_FLAGS=--leak-check=full
VALGRIND_FLAGS_v2 = --log-file="valgrind.txt" --track-origins=yes --trace-children=yes --leak-check=full --leak-resolution=med
LINUX_FLAGS=-lcheck -lsubunit -lm -lrt -lpthread
MAC_FLAGS=-lcheck -lm
OS := $(shell uname -s)


all: decimal.a test gcov_report

gcov: gcov_report

test: decimal.a
ifeq ($(OS),Linux)
	$(CC) $(FLAGS) $(OBJ) $(LFLAGS) check.c -o test -lm -lcheck -L/usr/local/lib
else
	$(CC) $(FLAGS) $(OBJ) $(LFLAGS) check.c -o test $(MAC_FLAGS)
endif
	./test

decimal.a: 
	gcc -Wall -Wextra -Werror funcs/*.c -c
	ar rc libdecimal.a *.o
	ranlib libdecimal.a
	cp libdecimal.a ./decimal.a
	rm *.o

gcov_report: test
	gcov check.c
	lcov --directory . --capture --output-file coverage.info
	genhtml coverage.info --output-directory coverage-html
	rm -rf *.gcda *.gcno
ifeq ($(OS),Linux)
	xdg-open coverage-html/index.html
else
	open coverage-html/index.html
endif
	
style:
	clang-format -style=Google -i decimal.h check.c funcs/*.c

stylecheck:
	clang-format -style=Google -n decimal.h check.c funcs/*.c

memory_check: decimal.a
ifeq ($(OS),Linux)
	$(CC) $(FLAGS) check.c $< -o memory_test $(LINUX_FLAGS)
	CK_FORK=no valgrind $(VALGRIND_FLAGS) ./memory_test
endif
ifeq ($(OS),Darwin)
	$(CC) $(FLAGS) check.c $< -o memory_test $(MAC_FLAGS)
	leaks --atExit -- ./memory_test      
endif

valgrind: test
	valgrind $(VALGRIND_FLAGS_v2) ./test
	grep -n "ERROR SUMMARY" valgrind.txt

garb: decimal.a
	$(CC) $(FLAGS) $(OBJ) $(LFLAGS) garb.c -o test $(MAC_FLAGS)
	./test

clean:
	rm -rf *.o
	rm -rf *.gcno
	rm -rf *.gcov
	rm -rf *.gcda
	rm -rf *.a
	rm -rf *.info
	rm -rf *.a_check
	rm -rf gcov
	rm -rf coverage
	rm -rf coverage-html
	rm -rf test
	rm -rf memory_test
	rm -rf valgrind.txt
