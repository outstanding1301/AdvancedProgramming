#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct User {
    char name[30];
    char country[30];
    char area[30];
    char phone[15];
    char email[50];
    char userId[30];
    char usim[30];
} User;

void initUser(User *user, const char *key, const char *val);
int parse(char *buf, char *key, char *val);
User *parseFile(const char *filename);
void printUser(User *user);

int main(int arsc, const char **arsv) {
    if (arsc != 2) {
        fprintf(stderr, "usage: fparser <filename>\n");
        return -1;
    }
    User *user = parseFile(arsv[1]);
    if(user == NULL) {
        fprintf(stderr, "파일이 잘못되었거나 읽기에 실패했습니다.\n");
        return -1;
    }
    printUser(user);
    return 0;
}


void initUser(User *user, const char *key, const char *val) {
    if (strcmp(key, "NAME") == 0) {
        strcpy(user->name, val);
    }
    else if (strcmp(key, "COUNTRY") == 0) {
        strcpy(user->country, val);
    }
    else if (strcmp(key, "AREA") == 0) {
        strcpy(user->area, val);
    }
    else if (strcmp(key, "PHONE") == 0) {
        strcpy(user->phone, val);
    }
    else if (strcmp(key, "EMAIL") == 0) {
        strcpy(user->email, val);
    }
    else if (strcmp(key, "USRID") == 0) {
        strcpy(user->userId, val);
    }
    else if (strcmp(key, "USIM") == 0) {
        strcpy(user->usim, val);
    }
}

int parse(char *buf, char *key, char *val) {
    int i;
    int pivot = 0;
    int len = strlen(buf);
    char keyBuf[100] = {0};
    char valBuf[100] = {0};
    for (int i=0; i<len; i++) {
        if (buf[i] == '=') {
            pivot = i+1;
            continue;
        }
        if(pivot == 0) {
            if (buf[i] == '#') {
                keyBuf[i] = '\0';
                break;
            }
            keyBuf[i] = buf[i];
        }
        else {
            if (buf[i] == '#') {
                valBuf[i-pivot] = '\0';
                break;
            }
            valBuf[i-pivot] = buf[i]; 
        }
    }
    if (pivot == 0) return -1;
    strcpy(key, keyBuf);
    strcpy(val, valBuf);
    return 0;
}

User *parseFile(const char *filename) {
    User *user = NULL;
    FILE *file = fopen(filename, "r");
    char buf[255];

    if(file == NULL) return user;
    user = malloc(sizeof(User));
    memset(user, 0, sizeof(user));
    while (!feof(file)) {
        char key[100] = {0};
        char val[100] = {0};
        fgets(buf, sizeof(buf), file);
        if(buf[strlen(buf)-1] == '\n')
        buf[strlen(buf)-1] = '\0';
        if (parse(buf, key, val) == 0)
            initUser(user, key, val);
    }
    fclose(file);
    return user;
}

void printUser(User *user) {
    printf("--User-----------\n");
    printf("name: %s\n", user->name);
    printf("country: %s\n", user->country);
    printf("area: %s\n", user->area);
    printf("phone: %s\n", user->phone);
    printf("email: %s\n", user->email);
    printf("userId: %s\n", user->userId);
    printf("usim: %s\n", user->usim);
    printf("-----------------\n");
}