#include "include/maths.h"
#include "include/draw.h"
#include "include/files.h"
#include "include/classes.h"

// Define a Person class for demonstration
class Person {
    char* name;
    int age;
    method(void, speak, const char* msg);
};

def(void) Person_speak(class Person* self, const char* msg) {
    printf("%s says: %s\n", self->name, msg);
}

def(class Person*) __init__(Person)(const char* name, int age) {
    class Person* self = malloc(sizeof(class Person));
    self->name = strdup(name);
    self->age = age;
    self->speak = Person_speak;
    return self;
}

def(void) __del__(Person)(class Person* self) {
    free(self->name);
}

int main() {
    printf("BitLib Demonstration\n\n");

    // 1. Mathematics Demonstrations
    printf("=== Math Operations ===\n");
    Length radius = LENGTH(5);
    Area circle_area = area_circle(radius);
    printf("Circle Area: %Lf square meters\n", AREA_VAL(circle_area));
    
    // Bit operations
    byte b = charInBinary('A');
    printf("'A' in binary: %d%d%d%d%d%d%d%d\n", 
           b.b0, b.b1, b.b2, b.b3, b.b4, b.b5, b.b6, b.b7);

    // 2. Drawing Demonstrations
    printf("\n=== Drawing Demo ===\n");
    clear_screen();
    draw_box(9, 6, 10, 5, "*");
    draw_circle(24, 13, 6, "o");
    draw_line(1, 1, 30, 15, ".");
    printf("\n\n\n");
    sleep_ms(2000);  // Pause to see the drawing

    // 3. File Operations
    printf("\n=== File Operations ===\n");
    FILE* file = fopen("demo.txt", "w");
    fwriteText(file, "Hello from BitLib!");
    fclose(file);

    file = fopen("demo.txt", "r");
    char* content = fgetText(file);
    printf("File content: %s\n", content);
    free(content);

    // 4. Class System Demo
    printf("\n=== Class System Demo ===\n");
    class Person* person = new(Person, "John", 30);
    person->speak(person, "Hello from BitLib's class system!");
    delete(person, Person);

    // 5. Physics Calculations
    printf("\n=== Physics Calculations ===\n");
    Mass mass = MASS(10);
    Length dist = LENGTH(2);
    Time time = TIME(1);
    
    Acceleration acc = ACCEL(dist, time);
    Force force = FORCE(mass, acc);
    printf("Force: %Lf Newtons\n", FORCE_VAL(force));

    printf("\nDemo completed!\n");
    return 0;
}