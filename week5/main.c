#include "fun.h"
#include <stdio.h>

int main() {
    fprintf(stdout, "main 함수 :: \n");
    func1();
    func2();
    func3();
    return 0;
}

// (1) 오브젝트 파일 생성 : gcc -c file1.c file2.c file3.c
// (2) 정적라이브러리 lib???.a 생성 : ar rscv libmyfunc.a file1.o file2.o file3.o
// (심볼 테이블 출력 : nm libmyfunc.a)
// (3) 라이브러리를 포함하는 실행파일 작성 : gcc -o main.o main.c -L. -lmyfunc