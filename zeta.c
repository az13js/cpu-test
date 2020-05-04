/* 测试处理器速度，原理：给定参数计算黎曼函数的值，计算运行时间差 */
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(int argv, char **argc) {
    int i = 0;
    clock_t start, end;
    double s = 0.0;
    int n = 0;
    double y = 0.0;
    double diff;

    /* 首先从命令行中提取参数 */
    for (i = 0; i < argv; i++) {
        if (0 == strcmp("-s", argc[i]) && i + 1 < argv) {
            s = atof(argc[i + 1]);
        }
        if (0 == strcmp("-n", argc[i]) && i + 1 < argv) {
            n = atoi(argc[i + 1]);
        }
    }
    printf("s=%f, n=%d\n", s, n);

    /* 开始计算 */
    start = clock();
    for (i = 0; i < n; i++) {
        y = y + 1.0 / pow((double)i + 1.0, s);
    }
    end = clock();

    /* 计算时间差并输出结果 */
    diff = (double)(end - start) / CLOCKS_PER_SEC;
    printf("zeta(%f)=%f, time=%f(sec)\n", s, y, diff);
    return 0;
}

