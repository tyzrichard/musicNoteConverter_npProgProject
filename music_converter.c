#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE 25
#define STRING_LENGTH 100

// Function Prototypes
const char *shiftNote(const char *input, int shift);

// Here, I define a 2D array of notes
char NoteArray[ARRAY_SIZE][STRING_LENGTH] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B",};

int main(){
    // Variables
    char input[STRING_LENGTH];
    int shift;

    // Get input from the user
    printf("Enter a string: ");
    scanf("%99s", input);
    printf("How many to shift by? ");
    scanf("%d", &shift);

    printf("Shifted string is: %s\n", shiftNote(input, shift));
}

const char *shiftNote(const char *input, int shift) {
    // Search for the input note in the array, and then returns the value "shift" positions to the right of the input note.
    int i = 0;
    while (i < ARRAY_SIZE)
    {
        i++;
        if (strcmp(input, NoteArray[i]) == 0)
        {
            return NoteArray[i + shift];
        }
    }
    return NULL;
}

/*
char inputNote, sharpFlat, key, finalNote, finalSharpFlat;

printf("Welcome! Enter a note (C, D, E, F, G, A, B): ");
scanf(" %c", &inputNote);
printf("\nDoes your note have a sharp/flat? Enter # for sharp, b for flat, and any other key if it has none of the mentioned: ");
scanf(" %c", &sharpFlat);

printf("\nFrom C Major, which key would you like to convert this note to?");
printf("\nEnter E for E Major, C for C# Minor, A for Ab Major, and F for F Minor: ");
scanf(" %c", &key);

if (key == 'E') { //Everything is shifted up 4 semitones
    if ((inputNote == 'C' && (sharpFlat != '#' || sharpFlat != 'b')) || (inputNote == 'B' && sharpFlat == '#')) { //C, aka B#
        finalNote = 'E';
    } else if ((inputNote == 'C' && sharpFlat == '#') || (inputNote == 'D' && sharpFlat == 'b')) { //C#, aka Db
        finalNote = 'F';
    } else if (inputNote == 'D' && (sharpFlat != '#' || sharpFlat != 'b')) { //D
        finalNote = 'F';
        finalSharpFlat = '#';
    } else if ((inputNote == 'D' && sharpFlat == '#') || (inputNote == 'E' && sharpFlat == 'b')) { //D#, aka Eb
        finalNote = 'G';
    } else if ((inputNote == 'E' && (sharpFlat != '#' || sharpFlat != 'b')) || (inputNote == 'F' && sharpFlat == 'b')) { //E, aka Fb
        finalNote = 'G';
        finalSharpFlat = '#';
    } else if ((inputNote == 'F' && (sharpFlat != '#' || sharpFlat != 'b')) || (inputNote == 'E' && sharpFlat == '#')) { //F, aka E#
        finalNote = 'A';
    } else if ((inputNote == 'F' && sharpFlat == '#') || (inputNote == 'G' && sharpFlat == 'b')) { //F#, aka Gb
        finalNote = 'A';
        finalSharpFlat = '#';
    } else if (inputNote == 'G' && (sharpFlat != '#' || sharpFlat != 'b')) { //G
        finalNote = 'B';
    } else if ((inputNote == 'G' && sharpFlat == '#') || (inputNote == 'A' && sharpFlat == 'b')) { //G#, aka Ab
        finalNote = 'C';
    } else if (inputNote == 'A' && (sharpFlat != '#' || sharpFlat != 'b')) { //A
        finalNote = 'C';
        finalSharpFlat = '#';
    } else if ((inputNote == 'A' && sharpFlat == '#') || (inputNote == 'B' && sharpFlat == 'b')) { //A#, aka Bb
        finalNote = 'D';
    } else if ((inputNote == 'B' && (sharpFlat != '#' || sharpFlat != 'b')) || (inputNote == 'C' && sharpFlat == 'b')) { //B, aka Cb
        finalNote = 'D';
        finalSharpFlat = '#';
    } else {
        printf("\nThe note %c%c either doesn't exist, or isn't within the keys that this program can convert currently.\n", inputNote, sharpFlat);
        printf("Perhaps you might want to run this program again?\n");
    }

    if (sharpFlat == '#' || sharpFlat == 'b') {
        printf("\nThe note %c%c when converted from C Major to E Major is %c%c.", inputNote, sharpFlat, finalNote, finalSharpFlat);
    } else {
        printf("\nThe note %c when converted from C Major to E Major is %c%c.", inputNote, finalNote, finalSharpFlat);
    } */
