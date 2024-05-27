#include <stdio.h>

void main () {
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
        }

    } else if (key == 'C') {
        if ((inputNote == 'C' && (sharpFlat != '#' || sharpFlat != 'b')) || (inputNote == 'B' && sharpFlat == '#')) { //C, aka B#
            finalNote = 'C';
            finalSharpFlat = '#';
        } else if ((inputNote == 'C' && sharpFlat == '#') || (inputNote == 'D' && sharpFlat == 'b')) { //C#, aka Db
            finalNote = 'D';
        } else if (inputNote == 'D' && (sharpFlat != '#' || sharpFlat != 'b')) { //D
            finalNote = 'D';
            finalSharpFlat = '#';
        } else if ((inputNote == 'D' && sharpFlat == '#') || (inputNote == 'E' && sharpFlat == 'b')) { //D#, aka Eb
            finalNote = 'E';
        } else if ((inputNote == 'E' && (sharpFlat != '#' || sharpFlat != 'b')) || (inputNote == 'F' && sharpFlat == 'b')) { //E, aka Fb
            finalNote = 'F';
        } else if ((inputNote == 'F' && (sharpFlat != '#' || sharpFlat != 'b')) || (inputNote == 'E' && sharpFlat == '#')) { //F, aka E#
            finalNote = 'F';
            finalSharpFlat = '#';
        } else if ((inputNote == 'F' && sharpFlat == '#') || (inputNote == 'G' && sharpFlat == 'b')) { //F#, aka Gb
            finalNote = 'G';
        } else if (inputNote == 'G' && (sharpFlat != '#' || sharpFlat != 'b')) { //G
            finalNote = 'G';
            finalSharpFlat = '#';
        } else if ((inputNote == 'G' && sharpFlat == '#') || (inputNote == 'A' && sharpFlat == 'b')) { //G#, aka Ab
            finalNote = 'A';
        } else if (inputNote == 'A' && (sharpFlat != '#' || sharpFlat != 'b')) { //A
            finalNote = 'A';
            finalSharpFlat = '#';
        } else if ((inputNote == 'A' && sharpFlat == '#') || (inputNote == 'B' && sharpFlat == 'b')) { //A#, aka Bb
            finalNote = 'B';
        } else if ((inputNote == 'B' && (sharpFlat != '#' || sharpFlat != 'b')) || (inputNote == 'C' && sharpFlat == 'b')) { //B, aka Cb
            finalNote = 'C';
        } else {
            printf("\nThe note %c%c either doesn't exist, or isn't within the keys that this program can convert currently.\n", inputNote, sharpFlat);
            printf("Perhaps you might want to run this program again?\n");
        }

        if (sharpFlat == '#' || sharpFlat == 'b') {
            printf("\nThe note %c%c when converted from C Major to C# Minor is %c%c.", inputNote, sharpFlat, finalNote, finalSharpFlat);
        } else {
            printf("\nThe note %c when converted from C Major to C# Minor is %c%c.", inputNote, finalNote, finalSharpFlat);
        }

    } else if (key == 'A') {
        if ((inputNote == 'C' && (sharpFlat != '#' || sharpFlat != 'b')) || (inputNote == 'B' && sharpFlat == '#')) { //C, aka B#
            finalNote = 'A';
            finalSharpFlat = 'b';
        } else if ((inputNote == 'C' && sharpFlat == '#') || (inputNote == 'D' && sharpFlat == 'b')) { //C#, aka Db
            finalNote = 'A';
        } else if (inputNote == 'D' && (sharpFlat != '#' || sharpFlat != 'b')) { //D
            finalNote = 'B';
            finalSharpFlat = 'b';
        } else if ((inputNote == 'D' && sharpFlat == '#') || (inputNote == 'E' && sharpFlat == 'b')) { //D#, aka Eb
            finalNote = 'B';
        } else if ((inputNote == 'E' && (sharpFlat != '#' || sharpFlat != 'b')) || (inputNote == 'F' && sharpFlat == 'b')) { //E, aka Fb
            finalNote = 'C';
        } else if ((inputNote == 'F' && (sharpFlat != '#' || sharpFlat != 'b')) || (inputNote == 'E' && sharpFlat == '#')) { //F, aka E#
            finalNote = 'D';
            finalSharpFlat = 'b';
        } else if ((inputNote == 'F' && sharpFlat == '#') || (inputNote == 'G' && sharpFlat == 'b')) { //F#, aka Gb
            finalNote = 'D';
        } else if (inputNote == 'G' && (sharpFlat != '#' || sharpFlat != 'b')) { //G
            finalNote = 'E';
            finalSharpFlat = 'b';
        } else if ((inputNote == 'G' && sharpFlat == '#') || (inputNote == 'A' && sharpFlat == 'b')) { //G#, aka Ab
            finalNote = 'E';
        } else if (inputNote == 'A' && (sharpFlat != '#' || sharpFlat != 'b')) { //A
            finalNote = 'F';
        } else if ((inputNote == 'A' && sharpFlat == '#') || (inputNote == 'B' && sharpFlat == 'b')) { //A#, aka Bb
            finalNote = 'G';
            finalSharpFlat = 'b';
        } else if ((inputNote == 'B' && (sharpFlat != '#' || sharpFlat != 'b')) || (inputNote == 'C' && sharpFlat == 'b')) { //B, aka Cb
            finalNote = 'G';
        } else {
            printf("\nThe note %c%c either doesn't exist, or isn't within the keys that this program can convert currently.\n", inputNote, sharpFlat);
            printf("Perhaps you might want to run this program again?\n");
        }

        if (sharpFlat == '#' || sharpFlat == 'b') {
            printf("\nThe note %c%c when converted from C Major to Ab Major is %c%c.", inputNote, sharpFlat, finalNote, finalSharpFlat);
        } else {
            printf("\nThe note %c when converted from C Major to Ab Major is %c%c.", inputNote, finalNote, finalSharpFlat);
        }

    } else if (key == 'F') {
        if ((inputNote == 'C' && (sharpFlat != '#' || sharpFlat != 'b')) || (inputNote == 'B' && sharpFlat == '#')) { //C, aka B#
            finalNote = 'F';
        } else if ((inputNote == 'C' && sharpFlat == '#') || (inputNote == 'D' && sharpFlat == 'b')) { //C#, aka Db
            finalNote = 'G';
            finalSharpFlat = 'b';
        } else if (inputNote == 'D' && (sharpFlat != '#' || sharpFlat != 'b')) { //D
            finalNote = 'G';
        } else if ((inputNote == 'D' && sharpFlat == '#') || (inputNote == 'E' && sharpFlat == 'b')) { //D#, aka Eb
            finalNote = 'A';
            finalSharpFlat = 'b';
        } else if ((inputNote == 'E' && (sharpFlat != '#' || sharpFlat != 'b')) || (inputNote == 'F' && sharpFlat == 'b')) { //E, aka Fb
            finalNote = 'A';
        } else if ((inputNote == 'F' && (sharpFlat != '#' || sharpFlat != 'b')) || (inputNote == 'E' && sharpFlat == '#')) { //F, aka E#
            finalNote = 'B';
            finalSharpFlat = 'b';
        } else if ((inputNote == 'F' && sharpFlat == '#') || (inputNote == 'G' && sharpFlat == 'b')) { //F#, aka Gb
            finalNote = 'B';
        } else if (inputNote == 'G' && (sharpFlat != '#' || sharpFlat != 'b')) { //G
            finalNote = 'C';
        } else if ((inputNote == 'G' && sharpFlat == '#') || (inputNote == 'A' && sharpFlat == 'b')) { //G#, aka Ab
            finalNote = 'D';
            finalSharpFlat = 'b';
        } else if (inputNote == 'A' && (sharpFlat != '#' || sharpFlat != 'b')) { //A
            finalNote = 'D';
        } else if ((inputNote == 'A' && sharpFlat == '#') || (inputNote == 'B' && sharpFlat == 'b')) { //A#, aka Bb
            finalNote = 'E';
            finalSharpFlat = 'b';
        } else if ((inputNote == 'B' && (sharpFlat != '#' || sharpFlat != 'b')) || (inputNote == 'C' && sharpFlat == 'b')) { //B, aka Cb
            finalNote = 'E';
        } else {
            printf("\nThe note %c%c either doesn't exist, or isn't within the keys that this program can convert currently.\n", inputNote, sharpFlat);
            printf("Perhaps you might want to run this program again?\n");
        }

        if (sharpFlat == '#' || sharpFlat == 'b') {
            printf("\nThe note %c%c when converted from C Major to F Minor is %c%c.", inputNote, sharpFlat, finalNote, finalSharpFlat);
        } else {
            printf("\nThe note %c when converted from C Major to F Minor is %c%c.", inputNote, finalNote, finalSharpFlat);
        }

    } else {
        printf("\nThe key %c either doesn't exist, or isn't within the keys that this program can convert currently.\n", key);
        printf("Perhaps you might want to run this program again?\n");
    }
}