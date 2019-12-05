/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-12-05 16:52:46
 */
#include <vector>

class EmployeeDO
{
};

//数据库访问有关的基类
class IDBConnection
{
};
class IDBCommand
{
};
class IDBFactory
{
public:
    virtual IDBConnection *CreateDBConnection() = 0;
    virtual IDBCommand *CreateDBCommand() = 0;
};

//支持sql server 的类型
class SqlConnection : public IDBConnection
{
};
class SqlCommand : public IDBCommand
{
};

//具体工厂
class SqlDBFactory : public IDBFactory
{
public:
    virtual IDBConnection *CreateDBConnection()
    {
        return new SqlConnection;
    }
    virtual IDBCommand *CreateDBCommand()
    {
        return new SqlCommand;
    }
};

class EmployeeDAO
{
    IDBFactory *db_factory;

public:
    vector<EmployeeDO> GetEmployees()
    {
        IDBConnection *connection =
            db_factory->CreateDBConnection();
        connection->ConnectionString("...");

        IDBCommand *command =
            db_factory->CreateDBCommand();
        command->CommandText = (...);
        command->SetConnection(connection);
    }
};
