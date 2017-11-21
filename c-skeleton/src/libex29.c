#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dbg.h"

int print_a_message(const char *msg)
{
    size_t len = strlen(msg);
    printf("A STRING: %s, len : %zu\n", msg, len);
    return 0;
}


int uppercase(const char *msg)
{
    size_t i = 0;

    size_t len = strlen(msg);
    // BUG: \0 termination problems
    for (i = 0; i < len; i++) {
        printf("%c", toupper(msg[i]));
    }
    printf("\n");
    return 0;
}

int lowercase(const char *msg)
{
    size_t i = 0;

    // BUG: \0 termination problems
    size_t len = strlen(msg);
    for (i = 0;i < len; i++) {
        printf("%c", tolower(msg[i]));
    }
    printf("\n");
    return 0;
}

int fail_on_purpose(const char *msg)
{
    return 1;
}
