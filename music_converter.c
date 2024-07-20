#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE 100
#define STRING_LENGTH 10

// Function Prototypes
const char *shiftNote(const char *input, int shift);
int shiftFinder(const char *startKey, const char *endKey);

// Define a 2D array of notes
char NoteArray[ARRAY_SIZE][STRING_LENGTH] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};

int main(){
    // Variables
    char input[STRING_LENGTH], inputList[ARRAY_SIZE][STRING_LENGTH], outputList[ARRAY_SIZE][STRING_LENGTH];
    char initialKey[STRING_LENGTH], finalKey[STRING_LENGTH];
    int shift, count = 0, i = 0;

    // Get input from the user
    while (count < ARRAY_SIZE) {
        printf("Enter a note that you would like to transpose, or press q to end: ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break; //End input on EOF or error
        }

        // Remove the newline character from the input
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0) {
            break;
        }

        // Copy the input string to the array
        strcpy(inputList[count], input);
        count++;
    }
    
    printf("Enter the key that the note is in: ");
    scanf("%2s", initialKey);
    printf("Enter key you would like to transpose to: ");
    scanf("%2s", finalKey);
    
    // Process notes
    printf("You entered:\n");
    while (i < count) {
        printf("%s ", inputList[i]);
        shift = shiftFinder(initialKey, finalKey);
        strcpy(outputList[i], shiftNote(inputList[i], shift));
        i++;
    }

    i = 0; //reset i to 0
    printf("\nThe shifted notes are:\n");
    while (i < count) {
        printf("%s ", outputList[i]);
        i++;
    }

    return 0;
}

const char *shiftNote(const char *input, int shift) {
    int i = 0;
    while (i < ARRAY_SIZE) {
        if (strcmp(input, NoteArray[i]) == 0) {
            int index = (i + shift + ARRAY_SIZE) % ARRAY_SIZE; // Handle wrapping around
            return NoteArray[index];
        }
        i++;
    }
    return "Unknown"; // Handle error case
}

int shiftFinder(const char *startKey, const char *endKey) {
    int startIndex = -1, endIndex = -1;
    int i = 0;
    
    while (i < ARRAY_SIZE) {
        if (strcmp(startKey, NoteArray[i]) == 0) {
            startIndex = i;
            break;
        }
        i++;
    }
    
    i = 0; // Reset i for the second search
    while (i < ARRAY_SIZE) {
        if (strcmp(endKey, NoteArray[i]) == 0) {
            endIndex = i;
            break;
        }
        i++;
    }
    
    if (startIndex == -1 || endIndex == -1) {
        printf("Error: Start or end key not found.\n");
        return 0; // Handle error case
    }
    
    return (endIndex - startIndex + ARRAY_SIZE) % ARRAY_SIZE; // Ensure positive shift
}