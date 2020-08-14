#ifndef FACTORIAL_H
#define FACTORIAL_H

#include "core/reference.h"

class Factorial : public Reference
{
    GDCLASS( Factorial, Reference );

public:
    int fact( int n );

    Factorial();

protected:
    static void _bind_methods();
};

#endif // FACTORIAL_H