//
// Created by USUARIO on 9/12/2021.
//

#include "ClientHorrorHouse.h"

ClientHorrorHouse::ClientHorrorHouse(const string &ids, const string &nameClient, const string &telClient,
                                     const string &direction, int age, const string &gender, const string &date)
        : id(ids), nameClient(nameClient), telClient(telClient), direction(direction), age(age), gender(gender),
          date(date) {}

const string &ClientHorrorHouse::getId() const {
    return id;
}

void ClientHorrorHouse::setId(const string &ids) {
    ClientHorrorHouse::id = ids;
}

const string &ClientHorrorHouse::getNameClient() const {
    return nameClient;
}

void ClientHorrorHouse::setNameClient(const string &nameClient) {
    ClientHorrorHouse::nameClient = nameClient;
}

const string &ClientHorrorHouse::getTelClient() const {
    return telClient;
}

void ClientHorrorHouse::setTelClient(const string &telClient) {
    ClientHorrorHouse::telClient = telClient;
}

const string &ClientHorrorHouse::getDirection() const {
    return direction;
}

void ClientHorrorHouse::setDirection(const string &direction) {
    ClientHorrorHouse::direction = direction;
}

int ClientHorrorHouse::getAge() const {
    return age;
}

void ClientHorrorHouse::setAge(int age) {
    ClientHorrorHouse::age = age;
}

const string &ClientHorrorHouse::getGender() const {
    return gender;
}

void ClientHorrorHouse::setGender(const string &gender) {
    ClientHorrorHouse::gender = gender;
}

const string &ClientHorrorHouse::getDate() const {
    return date;
}

void ClientHorrorHouse::setDate(const string &date) {
    ClientHorrorHouse::date = date;
}

ostream &operator<<(ostream &os, const ClientHorrorHouse &house) {
    os << "idCard: " << house.id << " nameClient: " << house.nameClient << " telClient: " << house.telClient
       << " direction: " << house.direction << " age: " << house.age << " gender: " << house.gender << " date: "
       << house.date;
    return os;
}

ClientHorrorHouse::~ClientHorrorHouse() {

}
