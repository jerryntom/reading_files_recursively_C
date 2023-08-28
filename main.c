#include <stdio.h>
#include <string.h>

int read_file(const char *filename) {
    if(filename == NULL) return -1;
    int count = 1;

    FILE *file = NULL, *sub_file = NULL;
    char buf[2048], temp_buf[2048];

    file = fopen(filename, "rb");
    if(file == NULL) {
        return 0;
    }
    else {
        while(!feof(file)) {
            strcpy(temp_buf, buf);
            fscanf(file, "%1023s", buf);
            if(strcmp(buf, temp_buf) != 0) {
                printf("%s\n", buf);
                sub_file = fopen(buf, "rb");
                if(sub_file != NULL) {
                    fclose(sub_file);
                    sub_file = NULL;
                    if(strcmp(buf, "\n") != 0) count += read_file(buf);
                }
            }
            else continue;
        }
    }

    if(file != NULL) {
        fclose(file);
        file = NULL;
    }
    if(sub_file != NULL) {
        fclose(sub_file);
        sub_file = NULL;
    }
    return count;
}

int main() {
    char file_path[31];
    int res;
    printf("File path:");
    scanf("%30[^\n]", file_path);
    res = read_file(file_path);
    if(res == 0) {
        printf("Couldn't open file");
        return 4;
    }
    printf("%d", res);
    return 0;
}