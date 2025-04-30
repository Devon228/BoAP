#ifndef PLANT_H
#define PLANT_H

struct Plant
{
    char name[51];
    int num_leaves;
    int leave_area[100];
    char code_place;
    bool is_toxic;
    double length;
};

#endif // PLANT_H
