#include "Mariadb.h"

MariadbHandler::MariadbHandler(const std::string &dbNameParam, const std::string &hostParam) 
    : kDbName_(dbNameParam), 
    kHostAddress_(hostParam) {

}

MariadbHandler::~MariadbHandler() {

}

MariadbHandler *MariadbHandler::init(
        const std::string &dbNameParam, 
        const std::string &hostParam,
        const std::string &userParam,
        const std::string &passParam) {

    // Run some validation on the params eventually

    if(AbstractDatabaseHandler::instance == nullptr) {
        AbstractDatabaseHandler::instance = new MariadbHandler(dbNameParam, hostParam);

        do {
            std::cout << "Attempting to connect to database at " << dynamic_cast<MariadbHandler *>(AbstractDatabaseHandler::instance)->kHostAddress_ << std::endl;
            sleep(1);
        } while (!dynamic_cast<MariadbHandler *>(AbstractDatabaseHandler::instance)->connect(userParam, passParam));
    }

    return dynamic_cast<MariadbHandler *>(AbstractDatabaseHandler::instance);
}

MariadbHandler *MariadbHandler::getInstance() {

    return dynamic_cast<MariadbHandler *>(AbstractDatabaseHandler::instance);
}

void MariadbHandler::cleanup() {

    // Insert some cleanup related logic
    // 1. Flush buffers
    // 2. Disconnection

    delete AbstractDatabaseHandler::instance;
}

bool MariadbHandler::connect(const std::string &userParam, const std::string &passParam) {

    // Here you should be running some validation on the params that were passed

    std::string urlstring = "jdbc:mariadb://";
	urlstring.append(kHostAddress_);
	urlstring.append(":3306/");
    urlstring.append(kDbName_);

	dbDriver_ = sql::mariadb::get_driver_instance();
	sql::SQLString url(urlstring);
	sql::Properties properties({
		{"user", userParam},
		{"password", passParam}
	});

	try {
		dbConn_ = std::shared_ptr<sql::Connection>(dbDriver_->connect(url, properties));
	} catch (sql::SQLSyntaxErrorException) {
		return false;
	}

    return true;
}

std::string MariadbHandler::dataTypeToString(Datatypes &datatypeParam) {

    std::string returnstring {};

    switch(datatypeParam) {
        case BOOL:
            returnstring = "BOOL";
            break;
        case INT8:
            returnstring = "TINYINT";
            break;
        case INT16:
            returnstring = "SMALLINT";
            break;
        case INT32:
            returnstring = "INT";
            break;
        case INT64:
            returnstring = "BIGINT";
            break;
        case UINT8:
            returnstring = "TINYINT UNSIGNED";
            break;
        case UINT16:
            returnstring = "SMALLINT UNSIGNED";
            break;
        case UINT32:
            returnstring = "INT UNSIGNED";
            break;
        case UINT64:
            returnstring = "BIGINT UNSIGNED";
            break;
        case CHAR:
            returnstring = "CHAR(1)";
            break;
        case STRING16:
            returnstring = "VARCHAR(16)";
            break;
        case STRING32:
            returnstring = "VARCHAR(32)";
            break;
        case STRING64:
            returnstring = "VARCHAR(64)";
            break;
        default:
            returnstring = "";
            break;
    }

    return returnstring;
}
    
