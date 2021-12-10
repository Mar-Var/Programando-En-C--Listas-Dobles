#include <iostream>
#include "ClientManagement.h"
#include "ClientHorrorHouse.h"
#include <string>
using namespace std;

int main() {
    int menuPrincipal;
    ClientManagement* cm = new ClientManagement();

    cout<<"Bienvenido al sistema de atencion de la casa del Terror\n"
          "Gestione a los nuevos participantes de la forma que crea mas conveniente:\n"
          "1.Añadir al final de la cola\n"
          "2.Añadir despues de alguien\n"
          "3.Añadir antes que alguien\n"
          "4.Sacar a alguien de la cola por mal comportamiento\n"
          "5.Sacar de la cola por que ya termino su participacion\n"
          "6.Mostrar cantidad de personas restantes\n"
          "7.Ver informacion de las personas restantes\n"
          "8.Mostrar la informacion de alguien segun posicion en la fila\n"
          "9.Mostrar la informacion de la lista negra de la casa del terror\n"
          "10.Salir";
    cin>>menuPrincipal;

    string idCard="",name="",tel="",direction="",gender="",date="",idPoint="",idBadBoy="";
    int age=0;
    switch(menuPrincipal){
        case 1:
            cout<<"Bienvendio a Añadir al final de la fila\n";
            cout<<"Dijite sunumero de identificacion\\n"<<endl;
            cin>>idCard ;
            cout<<"Dijite su nombre\n"<<endl;
            cin>> name;
            cout<<"Dijite su telefono\n"<<endl;
            cin>>tel ;
            cout<<"Dijite su direccion\n"<<endl;
            cin>>direction ;
            cout<<"Dijite su edad\n"<<endl;
            cin>> age;
            cout<<"Digite su genero\n"<<endl;
            cin>>gender ;
            date = __TIMESTAMP__;
            cm->addLastPlace(ClientHorrorHouse(idCard,name,tel,direction,age,gender,date));


            break;
        case 2:
            cout<<"Bienvendio a Añadir despues de alguien\n";
            cout<<"Dijite su numero de identificacion\n"<<endl;
            cin>>idCard ;
            cout<<"Dijite su nombre\n"<<endl;
            cin>> name;
            cout<<"Dijite su telefono\n"<<endl;
            cin>>tel ;
            cout<<"Dijite su direccion\n"<<endl;
            cin>>direction ;
            cout<<"Dijite su edad\n"<<endl;
            cin>> age;
            cout<<"Digite su genero\n"<<endl;
            cin>>gender ;
            date = __TIMESTAMP__;

            cout<<"Indique despues de que numero de identificacion desea colocar al cliente\n"<<endl;
            cin>>idPoint;
            cm->addNodeClientAfterTo(idPoint,ClientHorrorHouse(idCard,name,tel,direction,age,gender,date));
            break;

        case 3:
            cout<<"Bienvendio a Añadir antes de alguien\n";
            cout<<"Dijite sunumero de identificacion\n"<<endl;
            cin>>idCard ;
            cout<<"Dijite su nombre\n"<<endl;
            cin>> name;
            cout<<"Dijite su telefono\n"<<endl;
            cin>>tel ;
            cout<<"Dijite su direccion\n"<<endl;
            cin>>direction ;
            cout<<"Dijite su edad\n"<<endl;
            cin>> age;
            cout<<"Digite su genero\n"<<endl;
            cin>>gender ;
            date = __TIMESTAMP__;
            cm->addClientBeforeTo(idPoint,ClientHorrorHouse(idCard,name,tel,direction,age,gender,date));

            break;
        case 4:
            cout<<"Bienvendio a la zona de castigo\n"
                  "Dijite el numero de identificacion del que se ´porta mal en la fila :\n";
            cin>>idBadBoy;
            cm->deleteClientbyBad(idBadBoy);
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        default:
            break;

    }

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
