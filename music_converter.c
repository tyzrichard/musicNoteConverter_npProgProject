#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ARRAY_SIZE 13
#define STRING_LENGTH 10

// Function Prototypes
const char *flatConvert(const char *input);                                                                           // Converts notes with flats to their sharp equivalents for processing
int searchNote(const char *input);                                                                                    // Searches for a note, usually to see if its a valid input
int searchScale(const char *scale, int major);                                                                        // Similar to searchNote, but for scales
const char *shiftNote(const char *input, int shift);                                                                  // To find the value x positions to the right of a note in an array
int shiftFinder(const char *startScale, const char *endScale);                                                        // To find what's the x positions needed
void fullPiano();                                                                                                     // Prints the default piano with all the notes
void piano(char arr[ARRAY_SIZE][STRING_LENGTH], const char *scale, int major, int sharp, int flat, char print[7][3]); // A more modifyable piano

// Define a 2D array of notes
char NoteArray[30][STRING_LENGTH] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
char MajorScaleArray[ARRAY_SIZE][STRING_LENGTH] = {"C", "Db", "D", "Eb", "E", "F", "F#", "G", "Ab", "A", "Bb", "B"};
char MinorScaleArray[ARRAY_SIZE][STRING_LENGTH] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "Bb", "B"};

int main()
{
    char option[STRING_LENGTH];
    while (1)
    {
        printf("\n\n1) Transpose between Major Scales\n2) Transpose between Minor Scales\n3) Discover how Music Theory works!\n4) Settings\nEnter anything else to quit.\n\nSelect an option to continue: ");
        fgets(option, sizeof(option), stdin);
        option[strcspn(option, "\n")] = 0;

        if (strcmp(option, "1") == 0 || strcmp(option, "2") == 0) // Transposition
        {
            // Variables
            char input[STRING_LENGTH], inputList[ARRAY_SIZE][STRING_LENGTH] = {0}, outputList[ARRAY_SIZE][STRING_LENGTH] = {0};
            char initialScale[STRING_LENGTH] = {0}, finalScale[STRING_LENGTH] = {0};
            int shift, count = 0, i = 0;
            int major;
            char majorStr[6];

            if (strcmp(option, "1") == 0)
            { // Give basic information on the Major/Minor scaless, based on what the user chose
                printf("The 12 Major Scales are: C, Db, D, Eb, E, F, F#, G, Ab, A, Bb and B.\n");
                major = 1;
                strcpy(majorStr, "Major");
            }
            else
            {
                printf("The 12 Minor Scales are: C, C#, D, D#, E, F, F#, G, G#, A, Bb and B.\n");
                major = 0;
                strcpy(majorStr, "Minor");
            }

            // Get input from the user: initialScale, finalScale and an array of notes
            while (1) // Input Validation
            {
                printf("Enter the scale that you would like to transpose from: ");
                scanf("%s", initialScale);
                getchar();                            // Consume the newline character left in the buffer by scanf
                if (searchScale(initialScale, major)) // to search through Major/Minor ScaleArray
                {
                    break;
                }
                printf("Invalid input! Please enter a valid scale.\n");
            }
            while (1) // Input Validation
            {
                printf("Enter the scale you would like to transpose to: ");
                scanf("%s", finalScale);
                getchar();                          // Consume the newline character left in the buffer by scanf
                if (searchScale(finalScale, major)) // to search through Major/Minor ScaleArray
                {
                    break;
                }
                printf("Invalid input! Please enter a valid scale.\n");
            }

            while (count < ARRAY_SIZE)
            {
                printf("Enter a note that you would like to transpose, or press q to end: ");
                fgets(input, sizeof(input), stdin);

                // Remove the newline character from the input
                input[strcspn(input, "\n")] = '\0';

                if (strcmp(input, "q") == 0)
                {
                    break; // Breaks out of user validation if the input is 'q'
                }

                if (searchNote(input))
                {
                    strcpy(inputList[count], input); // Copy the input string to the array
                    count++;
                }
                else
                {
                    printf("Invalid input! Please enter a valid note.\n");
                }
            }

            // Process notes
            printf("You entered %d notes in %s %s:\n", count, initialScale, majorStr);
            shift = shiftFinder(initialScale, finalScale);
            while (i < count)
            {
                printf("%s ", inputList[i]);
                strcpy(outputList[i], shiftNote(inputList[i], shift));
                i++;
            }

            i = 0; // reset i to 0
            printf("\nAfter being shifted to %s %s, the notes are:\n", finalScale, majorStr);
            while (i < count)
            {
                printf("%s ", outputList[i]);
                i++;
            }
            printf("\n");
        }
        else if (strcmp(option, "3") == 0) // How Music Transposition Works
        {
            while (1)
            {
                char infoOption[STRING_LENGTH];
                printf("\n1) The different keys of a piano\n2) The 24 Music Scales\n3) Music Transposition\nOr enter anything else to go back.\nYour choice: ");
                fgets(infoOption, sizeof(infoOption), stdin);
                infoOption[strcspn(infoOption, "\n")] = 0;
                if (strcmp(infoOption, "1") == 0)
                {
                    printf("A piano typically has 12 keys as follows:\n");
                    fullPiano(1);
                    printf("From here, it repeats the same 12 keys, with each set being in a different pitch!\nA sharp (#) refers to a key that is one semitone higher (one step to the right) of the key before it, so C# refers to the black key directly to the right of C.\nOn the other hand, a flat (b) refers to a key that is one semitone lower, like how Db can be used to refer to the same black key.\n\nIn some rare occasions, x means double-sharp, and bb means double-flat.");
                }
                else if (strcmp(infoOption, "2") == 0)
                {
                    char scale[STRING_LENGTH];
                    printf("There are a total of 24 Scales. Which would you like to learn more about?\n");
                    printf(" ___________________________________________________________________________________________________________\n");
                    printf("|           |       |       |       |       |       |       |       |       |       |       |       |       |\n");
                    printf("|   Major   |   A   |  Bb   |   B   |   C   |  Db   |   D   |  Eb   |   E   |   F   |  F#   |   G   |  Ab   |\n");
                    printf("|-----------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|\n");
                    printf("|   Minor   |   Am  |  Bbm  |   Bm  |   Cm  |  C#m  |   Dm  |  D#m  |   Em  |   Fm  |  F#m  |   Gm  |  G#m  |\n");
                    printf("|___________|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|\n\n");
                    while (1)
                    { // Input Validation
                        printf("Choose a scale: ");
                        fgets(scale, sizeof(scale), stdin);
                        scale[strcspn(scale, "\n")] = 0;
                        size_t len = strlen(scale); // size_t only represents non-negative values and is commonly used for array lengths.

                        if (len > 0 && scale[len - 1] == '\n')
                        { // Removes newline character if somehow it pops up
                            scale[len - 1] = '\0';
                            len--;
                        }

                        // Check if the last character is 'm'
                        if (len > 0 && scale[len - 1] == 'm')
                        {
                            scale[len - 1] = '\0'; // Removes the 'm' and then searches it within the MinorScaleArray
                            len--;
                            if (searchScale(scale, 0))
                            {
                                if (strcmp(scale, "A") == 0)
                                {
                                    char stringArray[ARRAY_SIZE][STRING_LENGTH] = {"C ", "  ", "D ", "  ", "E ", "F ", "  ", "  ", "G#", "A ", "  ", "B ", '\0'}, print[7][3] = {"A", "B", "C", "D", "E", "F", "G#"};
                                    piano(stringArray, scale, 0, 1, 0, print);
                                }
                                else if (strcmp(scale, "Bb") == 0)
                                {
                                    char stringArray[ARRAY_SIZE][STRING_LENGTH] = {"C ", "Db", "  ", "Eb", "  ", "F ", "Gb", "  ", "  ", "A ", "Bb", "  ", '\0'}, print[7][3] = {"Bb", "C", "Db", "Eb", "F", "Gb", "A"};
                                    piano(stringArray, scale, 0, 0, 4, print);
                                }
                                else if (strcmp(scale, "B") == 0)
                                {
                                    char stringArray[ARRAY_SIZE][STRING_LENGTH] = {"  ", "C#", "D ", "  ", "E ", "  ", "F#", "G ", "  ", "  ", "A#", "B ", '\0'}, print[7][3] = {"B", "C#", "D", "E", "F#", "G", "A#"};
                                    piano(stringArray, scale, 0, 3, 0, print);
                                }
                                else if (strcmp(scale, "C") == 0)
                                {
                                    char stringArray[ARRAY_SIZE][STRING_LENGTH] = {"C ", "  ", "D ", "Eb", "  ", "F ", "  ", "G ", "Ab", "  ", "  ", "B ", '\0'}, print[7][3] = {"C", "D", "Eb", "F", "G", "Ab", "B"};
                                    piano(stringArray, scale, 0, 0, 2, print);
                                }
                                else if (strcmp(scale, "C#") == 0)
                                {
                                    char stringArray[ARRAY_SIZE][STRING_LENGTH] = {"B#", "C#", "  ", "D#", "E ", "  ", "F#", "  ", "G#", "A ", "  ", "  ", '\0'}, print[7][3] = {"C#", "D#", "E", "F#", "G#", "A", "B#"};
                                    piano(stringArray, scale, 0, 5, 0, print);
                                }
                                else if (strcmp(scale, "D") == 0)
                                {
                                    char stringArray[ARRAY_SIZE][STRING_LENGTH] = {"  ", "C#", "D ", "  ", "E ", "F ", "  ", "G ", "  ", "A ", "Bb", "  ", '\0'}, print[7][3] = {"D", "E", "F", "G", "A", "Bb", "C#"};
                                    piano(stringArray, scale, 0, 1, 1, print);
                                }
                                else if (strcmp(scale, "D#") == 0)
                                {
                                    char stringArray[ARRAY_SIZE][STRING_LENGTH] = {"  ", "  ", "C𝄪", "D#", "  ", "E#", "F#", "  ", "G#", "  ", "A#", "B ", '\0'}, print[7][3] = {"D#", "E#", "F#", "G#", "A#", "B", "Cx"};
                                    piano(stringArray, scale, 0, 6, 0, print);
                                }
                                else if (strcmp(scale, "E") == 0)
                                {
                                    char stringArray[ARRAY_SIZE][STRING_LENGTH] = {"C ", "  ", "  ", "D#", "E ", "  ", "F#", "G ", "  ", "A ", "  ", "B ", '\0'}, print[7][3] = {"E", "F#", "G", "A", "B", "C", "D#"};
                                    piano(stringArray, scale, 0, 2, 0, print);
                                }
                                else if (strcmp(scale, "F") == 0)
                                {
                                    char stringArray[ARRAY_SIZE][STRING_LENGTH] = {"C ", "Db", "  ", "  ", "E ", "F ", "  ", "G ", "Ab", "  ", "Bb", "  ", '\0'}, print[7][3] = {"F", "G", "Ab", "Bb", "C", "Db", "E"};
                                    piano(stringArray, scale, 0, 0, 3, print);
                                }
                                else if (strcmp(scale, "F#") == 0)
                                {
                                    char stringArray[ARRAY_SIZE][STRING_LENGTH] = {"  ", "C#", "D ", "  ", "  ", "E#", "F#", "  ", "G#", "  ", "A ", "B ", '\0'}, print[7][3] = {"F#", "G#", "A", "B", "C#", "D", "E#"};
                                    piano(stringArray, scale, 0, 4, 0, print);
                                }
                                else if (strcmp(scale, "G") == 0)
                                {
                                    char stringArray[ARRAY_SIZE][STRING_LENGTH] = {"C ", "  ", "D ", "Eb", "  ", "F ", "  ", "G ", "  ", "A ", "Bb", "  ", '\0'}, print[7][3] = {"G", "A", "Bb", "C", "D", "Eb", "F"};
                                    piano(stringArray, scale, 0, 1, 2, print);
                                }
                                else if (strcmp(scale, "G#") == 0)
                                {
                                    char stringArray[ARRAY_SIZE][STRING_LENGTH] = {"  ", "C#", "  ", "D#", "E ", "  ", "  ", "F𝄪", "G#", "  ", "A#", "B ", '\0'}, print[7][3] = {"G#", "A#", "B", "C#", "D#", "E", "Fx"};
                                    piano(stringArray, scale, 0, 5, 0, print);
                                }
                                break;
                            }
                            printf("Invalid input!\n");
                        }
                        else
                        {
                            if (searchScale(scale, 1)) // Searches whether it exists within the MajorScaleArray
                            {
                                if (strcmp(scale, "A") == 0)
                                {
                                    char stringArray[ARRAY_SIZE][STRING_LENGTH] = {"  ", "C#", "D ", "  ", "E ", "  ", "F#", "  ", "G#", "A ", "  ", "B ", '\0'}, print[7][3] = {"A", "B", "C#", "D", "E", "F#", "G#"};
                                    piano(stringArray, scale, 1, 3, 0, print);
                                }
                                else if (strcmp(scale, "Bb") == 0)
                                {
                                    char stringArray[ARRAY_SIZE][STRING_LENGTH] = {"C ", "  ", "D ", "Eb", "  ", "F ", "  ", "G ", "  ", "A ", "Bb", "  ", '\0'}, print[7][3] = {"Bb", "C", "D", "Eb", "F", "G", "A"};
                                    piano(stringArray, scale, 1, 0, 2, print);
                                }
                                else if (strcmp(scale, "B") == 0)
                                {
                                    char stringArray[ARRAY_SIZE][STRING_LENGTH] = {"  ", "C#", "  ", "D#", "E ", "  ", "F#", "  ", "G#", "  ", "A#", "B ", '\0'}, print[7][3] = {"B", "C#", "D#", "E", "F#", "G#", "A#"};
                                    piano(stringArray, scale, 1, 5, 0, print);
                                }
                                else if (strcmp(scale, "C") == 0)
                                {
                                    char stringArray[ARRAY_SIZE][STRING_LENGTH] = {"C ", "  ", "D ", "  ", "E ", "F ", "  ", "G ", "  ", "A ", "  ", "B ", '\0'}, print[7][3] = {"C", "D", "E", "F", "G", "A", "B"};
                                    piano(stringArray, scale, 1, 0, 0, print);
                                }
                                else if (strcmp(scale, "Db") == 0)
                                {
                                    char stringArray[ARRAY_SIZE][STRING_LENGTH] = {"C ", "Db", "  ", "Eb", "  ", "F ", "Gb", "  ", "Ab", "  ", "Bb", "  ", '\0'}, print[7][3] = {"Db", "Eb", "F", "Gb", "Ab", "Bb", "C"};
                                    piano(stringArray, scale, 1, 0, 5, print);
                                }
                                else if (strcmp(scale, "D") == 0)
                                {
                                    char stringArray[ARRAY_SIZE][STRING_LENGTH] = {"  ", "C#", "D ", "  ", "E ", "  ", "F#", "G ", "  ", "A ", "  ", "B ", '\0'}, print[7][3] = {"D", "E", "F#", "G", "A", "B", "C#"};
                                    piano(stringArray, scale, 1, 2, 0, print);
                                }
                                else if (strcmp(scale, "Eb") == 0)
                                {
                                    char stringArray[ARRAY_SIZE][STRING_LENGTH] = {"C ", "  ", "D ", "Eb", "  ", "F ", "  ", "G ", "Ab", "  ", "Bb", "  ", '\0'}, print[7][3] = {"Eb", "F", "G", "Ab", "Bb", "C", "D"};
                                    piano(stringArray, scale, 1, 0, 3, print);
                                }
                                else if (strcmp(scale, "E") == 0)
                                {
                                    char stringArray[ARRAY_SIZE][STRING_LENGTH] = {"  ", "C#", "  ", "D#", "E ", "  ", "F#", "  ", "G#", "A ", "  ", "B ", '\0'}, print[7][3] = {"E", "F#", "G#", "A", "B", "C#", "D#"};
                                    piano(stringArray, scale, 1, 4, 0, print);
                                }
                                else if (strcmp(scale, "F") == 0)
                                {
                                    char stringArray[ARRAY_SIZE][STRING_LENGTH] = {"C ", "  ", "D ", "  ", "E ", "F ", "  ", "G ", "  ", "A ", "Bb", "  ", '\0'}, print[7][3] = {"F", "G", "A", "Bb", "C", "D", "E"};
                                    piano(stringArray, scale, 1, 0, 1, print);
                                }
                                else if (strcmp(scale, "F#") == 0)
                                {
                                    char stringArray[ARRAY_SIZE][STRING_LENGTH] = {"  ", "C#", "  ", "D#", "  ", "E#", "F#", "  ", "G#", "  ", "A#", "B ", '\0'}, print[7][3] = {"F#", "G#", "A#", "B", "C#", "D#", "E#"};
                                    piano(stringArray, scale, 1, 6, 0, print);
                                }
                                else if (strcmp(scale, "G") == 0)
                                {
                                    char stringArray[ARRAY_SIZE][STRING_LENGTH] = {"C ", "  ", "D ", "  ", "E ", "  ", "F#", "G ", "  ", "A ", "  ", "B ", '\0'}, print[7][3] = {"G", "A", "B", "C", "D", "E", "F#"};
                                    piano(stringArray, scale, 1, 1, 0, print);
                                }
                                else if (strcmp(scale, "Ab") == 0)
                                {
                                    char stringArray[ARRAY_SIZE][STRING_LENGTH] = {"C ", "Db", "  ", "Eb", "  ", "F ", "  ", "G ", "Ab", "  ", "Bb", "  ", '\0'}, print[7][3] = {"Ab", "Bb", "C", "Db", "Eb", "F", "G"};
                                    piano(stringArray, scale, 1, 0, 4, print);
                                }
                                break;
                            }
                            printf("Invalid input!\n");
                        }
                    }
                }
                else if (strcmp(infoOption, "3") == 0)
                {
                }
                else
                {
                    break; // Go back to the Main Menu
                }
            }
        }
        else if (strcmp(option, "4") == 0)
        {
            // Settings
        }
        else
        {
            printf("Thanks for using my Music Transposer! See you next time :D\n");
            break; // Quit the Program
        }
    }
}
// Function Definitions

