#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

long fileSize (FILE *stream);
long fileSizeWithStat (const char *filename);

int main(int argc, const char **argv) {
    FILE *file = NULL;
    long fsize = 0;
    if (argc != 2) {
        fprintf(stderr, "[usage] size <filename>\n");
        return 0;
    }
    else {
        file = fopen(argv[1], "r");
        if (file == NULL) {
            fprintf(stderr, "file \'%s\' not found.\n", argv[1]);
            return 0;
        }
        fsize = fileSize(file);
        fclose(file);
        // fsize = fileSizeWithStat(argv[1]);

        fprintf(stdout, "%ld\n", fsize);
    }
}

long fileSize (FILE *stream) {
    long cur, len;
    cur = ftell(stream);
    fseek(stream, 0L, SEEK_END);
    len = ftell(stream);
    fseek(stream, cur, SEEK_SET);
    return len;
}

long fileSizeWithStat (const char *filename) {
    struct stat *_stat = malloc(sizeof(struct stat));
    stat(filename, _stat);
    return _stat -> st_size;
}