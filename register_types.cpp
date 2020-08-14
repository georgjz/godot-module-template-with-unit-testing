#include "register_types.h"
#include "core/class_db.h"
#include "factorial.h"

void register_factorial_types()
{
    ClassDB::register_class<Factorial>();
}

void unregister_factorial_types()
{
    // ain't nothing to do here.
    // just a small change for scons...
}