#include <stdio.h>

void main () {
    char inputNote;
    int semitonesUp;

    printf("Welcome! Enter a note: ");
    scanf(" %c", &inputNote);
    printf("Number of semitones to transpose it up by: ");
    scanf("%d", &semitonesUp);

    printf("Summary: You entered the note %c and wanted to transpose it up by %d semitones.", inputNote, semitonesUp);
}