const char *flatConvert(const char *input)
{
    if (strcmp(input, "Db") == 0)
    {
        return "C#";
    }
    else if (strcmp(input, "Eb") == 0)
    {
        return "D#";
    }
    else if (strcmp(input, "Gb") == 0)
    {
        return "F#";
    }
    else if (strcmp(input, "Ab") == 0)
    {
        return "G#";
    }
    else if (strcmp(input, "Bb") == 0)
    {
        return "A#";
    }
    return input;
}

int searchNote(const char *input)
{
    int i = 0;
    input = flatConvert(input);
    while (i < ARRAY_SIZE) // Sieves through NoteArray to find the input note
    {
        if (strcmp(input, NoteArray[i]) == 0)
        {
            return 1;
        }
        i++;
    }
    return 0; // Handle error case
}

int searchScale(const char *scale, int major)
{
    int i = 0;
    if (major)
    {
        while (i < ARRAY_SIZE) // Sieves through MajorScaleArray to find the input note
        {
            if (strcmp(scale, MajorScaleArray[i]) == 0)
            {
                return 1;
            }
            i++;
        }
        return 0; // Handle error case
    }
    while (i < ARRAY_SIZE) // Sieves through MinorScaleArray to find the input note
    {
        if (strcmp(scale, MinorScaleArray[i]) == 0)
        {
            return 1;
        }
        i++;
    }
    return 0; // Handle error case
}

