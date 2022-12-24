#include "s21_cat.h"

int main(int argc, char *argv[]) { return s21_cat(argc, argv); }

int s21_cat(int argc, char *argv[]) {
  int err_flag = 0;
  if (argc > 1) {
    char *optstring = "b e E s t T n v";
    int one_option = 0;
    opt options;
    init_options(&options);
    while (one_option != -1) {
      one_option = getopt_long(argc, argv, optstring, longopts, NULL);
      parse_opt(&options, one_option);
    }
    for (int i = optind; i < argc; i++) {
      FILE *fp = fopen(argv[i], "r+");
      if (fp == NULL) {
        err_flag = 1;
        perror(argv[i]);
      } else {
        print(fp, options);
        fclose(fp);

        
      }
    }
  } else {
    err_flag = 1;
  }
  return err_flag;
}

void init_options(opt *options) {
  options->b = 0;
  options->e = 0;
  options->s = 0;
  options->t = 0;
  options->n = 0;
  options->v = 0;
}

void parse_opt(opt *options, int one_option) {
  if (one_option == 'b') options->b = 1;
  if (one_option == 'e') {
    options->e = 1;
    options->v = 1;
  }
  if (one_option == 'E') options->e = 1;
  if (one_option == 's') options->s = 1;
  if (one_option == 't') {
    options->t = 1;
    options->v = 1;
  }
  if (one_option == 'T') options->t = 1;
  if (one_option == 'n') options->n = 1;
}

void print(FILE *fp, opt options) {
  int string_count = 1;
  if (fp != NULL) {
    char x, fut_x;
    int flag = 0;
    fut_x = getc(fp);
    b_option(fut_x, &options, &string_count, fp, flag);
    n_option(fut_x, options, &string_count, fp);
    do {
      flag = 1;
      t_option(&fut_x, options, fp);
      s_option(fp, &fut_x, options, &string_count);
      x = fut_x;
      e_option(&x, options);
      printf("%c", x);
      b_option(x, &options, &string_count, fp, flag);
      n_option(x, options, &string_count, fp);
    } while ((fut_x = getc(fp)) != EOF);
  }
}

void s_option(FILE *fp, char *fut_x, opt options, int *string_count) {
  if (options.s == 1) {
    char fut_fut_x = getc(fp);
    if (*fut_x == '\n' && fut_fut_x == '\n') {
      while (fut_fut_x == '\n') {
        *fut_x = fut_fut_x;
        fut_fut_x = getc(fp);
      }
      if (options.e == 1) printf("$");
      printf("%c", *fut_x);
      if (options.n == 1) {
        printf("%6d\t", *string_count);
        (*string_count)++;
      }
    }
    if (fut_fut_x != -1) fseek(fp, -1, SEEK_CUR);
  }
}

void n_option(char x, opt options, int *string_count, FILE *fp) {
  if (options.n == 1) {
    if (getc(fp) != EOF) {
      if (x == '\n' || *string_count == 1) {
        printf("%6d\t", *string_count);
        (*string_count)++;
      }
      fseek(fp, -1, SEEK_CUR);
    }
  }
}

void b_option(char x, opt *options, int *string_count, FILE *fp, int flag) {
  if (options->b == 1) {
    options->n = 0;
    int fut_x = getc(fp);
    if (fut_x != EOF) {
      if ((x == '\n' && fut_x != '\n' && flag != 0) ||
          (x != '\n' && flag == 0)) {
        printf("%6d\t", *string_count);
        (*string_count)++;
      }
      fseek(fp, -1, SEEK_CUR);
    }
  }
}

void e_option(char *x, opt options) {
  if (options.e == 1) {
    if (*x == '\n') printf("$");
  }
  if (options.e == 1 && options.v == 1) v_option((unsigned char *)x);
}

void t_option(char *x, opt options, FILE *fp) {
  if (options.t == 1 && *x == 9) {
    while (*x == 9) {
      printf("^I");
      *x = getc(fp);
    }
  }
  if (options.t == 1 && options.v == 1) v_option((unsigned char *)x);
}

void v_option(unsigned char *x) {
  if (*x < 9 || (*x > 10 && *x <= 31)) {
    *x += 64;
    printf("^");
  } else if (*x == 127) {
    *x -= 64;
    printf("^");
  } else if (*x >= 128 && *x <= 159) {
    *x -= 64;
    printf("M-^");
  }
}
