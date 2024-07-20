#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE 100 // There's no limit to the array, so I just set it to 100.
#define STRING_LENGTH 10 // Stores the maximum 2 characters of a note + the null terminator

// Function Prototypes
const char *shiftNote(const char *input, int shift);
int shiftFinder(const char *startKey, const char *endKey);

// Here, I define a 2D array of notes
char NoteArray[ARRAY_SIZE][STRING_LENGTH] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B",};

int main(){
    // Variables
    char input[STRING_LENGTH], inputList[ARRAY_SIZE][STRING_LENGTH], outputList[ARRAY_SIZE][STRING_LENGTH], initialKey[STRING_LENGTH], finalKey[STRING_LENGTH];
    int shift, count = 0, i = 0;

    // Get input from the user
    while (count < ARRAY_SIZE) {
        printf("Enter a note that you would like to transpose, or press Enter to end: ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break; // Breaks if nothing is entered
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
    

    printf("You entered:\n");
    for (int i = 0; i < count; i++) {
        printf("%s ", inputList[i]);
    }
    printf("Shifted string is: %s and shift is %d\n", shiftNote(input, shiftFinder(initialKey, finalKey)), shiftFinder(initialKey, finalKey));
}

const char *shiftNote(const char *input, int shift) {
    // Search for the input note in the array, and then returns the value "shift" positions to the right of the input note.
    int i = 0;
    while (i < ARRAY_SIZE) {
        i++;
        if (strcmp(input, NoteArray[i]) == 0) {
            return NoteArray[i + shift];
        }
    }
    return NULL;
}

int shiftFinder(const char *startKey, const char *endKey) {
    int i = 0;
    int startIndex, endIndex;
    while (i < ARRAY_SIZE) { //Increment i to check against every note
        i++;
        if (strcmp(startKey, NoteArray[i]) == 0) {
            startIndex = i;
            printf("%d", startIndex);
            break;
        }
    }
    while (i < ARRAY_SIZE) { //Continue to increment the same value of i so the shift is always positive 
        i++;
        if (strcmp(endKey, NoteArray[i]) == 0) {
            endIndex = i;
            printf("%d", endIndex);
            break;
        }
    }
    return (endIndex - startIndex);
}