std::unique_ptr<sql::PreparedStatement> MariadbHandler::prepareSqlStatement(const std::string &preparedQuery, Storable *storableParam, std::vector<int> columnList = {}) {

    std::unique_ptr<sql::PreparedStatement> query_statement(dbConn_->prepareStatement(preparedQuery));
    std::string placeholder_string {};

    for(int col : columnList) {
        Column datacolumn = storableParam->kColumnList_[col];

        try {
            switch(datacolumn.datatype) {
                case BOOL:
                    query_statement->setBoolean(col+1, *static_cast<bool *>(datacolumn.datapointer));
                    break;
                case INT8:
                    query_statement->setInt(col+1, *static_cast<int8_t *>(datacolumn.datapointer));
                    break;
                case INT16:
                    query_statement->setInt(col+1, *static_cast<int16_t *>(datacolumn.datapointer));
                    break;
                case INT32:
                    query_statement->setInt(col+1, *static_cast<int32_t *>(datacolumn.datapointer));
                    break;
                case INT64:
                    query_statement->setInt64(col+1, *static_cast<int64_t *>(datacolumn.datapointer));
                    break;
                case UINT8:
                    query_statement->setUInt(col+1, *static_cast<uint8_t *>(datacolumn.datapointer));
                    break;
                case UINT16:
                    query_statement->setUInt(col+1, *static_cast<uint16_t *>(datacolumn.datapointer));
                    break;
                case UINT32:
                    query_statement->setUInt(col+1, *static_cast<uint32_t *>(datacolumn.datapointer));
                    break;
                case UINT64:
                    query_statement->setUInt64(col+1, *static_cast<uint64_t *>(datacolumn.datapointer));
                    break;
                case CHAR:
                    placeholder_string = std::string(1, *static_cast<char *>(datacolumn.datapointer));
                    query_statement->setString(col+1, placeholder_string);
                    break;
                case STRING16:
                    query_statement->setString(col+1, *static_cast<std::string *>(datacolumn.datapointer));
                    break;
                case STRING32:
                    query_statement->setString(col+1, *static_cast<std::string *>(datacolumn.datapointer));
                    break;
                case STRING64:
                    query_statement->setString(col+1, *static_cast<std::string *>(datacolumn.datapointer));
                    break;
                default:
                    std::cout << "Unknown datatype" << std::endl;
                    throw(sql::SQLException());
            }
        } catch (sql::SQLException e) {
            std::cout << "Error when preparing the SQL statement for storable object in table " << storableParam->kTableName_ << std::endl;
        }
    }

    return std::move(query_statement);
}

void MariadbHandler::bindResultToStorable(sql::ResultSet *res, Storable *storableParam, std::vector<int> columnList = {}) {

    for(int col : columnList) {
        Column datacolumn = storableParam->kColumnList_[col];

        try {
            switch(datacolumn.datatype) {
                case BOOL:
                    *static_cast<bool *>(datacolumn.datapointer) = res->getBoolean(col);
                    break;
                case INT8:
                    *static_cast<int8_t *>(datacolumn.datapointer) = res->getInt(col);
                    break;
                case INT16:
                    *static_cast<int16_t *>(datacolumn.datapointer) = res->getInt(col);
                    break;
                case INT32:
                    *static_cast<int32_t *>(datacolumn.datapointer) = res->getInt(col);
                    break;
                case INT64:
                    *static_cast<int64_t *>(datacolumn.datapointer) = res->getInt64(col);
                    break;
                case UINT8:
                    *static_cast<uint8_t *>(datacolumn.datapointer) = res->getUInt(col);
                    break;
                case UINT16:
                    *static_cast<uint16_t *>(datacolumn.datapointer) = res->getUInt(col);
                    break;
                case UINT32:
                    *static_cast<uint32_t *>(datacolumn.datapointer) = res->getUInt(col);
                    break;
                case UINT64:
                    *static_cast<uint64_t *>(datacolumn.datapointer) = res->getUInt64(col);
                    break;
                case CHAR:
                    *static_cast<char *>(datacolumn.datapointer) = res->getString(col)[0];
                    break;
                case STRING16:
                    *static_cast<std::string *>(datacolumn.datapointer) = res->getString(col);
                    break;
                case STRING32:
                    *static_cast<std::string *>(datacolumn.datapointer) = res->getString(col);
                    break;
                case STRING64:
                    *static_cast<std::string *>(datacolumn.datapointer) = res->getString(col);
                    break;
                default:
                    std::cout << "Unknown datatype" << std::endl;
                    throw(sql::SQLException());
            }
        } catch (sql::SQLException e) {
            std::cout << "Error when preparing the SQL statement for storable object in table " << storableParam->kTableName_ << std::endl;
        }
        
    }
}

bool MariadbHandler::saveStorable(Storable *storableParam) {

    std::string sqlquery = "INSERT INTO " + storableParam->kTableName_ + " (";

    // It might be better to start at i = 1, since element 0 of kColumnList will always be the ID column
    // and we don't want to be manually entering the id for the database entry.
    int firstColumn = 0;

    for(int i = firstColumn; i < storableParam->kColumnList_.size(); i++) {
        Column datacolumn = storableParam->kColumnList_[i];

        sqlquery.append(datacolumn.name);

        if(i != storableParam->kColumnList_.size()-1) {
            sqlquery.append(",");
        }
    }

    sqlquery.append(") VALUES (");

    for(int i = firstColumn; i < storableParam->kColumnList_.size(); i++) {
        sqlquery.append("?");

        if(i != storableParam->kColumnList_.size()-1) {
            sqlquery.append(",");
        } else {
            sqlquery.append(")");
        }
    }

    std::vector<int> columnList(storableParam->kColumnList_.size() - firstColumn);
    std::iota(columnList.begin(), columnList.end(), firstColumn);
    std::unique_ptr<sql::PreparedStatement> query = MariadbHandler::prepareSqlStatement(sqlquery, storableParam, columnList);

    try {
        sql::ResultSet *res = query->executeQuery();
    } catch(sql::SQLException e) {
        std::cout << e.what() << std::endl;
        return false;
        // Just print the exception and move on, don't touch the storable object
    }

    return true;
}

