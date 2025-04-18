#include <stdio.h>
#include <stdlib.h>

// Macros for file modes
#define R   "r"
#define W   "w"
#define A   "a"

#define RP  "r+"
#define WP  "w+"
#define AP  "a+"

#define RB  "rb"
#define WB  "wb"
#define AB  "ab"

#define RBP "rb+"
#define WBP "wb+"
#define ABP "ab+"

/// @brief Reads file contents into a string.
/// @param file The file pointer to read from.
/// @return The contents of the file as a string, or NULL if the file is not opened.
char* fgetText(FILE* file){// Originally from: Headers.h(2023)     Reads file contents into a string.
    if (!file) return NULL;

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);

    char *content = malloc(size + 1);
    if (!content) {
        fclose(file);
        return NULL;
    }

    fread(content, 1, size, file);
    content[size] = '\0';

    fclose(file);
    return content;
}

/// @brief Writes a string to a file.
/// @param file The file pointer to write to.
/// @param text The text to write.
/// @return 0 if successful, 1 if the file pointer is NULL.
int fwriteText(FILE* file, char* text){// Originally from: Headers.h(2023)     Writes a string to a file.
    if(file != NULL){
        fprintf(file, "%s", text);
        return 0;
    }
    return 1;
}

/// @brief Checks if a file exists.
/// @param path The file path to check.
/// @return 1 if the file exists, 0 otherwise.
/// @note This function uses fopen to check for file existence.
int fexists(const char* path){// Checks if a file exists.
    FILE* file = fopen(path, "r");
    if (file) {
        fclose(file);
        return 1; // File exists
    }
    return 0; // File does not exist
}

/// @brief Deletes a file.
/// @param path The path to the file to delete.
/// @note This function uses remove to delete the file.
/// @return 1 if the file is deleted successfully, 0 otherwise.
/// @note This function does not check if the file exists before attempting to delete it.
int fdelete(const char* path){// Deletes a file.
    if (remove(path) == 0) {
        return 1; // File deleted successfully
    } else {
        return 0; // File deletion failed
    }
}