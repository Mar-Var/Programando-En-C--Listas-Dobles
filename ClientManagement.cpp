//
// Created by USUARIO on 9/12/2021.
//

#include "ClientManagement.h"
#include <ctime>


ClientManagement::ClientManagement() {
    currentList=new LinkedDouble<ClientHorrorHouse>;
    blackList= new LinkedDouble<ClientHorrorHouse>;
    totalList = new LinkedDouble<ClientHorrorHouse>;

}

bool ClientManagement::validateFields(string) {
    return true;
}

bool ClientManagement::addFirstPlace(ClientHorrorHouse info) {
    if (validateFields(info.getId())){
        currentList->addNodeFirst(info);
        return true;
    }
    return false;
}

bool ClientManagement::addLastPlace(ClientHorrorHouse info) {
    if (validateFields(info.getId())){
        currentList->addNodeLast(info);
        return true;
    }
    return false;
}
bool ClientManagement::existInAnyList(string) {
    return false;
}

NodeDouble<ClientHorrorHouse> *ClientManagement::findClientPoint(string idCard) {
    if(existInAnyList(idCard)){
        return NULL;
    }
    return currentList->findNode(idCard);
}

ClientHorrorHouse *ClientManagement::findInfoClient(int id) {

    return currentList->getObject(id);
}

bool ClientManagement::addClientBeforeTo(string idPoint, ClientHorrorHouse info) {
    if(validateFields(
            (info.getId(), info.getNameClient(), info.getTelClient(), info.getDirection(), info.getAge(), info.getGender(), info.getDate()))){

    if(findClientPoint(idPoint)!=NULL){
        currentList->addNodeBeforeTo(findClientPoint(idPoint),info);
        return true;

    }
    }

    return false;
}

bool ClientManagement::addNodeClientAfterTo(string idPoint, ClientHorrorHouse info) {

    if(validateFields(
            (info.getId(), info.getNameClient(), info.getTelClient(), info.getDirection(), info.getAge(), info.getGender(), info.getDate()))){

        if(findClientPoint(idPoint)!=NULL){
            currentList->addNodeAfterTo(findClientPoint(idPoint),info);
            return true;

        }
    }


    return false;
}

std::vector<ClientHorrorHouse> ClientManagement::getList(bool sw) {
    return currentList->getList(sw);
}

int ClientManagement::getSizeRow() {
    return currentList->getSize();
}

bool ClientManagement::deleteClientSimply(string idPoint) {

    if(findClientPoint(idPoint)!=NULL){
        ClientHorrorHouse chh = currentList->deleteNode(findClientPoint(idPoint));
        currentList->deleteNode(findClientPoint(idPoint));
        totalList->addNodeFirst(chh);
        return true;

    }
    return false;
}


bool ClientManagement::deleteClientbyBad(string idPoint) {

    if(findClientPoint(idPoint)!=NULL){
        addToBlackList(currentList->deleteNode(findClientPoint(idPoint))) ;
//        currentList->deleteNode(findClientPoint(idPoint));
        return true;

    }
    return false;
}

bool ClientManagement::addToBlackList(ClientHorrorHouse info) {
    if(validateFields(info.getId())){
        blackList->addNodeFirst(info);
        return true;
    }

    return false;
}

std::vector<ClientHorrorHouse> ClientManagement::getBlackList(bool sw) {
    return blackList->getList(sw);
}

std::vector<ClientHorrorHouse> ClientManagement::getTotalList(bool sw) {
    return totalList->getList(sw);
}

string ClientManagement::getTime() {
    time_t current_time;
    struct tm * time_info;
    char timeString[9];

    time(&current_time);
    time_info = localtime(&current_time);

    strftime(timeString, sizeof(timeString), "%H:%M:%S", time_info);

    return timeString;
}











