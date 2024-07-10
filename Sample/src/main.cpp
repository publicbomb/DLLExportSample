#include <stdio.h>

// #define VERSION_DECLSPEC

#ifdef VERSION_DECLSPEC
#include "DeclspecExport.h"
#else
#include "DefExport.h"
#endif

int main(int argc, char* argv[])
{
    int result = AddTest(1, 2);
    printf("AddTest(1, 2) = %d\n", result);
    return 0;
}
