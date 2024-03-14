#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 2024
#define MIN_LENGTH 1945

void lessThanRequired(int *n) {
    printf("The length of your text is less than specified, please update your text");
    *n = MIN_LENGTH;
}

void equalThanRequired(int *n) {
    printf("Thank you, Your text length is correct");
}

void moreThanRequired(int *n) {
    printf("Your text is too long, please reduce the text");
    *n = MAX_LENGTH;
}

int checkLengthRequirement(char* text) {
    int length = strlen(text);
    if (length < MIN_LENGTH)
        return 0;
    else if (length == MIN_LENGTH)
        return 1;
    else
        return 2;
}

int main() {
    int lengthOfText, selectOption;
    FILE *fptr = NULL;
    char text[MAX_LENGTH];

    void (*nih_ptr_arr[])(int*) = {lessThanRequired, equalThanRequired, moreThanRequired};

    fptr = fopen("file.txt", "r");

    if (fptr == NULL) {
        printf("Error");
        exit(1);
    }

    fgets(text, MAX_LENGTH, fptr);
    fclose(fptr);

    selectOption = checkLengthRequirement(text);
    (*nih_ptr_arr[selectOption])(&lengthOfText);

    printf("\nThe Length is updated to %d", lengthOfText);

    return 0;
}
