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