bool MariadbHandler::saveAndReturnStorable(Storable *storableParam) {

    std::string sqlquery = "INSERT INTO " + storableParam->kTableName_ + " (";

    // It might be better to start at i = 1, since element 0 of kColumnList will always be the ID column
    // and we don't want to be manually entering the id for the database entry.
    int firstColumn = 0;

    for(int i = firstColumn; i < storableParam->kColumnList_.size(); i++) {
        Column datacolumn = storableParam->kColumnList_[i];

        sqlquery.append(datacolumn.name);

        if(i != storableParam->kColumnList_.size()-1) {
            sqlquery.append(",");
        }
    }

    sqlquery.append(") VALUES (");

    for(int i = firstColumn; i < storableParam->kColumnList_.size(); i++) {
        sqlquery.append("?");

        if(i != storableParam->kColumnList_.size()-1) {
            sqlquery.append(",");
        } else {
            sqlquery.append(") RETURNING (");
        }
    }

    for(int i = firstColumn; i < storableParam->kColumnList_.size(); i++) {
        Column datacolumn = storableParam->kColumnList_[i];

        sqlquery.append(datacolumn.name);
        
        if(i != storableParam->kColumnList_.size()-1) {
            sqlquery.append(",");
        } else {
            sqlquery.append(") RETURNING (");
        }
    }

    std::vector<int> columnList(storableParam->kColumnList_.size() - firstColumn);
    std::iota(columnList.begin(), columnList.end(), firstColumn);
    std::unique_ptr<sql::PreparedStatement> query = MariadbHandler::prepareSqlStatement(sqlquery, storableParam, columnList);

    try {
        sql::ResultSet *res = query->executeQuery();
        while(res->next()) {
            bindResultToStorable(res, storableParam, columnList);
        }
    } catch(sql::SQLException e) {
        std::cout << e.what() << std::endl;
        // Just print the exception and move on, don't touch the storable object
        return false;
    }

    return true;
}

void MariadbHandler::readStorable(Storable *storableParam) {
        
    std::string sqlquery = "SELECT * FROM " + storableParam->kTableName_ + " WHERE ";
    
    int firstColumn = 1;

    for(int i = firstColumn; i < storableParam->kColumnList_.size(); i++) {
        Column datacolumn = storableParam->kColumnList_[i];

        sqlquery.append(datacolumn.name);

        if(i != storableParam->kColumnList_.size()-1) {
            sqlquery.append(",");
        }
    }

    // Read into the storable object the data that's retrieved from the database
    // In case you get multiple objects, not sure what to do yet
    try {

    } catch(sql::SQLException e) {
        std::cout << e.what() << std::endl;
        // Just print the exception and move on, don't touch the storable object
    }
}

void MariadbHandler::updateStorable(Storable *) {

    // Here you assume that all fields of the storable object are already filled out
    try {

    } catch(sql::SQLException e) {

    }
}

void MariadbHandler::deleteStorable(Storable *) {

    try {

    } catch(sql::SQLException e) {

    }
}

void MariadbHandler::createTable(const std::string &tableName, std::vector<Column> objectColumnList) {

    std::string tableCreationQuery = "CREATE TABLE IF NOT EXISTS " + tableName + "(";

    for(int i = 0; i < objectColumnList.size(); i++) {
        Column datacolumn = objectColumnList[i];
        tableCreationQuery.append(datacolumn.name);
        tableCreationQuery.append(" " + MariadbHandler::dataTypeToString(datacolumn.datatype));

        if(datacolumn.not_null)
            tableCreationQuery.append(" NOT NULL");

        if(datacolumn.unique)
            tableCreationQuery.append(" UNIQUE");

        if(datacolumn.auto_increment)
            tableCreationQuery.append(" AUTO_INCREMENT");

        if(datacolumn.primary_key)
            tableCreationQuery.append(" PRIMARY KEY");

        if(i != objectColumnList.size()-1)
            tableCreationQuery.append(",");
    }

    tableCreationQuery.append(")");

    std::unique_ptr<sql::Statement> query(dbConn_->createStatement());
    query->executeQuery(tableCreationQuery);
}
