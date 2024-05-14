#ifndef STORABLE_H
#define STORABLE_H

#include <string>
#include <vector>
#include <initializer_list>

#include "data_column.h"

struct Storable {

    static const std::string kIdField_;
    unsigned int id_;

    const std::string kTableName_;
    const std::vector<Column> kColumnList_;

    Storable(const std::string &, std::initializer_list<Column>);
};

#endif
