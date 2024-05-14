#ifndef DATA_COLUMN_H
#define DATA_COLUMN_H

#include <string>

enum Datatypes {

    BOOL,
    INT8,
    INT16,
    INT32,
    INT64,
    UINT8,
    UINT16,
    UINT32,
    UINT64,
    CHAR,
    STRING16,
    STRING32,
    STRING64,
    STRING
};

struct Column {

    // The core components of a data column
    std::string name;
    Datatypes datatype;
    void *datapointer;

    // Any extra components that describe the data column
    bool unique;
    bool primary_key;

    Column(
        const std::string &, 
        const Datatypes, 
        void *,
        bool primary_key = false
    );
};

#endif
