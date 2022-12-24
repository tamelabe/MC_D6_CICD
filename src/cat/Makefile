OS := $(shell uname -s)
CC = gcc

ifeq ($(OS), Darwin)
	@FLAGS := -Wall -Wextra -Werror -std=c11
else
	@FLAGS := -Wall -Wextra -Werror -std=c11 -D_GNU_SOURCE
endif
all: clean s21_cat

s21_cat:
	@$(CC) $(FLAGS) s21_cat.c -o s21_cat

clean:
	@rm -f s21_cat

leaks: s21_cat
	@leaks --atExit -- ./s21_cat -benst test_file/all_flag_tests/*

style: s21_cat
	@cp ../../materials/linters/CPPLINT.cfg ./
	@python3 ./../../materials/linters/cpplint.py --extensions=c s21_cat.c s21_cat.h
	@rm -f CPPLINT.cfg

check: style

test: s21_cat
	@bash t_cat.sh