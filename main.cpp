#include <iostream>
#include "ClientManagement.h"
#include "ClientHorrorHouse.h"
#include <string>
using namespace std;

int main() {
    int menuPrincipal;

    ClientManagement* cm = new ClientManagement();
    cm->addLastPlace(ClientHorrorHouse("123","nada","3224031216","cra15",5,"Male","10-52-41"));
    cm->addLastPlace(ClientHorrorHouse("124","nada","3224031216","cra15",5,"Male","10-52-41"));
    cm->addLastPlace(ClientHorrorHouse("125","nada","3224031216","cra15",5,"Male","10-52-41"));
    cm->addLastPlace(ClientHorrorHouse("126","nada","3224031216","cra15",5,"Male","10-52-41"));
    cm->deleteClientbyBad("126");

    for(ClientHorrorHouse cd :cm->getList(true)){
        cout<<cd<<endl;
    }
    cout<<"------------------------------------\n";
    for(ClientHorrorHouse bl :cm->getBlackList(true)){
        cout<<bl<<endl;
    }

    return 0;
}
