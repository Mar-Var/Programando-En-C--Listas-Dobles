//
// Created by USUARIO on 9/12/2021.
//

#ifndef TALLERLISTASDOBLEENLACE_CLIENTHORRORHOUSE_H
#define TALLERLISTASDOBLEENLACE_CLIENTHORRORHOUSE_H
#include <string>
#include <ostream>

using namespace std;


class ClientHorrorHouse {
public:
    ClientHorrorHouse(const string &id, const string &nameClient, const string &telClient, const string &direction,
                      int age, const string &gender, const string &date);

    const string &getId() const;

    void setId(const string &id);

    const string &getNameClient() const;

    void setNameClient(const string &nameClient);

    const string &getTelClient() const;

    void setTelClient(const string &telClient);

    const string &getDirection() const;

    void setDirection(const string &direction);

    int getAge() const;

    void setAge(int age);

    const string &getGender() const;

    void setGender(const string &gender);

    const string &getDate() const;

    void setDate(const string &date);

    friend ostream &operator<<(ostream &os, const ClientHorrorHouse &house);

    virtual ~ClientHorrorHouse();

private:
    string id;
    string nameClient;
    string telClient;
    string direction;
    int age;
    string gender;
    string date;


};


#endif //TALLERLISTASDOBLEENLACE_CLIENTHORRORHOUSE_H
