#pragma once

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef long double ld;

#define PI 3.14159265358979323846

#define square(x) ((x) * (x))
#define cube(x) ((x) * (x) * (x))

#define second 1
#define minute 60
#define hour 3600
#define day 86400
#define week 604800
#define month 2592000
#define year 31536000

typedef struct { long double length; } Length;           // meters
typedef struct { long double time; } Time;               // seconds
typedef struct { long double mass; } Mass;               // kilograms
typedef struct { long double temp; } Temperature;        // kelvin
typedef struct { long double current; } Current;         // amperes
typedef struct { long double substance; } Amount;        // moles
typedef struct { long double luminous; } Light;          // candelas
typedef struct { Length length; Length breadth; } Area;                       // m²
typedef struct { Length length; Length breadth; Length height; } Volume; // m³
typedef struct { Length length; Time time; } Speed;                                     // m/s
typedef struct { Length length; Time time; Time time2; } Acceleration;                  // m/s²
typedef struct { Mass mass; Acceleration acceleration; } Force;                         // newtons (kg·m/s²)
typedef struct { Force force; Length displacement; } Work;                              // joules (N·m)
typedef struct { Work work; Time time; } Power;                                         // watts (J/s)

#define LENGTH(m)         ((Length){ .length = (m) })
#define TIME(s)           ((Time){ .time = (s) })
#define MASS(kg)          ((Mass){ .mass = (kg) })
#define TEMP(k)           ((Temperature){ .temp = (k) })
#define CURRENT(a)        ((Current){ .current = (a) })
#define AMOUNT(mol)       ((Amount){ .substance = (mol) })
#define LIGHT(cd)         ((Light){ .luminous = (cd) })
// --- Area: Length × Breadth ---
#define AREA(l, b)        ((Area){ .length = (l), .breadth = (b) })
#define AREA_VAL(a)       (LENGTH_VAL((a).length) * LENGTH_VAL((a).breadth))

// --- Volume: Length × Breadth × Height ---
#define VOLUME(l, b, h)   ((Volume){ .length = (l), .breadth = (b), .height = (h) })
#define VOLUME_VAL(v)     (LENGTH_VAL((v).length) * LENGTH_VAL((v).breadth) * LENGTH_VAL((v).height))

// --- Speed: Length / Time ---
#define SPEED(d, t)       ((Speed){ .length = (d), .time = (t) })
#define SPEED_VAL(s)      (LENGTH_VAL((s).length) / TIME_VAL((s).time))

// --- Acceleration: Length / Time² ---
#define ACCEL(l, t)       ((Acceleration){ .length = (l), .time = (t), .time2 = (t) })
#define ACCEL_VAL(a)      (LENGTH_VAL((a).length) / (TIME_VAL((a).time2) * TIME_VAL((a).time2)))

// --- Force: Mass × Acceleration ---
#define FORCE(m, a)       ((Force){ .mass = (m), .acceleration = (a) })
#define FORCE_VAL(f)      (MASS_VAL((f).mass) * ACCEL_VAL((f).acceleration))

// --- Work: Force × Displacement ---
#define WORK(f, d)        ((Work){ .force = (f), .displacement = (d) })
#define WORK_VAL(w)       (FORCE_VAL((w).force) * LENGTH_VAL((w).displacement))

// --- Power: Work / Time ---
#define POWER(w, t)       ((Power){ .work = (w), .time = (t) })
#define POWER_VAL(p)      (WORK_VAL((p).work) / TIME_VAL((p).time))

#define LENGTH_VAL(l)     ((l).length)
#define TIME_VAL(t)       ((t).time)
#define MASS_VAL(m)       ((m).mass)
#define TEMP_VAL(t)       ((t).temp)
#define CURRENT_VAL(c)    ((c).current)
#define AMOUNT_VAL(a)     ((a).substance)
#define LIGHT_VAL(l)      ((l).luminous)


#define meter 1
#define foot 0.3048
#define inch 0.0254
#define mile 1609.34
#define lightyear 9460730472580800
#define lightsecond 299792458
#define lightminute 179875472580800
#define lighthour 1079252848819000
#define lightday 8640000000000000
#define lightweek 60480000000000000
#define lightmonth 259200000000000000

#define kilo 1000 *
#define mega 1000000 *
#define centi (1/100) *
#define milli (1/1000) *
#define micro (1/1000000) *

/// @brief Calculates the power of a number.
/// @param base The base of the exponentiation.
/// @param exp The exponent.
/// @return The result of base raised to the power of exp.
/// @note This function handles negative exponents by returning the reciprocal of the positive exponent.
/// @note This function handles the case of 0^0 by returning 1, as it is often treated as such in programming.
long double power(long base, long exp) { // Originally from: Headers.h(2023)     Calculates the power of a number.
    if (base == 0 && exp == 0) return 1; // 0^0 is undefined, but often treated as 1 in programming
    if (exp == 0) return 1;
    if (exp < 0){
        exp = abs(exp);
        long double result = 1;
        for (long i = 0; i < exp; i++) {
        result *= base;
        }
        result = 1 / result;
        return result;
    }
    long double result = 1;
    for (long i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

/// @brief Calculates the factorial of a number.
/// @param n The number to calculate the factorial of.
/// @return The factorial of n, or 0 if n is negative or too large.
unsigned long long factorial(long n){ // Originally from: Headers.h(2023)     Calculates the factorial of a number.
    // Factorial is not defined for negative numbers
    if (n < 0) return 0;
    if (n == 0 || n == 1) return 1;
    long long result = 1;
    for (long i = 2; i <= n; i++) {
        if (result > ULLONG_MAX / i) return 0; // overflow
        result *= i;
    }

    return result;
}

/// @brief Calculates the circumference of a circle.
/// @param radius The radius of the circle.
/// @return The circumference of the circle.
/// @note The formula for circumference is 2 * PI * radius.
/// @note This function uses the constant PI defined in the header file.
/// @note This function returns a Length structure to handle values of length.
Length circumference(Length radius){// Calculates the circumference of a circle.
    if (radius.length < 0) return (Length){0}; // Circumference is not defined for negative radius
    if (radius.length == 0) return (Length){0}; // Circumference is 0 for radius 0
    if (radius.length > INT_MAX / 2) return (Length){0}; // overflow
    Length result; result.length = 2 * PI * radius.length; 
    return result; // Circumference = 2 * PI * radius
}

/// @brief Calculates the area of a circle.
/// @param radius The radius of the circle.
/// @return An Area structure representing the area of the circle.
Area area_circle(Length radius){// Calculates the area of a circle.
    if (radius.length < 0) return (Area){0, 0}; // Area is not defined for negative radius
    if (radius.length == 0) return (Area){0, 0}; // Area is 0 for radius 0
    if (radius.length > INT_MAX / PI) return (Area){0, 0}; // overflow
    Area result; result.length.length = sqrt( PI * square(radius.length)); result.breadth.length = sqrt( PI * square(radius.length)); 
    return result; // Area = PI * radius^2
}