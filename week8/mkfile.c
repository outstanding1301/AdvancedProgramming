#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
    if(mkdir("pilot", 0755) == -1) {
        perror("failed mkdir pilot");
    }

    if(chdir("pilot") == -1) {
        perror("failed chdir pilot\n");
    }

    
    if(mkdir("a", 0755) == -1) {
        perror("failed mkdir pilot/a");
    }

    FILE *f = fopen("pilot/a/test.txt", "w");
    fprintf(f, "한국산업기술대학교\n컴퓨터공학과\n홍길동");
    fclose(f);


    // system call
    system("mkdir pilot_sys pilot_sys/a");
    
    f = fopen("pilot_sys/a/test.txt", "w");
    fprintf(f, "한국산업기술대학교\n컴퓨터공학과\n홍길동");
    fclose(f);

    return 0;
}