#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE 100
#define STRING_LENGTH 10

// Function Prototypes
int searchNote(const char *input);
int searchScale(const char *scale, int major);
const char *shiftNote(const char *input, int shift);
int shiftFinder(const char *startScale, const char *endScale);
void fullPiano(int defaultKeys);

// Define a 2D array of notes
char NoteArray[ARRAY_SIZE][STRING_LENGTH] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
char MajorScaleArray[ARRAY_SIZE][STRING_LENGTH] = {"C", "Db", "D", "Eb", "E", "F", "F#", "G", "Ab", "A", "Bb", "B"};
char MinorScaleArray[ARRAY_SIZE][STRING_LENGTH] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "Bb", "B"};

int main()
{
    int option;
    while (1)
    {
        printf("\n\n1) Transpose between Major Scales\n2) Transpose between Minor Scales\n3) Discover how Music Theory works!\n4) Settings\nEnter anything else to quit.\n\nSelect an option to continue: ");
        scanf("%d", &option);
        getchar(); // Consume the newline character left in the buffer by scanf

        if (option == 1 || option == 2) // Transposition
        {
            // Variables
            char input[STRING_LENGTH], inputList[ARRAY_SIZE][STRING_LENGTH] = {0}, outputList[ARRAY_SIZE][STRING_LENGTH] = {0};
            char initialScale[STRING_LENGTH] = {0}, finalScale[STRING_LENGTH] = {0};
            int shift, count = 0, i = 0;
            int major;
            char majorStr[6];

            if (option == 1)
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
        else if (option == 3) // How Music Transposition Works
        {
            while (1)
            {
                printf("1) The different keys of a piano\n2) The 24 Music Scales\n3) Music Transposition\nOr enter anything else to go back.\nYour choice: ");
                scanf("%d", &option);
                getchar(); // Consume the newline character left in the buffer by scanf
                if (option == 1)
                {
                    printf("A piano typically has 12 keys as follows:\n");
                    fullPiano(1);
                    printf("From here, it repeats the same 12 keys, with each set being in a different pitch!\nA sharp (#) refers to a key that is one semitone higher (one step to the right) of the key before it, so C# refers to the black key directly to the right of C.\nOn the other hand, a flat (b) refers to a key that is one semitone lower, like how Db can be used to refer to the same black key.\n\n");
                }
                else if (option == 2)
                {
                    printf("Select any one of the 24 scales:");
                    printf(" ___________________________________________________________________________________________________________\n");
                    printf("|           |       |       |       |       |       |       |       |       |       |       |       |       |\n");
                    printf("|   Major   |   A   |  Bb   |   B   |   C   |  Db   |   D   |  Eb   |   E   |   F   |  F#   |   G   |  Ab   |\n");
                    printf("|-----------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|\n");
                    printf("|   Minor   |   Am  |  Bbm  |   Bm  |   Cm  |  C#m  |   Dm  |  D#m  |   Em  |   Fm  |  F#m  |   Gm  |  G#m  |\n");
                    printf("|___________|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|\n");
                    while (1) { // Input Validation

                    }
                }
                else if (option == 3)
                {
                }
                else
                {
                    break; // Go back to the Main Menu
                }
            }
        }
        else if (option == 4)
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

int searchNote(const char *input)
{
    int i = 0;
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
        if (strcmp(input, NoteArray[i]) == 0)
        {
            return NoteArray[i + shift];
        }
        i++;
    }
    return " "; // Handle error case
}

int shiftFinder(const char *startScale, const char *endScale)
{
    int startIndex = -1, endIndex = -1;
    int i = 0;

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

void fullPiano(int defaultKeys)
{
    printf(" ____________________________________________________________\n");
    printf("|     |    |   |    |     |     |    |   |    |   |    |     |\n");
    if (defaultKeys)
    {
        printf("|     | C# |   | D# |     |     | F# |   | G# |   | A# |     |\n");
    } else {
        printf("|     |    |   |    |     |     |    |   |    |   |    |     |\n");
    }
    printf("|     |____|   |____|     |     |____|   |____|   |____|     |\n");
    printf("|        |        |       |        |        |        |       |\n");
    printf("|   C    |   D    |   E   |   F    |   G    |   A    |   B   |\n");
    printf("|________|________|_______|________|________|________|_______|\n\n");
}
