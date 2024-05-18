#ifndef MARIADB_H
#define MARIADB_H

#include <iostream>
#include <numeric>
#include <unistd.h>
#include <mariadb/conncpp.hpp>

#include "DatabaseHandler.h"

class MariadbHandler final : public AbstractDatabaseHandler {

    const std::string kDbName_;
    const std::string kHostAddress_;

    sql::Driver *dbDriver_;
    std::shared_ptr<sql::Connection> dbConn_;
    

    MariadbHandler(const std::string &, const std::string &);
    ~MariadbHandler();

    /**
     * @brief Connect the handler to
     * the database
     *
     * @return Returns a true on a good connection
     * and false on a bad connection
     */
    bool connect(const std::string &, const std::string &);

    static std::string dataTypeToString(Datatypes &);

    /**
     * @brief Fills out the data missing in the sql string
     * that was previously created, and creates a prepared
     * statement out of it.
     *
     * @param First parameter is the prepares sql string
     * with missing values having '?' in their place.
     * Second parameter is the storable object in question.
     * Third parameter is a list of which columns of the
     * storable object to access. If the vector is empty,
     * then all columns are used.
     *
     * @return A unique_ptr to the prepared statement.
     */
    std::unique_ptr<sql::PreparedStatement> prepareSqlStatement(const std::string &, Storable *, std::vector<unsigned int>);

    /**
     * @brief Takes apart the data from the result set and
     * saves it to the passed storable object.
     *
     * @param First parameter is the result set from the
     * database. Second parameter is the storable object in
     * which the response should be saved in. Third parameter
     * is a list of which columns of the storable object to
     * access. If the vector is empty, then all columns are
     * used.
     *
     * @warning There are no checks to make sure that the
     * result set will have the same columns as what the
     * storable object expects.
     */
    void bindResultToStorable(sql::ResultSet *, Storable *, std::vector<unsigned int>);
public:

    /**
     * @brief Init method for global instance (singleton implementation)
     *
     * @param First param is the database name 
     * Second param is the host address
     * Third param is the username
     * Fourth param is the password
     *
     * @return The current global instance
     */
    static MariadbHandler *init(const std::string &, const std::string &, const std::string &, const std::string &);

    /**
     * @brief Method that returns the global instance (singleton implementation)
     *
     * @warning This method does not initialize a new instance if there isn't
     * one currently initialized, since no database name or host address is
     * passed.
     *
     * @return The current global instance.
     */
    static MariadbHandler *getInstance();

    /**
     * @brief Cleanup method that gracefully deletes any MariaDB related
     * memory.
     *
     * @detailed First checks that nothing remains in any buffers, if so
     * will write it to the db before disconnecting. Then deletes the global instance
     * if it exists.
     */
    static void cleanup();

    /**
     * @brief Save to the database a storable object.
     */
    bool saveStorable(Storable *) override;

    /**
     * @brief Save to the database a storable object and bind all of its
     * fields in the database to the storable object.
     *
     * @details This is intended to allow the storable object that's passed
     * to the function to come out of the function with some of its database
     * specific fields filled out, such as its ID field, which might not be
     * known beforehand.
     */
    bool saveAndReturnStorable(Storable *) override;

    /**
     * @brief Reads from the database a single storable object and
     */
    void readStorable(Storable *, std::vector<unsigned int>) override;
    void readMultipleStorables(std::vector<Storable *>, std::vector<unsigned int>) override;
    void updateStorable(Storable *) override;
    void deleteStorable(Storable *) override;

    /**
     * @brief Concrete implementation of createTables
     *
     */
    void createTable(const std::string &, std::vector<Column>) override;
};

#endif
