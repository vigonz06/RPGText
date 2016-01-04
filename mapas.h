#ifndef MAPAS
#define MAPAS

#include <string>
#include "Archivo.h"
#include "PlaceList.h"
#include "GraphInter.h"

class Mapas
{
public:
	Mapas() {};

	void Villa_Raiz(PlaceList* places);

private:

	void Bosque();
	void Eleccion_Bosque();
	void Zona_Oscura();
	void Catacumbas();
	void Cofre_Serpiente();
};

#endif
void Mapas::Villa_Raiz(PlaceList* places)
{
	int localizacion;

	localizacion = GraphInter::get()->menu(places->get("villa_raiz"));

    switch(localizacion)
    {
    case 1:
		Bosque();
        break;

    case 2:
		//kamikaze();
        break;

    case 3:
       // Cumbres_Tenebrosas();
        break;
    }
}


void Mapas::Bosque()
{
    int localizacion= rand()%3+1;
    // = rand()%3+1;
	GraphInter::get()->clearConsole();
	find("Bosque");

    switch(localizacion)
    {
    case 1:
		GraphInter::get()->display("");
		GraphInter::get()->display("Te has encontrado un troll.");
        //combate(jugador, "troll");
        Eleccion_Bosque();
        break;

    case 2:
		GraphInter::get()->display("");
		GraphInter::get()->display("Te has encontrado un unicornio rosa.");
        //combate(jugador, "unicornio_rosa");
        Eleccion_Bosque();
        break;

    case 3:
		GraphInter::get()->display("");
		GraphInter::get()->display("Te has encontrado un goomba.");
        //combate(jugador, "goomba");
        Eleccion_Bosque();
        break;

    }
}

void Mapas::Eleccion_Bosque()
{
    int localizacion;
	std::string options[3];

	options[0] = "Ir a la Zona Oscura";
	options[1] = "Ir a las Catacumbas";
	options[2] = "Explorar el Cofre";

	localizacion = GraphInter::get()->menu(options, 3, "A donde quieres ir?");

    switch (localizacion)
	{
    case 1:
        find("zona oscura.txt");
        Zona_Oscura();
        break;
    case 2:
        find("catacumbas.txt");
        GraphInter::get()->display("Estas en catacumbas");
        Catacumbas();
        break;
    case 3:
        find("cofre.txt");
        GraphInter::get()->display("Has encontrado un cofre");
        Cofre_Serpiente();
        break;
	}
}


void Mapas::Zona_Oscura ()
{
	GraphInter::get()->clearConsole();
	GraphInter::get()->display("");
	GraphInter::get()->display("Has llegado a la zona oscura y te has encontrado un pikachu. Le despertaste de su siesta y te ha lanzado un impactrueno.");
    //muerte();
}

void Mapas::Catacumbas ()
{
	GraphInter::get()->clearConsole();
	GraphInter::get()->display("");
    GraphInter::get()->display("Has salido del bosque y te encontraste con unas catacumbas");

	int localizacion = rand() % 3;

    switch(localizacion)
    {
    case 0:
		GraphInter::get()->display("");
		GraphInter::get()->display("Te has encontrado un lobo carmesi.");
		//combate(jugador, "lobo");
		//albacete();
		break;

	case 1:
		GraphInter::get()->display("");
		GraphInter::get()->display("Te has encontrado un dinosaurio");
        //combate(jugador, "dinosaurio");
        //albacete();
        break;

	case 2:
		GraphInter::get()->display("");
		GraphInter::get()->display("Te has encontrado con Sefirot y te ejecuto de un ataque definitivo");
        //muerte();
        break;
    }
}


