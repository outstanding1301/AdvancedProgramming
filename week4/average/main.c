#include <stdio.h>

int input_data();
double average();
void print_data(double);

int count = 0;
static int total = 0;

int main() {
    double avg;

    total = input_data();
    avg = average();
    print_data(avg);

    return 0;
}

void print_data(double avg) {
    printf(" 입력한 양수의 개수: %d\n", count);
    printf(" 전체 합과 평균: %d, %.1lf\n", total, avg);
}