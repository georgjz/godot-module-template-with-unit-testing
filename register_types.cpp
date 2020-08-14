#include "register_types.h"
#include "core/class_db.h"
#include "summator.h"

void register_summator_types()
{
    ClassDB::register_class<Summator>();
}

void unregister_summator_types()
{
    // ain't nothing to do here.
    // just a small change for scons...
}