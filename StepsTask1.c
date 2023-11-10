#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here



// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);

    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }

    // Free the duplicated string
    free(inputCopy);

}

// Complete the main function
int main() {

    FILE *file = fopen("FitnessData_2023.csv", "r");
    if (file == NULL) {
        perror("open error");
        return 1;
    }

    char line[30];
    char date[11], time[6], steps[20];
    int count = 0;
    FITNESS_DATA data[2000] = {"","",0};
    while (fgets(line, sizeof(line), file) != NULL) {
        tokeniseRecord(line, ",", date, time, steps);
        strcpy(data[count].date, date);
        strcpy(data[count].time, time);
        data[count].steps = atoi(steps);

        count++;
    }

    for (int j = 0; j < 3; j++) {
        printf("%s/%s/%d\n", data[j].date, data[j].time, data[j].steps);
    }

    fclose(file);
    return 0;


}




