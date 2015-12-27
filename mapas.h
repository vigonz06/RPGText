void villa_raiz(string& filename)
{
    limpiar_pantalla();
    int localizacion;
    vector<int> opciones = {1, 2, 3};
    imprimir_descripcion("villaraiz.txt");

    cout << "\n\nIr al bosque                   [1]" << endl;
    cout << "Salir del pueblo a lo kamikaze     [2]" << endl;
    cout << "Ir a las cumbres tormentosas       [3]" << endl;

    localizacion = recoger_int(opciones);

    switch(localizacion)
    {
        case 1:
            cout << "Ir al bosque" << endl;
            bosque();
            break;

        case 2:
            cout << "\nSalir del pueblo a lo kamikaze." << endl;
            /*kamikaze*/
            break;

        case 3:
            cout << "\nIr a las cumbres tenebrosas." << endl;
            cumbres_tenebrosas();
            break;

        }
}


void bosque( )
{
    int localizacion= rand()%3+1;
    // = rand()%3+1;
    limpiar_pantalla();
    switch(localizacion)
    {
        case 1:
            imprimir_descripcion("bosque.txt");
            cout << "\nTe has encontrado un troll."<< endl;
            combate(jugador, "troll");
            eleccion_en_bosque();
            break;

        case 2:
            imprimir_descripcion("bosque.txt");
            cout << "\nTe has encontrado un unicornio rosa" << endl;
            combate(jugador, "unicornio_rosa");
            eleccion_en_bosque();
            break;

        case 3:
            imprimir_descripcion("bosque.txt");
            cout << "Te has encontrado un goomba"<< endl;
            combate(jugador, "goomba");
            eleccion_en_bosque();
            break;

    }
}

void eleccion_en_bosque()
{
    vector<int> opciones = {1, 2, 3};
    int localizacion;


    cout << "\nA donde quieres ir?" << endl;
    cout << "Ir a la Zona oscura   [1]" << endl;
    cout << "Ir a las Catacumbas   [2]" << endl;
    cout << "Explorar el Cofre     [3]\n" << endl;

    localizacion = recoger_int(opciones);

    switch (localizacion){
    case 1:
        imprimir_descripcion("zona oscura.txt");
        zona_oscura();
        break;
    case 2:
        imprimir_descripcion("catacumbas.txt");
        cout << "Estas en catacumbas" << endl;
        catacumbas();
        break;
    case 3:
        imprimir_descripcion("cofre.txt");
        cout << "Has encontrado un cofre" << endl;
        cofre_serpiente();
        break;
    default:
        cerr << "Esta opcion no existe" << endl;

    }
}


void zona_oscura ()
{
    limpiar_pantalla();
    cout << "\nHas llegado a la zona oscura y te has encontrado un pikachu. Le despertaste "
         << "de su siesta y te ha lanzado un impactrueno." << endl;
    muerte();
}
void catacumbas ()
{
    limpiar_pantalla();
    cout << "\nHas salido del bosque y te encontraste con unas catacumbas" << endl;
    int localizacion = rand()%3+1;

        switch(localizacion)
            {
                case 1:
                cout << "\nTe has encontrado un lobo carmesi." << endl;
                combate(jugador, "lobo");
                albacete();
                break;

                case 2:
                cout << "\nTe has encontrado un dinosaurio" << endl;
                combate(jugador, "dinosaurio");
                albacete();
                break;

                case 3:
                cout << "\nTe has encontrado con Sefirot y te ejecuto de un ataque definitivo" << endl;
                muerte();
                break;

                default:
            ;

            }
}


void cofre_serpiente()
{
    limpiar_pantalla();
    cout << "Te encontraste con un cofre que contenia una pocion." << endl;
         jugador.vida += 25;
         cout <<"Ahora tienes: " << jugador.vida << " HP" << endl
         << "\nDe repente sale ""Solid Snake""(serpiente gigante) y te come.\n" << endl;

     int localizador = rand()%3+1;
     switch(localizador) {
        case 1:
            imprimir_descripcion("tripas serpiente.txt");
            cout << "\nConseguiste escapar gracias a tu poderoso hechizo." << endl;
            albacete();
            break;
        case 2:
            cout << "Te desintegraste dentro" << endl;
            muerte();
            break;

        case 3:
            cout << "Tuviste suerte, a la serpiente le dio un corte de digestion por no hacerse caso de su madre,"
                 << " como consecuencia sales disparado." << endl;
            albacete();
            break;
         default:;
     }
}

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

void volcan ()
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
        default:
            cout << "Entrada no valida",
            exit(EXIT_FAILURE);
    }
}
