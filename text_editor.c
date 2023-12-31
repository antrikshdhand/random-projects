/**
 * @file text_editor.c
 * @author Antriksh Dhand (base code from Nir Lichtman)
 * @brief An improved version of Nir Lichtman's "Minimal Text Editor in C".
 * @date 2023-12-28
 * 
 * Future improvements:
 *   - Dynamically allocate memory based on the input file size.
 *   - Use fgets() instead of scanf(). 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

#define MAX_BUF 1024

FILE* open_file(const char* filename, const char* mode) {
    FILE* file = fopen(filename, mode);
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    return file;
}

void get_replacement_line(char* buffer) {
    printf("Please enter replacement string: ");

    fflush(stdin);
    fgets(buffer, MAX_BUF, stdin); 

    size_t newline_pos = strcspn(buffer, "\n");
    if (newline_pos < MAX_BUF) {
        buffer[newline_pos] = '\0';
    }
}

size_t count_total_lines(char* buffer) {
    size_t lines = 0;
    const char* ptr = buffer;

    while (*ptr != '\0') {
        if (*ptr == '\n') {
            lines++;
        }
        ptr++;
    }

    return lines;
}

void edit_line(char* buffer, int current_line) {
    if (current_line <= 0 || current_line > count_total_lines(buffer)) {
        printf("Invalid line number. Please enter a valid line number.\n");
        return;
    }

    // By the end of the loop, `buffer` points to the first character
    // of `current_line`.
    for (int i = 1; i < current_line; i++) {
        buffer = strchr(buffer, '\n') + 1;
    }
    
    // `line_end` points to the end of the line we want to edit.
    char* line_end = strchr(buffer, '\n');

    // Store the rest of the file in a separate buffer. Note here that strcpy()
    // copies from `line_end` till the first null \0 character it finds,
    // which in a text file is EOF.
    char rest_of_file[MAX_BUF] = { 0 };
    strcpy(rest_of_file, line_end);
    
    // Request replacement line from user and replace the entire rest
    // of the file with it.
    get_replacement_line(buffer);

    // At this point, buffer consists of all the lines before current_line
    // and then the user-input.

    // Append the saved rest-of-file.
    strcpy(buffer + strlen(buffer), rest_of_file);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: ./text-editor file_to_edit.txt\n");
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_BUF] = {0};

    // Open and read the entire file into buffer.
    FILE* f = open_file(argv[1], "r");
    fread(buffer, MAX_BUF, 1, f);
    fclose(f);

    printf("\n---------- CONTENTS -----------\n");
    printf("%s\n", buffer);
    printf("--------------------------------\n\n");

    // Ask the user for a line to edit.
    printf("Please enter the line you wish to edit: ");
    int current_line = 0;
    if (scanf("%d", &current_line) != 1) {
        // Input was not a valid integer
        printf("Invalid input. Please enter a valid line number.\n");
        exit(EXIT_FAILURE);
    }

    edit_line(buffer, current_line);

    // Write the changed buffer to file.
    f = openFile(argv[1], "w");
    if (fwrite(buffer, strlen(buffer), 1, f) != 1) {
        perror("Error writing to file");
        fclose(f);
        exit(EXIT_FAILURE);
    }
    fclose(f);

    // On success, print out changes.
    printf("\n---------- CONTENTS AFTER EDIT -----------\n");
    printf("%s\n", buffer);
    printf("------------------------------------------\n\n");

    return 0;
}