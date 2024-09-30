#include "push_swap.h"

t_cost cost_for_biggest(int biggest, int *size_b)
{
    t_cost info;

    if (biggest <= *size_b / 2)
    {
        info.cost = biggest;
        info.operation = 'u';
    }
    else
    {
        info.cost = *size_b - biggest;
        info.operation = 'd';
    }
    return (info);
}

t_cost cost_for_closest(int closer_index, int *size_b)
{
    t_cost info;

    if (closer_index <= *size_b / 2)
    {
        info.cost = closer_index;
        info.operation = 'u';
    }
    else
    {
        info.cost = *size_b - closer_index;
        info.operation = 'd';
    }
    return (info);
}

int cheapest_one(int index_a, int total_cost, int *cost, int cheapest)
{
    if (*cost > total_cost)
    {
        *cost = total_cost;
        cheapest = index_a;
    }
    return (cheapest);
}
