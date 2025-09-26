#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#include <task3/actions.h>

bool Eq(double a,
        double b,
        double epsilon) {
    return fabs(a - b) < epsilon;
}

bool Less(double a,
          double b,
          double epsilon) {
    return b - a > epsilon;
}

bool Greater(double a,
             double b,
             double epsilon) {
    return a - b > epsilon;
}

bool LessEq(double a,
            double b,
            double epsilon) {
    return !Greater(a, b, epsilon);
}

void Swap(double *a, double *b) {
    double tmp = *a;
    *a = *b;
    *b = tmp;
}

const int32_t NO_ROOTS = 0;
const int32_t ONE_ROOT = 1;
const int32_t TWO_ROOTS = 2;
const int32_t INFINITY_ROOTS = 3;

int32_t SolveQuadraticEquation(double a,
                               double b,
                               double c,
                               double epsilon,
                               double *roots) {
    if (Eq(a, 0, epsilon)) {
        if (Eq(b, 0, epsilon)) {
            if (Eq(c, 0, epsilon)) {
                return INFINITY_ROOTS;
            }

            return NO_ROOTS;
        }

        roots[0] = -c / b;

        return ONE_ROOT;
    }

    double discriminant = b * b - 4 * a * c;

    if (Less(discriminant, 0, epsilon)) {
        return NO_ROOTS;
    } else if (Eq(discriminant, 0, epsilon)) {
        roots[0] = -b / (2 * a);

        return ONE_ROOT;
    }

    double discriminant_sqrt = sqrt(discriminant);

    roots[0] = (-b + discriminant_sqrt) / (2 * a);
    roots[1] = (-b - discriminant_sqrt) / (2 * a);

    return TWO_ROOTS;
}

int32_t SolveEquation(double a,
                      double b,
                      double c,
                      double epsilon) {
    double coefficients[3] = {a, b, c};
    double roots[2];
    uint32_t precision = ceil(-log10(epsilon));

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (j == i) {
                continue;
            }

            for (int k = 0; k < 3; ++k) {
                if (k == i
                 || k == j) {
                    continue;
                }

                int32_t roots_count = SolveQuadraticEquation(coefficients[i],
                                                             coefficients[j],
                                                             coefficients[k],
                                                             epsilon,
                                                             roots);

                printf("%fx^2 + %fx + %f = 0 ",
                       coefficients[i],
                       coefficients[j],
                       coefficients[k]);
                
                if (roots_count == NO_ROOTS) {
                    printf("haven`t roots\n");
                } else if (roots_count == ONE_ROOT) {
                    printf("have one root %.*f\n",
                           precision,
                           roots[0]);
                } else if (roots_count == TWO_ROOTS) {
                    printf("have two roots %.*f and %.*f\n",
                           precision, roots[0],
                           precision, roots[1]);
                } else if (roots_count == INFINITY_ROOTS) {
                    printf("have infinity roots\n");
                }
            }
        }
    }

    return 0;
}

int32_t CheckMultiplicity(int64_t a,
                          int64_t b) {
    if (a == 0
     || b == 0) {
        printf("[ERROR] Numbers for multiplicity check must be non-zero!\n");

        return 1;
    }

    if (a % b == 0) {
        printf("The first number is a multiple of the second\n");
    } else {
        printf("The first number isn`t a multiple of the second\n");
    }

    return 0;
}

int32_t CheckTriangle(double a,
                      double b,
                      double c,
                      double epsilon) {
    if (LessEq(a, 0, epsilon)
     || LessEq(b, 0, epsilon)
     || LessEq(c, 0, epsilon)) {
        printf("[ERROR] All triangle sides must be positive numbers!\n");

        return 1;
    }

    double sides[3] = {a, b, c};

    if (Greater(sides[0], sides[1], epsilon)) {
        if (Greater(sides[0], sides[2], epsilon)) {
            // ok, 'a' is max
        } else {
            Swap(&sides[0], &sides[2]);
        }
    } else {
        if (Greater(sides[1], sides[2], epsilon)) {
            Swap(&sides[0], &sides[1]);
        } else {
            Swap(&sides[0], &sides[2]);
        }
    }

    if (Eq(sides[0] * sides[0], sides[1] * sides[1] + sides[2] * sides[2], epsilon)) {
        printf("A triangle with the specified coefficients exists\n");
    } else {
        printf("A triangle with the specified coefficients not exists\n");
    }

    return 0;
}
