#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Basic class system
#define class struct
#define def(returntype) returntype
#define method(returntype, name, ...) returntype (*name)(class Person* self, ##__VA_ARGS__)

// Constructor/destructor helpers
#define __init__(classname) classname##_new
#define __del__(classname) classname##_del

// Object lifecycle management
#define new(classname, ...) __init__(classname)(__VA_ARGS__)
#define delete(obj, classname) do { \
    if (obj) { \
        __del__(classname)(obj); \
        free(obj); \
        obj = NULL; \
    } \
} while(0)

/*
Usage Example:
-------------
// Define a class
class Person {
    char* name;
    int age;
    method(void, speak, const char* msg);
};

// Constructor
def(Person*) __init__(Person)(const char* name, int age) {
    Person* self = malloc(sizeof(Person));
    self->name = strdup(name);
    self->age = age;
    self->speak = Person_speak;
    return self;
}

// Method implementation
def(void) Person_speak(Person* self, const char* msg) {
    printf("%s says: %s\n", self->name, msg);
}

// Destructor
def(void) __del__(Person)(Person* self) {
    free(self->name);
}

// Usage
int main() {
    Person* p = new(Person, "John", 30);
    p->speak(p, "Hello!");
    delete(p, Person);
    return 0;
}
*/
