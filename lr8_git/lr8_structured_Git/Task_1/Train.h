#include "Time.h"

struct Train
{
    union num
    {
        int n32;
        int n64;
    } n;

    char *type;
    Time start;
    Time arrive;

    char* place;

    int seats;
};
typedef struct Train Train;