const char *shiftNote(const char *input, int shift)
{
    int i = 0;
    while (i < ARRAY_SIZE)
    {
        input = flatConvert(input);
        if (strcmp(input, NoteArray[i]) == 0)
        {
            return NoteArray[i + shift];
        }
        i++;
    }
    return "Error"; // Handle error case
}

int shiftFinder(const char *startScale, const char *endScale)
{
    int startIndex = -1, endIndex = -1;
    int i = 0;
    startScale = flatConvert(startScale);
    endScale = flatConvert(endScale);

    while (i < ARRAY_SIZE)
    {
        if (strcmp(startScale, NoteArray[i]) == 0)
        {
            startIndex = i;
            break;
        }
        i++;
    }

    while (i < ARRAY_SIZE)
    {
        if (strcmp(endScale, NoteArray[i]) == 0)
        {
            endIndex = i;
            break;
        }
        i++;
    }

    if (startIndex == -1 || endIndex == -1)
    {
        printf("Error: Start or end scale not found.\n"); // NOTE TO SELF: ALLOW FLAT INPUTS, THATS WHATS TRIGGERING IT
        return 0;                                         // Handle error case
    }

    return (endIndex - startIndex);
}

void fullPiano()
{
    printf(" ____________________________________________________________\n");
    printf("|     |    |   |    |     |     |    |   |    |   |    |     |\n");
    printf("|     | C# |   | D# |     |     | F# |   | G# |   | A# |     |\n");
    printf("|     | Db |   | Eb |     |     | Gb |   | Ab |   | Bb |     |\n");
    printf("|     |____|   |____|     |     |____|   |____|   |____|     |\n");
    printf("|        |        |       |        |        |        |       |\n");
    printf("|   C    |   D    |   E   |   F    |   G    |   A    |   B   |\n");
    printf("|________|________|_______|________|________|________|_______|\n\n");
}

