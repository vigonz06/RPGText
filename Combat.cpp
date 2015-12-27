#include "Combat.h"

void inizializar_npc_basico(Npc& actual){

    npc_basico.vida = 50;
    npc_basico.mana = 50;
    npc_basico.municion = 0;

}
void inizializar_npc_medio(Npc& actual){

    npc_basico.vida = 100;
    npc_basico.mana = 100;
    npc_basico.municion = 5;

}
void inizializar_npc_fuerte(Npc& actual){

    npc_basico.vida = 150;
    npc_basico.mana = 150;
    npc_basico.municion = 10;

}

char devolver_caracter(const Jugador& jugador){ //DEVUELVE EL CARACTER DE LA CLASE DE JUGADOR

    if(jugador.clase == "guerrero"){
        return 'g';
    }
    else if(jugador.clase == "mago"){
        return 'm';
    }
    else if(jugador.clase == "ladron"){
        return 'l';
    }
    return 'f';
}

void ataque_guerrero(const Jugador& jugador, Ataque a_jugador){
    int opcion;

    vector<int> opciones ={1, 2, 3};

    cout << "elige tu ataque" << endl;
    cout << "1. Golpe de espada" << endl;
    cout << "2. Pedo" << endl;

    opcion = recoger_int(opciones);

    do{
        switch (opcion)
        {
        case 1:
            a_jugador.danio = 10;
            a_jugador.mana = 0;
            a_jugador.municion = 0;
            break;
        case 2:
            a_jugador.danio = 1;
            a_jugador.mana = 1;
            a_jugador.municion = 0;
            break;
    }while(!comprobar_ataque(a_jugador, jugador.mana));
}

bool comprobar_ataque(const Ataque& actual, int restante){


    if(actual.mana >= restante){
        return true;
    }
    else{
        return false;
    }
}

void ataque_mago(const Jugador& jugador, Ataque a_jugador){
    int opcion;
    vector<int> opciones ={1, 2, 3};

    cout << "elige tu ataque" << endl;
    cout << "1. Rayo" << endl;
    cout << "2. Fuego" << endl;

    opcion = recoger_int(opciones);
    do{
        switch (opcion)
        {
        case 1:
            a_jugador.danio = 10;
            a_jugador.mana = 10;
            a_jugador.municion = 0;
            break;
        case 2:
            a_jugador.danio = 1;
            a_jugador.mana = 0;
            a_jugador.municion = 0;
            break;

        }
    }while(!comprobar_ataque(a_jugador, jugador.mana));
}

void ataque_ladron(const Jugador& jugador, Ataque a_jugador){
    int opcion;
    vector<int> opciones ={1, 2, 3};

    cout << "elige tu ataque" << endl;
    cout << "1. Daga" << endl;
    cout << "2. veneno" << endl;

    opcion = recoger_int(opciones);

    do{
        switch (opcion)
        {
        case 1:
            a_jugador.danio = 10;
            a_jugador.mana = 0;
            a_jugador.municion = 0;
            break;
        case 2:
            a_jugador.danio = 1;
            a_jugador.mana = 2;
            a_jugador.municion = 0;
            break;
        }
    }while(!comprobar_ataque(a_jugador, jugador.mana));
}

void ataque_jugador(Jugador& jugador, Ataque& a_jugador){

    char clase;

    clase = devolver_caracter(jugador);

    switch (clase)
    {
    case 'g':
        ataque_guerrero(jugador, a_jugador);
        break;
    case 'm':
        ataque_mago(jugador, a_jugador);
        break;
    case 'l':
       ataque_ladron(jugador, a_jugador);
        break;
    default:

    break;
    }

}
void ataque_npc(Npc& actual, Ataque& a_npc){

    int opcion;
    opcion = (rand() % 2) + 1;//FUNCION ELEGIR ATAQUE
    switch (opcion)
    {
    case 1:
        a_npc.danio = 10;
        a_npc.mana = 0;
        a_npc.municion = 0;
        break;
    case 2:
        a_npc.danio = 1;
        a_npc.mana = 2;
        a_npc.municion = 0;
        break;
    }
}

bool comprobar_vivo(int vida){

    if(vida <= 0){
        return false;
    }else{
        return true;
    }
}

void inizializar_npc(Npc& actual){//NUMEROS MAGICOS


     if (actual.clase == "basico"){

        actual.vida = 50;
        actual.mana = 20;
        actual.municion = 5;

     }else if(actual.clase == "medio"){

        actual.vida = 100;
        actual.mana = 50;
        actual.municion = 10;

     }else if(actual.clase == "fuerte"){

        actual.vida = 150;
        actual.mana = 75;
        actual.municion = 30;

     }


}

void combate(Jugador& jugador, Npc& actual){

    Ataque a_jugador;
    Ataque a_npc;



    bool continuar = true;

    do{
        if(comprobar_vivo(jugador.vida) == true){
            ataque_jugador(jugador,a_jugador);
            actual.vida = actual.vida - a_jugador.danio;
            jugador.mana = jugador.mana - a_jugador.mana;
            jugador.municion = jugador.municion - a_jugador.municion;
        }else{
            continuar = false;
        }
        if(comprobar_vivo(npc_basico.vida) == true){
            ataque_npc(actual, a_npc);
            jugador.vida = jugador.vida - a_npc.danio;
            actual.mana = actual.mana - a_npc.mana;
            actual.municion = actual.municion - a_npc.municion;
        }else{
            continuar = false;
        }

        //IMPRIMIR DATOS DE COMBATE
        //MEJORAR
        cout << "vida de " << jugador.nombre << ": " << jugador.vida;
        cout << "\t";
        cout << "vida de " << actual.nombre << ": " << npc_basico.vida;
    }while(continuar == true);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void bienvenida ()
{

}

string pregunta_nombre(void)
{

    string nombre;

    cout << "Como te llamas? ";

    getline(cin, nombre);



    return nombre;
}

string eleccion_personaje(string nombre)
{
    vector<string> opciones = {"mago", "guerrero", "ladron"};
    string clase;



    cout << "\nDime noble " << nombre << " que clase de aventurero eres?" << endl;
    cout << "\n\t\t    Guerrero        Mago         Ladron"<< endl;
    cout << "\tVida:       200 PS          75 PS        150 PS" << endl;
    cout << "\tMana:       100 PM          200 PM       100 PM" << endl;
    cout << "\tArma:       Espadazo        Hechizo      Flecha" << endl;

    do
    {
        cout << "\nEres guerrero, mago o ladron ?" << endl;
        clase = recoger_string(opciones);
        if (clase == "mago")
        {
            cout << "\nHas elegido mago" << endl;
            return "mago";
        }
        else if (clase == "guerrero")
        {
            cout << "\nHas elegido guerrero" << endl;
            return "guerrero";
        }
        else if (clase == "ladron")
        {
            cout << "\nHas elegido ladron" << endl;
            return "ladron";
        }
    }
    while(clase != "mago" || clase != "guerrero" || clase != "ladron");

    return clase;
}

int recoger_int(vector<int> opciones)
{

    int opcion;
    bool coincidencia = false;

    do
    {
        do
        {
            cin >> opcion;
            void clear_the_mess();
            if(opcion == error)
            {
                cout << "dato incorrecto, vuelve a intentarlo" << endl;
            }
        }
        while(opcion == error);

        for(unsigned int i = 0; i < opciones.size(); i++)
        {
            if(opcion == opciones[i])
            {
                coincidencia = true;
            }
        }
    }
    while(coincidencia != true);

    return opcion;
}

string recoger_string(vector<string> opciones)
{

    string opcion;
    bool coincidencia = false;
    do
    {

        cin >> opcion;

        for(unsigned int i = 0; i < opciones.size(); i++)
        {
            if(opcion == opciones[i])
            {
                coincidencia = true;
            }
        }
        if(coincidencia != true){
            cout << "dato incorrecto, vuelve a intentarlo" << endl;
        }
    } while(coincidencia != true);

    return opcion;
}
