#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <ftw.h>

void appendResult(const char *filename, int size) {
    char buf[255];
    FILE *result = fopen("result.txt", "a");
    FILE *file = fopen(filename, "r");
    fread(buf, 1, size, file);
    fprintf(result, "%s", buf);
    fprintf(stdout, "append %s(%d)\n", filename, size);
    fclose(file);
    fclose(result);
}

int handler(const char *fpath, const struct stat *sb, int tflag, struct FTW *ftwbuf) {
    if(strstr(fpath, "abc") != 0) {
        appendResult(fpath, sb->st_size);
    }
    return 0;
}

void mkDirAndFiles() {
    char buf[255];
    for (int i=1;i<=5;i++) {
        sprintf(buf, "%d", i);
        if (mkdir(buf, 0755) == -1) {
            perror("mkdir failed");
        }
        else {
            sprintf(buf, "%d/abc_%d.c", i, i);
            FILE *f = fopen(buf, "w");
            fprintf(f, "#include <stdio.h>\nint main() {\n\tprintf(\"this is file %d\");\n\treturn 0;\n}\n", i);
            fclose(f);
        }
    }
}

int main() {
    mkDirAndFiles();
    nftw(".", handler, 20, 0);
    return 0;
}