void piano(char arr[ARRAY_SIZE][STRING_LENGTH], const char *scale, int major, int sharp, int flat, char print[7][3])
{
    if (major)
    {
        printf("The notes of %s Major are ", scale);
    }
    else
    {
        printf("The notes of %s Minor are ", scale);
    }

    int i = 0;
    while (i < 7)
    {
        printf("%s ", print[i]);
        i++;
    }

    if (sharp > 0 && flat > 0)
    {
        printf("\nIts key signature has %d sharp(s) and %d flat(s).\n", sharp, flat);
    }
    else if (sharp > 0)
    {
        printf("\nIts key signature has %d sharp(s).\n", sharp);
    }
    else if (flat > 0)
    {
        printf("\nIts key signature has %d flat(s).\n", flat);
    }
    else
    {
        printf("\nIts key signature has no sharps or flats.\n");
    }

    printf(" ____________________________________________________________\n");
    printf("|     |    |   |    |     |     |    |   |    |   |    |     |\n");
    printf("|     |    |   |    |     |     |    |   |    |   |    |     |\n");
    printf("|     | %s |   | %s |     |     | %s |   | %s |   | %s |     |\n", arr[1], arr[3], arr[6], arr[8], arr[10]);
    printf("|     |____|   |____|     |     |____|   |____|   |____|     |\n");
    printf("|        |        |       |        |        |        |       |\n");
    printf("|   %s   |   %s   |   %s  |   %s   |   %s   |   %s   |   %s  |\n", arr[0], arr[2], arr[4], arr[5], arr[7], arr[9], arr[11]);
    printf("|________|________|_______|________|________|________|_______|\n\n");
}
