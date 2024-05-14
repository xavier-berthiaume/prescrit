#include "data_column.h"

Column::Column(
        const std::string &nameParam, 
        const Datatypes datatypeParam, 
        void *datapointerParam,
        bool unique,
        bool not_null,
        bool ai,
        bool pk
        ) : 
    name(nameParam),
    datatype(datatypeParam),
    datapointer(datapointerParam),
    unique(unique),
    not_null(not_null),
    auto_increment(ai),
    primary_key(pk)
{}
