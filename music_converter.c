#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE 100
#define STRING_LENGTH 10

// Function Prototypes
int searchNote(const char *input);
const char *shiftNote(const char *input, int shift);
int shiftFinder(const char *startKey, const char *endKey);

// Define a 2D array of notes
char NoteArray[ARRAY_SIZE][STRING_LENGTH] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};

int main()
{
    // Variables
    char input[STRING_LENGTH], inputList[ARRAY_SIZE][STRING_LENGTH], outputList[ARRAY_SIZE][STRING_LENGTH];
    char initialKey[STRING_LENGTH], finalKey[STRING_LENGTH];
    int shift, count = 0, i = 0;

    // Get input from the user
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

    printf("Enter the key that the note is in: ");
    scanf("%2s", initialKey);
    printf("Enter key you would like to transpose to: ");
    scanf("%2s", finalKey);

    // Process notes
    printf("You entered:\n");
    while (i < count)
    {
        printf("%s ", inputList[i]);
        shift = shiftFinder(initialKey, finalKey);
        strcpy(outputList[i], shiftNote(inputList[i], shift));
        i++;
    }

    i = 0; // reset i to 0
    printf("\nshift %d The shifted notes are:\n", shift);
    while (i < count)
    {
        printf("%s ", outputList[i]);
        i++;
    }

}

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
        printf("Error: Start or end key not found.\n");
        return 0; // Handle error case
    }

    return (endIndex - startIndex);
}