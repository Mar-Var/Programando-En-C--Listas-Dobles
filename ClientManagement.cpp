//
// Created by USUARIO on 9/12/2021.
//

#include "ClientManagement.h"
#include <ctime>

/**
 * Metodo constructor de la clase de gestion de Clientes ClientManagement
 */
ClientManagement::ClientManagement() {
    currentList=new LinkedDouble<ClientHorrorHouse>;
    blackList= new LinkedDouble<ClientHorrorHouse>;
    totalList = new LinkedDouble<ClientHorrorHouse>;

}
/**
 *Este metodo esta diseñado para validad los datos de entrada al objeto principal.
 * @param idCard Parametro de tipo string que recibe el numero de identificacion de el cliente
 * @param name  Parametro de tipo string que recibe el nombre del cliente
 * @param tel  Parametro de tipo string que recibe el numero de contacto de el cliente
 * @param direction  parametro de tipo string que recibe la direccion de domicilio del cliente
 * @param age parametro de tipo entero que recibe la edad del cliente
 * @param gender paramreto de tipo estring que recibe el genero u orientacion sexual del cliente
 * @param date parametro de tipo string que recibe la fecha actual en la que se registró
 * @return Retorna un valor booleando verdadero si la validacion fue exitosa y false si hubo algun error;
 */

bool ClientManagement::validateFields(string idCard,string name,string tel,string direction,int age,string gender,string date) {
    if(isNumber(tel)
    && isNumber(idCard)
    && isNotNumber(name)
    && direction.length()>4
    &&isNotNumber(gender)
    )return true;
    return false;
}
/**
 * Este metodo permite ingresar datos en el primer lugar de la lista.
 * @param info parametro de tipo objeto ClientHorrorHouse que contiene toda la informacion del cliente
 * @return Retorna un valor booleando, true si logra agregar el objeto a la lista.. false si no
 */
bool ClientManagement::addFirstPlace(ClientHorrorHouse info) {
    if (validateFields(info.getId(),info.getNameClient(),info.getTelClient(),info.getDirection(),info.getAge(),info.getGender(),info.getDate())&& existInAnyList(info.getId())){
        currentList->addNodeFirst(info);
        waringMessage+="El participante se ha añadido correctamente\n";
        return true;
    }
    return false;
}
/**
 * Este metodo permite ingresar el objeto ClientHorrorHouse en el ultimo lugar de la lista
 * @param info parametro de tipo objeto ClientHorrorHouse que contiene toda la informacion del cliente
 * @return  Retorna un valor booleando, true si logra agregar el objeto a la lista.. false si no
 */
bool ClientManagement::addLastPlace(ClientHorrorHouse info) {
    if (validateFields(info.getId(),info.getNameClient(),info.getTelClient(),info.getDirection(),info.getAge(),info.getGender(),info.getDate())&& existInAnyList(info.getId())){
        currentList->addNodeLast(info);
        waringMessage+="El participante se ha añadido correctamente\n";
        return true;
    }
    return false;
}
/**
 * Este metodo permite validar si existen mas objetos con el mismo Id de el argumento del metodo.
 * @param idSearch parametro de tipo string que recibe el numero de identificacion de algun cliente
 * @return Retorna u tipo de valor booleano, true si no exite esa identificacion en ninguna lista y false si encuentra alguna.
 */
bool ClientManagement::existInAnyList(string idSearch) {
    for(ClientHorrorHouse cl : getList(true)){
        if (cl.getId().compare(idSearch))     {
            waringMessage+="El participante ya se encuentra en la fila\n";
            return false;
        }
    }
    for(ClientHorrorHouse bl : getBlackList(true)){
        if (bl.getId().compare(idSearch))     {
            waringMessage+="El participante esta en la lista negra. No puede volver a participar\n";
            return false;
        }
    }
    for(ClientHorrorHouse tl : getTotalList(true)){
        if (tl.getId().compare(idSearch))     {
            waringMessage+="Solo se permite ingresar una sola vez. Lo sentimos\n";
            return false;
        }
    }
    return true;
}


/**
 * Este metodo permite buscar la ubicacion en el espacio de memoria donde se encuentra localizado un objeto a partir de uno de sus parametros.
 * @param idCard parametro de tipo string que recibe el valor de una identificacion de un cliente para poder ubicarlo dentro del espacio de memoria de la lista
 * @return retorna un puntero indicando la localizacion del objeto cuya identificacion concuerda con la entrada
 */
