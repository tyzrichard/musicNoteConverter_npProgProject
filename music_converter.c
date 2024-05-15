#include <stdio.h>

void main (void) {
    // Array for Music Notes. Its the only bit not covered in syllabus, but I really couldn't think of any other way to do it.
    // I could have used if-else statements, but ehhhhhh
    //char notes[] = {'C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'A#', 'B', 'C'};

    char initialNote;
    printf("Welcome! Enter a note to be converted (No flats, only whitekeys and sharps): ");
    scanf(" %c", &initialNote);

    printf("%c", initialNote);


}