#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_

#include <errno.h>
#include <getopt.h>
#include <stdio.h>

const struct option longopts[] = {{"number-nonblank", 0, 0, 'b'},
                                  {"number", 0, 0, 'n'},
                                  {"squeeze-blank", 0, 0, 's'},
                                  {0, 0, 0, 0}};

typedef struct opt {
  int b;
  int e;
  int s;
  int t;
  int n;
  int v;
} opt;

void init_options(opt *options);  // обнуляем структуру опций

void parse_opt(opt *options,
               int one_option);  // записываем в структуру все наши опции

int s21_cat(int argc, char *argv[]);  // основная функция

void print(FILE *fp, opt options);  // печатаем результат

void s_option(FILE *fp, char *fut_x, opt options, int *string_count);

void n_option(char x, opt options, int *string_count, FILE *fp);

void b_option(char x, opt *options, int *string_count, FILE *fp, int flag);

void e_option(char *x, opt options);

void t_option(char *x, opt options, FILE *fp);

void v_option(unsigned char *x);

#endif  // SRC_CAT_S21_CAT_H_
