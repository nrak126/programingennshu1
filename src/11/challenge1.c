#include <stdio.h>

int main(int argc, char *argv[]) {
    char paragraph[] =
        "we hold these truths to be self-evident, that all men are created "
        "equal, that they are endowed by their creator with certain "
        "unalienable "
        "rights, that among these are life, liberty and the pursuit of "
        "happiness.";
    char searchTerm[13];
    int index = -1;

    printf("searchTerm: ");
    scanf("%s", &searchTerm);

    for(int i = 0; paragraph[i] != '\0'; i++) {
        index = i;
        for(int j = i; j - i < searchTerm[j - i] != '\0'; j++)
            if(paragraph[j] == searchTerm[j - i])
                continue;
            else {
                index = -1;
                break;
            }
        if(index != -1)
            break;
    }

    printf("indexOf: %d\n", index);
    return 0;
}