void Mapas::Cofre_Serpiente()
{
    GraphInter::get()->clearConsole();
	GraphInter::get()->display("");
	GraphInter::get()->display("Te encontraste con un cofre que contenia una pocion.");
	/*jugador.vida += 25;
	cout <<"Ahora tienes: " << jugador.vida << " HP" << endl*/

	GraphInter::get()->display("De repente sale ""Solid Snake""(serpiente gigante) y te come.");

	int localizador = rand() % 3;
     switch(localizador)
	 {
    case 0:
        find("tripas serpiente.txt");
		GraphInter::get()->display("");
		GraphInter::get()->display("Conseguiste escapar gracias a tu poderoso hechizo.");
        //albacete();
        break;
    case 1:
		GraphInter::get()->display("Te desintegraste dentro");
        //muerte();
        break;

    case 2:
		GraphInter::get()->display("Tuviste suerte, a la serpiente le dio un corte de digestion por no hacer caso a su madre, como consecuencia sales disparado.");
        //albacete();
        break;
     }
}
/*
void albacete()
{
    limpiar_pantalla();
    imprimir_descripcion("albacete.txt");
    cout << "\nTomas rumbo a Albacete y " << endl;
    int localizador= rand()%3+1;

        switch(localizador)
            {
                case 1:
                imprimir_descripcion("iniesta.txt");
                cout << "\nTe has encontrado con Iniesta tomandose un helado, te lo da y restauras 20 HP." << endl;
                jugador.vida += 25;
                cout << "Ahora tienes " << jugador.vida << " HP" << endl;
                eleccion_en_albacete();
                break;

                case 2:
                cout << "\nTe encuentras al 'afilaor': Has obtenido navaja" << endl;
                imprimir_descripcion("forjador de navajas.txt");
                eleccion_en_albacete();
                break;

                case 3:
                imprimir_descripcion("casa.txt");
                cout << "\nEntras en una casa y renuncias a tu mision porque encontraste al amor de tu vida." << endl;
                muerte();
                break;

                default:;
            }
    }

void eleccion_en_albacete()
{
    vector<int> opciones = {1, 2, 3};

    cout << "\nY ahora, hacia donde quieres tirar?" << endl;
    cout << "\nTira 'pal' volcan      [1]"
         << "\nTira 'pal' pantano     [2]"
         << "\nMirar el wasap         [3]" << endl;

    int localizacion = recoger_int(opciones);
    switch (localizacion){
        case 1:
            volcan();
            break;
        case 2:
            pantano();
            break;
        case 3:
            wasap();
            break;
        default:;
    }
}

void volcan()
{
    limpiar_pantalla();
    int localizador = rand()%3+1;
    switch (localizador){
        case 1:
            imprimir_descripcion("volcan.txt");
            cout << "\nTe has encontrado con Charmander" << endl;
            combate(jugador, "charmander");
            break;
        case 2:
            imprimir_descripcion("volcan.txt");
            cout << "\nTopaste con Bowser" << endl;
            combate(jugador, "bowser");
            break;
        case 3:
            imprimir_descripcion("volcan.txt");
            cout << "\nUn Gordete de fuego aparecio" << endl;
            combate(jugador, "gordo_de_fuego");
            break;
        default:;


    }
}

void pantano()
{
    limpiar_pantalla();
    imprimir_descripcion("pantano.txt");
    cout << "\nShrek approves" << endl;

    int localizador = rand()%3+1;
    switch (localizador){
        case 1:
            imprimir_descripcion("pantano.txt");

            cout << "\nTe has encontrado con un mago negro";
            combate(jugador, "mago_negro");
            break;
        case 2:
            imprimir_descripcion("pantano.txt");
            cout << "\nEl gran Ganondorf te reta";
            combate(jugador, "ganondorf");
            break;
        case 3:
            imprimir_descripcion("pantano.txt");
            cout << "\nSale Gargamel y te ataca" << endl;
            combate(jugador, "gargamel");
            break;
        default:;
    }
}

void wasap()
{
    limpiar_pantalla();
    cout << "\nSe te hace pesado descansar y decides mirar el wasap" << endl;

    int localizador = rand()%3+1;
    switch (localizador) {
        case 1:
            cout << "\nTu novia te ha acosado a mensajes. Pusiste cara de escarnio" << endl;
            break;
        case 2:
            cout << "Tienes 10 llamadas perdidas de tu madre" << endl;
            break;
        case 3:
            cout << "Cambiaste el fondo de pantalla"<< endl;
            break;
        default:;
    }
}

void cumbres_tenebrosas()
{
    limpiar_pantalla();
    cout << "\nHas llegado a las cumbres tenebrosas y ";
    int localizacion = rand()%3+1;

    switch (localizacion){
        case 1:
            cout << "te has encontrado con Vegeta" << endl;
            combate(jugador, "vegeta");
            eleccion_cumbres();
            break;
        case 2:
            cout << "te has encontrado con un zombie del call of duty" << endl;
            combate(jugador, "zombie_call_of_duty");
            eleccion_cumbres();
            break;
        case 3:
            cout << "te has encontrado con un Metroid" << endl;
            combate(jugador, "metroid");
            eleccion_cumbres();
            break;
        default:
            cerr << "Entrada no valida";
            exit(EXIT_FAILURE);
        }
}

void eleccion_cumbres()
{
    vector<int> opciones = {1, 2, 3};

    cout << "\nHacia donde te dirigiras?" << endl;
    cout << "Papua Nueva Guinea   [1]\n"
         << "Columna Lanza        [2]\n"
         << "Barranco             [3]\n";

    int localizacion;
    localizacion = recoger_int(opciones);

    switch (localizacion){
        case 1:
            papua();
            break;
        case 2:
            columna_lanza();
            break;
        case 3:
            barranco();
            break;
        default:
            cerr << "Entrada no valida";
            exit(EXIT_FAILURE);
    }
}

void papua()
{
    limpiar_pantalla();
    int localizacion = rand()%3+1;
    switch(localizacion){
        case 1:
            cout << "Un Saibaman salvaje ha aparecido" << endl;
            combate(jugador, "saibaman");
            eleccion_columna_lanza_papua();
            break;
        case 2:
            cout << "Un lakitu en su nube te reta" << endl;
            combate(jugador, "lakitu");
            eleccion_columna_lanza_papua();
            break;
        case 3:
            cout << "Un poderoso Meta Knight te funde con su espadita" << endl;
            muerte();
            break;
        default:
            cerr << "Entrada no valida";
            exit(EXIT_FAILURE);
    }
}
void columna_lanza() //AQUI SE COGE LA LLAVE
{
    limpiar_pantalla();
    llave = true;
    int localizacion = rand()%3+1;
    cout << "\nTe has encontrado una llave." << endl;
    switch(localizacion){
        case 1:
            cout << "\nUn Jigglypuff salvaje ha aparecido" << endl;
            combate(jugador, "jigglypuff");
            eleccion_columna_lanza_papua();
            break;

        case 2:
            cout << "Ridley alzo sus alas sobre ti" << endl;
            combate(jugador, "ridley");
            eleccion_columna_lanza_papua();
            break;

        case 3:
            cout << "Chomp Cadenas aparecio" << endl;
            combate(jugador, "chomp_cadenas");
            eleccion_columna_lanza_papua();
            break;

        default:
            cout << "Entrada no valida",
            exit(EXIT_FAILURE);
    }
}
void barranco()
{
        limpiar_pantalla();
        cout << "Decides unirte a la grabacion de 'un paso adelante' en un mal sitio." << endl;
        muerte();
}




void eleccion_columna_lanza_papua()
{
    vector<int> opciones = {1, 2, 3};

    cout << "\nY ahora decide tu proximo camino?" << endl;
    cout << "Cadiz                                 [1]\n"
         << "Templo del tiempo  se necesita llave) [2]\n" << endl;

    int localizacion;
    localizacion = recoger_int(opciones);

    switch(localizacion){
        case 1:
            cadiz();
            break;
        case 2:
            if (llave  == true){
            cout << "\nTienes la llave entras" << endl;
            templo_tiempo();
            } else {
                cout << "\nno tienes la llave te vas pa cadiz" << endl;
                cadiz();

            }
            break;
        default:
            cerr << "Entrada no valida";
            exit(EXIT_FAILURE);
        }
}

void cadiz ()
{
    vector<int> opciones = {1, 2, 3};
    limpiar_pantalla();
    cout << "\nHas llegado a Cadiz" << endl;
    cout << "Que quieres hacer?: \n"
         << "Ir a la playa[1]\n"
         << "Irte a dormir la siesta[2]\n"
         << "Tomarte un salmorejo[3]" << endl;

    int localizacion;
    localizacion = recoger_int(opciones);

    switch (localizacion){
        case 1:
            cout << "\nTe has ido a la playa y tomaste el sol" << endl;
            eleccion_shinra_cueva();
            break;
        case 2:
            cout << "Te fuiste a dormir un ratito" << endl;
            eleccion_shinra_cueva();
            break;
        case 3:
            cout << "Te tomas un salmorejo" << endl;
            eleccion_shinra_cueva();
            break;
        default:
            cerr << "Entrada no valida";
            exit(EXIT_FAILURE);
    }
}

void templo_tiempo()
{
    limpiar_pantalla();
    int localizacion = rand()%3+1;
    switch(localizacion){
        case 1:
            cout << "Sale el Joker" << endl;
            combate(jugador, "joker");
            eleccion_shinra_cueva();
            break;
        case 2:
            cout << "King Boo se volvio visible hacia ti" << endl;
            combate(jugador, "king_boo");
            eleccion_shinra_cueva();
            break;
        case 3:
            cout << "Se acerca una fiora fedeada" << endl;
            combate(jugador, "fiora");
            eleccion_shinra_cueva();
            break;
        default:
            cout << "Entrada no valida",
            exit(EXIT_FAILURE);
    }
}

void eleccion_shinra_cueva()
{
    vector<int> opciones = {1, 2};

    cout << "\nY ahora decide tu proximo camino?" << endl;
    cout << "Shinra [1]\n"
         << "Cueva[2]" << endl;

    int localizacion;
    localizacion = recoger_int(opciones);

    switch(localizacion){
        case 1:
            shinra();
            break;
        case 2:
            cueva();
            break;
        default:
            cerr << "Entrada no valida";
            exit(EXIT_FAILURE);
        }
}

void shinra()
{
    limpiar_pantalla();
    int localizacion = rand()%3+1;
    switch(localizacion){
        case 1:
            cout << "Arma rubi" << endl;
            combate(jugador, "arma_rubi");
            break;
        case 2:
            cout << "Freezer" << endl;
            combate(jugador, "freezer");
            break;
        case 3:
            cout << "Donkey Kong" << endl;
            combate(jugador, "donkey_kong");
            break;
        default:
            cout << "Entrada no valida",
            exit(EXIT_FAILURE);
    }
}

void cueva()
{
    limpiar_pantalla();
    int localizacion= rand()%3+1;
    switch(localizacion){
        case 1:
            cout << "Satan" << endl;
            combate(jugador, "Satan");
            break;
        case 2:
            cout << "Voldemort" << endl;
            combate(jugador, "Voldemort");
            break;
        case 3:
            cout << "Kraken" << endl;
            combate(jugador, "kraken");
            break;
    }
}*/