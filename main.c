#include "include/maths.h"
#include "include/draw.h"
#include "include/files.h"

int main(){
    // Example usage of the functions
    Length radius = LENGTH(5);
    Area area = area_circle(radius);
    printf("Area of circle: %Lf\n", AREA_VAL(area));

    Length length = LENGTH(10);
    Length breadth = LENGTH(5);
    Area rectangle = AREA(length, breadth);
    printf("Area of rectangle: %Lf\n", AREA_VAL(rectangle));

    // Example usage of file functions
    FILE* file = fopen("example.txt", "w");
    fwriteText(file, "Hello, World!");
    fclose(file);
    file = fopen("example.txt", "r");
    char* content = fgetText(file);
    printf("File content: %s\n", content);
    
    free(content);

    return 0;
}