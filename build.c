#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main()
{
    printf("Enter compiler path:");
    char compiler[4096];
    scanf("%s", compiler);
    printf("Building library...\n");
    char command[4096];
    sprintf(command, "%s -o obj/draw.o -c srclib/draw.c", compiler);
    system(command);
    command[0] = '\0'; // Clear the command buffer
    sprintf(command, "%s -o obj/files.o -c srclib/files.c", compiler);
    system(command);
    command[0] = '\0'; // Clear the command buffer
    sprintf(command, "%s -o obj/maths.o -c srclib/maths.c", compiler);
    system(command);
    command[0] = '\0'; // Clear the command buffer
    #ifdef _WIN32
        sprintf(command, "lib /OUT:lib/libbitlib.a obj/draw.o obj/files.o obj/maths.o");
        system(command);
    #elif __linux__ || __APPLE__
        sprintf(command, "ar rcs lib/libbitlib.a obj/*.o");
        system(command);
    #endif
}