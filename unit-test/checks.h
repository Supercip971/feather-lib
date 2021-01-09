#ifndef CHECKS_H
#define CHECKS_H

#define CHECKS_COUNT 1
struct checks
{
    const char *test_name;
    int (*call)();
};

#endif // CHECKS_H
