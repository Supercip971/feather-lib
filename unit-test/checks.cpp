#include "checks.h"
#include "buffer/raw_buffer.h"
#include "buffer/temp_buffer.h"
#include "ferror.h"
#include "non_null.h"
#include "terminal/term_color.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int error_testing()
{
    return 0;
}
int ferror_checks()
{
    fth::ferror err = feather_error("test_error", 10);
    if (!err)
    { // there are no error
        return 1;
    }
    if (strcmp(err.get_info(), "test_error") != 0)
    { // should give good info
        return 2;
    }
    if (err.get_code() != 10)
    {
        return 3;
    }
    return 0;
}
int ferror_noerror_checks()
{
    fth::ferror err = feather_noerror;
    if (err)
    { // there are no error
        return 1;
    }
    if (strcmp(err.get_info(), "success") != 0)
    { // should give good info
        return 2;
    }
    return 0;
}
int fbuffer_checks()
{
    fth::raw_buffer buf;
    if (buf.create(64))
    {
        return 1;
    }
    if (buf.get_buffer_size() != 64)
    {
        return 2;
    }
    if (buf.increase(128))
    {
        return 3;
    }
    if (buf.destroy())
    {
        return 4;
    }
    return 0;
}
checks chk[] = {
    {"error_test", error_testing},
    {"ferror_test", ferror_checks},
    {"ferror_noerror_test", ferror_noerror_checks},
    {"fbuffer_test", fbuffer_checks}
};

int main(int argc, char *argv[])
{
    int unit_test_count = sizeof(chk) / sizeof(checks);
    printf("== %s feather lib unit testing (%i test) %s == \n", TERM_FG_COLOR_STR(TC_CYAN), unit_test_count, TERM_COLOR_RESET());

    int error_count = 0;
    for (int i = 0; i < unit_test_count; i++)
    {
        printf("running test %20s ...  ", chk[i].test_name);
        int result = chk[i].call();
        if (result != 0)
        {
            printf("%-20s error %i \n", TERM_FG_COLOR_STR(TC_RED), result);
            error_count++;
        }
        else
        {
            printf("%-20s success \n", TERM_FG_COLOR_STR(TC_GREEN));
        }
        printf(TERM_COLOR_RESET());
    }
    printf("== %s feather lib unit testing %s == \n", TERM_FG_COLOR_STR(TC_CYAN), TERM_COLOR_RESET());

    printf("runned %i tests (%i error)", unit_test_count, error_count);

    return error_count;
}
