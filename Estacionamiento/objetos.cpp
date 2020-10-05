#include "objetos.h"

objetos::objetos()
{

}


admin::admin(){

}

admin::admin(int id){
    idAdmin = id;
}

Usua::Usua(){

}

Usua::Usua(int id){
    idUsuario=id;
}

int Usua::getid(){
    return idUsuario;
}

lugares::lugares(){

}

lugares::lugares(int nE, int idP, QString est){
    noEspacio = nE;
    idPiso = idP;
    estado = est;
}


reservaciones::reservaciones(){

}

reservaciones::reservaciones(int noR, int idT, int idP, int noE, int idU, QDate dte, QTime hLl, QTime hSal, bool overB){
    noReservacion = noR;
    idTarifa = idT;
    idPago = idP;
    NoEspacio = noE;
    idUsuario = idU;
    fecha = dte;
    horallegada = hLl;
    horaSalida = hSal;
    oB = overB;
}
