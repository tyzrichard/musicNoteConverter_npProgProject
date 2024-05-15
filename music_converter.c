#include <stdio.h>

 main () {
    // Array for Music Notes. Its the only bit not covered in syllabus, but I really couldn't think of any other way to do it.
    // I could have used if-else statements, but ehhhhhh
    //char notes[] = {'C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'A#', 'B', 'C'};

    char input[20];
    printf("Enter something cool: ");
    scanf("%s", &input);
    printf("you entered %s, and it changed!", input);
}