#include "storable.h"

const std::string Storable::kIdField_ = "id";

Storable::Storable(const std::string &tableName, std::initializer_list<Column> columns) : 
    id_(0),
    kTableName_(tableName),
    kColumnList_(columns) {

}