NodeDouble<ClientHorrorHouse> *ClientManagement::findClientPoint(string idCard) {
    return currentList->findNode(idCard);
}


/**
 * Este metodo le permite buscar dentro de una lista segun su posicion en dentro de ella.
 * @param id Parametro de tipo entero que representa la posicion en la cual se encuentra localizado un objeto dentro de la lista.
 * @return retorna Un dato de tipo ClientHorrorHouse que coincide con la posicion en la lista.
 */
ClientHorrorHouse *ClientManagement::findInfoClient(int id) {

    return currentList->getObject(id);
}
/**
 * Este metodo permite añadir un objeto despues de la posicion de algu otro objeto que se encuentre localizado dentro de la lista.
 * @param idPoint Paramtro de tipo string que representa la identificacion de donde se pretende colocar el nuevo objeto
 * @param info Parametro de tipo ClientHorrorHouse que contiene la informacion de nuestro cliente
 * @return  retorna un tipo de dato booleano , True si se añade correctamente y false y no le añade correctamente;
 */
bool ClientManagement::addClientBeforeTo(string idPoint, ClientHorrorHouse info) {
    if(validateFields(
            info.getId(), info.getNameClient(), info.getTelClient(), info.getDirection(), info.getAge(), info.getGender(), info.getDate())&& existInAnyList(info.getId())){

    if(findClientPoint(idPoint)!=NULL){
        currentList->addNodeBeforeTo(findClientPoint(idPoint),info);
        waringMessage+="El participante se ha añadido correctamente\n";
        return true;

    }
    }

    return false;
}
/**
 * Este metodo permite añadir objetos despues de un determinado objeto dispuesto en la memoria en la lista.
 * @param idPoint Parametro de tipo string que representa el numero de identificacion del cliente sobre el cual se va a tomar como referencia.
 * @param info parametro de tipo ClientHorrorHouse que contiene toda la informacion del cliente,
 * @return Retorna un tipo de dato booleando. True si se logra agregar correctamente el objeto y false si no s elogra realizarlo.
 */
bool ClientManagement::addNodeClientAfterTo(string idPoint, ClientHorrorHouse info) {

    if(validateFields(
            info.getId(), info.getNameClient(), info.getTelClient(), info.getDirection(), info.getAge(), info.getGender(), info.getDate())&& existInAnyList(info.getId())){

        if(findClientPoint(idPoint)!=NULL){
            currentList->addNodeAfterTo(findClientPoint(idPoint),info);
            waringMessage+="El participante se ha añadido correctamente\n";
            return true;

        }
    }


    return false;
}
/**
 *Este metodo permite obtener la lista de las personas que se encuetran actualmente haciendo fila para entrar a la casa del terror
 * @param sw parametro de tipo booleano que indica en que sentido se va a recorrer la lista.
 * @return retorna un tipo de dato vector donde esta almacenada y orgaizada la informacion de la lista.
 */
std::vector<ClientHorrorHouse> ClientManagement::getList(bool sw) {
    return currentList->getList(sw);
}

/**
 * Este metodo permite dar a conocer la cantidad de registros que se encuentran en la lista actual de personas haciendo fila,
 * @return Rerotna un dato de tipo entero indicando la cantidad de registro guardados en la lista.
 */
int ClientManagement::getSizeRow() {
    return currentList->getSize();
}
/**
 * Este metodo permite eliminar a un cliente/objeto de la lista principal
 * @param idPoint parametro de tipo string que representa el id de la persona que se desea borrar de la lista
 * @return retorna un tipo de dato booleano, True si se elimina correctamente y false si no se puede aliminar.
 */

bool ClientManagement::deleteClientSimply(string idPoint) {

    if(findClientPoint(idPoint)!=NULL){

        totalList->addNodeFirst(currentList->deleteNode(findClientPoint(idPoint)));
        waringMessage+="El participante ha sido removido con exito\n";
        return true;

    }
    return false;
}

/**
 * Este metodo permite eliminar a una persona de la lista actual de personas en espera y una vez eliminado esta pasa a formar parte de la lista negra
 * @param idPoint Parametro de tipo entero que representa el id de la persona que se encuentra en la lista actual y sera removida y pasada a la lista negra
 * @return retorna un tipo de dato boolean . True si se puede liminar correctamente y false si o se puede eliminar correctamente
 */
