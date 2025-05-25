#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>
#include "utils.h"

int readInputFromFile(const char *filename, double **x, double **y, int *n) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        printf("Khong the mo file %s\n", filename);
        printLog("Khong the mo file %s\n", filename);
        return 0;
    }
    fscanf(f, "%d", n);
    *x = (double *)malloc((*n) * sizeof(double));
    *y = (double *)malloc((*n) * sizeof(double));
    for (int i = 0; i < *n; i++) {
        fscanf(f, "%lf%lf", &((*x)[i]), &((*y)[i]));
    }
    fclose(f);
    return 1;
}

void printLog(const char *format, ...) {
    FILE *log = fopen("log.txt", "a");
    if (!log) {
        printf("Khong the mo file log");
        return;
    }

    va_list args;
    va_start(args, format);
    vfprintf(log, format, args);
    va_end(args);

    fclose(log);
}