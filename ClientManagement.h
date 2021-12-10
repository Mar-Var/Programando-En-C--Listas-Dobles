//
// Created by USUARIO on 9/12/2021.
//

#ifndef TALLERLISTASDOBLEENLACE_CLIENTMANAGEMENT_H
#define TALLERLISTASDOBLEENLACE_CLIENTMANAGEMENT_H


#include "ClientHorrorHouse.h"
#include "LinkedDouble.cpp"

class ClientManagement {
public:
    ClientManagement();
    bool validateFields(string,string,string,string,int,string,string);

    bool addFirstPlace( ClientHorrorHouse );

    bool addLastPlace( ClientHorrorHouse );

    NodeDouble<ClientHorrorHouse>* findClientPoint( string );

    ClientHorrorHouse* findInfoClient( int );

    bool addClientBeforeTo( string, ClientHorrorHouse);

    bool addNodeClientAfterTo( string, ClientHorrorHouse);

    std::vector<ClientHorrorHouse> getList(bool);

    int getSizeRow();

    bool deleteClientbyBad(string);

    bool deleteClientSimply(string);

    std::vector<ClientHorrorHouse> getTotalList(bool);

    bool addToBlackList(ClientHorrorHouse info);

    std::vector<ClientHorrorHouse> getBlackList(bool);

    string getTime();

    bool existInAnyList(string);

    const string &getWaringMessage() const;

    bool isNumber (string);
    bool isNotNumber(string);

    void setWaringMessage(const string &waringMessage);

    virtual ~ClientManagement();

private:
    LinkedDouble<ClientHorrorHouse>* currentList;
    LinkedDouble<ClientHorrorHouse>* blackList;
    LinkedDouble<ClientHorrorHouse>* totalList;
    string waringMessage;
};


#endif //TALLERLISTASDOBLEENLACE_CLIENTMANAGEMENT_H