bool ClientManagement::deleteClientbyBad(string idPoint) {

    if(findClientPoint(idPoint)!=NULL){
        addToBlackList(currentList->deleteNode(findClientPoint(idPoint))) ;
//        currentList->deleteNode(findClientPoint(idPoint));
        waringMessage+="Se ha eliminado con exito y agregado a la lista negra\n";
        return true;

    }
    return false;
}


/**
 * Este metodo permite añadir los objetos  a la lista negra que se ha implementado en la glase de gestion de clientes
 * @param info Parametro de tipo ClientHorrorHouse que contiene la ifnormacion de la persona que va a ser dirigida hacia la lista negra
 * @return Retorna un tipo de dato tipo booleano. True si se puede ralizar ala operadcion correctamente, Flase si no se puede añadir correctamente
 */
bool ClientManagement::addToBlackList(ClientHorrorHouse info) {
    if(validateFields(info.getId(),info.getNameClient(),info.getTelClient(),info.getDirection(),info.getAge(),info.getGender(),info.getDate())){
        blackList->addNodeFirst(info);
        return true;
    }

    return false;
}


/**
 * Este metodo permite almacenar en un vector toda la informacion contenida en la lista
 * @param sw Parametro de tipo booleano que permite aclarar en que orden se va a guardar la informacion dentro del vecto
 * @return Retorna un dato de tipo vector con la informacion de todos los registros de la lista negra
 */
std::vector<ClientHorrorHouse> ClientManagement::getBlackList(bool sw) {
    return blackList->getList(sw);
}


/**
 * Este metodo permite almacenar todos los datos de todas las personas que han salido de la casa de terror, para tener un registro de salidas.
 * @param sw Parametro de tipo booleano que permite aclarar en que orden se va a guardar la informacion dentro del vecto
 * @return Retorna un dato de tipo vector con la informacion de todos los registros de la lista total final
 */
std::vector<ClientHorrorHouse> ClientManagement::getTotalList(bool sw) {
    return totalList->getList(sw);
}

/**
 * Este metodo permite generar una cadena con la informacionde la hora a la cual se llevo a cabo la visita a la casa del terror
 * @return retorna un tipo de dato string con la informacion de la hora exacta de ingreso a la casas del terror
 */

string ClientManagement::getTime() {
    time_t current_time;
    struct tm * time_info;
    char timeString[9];

    time(&current_time);
    time_info = localtime(&current_time);

    strftime(timeString, sizeof(timeString), "%H:%M:%S", time_info);

    return timeString;
}

/**
 * Metodo que permite guardar todos los errores que se generan a lo largo del codigo
 * @return Retorna un dato tipo string sobre la informacion de errores y aciertos a lo largo de la codificacion
 */
const string &ClientManagement::getWaringMessage() const {
    return waringMessage;
}

/**
 * Este metodo permite decir si una cadena es solo de caracteres numericos o solo letras
 * @param str Parametro de tipo string que es la cadena a la cual se va a sometaer el analisis de si es o no es un numero
 * @return retorna un tipo de dato booleano. True si es un numero, false si tambien contiene letras
 */

bool ClientManagement::isNumber(string str) {
    for (char const &c : str) {
        if (std::isdigit(c) == 0){
            waringMessage+="Entradas incorrectas: Ha ingresado una letra en un lugar donde solo deben ir numeros.Revise.\n";
            return false;
        }

    }

    return true;
}


/**
 * metodo que permite saber si una cadena de entrada es una palabra o si contiene numeros tambien
 * @param str parametro de tipo string que representa la cadena a ser analizada.
 * @return Retorna un valor de tipo booleano, true si es una cadena sin numeros y false si contiene algun caracter numerico
 */
bool ClientManagement::isNotNumber(string str) {
    for (char const &c : str) {
        if (std::isdigit(c) == 1){
            waringMessage+="Entradas incorrectas: Ha ingresado numerosen un lugar donde solo deben ir letras.Revise.\n";
            return false;
        }

    }

    return true;
}

void ClientManagement::setWaringMessage(const string &waringMessage) {
    ClientManagement::waringMessage = waringMessage;
}

ClientManagement::~ClientManagement() {
    delete(this);

}










