WWW = -std=c11 -Wall -Wextra -Werror

OS = $(shell uname)

ifeq ($(OS), Linux)
	LINUX_LIBS=-D_GNU_SOURCE
endif

.PHONY: all clean test s21_grep

all: clean s21_grep

s21_grep:
	gcc $(WWW) s21_grep.c -g -lpcre $(LINUX_LIBS) -o s21_grep

test: s21_grep
	bash t_grep.sh

clean:
	rm -rf s21_grep
	rm -rf log.txt

check:
	clang-format -n --Werror ./*.c ./*.h