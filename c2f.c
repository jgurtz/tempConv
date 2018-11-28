#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <errno.h>
#include <string.h>

void usage();
double parseDouble(char*);
double c2f(double);
double f2c(double);

int main(int argc, char** argv) {

    if (argc < 2) {
        usage();
    }
    else {
        double temp = parseDouble( argv[1] );
        char *cmd = argv[0] + (strlen( argv[0] ) - 3); //ptr to last 3 chars of argv[0]
        //printf("Cmd: %s\n", cmd);

        if ( strcmp("c2f", cmd) >= 0 ) {
            printf("%'.3f\n", c2f(temp));
        }
        else if ( strcmp("f2c", cmd) >= 0 ) {
            printf("%'.3f\n", f2c(temp));
        }
        else {
            printf("Something happened: %s\n\na", argv[0]);
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}

void usage() {
    printf("c2f, f2c - Temperature scale converter\n\n");
    printf("Usage:\n\n");
    printf("\tc2f <temp in C>\n");
    printf("\tf2c <temp in F>\n\n");

    exit(EXIT_FAILURE);
}

double parseDouble(char* temp) {
    /* Based largely on example in man strtol, but silently drop any extra non-digit chars */
    char *endptr;
    double theDouble;
    errno = 0;    /* To distinguish success/failure after call */
    theDouble = strtod(temp, &endptr);

    /* Check for various possible errors */
    if ( (errno == ERANGE && (theDouble == DBL_MAX || theDouble == DBL_MIN)) || (errno != 0 && theDouble == 0) ) {
        perror("strtod");
        exit(EXIT_FAILURE);
    }

    if (endptr == temp) {
        fprintf(stderr, "No digits were found\n");
        exit(EXIT_FAILURE);
    }

    return theDouble;
}

double c2f(double temp) {
    /* (2°C × 9/5) + 32 = 35.6°F */
    return ( temp * (9.0 / 5.0) ) + 32;
}

double f2c(double temp) {
    /* (2°F − 32) × 5/9 = -16.67°C */
    return (temp - 32) * (5.0 / 9.0);
}
