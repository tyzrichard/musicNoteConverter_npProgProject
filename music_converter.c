#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE 100
#define STRING_LENGTH 10

// Function Prototypes
int searchNote(const char *input);
int searchKey(const char *key, int major);
const char *shiftNote(const char *input, int shift);
int shiftFinder(const char *startKey, const char *endKey);

// Define a 2D array of notes
char NoteArray[ARRAY_SIZE][STRING_LENGTH] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
char MajorKeyArray[ARRAY_SIZE][STRING_LENGTH] = {"C", "G", "D", "A", "E", "B", "F#", "Gb", "C#", "Db", "Ab", "Eb", "Bb", "F"};
char MinorKeyArray[ARRAY_SIZE][STRING_LENGTH] = {"A", "E", "B", "F#", "Gb", "C#", "Db", "G#", "D#", "Eb", "A#", "Bb", "F", "C", "G", "D"};

int main()
{
    int option;
    while (1)
    {
        printf("\n\nSelect an option to continue: \n1) Transpose Major Key to Major Key\n2) Transpose Minor Key to Minor Key\n3) Discover how Music Transposition works!\n4) Settings\nEnter anything else to quit.\n\nYour choice: ");
        scanf("%d", &option);
        getchar(); // Consume the newline character left in the buffer by scanf

        if (option == 1 || option == 2)
        {
            // Variables
            char input[STRING_LENGTH], inputList[ARRAY_SIZE][STRING_LENGTH] = {0}, outputList[ARRAY_SIZE][STRING_LENGTH] = {0};
            char initialKey[STRING_LENGTH] = {0}, finalKey[STRING_LENGTH] = {0};
            int shift, count = 0, i = 0;
            int major;
            char majorStr[6];

            if (option == 1)
            { // Give basic information on the Major/Minor keys, based on what the user chose
                printf("The 12 Major Keys are: C, C#/Db, D, Eb, E, F, F#/Gb, G, Ab, A, Bb and B.\n");
                major = 1;
                strcpy(majorStr, "Major");
            }
            else
            {
                printf("The 12 Minor Keys are: C, C#/Db, D, D#/Eb, E, F, F#/Gb, G, G#, A, A#/Bb and B.\n");
                major = 0;
                strcpy(majorStr, "Minor");
            }

            // Get input from the user: initialKey, finalKey and an array of notes
            while (1)
            {
                printf("Enter the key that you would like to transpose from: ");
                scanf("%s", initialKey);
                getchar(); // Consume the newline character left in the buffer by scanf
                if (searchKey(initialKey, major)) // to search through Major/Minor KeyArray
                {
                    break;
                }
                printf("Invalid input! Please enter a valid key %s.\n", initialKey);
            }
            while (1)
            {
                printf("Enter the key you would like to transpose to: ");
                scanf("%s", finalKey);
                getchar(); // Consume the newline character left in the buffer by scanf
                if (searchKey(finalKey, major)) // to search through Major/Minor KeyArray
                {
                    break;
                }
                printf("Invalid input! Please enter a valid key.\n");
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
            printf("You entered %d notes in %s %s:\n", count, initialKey, majorStr);
            shift = shiftFinder(initialKey, finalKey);
            while (i < count)
            {
                printf("%s ", inputList[i]);
                strcpy(outputList[i], shiftNote(inputList[i], shift));
                i++;
            }

            i = 0; // reset i to 0
            printf("\nAfter being shifted to %s %s, the notes are:\n", finalKey, majorStr);
            while (i < count)
            {
                printf("%s ", outputList[i]);
                i++;
            }
            printf("\n");
        }
        else if (option == 3)
        {
            // How Music Transposition Works
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

int searchKey(const char *key, int major)
{
    int i = 0;
    if (major)
    {
        while (i < ARRAY_SIZE) // Sieves through MajorKeyArray to find the input note
        {
            if (strcmp(key, MajorKeyArray[i]) == 0)
            {
                return 1;
            }
            i++;
        }
        return 0; // Handle error case
    }
    while (i < ARRAY_SIZE) // Sieves through MinorKeyArray to find the input note
    {
        if (strcmp(key, MinorKeyArray[i]) == 0)
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

int shiftFinder(const char *startKey, const char *endKey)
{
    int startIndex = -1, endIndex = -1;
    int i = 0;

    while (i < ARRAY_SIZE)
    {
        if (strcmp(startKey, NoteArray[i]) == 0)
        {
            startIndex = i;
            break;
        }
        i++;
    }

    while (i < ARRAY_SIZE)
    {
        if (strcmp(endKey, NoteArray[i]) == 0)
        {
            endIndex = i;
            break;
        }
        i++;
    }

    if (startIndex == -1 || endIndex == -1)
    {
        printf("Error: Start or end key not found.\n"); //NOTE TO SELF: ALLOW FLAT INPUTS, THATS WHATS TRIGGERING IT
        return 0; // Handle error case
    }

    return (endIndex - startIndex);
}
