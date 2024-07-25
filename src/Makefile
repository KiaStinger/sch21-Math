CC= gcc
# CFLAGS= -Wall -Werror -Wextra -std=c11
CFLAGS= -Wall -Werror -Wextra -std=c11 $(shell pkg-config --cflags check)
MATH= ./functions/*.c
OBJECTS= *.o
TEST= ./unit_tests/*.c
CLANG= clang-format
TEST_FLAGS:= -lcheck -lm -lpthread $(shell pkg-config --libs check)

# FLAGS_FOR_LINUX= -lsubunit

.PHONY: all clean test rebuild s21_math.a

all: clean s21_math.a test gcov_report

s21_math.a:
	$(CC) $(CFLAGS) -c $(MATH)
	ar rcs s21_math.a $(OBJECTS)

test: s21_math.a
	$(CC) $(CFLAGS) $(MATH) $(TEST) s21_math.a $(TEST_FLAGS) -lcheck -lm -o test
	./test

clean:
	rm -rf *.o *.a test *.gch *.gcno *.gcda *.info report 

rebuild:
	make clean
	make all

gcov_report: s21_math.a
	$(CC) $(CFLAGS) --coverage $(MATH) $(TEST) $(TEST_FLAGS) -lm -o test 
	./test
	lcov -t "test" -o test_report.info -c -d .
	genhtml -o report test_report.info
	rm -rf *.o *.a  *.gch *.gcno test


clang_n:
	$(CLANG) -style=Google -n *.[ch]

clang_i:
	$(CLANG) -style=Google -i *.[ch]
