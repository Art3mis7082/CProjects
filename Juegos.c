/*
* Descripcion del programa: Con los conocimientos aplicados durante todo el semestre, ademas este 
* mismo busca una forma divertida de ver como la programacion se puede ver reflejada en juegos tan simples
*
* Author
*          Beatriz Almaraz
*/

#include <stdio.h>     /*Libreria <stdio.h> es la libreria que contiene las definiciones y declaraciones estandar del lenguaje C para hacer operaciones estandar de entrada y salida.*/
#include <string.h>    /*Libreria <string.h> es la libreria que contiene las definiciones y declaraciones estandar del lenguaje C para hacer operaciones de manipulacion de memoria.*/
#include <stdlib.h>    /*Libreria <stdlib.h> es la libreria que contiene las definiciones y declaraciones del lenguaje C para gestionar memoria dinamica, controlar procesos, entre otros usos.*/

#define pf printf
#define sf scanf
/* Declaracion de funciones que se utilizaran en el codigo, además que cada programa tiene un título de inicio
   el cual  se llama igualmente por medio de funciones. */

int op; /*Es global porque se ocupa en todas funciones de cada programa para saber si se va repetir el juego,
          además que se ocupa para seleccionar el juego que se desee ejecutar.*/
          
void texto_Bienvenido();
void texto_gato();
void programa_gato();
void dibujo_fin_gato();
int repetir_programa();
void texto_piedra();
void programa_piedra();
void imprimeGanador();
void programa_trivia();
void texto_trivia();
void ImprimirEstrella();
void programa_ahorcado();
void texto_ahorcado();
void imprimeAhorcado();
void texto_batalla();
void programa_batalla();
void Despedida();


int main()
{
    texto_Bienvenido();
    do      //Repite el menú hasta que el usuario desee

    {   //Menu de opciones
        pf("\n\n\tMen%c: ",163);
        pf("\n\t1) Gato");
        pf("\n\t2) Piedra, papel o tijera");
        pf("\n\t3) Trivia");
        pf("\n\t4) Ahorcado");
        pf("\n\t5) Batalla Naval");
        pf("\n\t6) CERRAR");
        do   /*Este ciclo verifica el usuario de únicamente opciones válidas, en caso contrario */
        {    /*vuelve a solicitar una opción.*/
            pf("\n\tSelecciona un juego: ");
            sf("%i",&op);
            fflush(stdin);
            if(op<1 || op>6)
                pf("\n\tOpci%cn inv%clida\n\tIngresa una opci%cn v%clida",162,160,162,160);
        }
        while(op<1 || op>6);

        switch(op)  /*En cada caso se evalúa op y se entra en una función, la cual equivale a un juego. */
        {
        case 1:
            system("cls");  /*Es para limpiar la pantalla, pertence a la libería <stdlib.h>*/
            programa_gato();
            break;
        case 2:
            system("cls");
            programa_piedra();
            break;
        case 3:
            system("cls");
            programa_trivia();
            break;
        case 4:
            system("cls");
            programa_ahorcado();
            break;
        case 5:
            system("cls");
            programa_batalla();
            break;
        }
        system("cls");
    }
    while(op!=6 && op!=3);
    Despedida();
}

void programa_gato()
{
    texto_gato();  /*Imprime el titulo del juego*/
    do /*El ciclo do while, repite el programa las veces que el jugador desee o se cierra o */
    {  /*regresa al menú o cierra completamente el juego.*/
        pf("\t---------------Bienvenido al juego *gato*---------------\n");
        pf("\tReglas:\n");
        pf("\t-Cada jugador tiene un s%cmbolo\n\t\t=Jugador 1 = X\n\t\t=Jugador 2 = O\n\t-En su turno deber%cn de elegir una casilla d%cnde tirar\n\t-El ganador ser%c aquel que logre tres seguidas ya sea en horizontal, vertical o diagonal\n\t",161,160,162,160);//Para elegir X o O deberás elegir bien tu numero de jugador.\n

        char matriz[3][3];  /*La matriz tipo char para tablero, es char para imprimir caracteres como X, O.*/
        int i,j,k=49, juegoVigente=1,posicion,turno=1;  /*K llena el tableros con las posiciones, inicia en 49 que en código ascii es "1". Turno se utiliza en caso de que haya empate*/
                                                        /*Juego vigente ayuda a verificar si algún jugador ya ganó. Posición indica en que casilla quiere tirar el jugador*/
                //Imprimir Tablero Incial
        pf("\n\tEl n%cmero de casillas estar%c dado por:",163,160);

        for(i=0; i<3; i++) /*Llena el tablero con el número de cada casilla en ascii*/
        {
            printf("\n\t\t");
            for(j=0; j<3; j++)
            {
                matriz[i][j]=k;
                k++;
                printf("[%c]",matriz[i][j]);
            }
        }
        pf("\n\n\t------------------------Comencemos------------------------\n");

        /*Se realiza un ciclo para todos los movimientos del juego hasta que un jugador gane.
          Este ciclo sirve para que se realicen los movimientos de ambos jugadores hasta que se tenga
          un ganador o se finalice el juego con ayuda de la variable "JuegoVigente" */
        do
        {

casilla1:  /*En caso de que el jugador de una casilla ya ocupada nos regresa a pedir nuevamente la casilla*/
            pf("\n\tJugador 1, indica el n%cmero de casilla donde deseas tirar: ",163);
            sf("%i",&posicion);

            switch(posicion)  /*Nos posiciona en la casilla seleccionada*/
            {
            case 1://Posición [0][0]
                while(matriz[0][0]==79 || matriz[0][0]==88)  /*While, nos indica que en caso de la casilla nos regrese a pedir la casilla.*/
                {
                    printf("\n\tLa casilla seleccionada ya est%c ocupada, tira en una distinta\n",160);
                    goto casilla1;
                }
                matriz[0][0]='X';  /*Si no está ocupada guarda el carácter en dicha casilla*/
                break;
            case 2://Posición [0][1]
                while(matriz[0][1]==79 || matriz[0][1]==88)
                {
                    printf("\n\tLa casilla seleccionada ya est%c ocupada, tira en una distinta\n",160);
                    goto casilla1;
                }
                matriz[0][1]='X';
                break;
            case 3://Posición [0][2]
                while(matriz[0][2]==79 || matriz[0][2]==88)
                {
                    printf("\n\tLa casilla seleccionada ya est%c ocupada, tira en una distinta\n",160);
                    goto casilla1;
                }
                matriz[0][2]='X';
                break;
            case 4://Posición [1][0]
                while(matriz[1][0]==79 || matriz[1][0]==88)
                {
                    printf("\n\tLa casilla seleccionada ya est%c ocupada, tira en una distinta\n",160);
                    goto casilla1;
                }
                matriz[1][0]='X';
                break;
            case 5://Posición [1][1]
                while(matriz[1][1]==79 || matriz[1][1]==88)
                {
                    printf("\n\tLa casilla seleccionada ya est%c ocupada, tira en una distinta\n",160);
                    goto casilla1;
                }
                matriz[1][1]='X';
                break;
            case 6://Posición [1][2]
                while(matriz[1][2]==79 || matriz[1][2]==88)
                {
                    printf("\n\tLa casilla seleccionada ya est%c ocupada, tira en una distinta\n",160);
                    goto casilla1;
                }
                matriz[1][2]='X';
                break;
            case 7://Posición [2][0]
                while(matriz[2][0]==79 || matriz[2][0]==88)
                {
                    printf("\n\tLa casilla seleccionada ya est%c ocupada, tira en una distinta\n",160);
                    goto casilla1;
                }
                matriz[2][0]='X';
                break;
            case 8://Posición [2][1]
                while(matriz[2][1]==79 || matriz[2][1]==88)
                {
                    printf("\n\tLa casilla seleccionada ya est%c ocupada, tira en una distinta\n",160);
                    goto casilla1;
                }
                matriz[2][1]='X';
                break;
            case 9://Posisción [2][2]
                while(matriz[2][2]==79 || matriz[2][2]==88)
                {
                    printf("\n\tLa casilla seleccionada ya est%c ocupada, tira en una distinta\n",160);
                    goto casilla1;
                }
                matriz[2][2]='X';
                break;

            default:

                    printf("\n\tValor incorrecto, ingresa de nuevo tu tiro\n");
                    goto casilla1;


            }
             /*Estas condiciones anidadas nos permiten verificar si ya ganó un jugador.*/
            if((matriz[0][0]==88 && matriz[0][1]==88 && matriz[0][2]==88 ) || (matriz[1][0]==88 && matriz[1][1]==88 && matriz[1][2]==88) || (matriz[2][0]==88 && matriz[2][1]==88 && matriz[2][2]=='X'))   //Verifica si se gana en alfuna fila
            {
                juegoVigente=0; /*En caso de que el jugador gane la variable cambie a 0"*/
                printf("\n\n\tFelicidades Jugador 1, has ganado el juego!\n");
            }
            else if((matriz[0][0]==88 && matriz[1][0]==88 && matriz[2][0]==88 ) || (matriz[0][1]==88 && matriz[1][1]==88 && matriz[2][1]==88) || (matriz[0][2]==88 && matriz[1][2]==88 && matriz[2][2]==88))     //Verifica si se gana en alguna columna
            {
                juegoVigente=0;
                printf("\n\n\tFelicidades Jugador 1, has ganado el juego!\n");
            }
            else if((matriz[0][0]==88 &&  matriz[1][1]==88 && matriz[2][2]==88) || (matriz[2][0]==88 &&  matriz[1][1]==88 && matriz[0][2]==88))     //Verifica si se gana en alguna diagonal
            {
                juegoVigente=0;
                printf("\n\n\tFelicidades Jugador 1, has ganado el juego!\n");
            }
            //Impresión del tablero con las posiciones de los caracteres
            printf("\t\t");
            for(i=0; i<3; i++)
            {
                for(j=0; j<3; j++)
                {
                    printf("[%c]",matriz[i][j]);
                }
                printf("\n\t\t");
            }
            /*En caso de ya se hayan jugado 9 turno y aún no haya ganador se significa que hubo un empate*/
            if(turno==9 && juegoVigente==1)
            {
                juegoVigente=0;
                printf("\n\tHan empatado!!");
            }
            turno++;/*Nos indican cuantos turnos se han jugado*/
            if(juegoVigente==1) /*En caso de que el jugador 1 no haya gano se pasa al turno del jugador 2*/
            {
casilla2:   /*Se realiza las instrucciones similares pero para el jugador 2*/
                pf("\n\tJugador 2, indica el n%cmero de casilla donde deseas tirar: ",163);
                sf("%i",&posicion);

                switch(posicion)
                {
                case 1://Posición [0][0]
                    while(matriz[0][0]==79 || matriz[0][0]==88)
                    {
                        printf("\n\tLa casilla seleccionada ya est%c ocupada, tira en una distinta\n",160);
                        goto casilla2;
                    }
                    matriz[0][0]=79;
                    break;
                case 2://Posición [0][1]
                    while(matriz[0][1]==79 || matriz[0][1]==88)
                    {
                        printf("\n\tLa casilla seleccionada ya est%c ocupada, tira en una distinta\n",160);
                        goto casilla2;
                    }
                    matriz[0][1]=79;
                    break;
                case 3://Posición [0][2]
                    while(matriz[0][2]==79 || matriz[0][2]==88)
                    {
                        printf("\n\tLa casilla seleccionada ya est%c ocupada, tira en una distinta\n",160);
                        goto casilla2;
                    }
                    matriz[0][2]=79;
                    break;
                case 4://Posición [1][0]
                    while(matriz[1][0]==79 || matriz[1][0]==88)
                    {
                        printf("\n\tLa casilla seleccionada ya est%c ocupada, tira en una distinta\n",160);
                        goto casilla2;
                    }
                    matriz[1][0]=79;
                    break;
                case 5://Posición [1][1]
                    while(matriz[1][1]==79 || matriz[1][1]==88)
                    {
                        printf("\n\tLa casilla seleccionada ya est%c ocupada, tira en una distinta\n",160);
                        goto casilla2;
                    }
                    matriz[1][1]=79;
                    break;
                case 6://Posición [1][2]
                    while(matriz[1][2]==79 || matriz[1][2]==88)
                    {
                        printf("\n\tLa casilla seleccionada ya est%c ocupada, tira en una distinta\n",160);
                        goto casilla2;
                    }
                    matriz[1][2]=79;
                    break;
                case 7://Posición [2][0]
                    while(matriz[2][0]==79 || matriz[2][0]==88)
                    {
                        printf("\n\tLa casilla seleccionada ya est%c ocupada, tira en una distinta\n",160);
                        goto casilla2;
                    }
                    matriz[2][0]=79;
                    break;
                case 8://Posición [2][1]
                    while(matriz[2][1]==79 || matriz[2][1]==88)
                    {
                        printf("\n\tLa casilla seleccionada ya est%c ocupada, tira en una distinta\n",160);
                        goto casilla2;
                    }
                    matriz[2][1]=79;
                    break;
                case 9://Posición [2][2]
                    while(matriz[2][2]==79 || matriz[2][2]==88)
                    {
                        printf("\n\tLa casilla seleccionada ya est%c ocupada, tira en una distinta\n",160);
                        goto casilla2;
                    }
                    matriz[2][2]=79;
                    break;

                default:

                    printf("\n\tValor incorrecto, ingresa de nuevo tu tiro\n");
                    goto casilla2;
                }


                if((matriz[0][0]==79 && matriz[0][1]==79 && matriz[0][2]==79 ) || (matriz[1][0]==79 && matriz[1][1]==79 && matriz[1][2]==79) || (matriz[2][0]==79 && matriz[2][1]==79 && matriz[2][2]==79))   //Verifica si se gana de alguna manera en las filas
                {
                    juegoVigente=0;
                    printf("\n\n\tFelicidades Jugador 2, has ganado el juego!\n");
                }
                else if((matriz[0][0]==79 && matriz[1][0]==79 && matriz[2][0]==79 ) || (matriz[0][1]==79 && matriz[1][1]==79 && matriz[2][1]==79) || (matriz[0][2]==79 && matriz[1][2]==79 && matriz[2][2]==79))     //Verifica si se gana en alguna manera en las columnas
                {
                    juegoVigente=0;
                    printf("\n\n\tFelicidades Jugador 2, has ganado el juego!\n");
                }
                else if((matriz[0][0]==79 &&  matriz[1][1]==79 && matriz[2][2]==79) || (matriz[2][0]==79 &&  matriz[1][1]==79 && matriz[0][2]==79))     //Verifica si se gana en alguna diagonal
                {
                    juegoVigente=0;
                    printf("\n\n\tFelicidades Jugador 2, has ganado el juego!\n");
                }
                //Impresion del tablero
                printf("\t\t");
                for(i=0; i<3; i++)
                {
                    for(j=0; j<3; j++)
                    {
                        printf("[%c]",matriz[i][j]);
                    }
                    printf("\n\t\t");
                }
                pf("\n");
            }
            turno++;
        }
        while(juegoVigente==1);  /*En caso de que un jugador gane o haya empate el valor de “juegoVigente” cambio a 0
                                  por lo que se rompe el ciclo. */
        dibujo_fin_gato();
        op=repetir_programa();   /*Pregunta si se desea repetir, ir al menú o salir del programa, mediante una función que nos */
    }                            /*regresa el valor de “op”)*/
    while(op==1);   /*Se repetirá el programa si se seleccionó repetir (op=1)*/
}

void programa_piedra()
{
    do /*El ciclo do while, repite el programa las veces que el jugador desee o se cierra o */
    {
        int j1, j2; /*Guarda la opción que escoje cada jugador*/
        texto_piedra();

        pf("\n\tReglas:\n\tLa piedra aplasta a la tijera. Gana la piedra");
        pf("\n\tLa tijera corta el papel. Gana la tijera\n");
        pf("\tEl papel envuelve la piedra. Gana el papel\n");
        pf("\n\tEn caso de empate -que dos jugadores elijan el mismo elemento- se juega otra vez\n");
        pf("\n\tJugador 1. Elige:\n\t1)Piedra\n\t2)Papel\n\t3)Tijera\n\t");
        sf("%d", &j1);
        while ((j1!=1)&&(j1!=2)&&(j1!=3)) /*Verifica que de una opción valida*/
        {
            pf("\n\tOpci%cn invalida,elige una valida\n\t",162);
            sf("%d", &j1);
        }
        //Esta funcion ayuda a limpiar la pantalla del ejecutable
        system("cls"); /*Limpia la pantalla para que el jugador 2 no vea lo que selecciono el jugador 1*/
        pf("\n\tJugador 2. Elige:\n\t1)Piedra\n\t2)Papel\n\t3)Tijera\n\t");
        sf("%d", &j2);
        while ((j2!=1)&&(j2!=2)&&(j2!=3)) /*Verifica que de una opción valida*/
        {
            pf("\n\tOpci%cn inv%clida, elige una v%clida\n\t",162,160,160);
            sf("%d", &j2);
        }
        /*Las condicones anidadas verifican que jugador gano o si hay empate*/
        if(((j1==1)&&(j2==1))||((j1==2)&&(j2==2))||((j1==3)&&(j2==3))) //Si hay empate
        {
            pf ("\n\tEmpate");
        }

        if(((j1==1)&&(j2==2)))
        {
            pf ("\n\tGana jugador 2 con papel\n");
            imprimeGanador(2);
        }

        if(((j1==1)&&(j2==3)))
        {
            pf ("\n\tGana jugador 1 con piedra\n");
            imprimeGanador(1);
        }

        if(((j1==2)&&(j2==1)))
        {
            pf ("\n\tGana jugador 1 con papel\n");
            imprimeGanador(2);
        }

        if(((j1==2)&&(j2==3)))
        {
            pf ("\n\tGana jugador 2 con tijera\n");
            imprimeGanador(3);
        }

        if(((j1==3)&&(j2==1)))
        {
            pf ("\n\tGana jugador 2 con piedra\n");
            imprimeGanador(1);
        }

        if(((j1==3)&&(j2==2)))
        {
            pf ("\n\tGana jugador 1 con tijera\n");
            imprimeGanador(3);
        }
        op=repetir_programa();  /*Pregunta si se desea repetir, ir al menú o salir del programa, mediante una función que nos */
    }                           /*regresa el valor de “op”)*/
    while(op==1);  /*Se repetirá el programa si se seleccionó repetir (op=1)*/
}

void imprimeGanador(int ganador)  /*Dependiendo de que opción gano se imprime dicha figura*/
{
    if (ganador==1)
    {
        pf("\n                                 ....                                 ");
        pf("\n                            /@@@@@@@@@@@@,                            ");
        pf("\n                %c@@@@@@@@@@@@@,        .@@@%c@@@@@@@#.                 ",37,37);
        pf("\n              %c@@&.      .&@@.           #@@/    .*@@@&               ",37);
        pf("\n             &@@,          /@@            &@.        &@@*             ");
        pf("\n            #@@/            &@(           *@#         (@@(.           ");
        pf("\n            @@@             /@&           .@&          @@@@@@@@*      ");
        pf("\n           .@@&             .@@           .@#          #@    /@@@,    ");
        pf("\n          /&@@&              ,(                        %c@      %c@@(   ",37,37);
        pf("\n      ,@@@@&&@&                                                 %c@@,  ",37);
        pf("\n    ,@@@(   (@@                                                 .@@&  ");
        pf("\n   (@@%c     ,@@                                                  %c@@. ",37,37);
        pf("\n  ,@@&       @@.                                                 (@@* ");
        pf("\n  &@@,       @@                       &@#         .              /@@( ");
        pf("\n  @@@        &@          ,@@&        .@@@        &@@.            /@@( ");
        pf("\n  @@@.                   ,@@@.        @@@.       %c@@(            (@@/ ",37);
        pf("\n  #@@#                   .@@@,        @@@.       %c@@*            #@@* ",37);
        pf("\n  .@@@                    @@@*        @@@        &@@.            %c@@. ",37);
        pf("\n   %c@@(                   %c@@/        @@@        @@@             @@@  ",37,37);
        pf("\n    @@@                   /@@#        @@@       *@@#            /@@(  ");
        pf("\n    ,@@&                  .@@&        @@&       %c@@.           .@@@   ",37);
        pf("\n     /@@%c                  &@@        @@&       @@%c            &@@,   ",37,37);
        pf("\n      /@@&                 /@@,       @@(      (@@.           &@@*    ");
        pf("\n       ,@@@,                @@/      .@@.      @@(          ,@@@.     ");
        pf("\n         %c@@&               #@%c      ,@@      /@@          @@@#       ",37,37);
        pf("\n           @@@@                                          @@@&         ");
        pf("\n             #@@@&.                                   #@@@(           ");
        pf("\n                (@@@@@%c*.                        .(@@@@@@%c            ",37,37);
        pf("\n                &@@     .                     ,%c#/.    .@@%c           ",37,37);
        pf("\n                @@@                                    @@@/           ");
        pf("\n                 @@@@*                             .%c@@@@             ",37);
        pf("\n                   .@@@@@@@@%c/,.         .*(@@@@@@@@@/                ",37);
        pf("\n                         .*%c&@@@@@@@@@@@@@@@&%c/                       ",37,37);

    }
    else if (ganador==2)
    {
        pf("\n                             .@@@@@@,                       ");
        pf("\n                            @@      %c@*                     ",37);
        pf("\n                           &@        &@/@@@@@@%c             ",37);
        pf("\n               ,@@@*.%c@@   @@        (@@      @@*           ",37);
        pf("\n              ,@@      #@%c @@        *@,       @@           ",37);
        pf("\n              *@%c       (@(@@        .@*       @@           ",37);
        pf("\n              .@@        @@@@        .@/       @@  .@@@@@(  ");
        pf("\n               @@         @@@         @*       @@ @@.    @@ ");
        pf("\n               ,@&        @@@        .@,       @@&@      .@@");
        pf("\n                @@        .@@        ,@        @@@#       @@");
        pf("\n                .@%c        @@        (@       ,@@@       .@@",37);
        pf("\n                 @@        &c@        %c@       (@@,      /@/",37,37);
        pf("\n  %c@@@@@@@&.     (@,       ,@        %c*       &@%c        @@ ",37,37,37);
        pf("\n @@        %c@&    @@                          %c/        #@/ ",37,37);
        pf("\n @@*         (@&  @@                                   ,@&  ");
        pf("\n  ,@@          @@ /@,                                  @@   ");
        pf("\n    (@@         %c@,@(                                 *@%c   ",37,37);
        pf("\n      @@,        /@@(      @%c      @@(      @(        (@(   ",37);
        pf("\n       %c@(                 @@      @@%c      @@        #@/   ",37,37);
        pf("\n        @@.                @@.     &@%c      @@        &@.   ",37);
        pf("\n         @@                @@*     %c@%c      @&        @@    ",37);
        pf("\n          @@               &@(     %c@(     (@*       (@(    ",37);
        pf("\n          (@(              *@#     &@,     @@        @@     ");
        pf("\n           %c@*              @&     @@      @(       @@.     ",37);
        pf("\n            #@#             @@     @@     @@       @@       ");
        pf("\n              @@,           (/     /.     %c      /@@        ",37);
        pf("\n                &@@.                           (@@          ");
        pf("\n                  @@/#@@                  *@@@@%c            ",37);
        pf("\n                  @@                          @@            ");
        pf("\n                   @@@%c,                   (@@@             ",37);
        pf("\n                       ,#@@@@@@@@@@@@@@@@@(.                ");

    }
    else if (ganador==3)
    {
        pf("\n                           .@@@@@@,                ");
        pf("\n         ,@@@@@@&         @@.     @@               ");
        pf("\n        @@*     &@(     *@&       (@(              ");
        pf("\n       (@#       @@.    @@        %c@*              ",37);
        pf("\n       %c@*        @@   &@         @@               ",37);
        pf("\n       #@(        @@.  @&         @@               ");
        pf("\n       .@@         @@ (@,        &@,               ");
        pf("\n        &@,        &@,&@         @@                ");
        pf("\n         @@         @@@@        .@%                ");
        pf("\n         #@/        (@@&        @@@@@@@(           ");
        pf("\n          @@         @@#        @#     &@(         ");
        pf("\n          (@*        .@#        @.      %c&/&@@%c    ",37,37);
        pf("\n           @@         (#        @       %c%c    @@/  ",37,37);
        pf("\n        ,@@@@                                  @@  ");
        pf("\n     ,@@%c   @%c                                 @@. ",37,37);
        pf("\n    @@/     @@                                 @@* ");
        pf("\n   @@*      /@      ,@,     .@@       .        @@* ");
        pf("\n   @@        @      #@@      @@      &@*       @@. ");
        pf("\n   @@               ,@@      @@      @@.       @@  ");
        pf("\n   @@.               @@      @@      @@        @@ ");
        pf("\n   /@@               @@.     @@      @%c       &@# ",37);
        pf("\n    @@,              &@,     @@     %c@.      .@@  ",37);
        pf("\n     @@              (@*    .@&     @%c       @@   ",37);
        pf("\n      @@.            .@*    ,@.    @@      .@@    ");
        pf("\n       &@%c            *      ,    /&      @@&     ",37);
        pf("\n         &@&                            @@&       ");
        pf("\n           ,@@@(                    (@@@(         ");
        pf("\n           ,@%c                         #@/        ",37);
        pf("\n            /@@#                     #@@#         ");
        pf("\n               .#@@@@@@@@@@@@@@@@@@@(.            ");
    }
}

void programa_trivia()
{
    texto_trivia();
    do  /*El ciclo do while, repite el programa las veces que el jugador desee o se cierra o */
    {
        int trivia,c=0; /*Trivia guarda la opcion de quje trivia se quiere jugar. "c" es un contador que nos va contando los aciertos obtenidos*/
        char r;  /*Guarda la respuesta dada*/


        pf("\n\n\tCategorias:\n");
        pf("\t1)Historia\n");
        pf("\t2)Entretenimiento\n");
        pf("\t3)Ciencias\n");
        pf("\t4)Artes\n");

inicioTrivia:
            pf("\tOpci%cn: ",162);
            sf("%d",&trivia);
            fflush(stdin);

        switch (trivia) //Nos lleva a la trivia seleccionada
        {

        case 1:
            pf("\n\t========================Trivia de Historia========================");
            pf("\n\tRecuerde dar sus respuestas en may%csculas\n",163);
            //==============================PREGUNTA 1==============================
            pf ("\n\n\t1. %cEn qu%c a%co lleg%c Crist%cbal Col%cn a Am%crica?\n",168,130,164,162,162,162,130);
            pf ("\t\tA) 1492 \n\t\tB) 1502 \n\t\tC) 1496 \n\t\tD) 1488 ");
            pf ("\n\tElecci%cn: ",162);
            sf("%c",&r);
            fflush(stdin);
            while(r!=65 && r!=66 && r!=67 && r!=68) /*Verifica que se haya dado una opción válida*/
            {
                pf ("\tOpci%cn no v%clida, ingresa una v%clida (A,B,C,D): ",162,160,160);
                pf ("\n\tElecci%cn: ",162);
                sf("%c",&r);
                fflush(stdin);

            }
            if(r==65) /*Compara la respuesta dada por el usuario con la correcta*/
            {   /*Si es correcta lo indica y aumenta el número de aciertos*/
                pf ("\tRespuesta correcta\n");
                c++;
            }
            else
            {   /*Si es incorrecta lo indica y nos muestra la respuesta correcta*/
                pf ("\tRespuesta incorrecta");
                pf ("\n\tLa respuesta correcta era la opci%cn: A) 1492\n",162);
            }
            //==============================PREGUNTA 2==============================  //Se realiza la misma estructura para las todas preguntas
            pf ("\n\t2. %cC%cmo se llamaba el primer presidente de los Estados Unidos?\n",168,162);
            pf ("\t\tA) John Adams \n\t\tB) George Washington \n\t\tC) Abraham Lincoln \n\t\tD) Thomas Jefferson ");
            pf ("\n\tElecci%cn: ",162);
            sf("%c",&r);
            fflush(stdin);
            while(r!=65 && r!=66 && r!=67 && r!=68)
            {
                pf ("\tOpci%cn no v%clida, ingresa una v%clida (A,B,C,D): ",162,160,160);
                pf ("\n\tElecci%cn: ",162);
                sf("%c",&r);
                fflush(stdin);

            }
            if(r==66)
            {
                pf ("\tRespuesta correcta\n");
                c++;
            }
            else
            {
                pf ("\tRespuesta incorrecta");
                pf ("\n\tLa respuesta correcta era la opci%cn: B) George Washington\n",162);
            }
            //==============================PREGUNTA 3==============================
            pf ("\n\t3. %cQu%c se celebra el 5 de mayo en M%cxico?\n",168,130,130);
            pf ("\t\tA) La Revoluci%cn Mexicana \n\t\tB) La Batalla de Puebla \n\t\tC) La Independencia de M%cxico \n\t\tD) El D%ca de Muertos ",162,130,161);
            pf ("\n\tElecci%cn: ",162);
            sf("%c",&r);
            fflush(stdin);
            while(r!=65 && r!=66 && r!=67 && r!=68)
            {
                pf ("\tOpci%cn no v%clida, ingresa una v%clida (A,B,C,D): ",162,160,160);
                pf ("\n\tElecci%cn: ",162);
                sf("%c",&r);
                fflush(stdin);

            }
            if(r==66)
            {
                pf ("\tRespuesta correcta\n");
                c++;
            }
            else
            {
                pf ("\tRespuesta incorrecta");
                pf ("\n\tLa respuesta correcta era la opci%cn: B) La Batalla de Puebla\n",162);
            }
            //==============================PREGUNTA 4==============================
            pf ("\n\t4. %cQu%c ciudad fundaron los aztecas?\n",168,130);
            pf ("\t\tA) Monte Alb%cn \n\t\tB) Palenque \n\t\tC) Chich%cn Itz%c \n\t\tD) Tenochtitl%cn ",160,130,160,160);
            pf ("\n\tElecci%cn: ",162);
            sf("%c",&r);
            fflush(stdin);
            while(r!=65 && r!=66 && r!=67 && r!=68)
            {
                pf ("\tOpci%cn no v%clida, ingresa una v%clida (A,B,C,D): ",162,160,160);
                pf ("\n\tElecci%cn: ",162);
                sf("%c",&r);
                fflush(stdin);
            }
            if(r==68)
            {
                pf ("\tRespuesta correcta\n");
                c++;
            }
            else
            {
                pf ("\tRespuesta incorrecta");
                pf ("\n\tLa respuesta correcta era la opci%cn: D) Tenochtitl%cn\n",162,160);
            }
            //==============================PREGUNTA 5==============================
            pf ("\n\t5. %cQu%c conflicto finaliz%c tras la firma del %cTratado de Versalles%c?\n",168,130,162,34,34);
            pf ("\t\tA) La Revoluci%cn Francesa \n\t\tB) La Guerra de los Cien A%cos \n\t\tC) La Primera Guerra Mundial \n\t\tD) La Revoluci%cn Industrial ",162,164,162);
            pf ("\n\tElecci%cn: ",162);
            sf("%c",&r);
            fflush(stdin);
            while(r!=65 && r!=66 && r!=67 && r!=68)
            {
                pf ("\tOpci%cn no v%clida, ingresa una v%clida (A,B,C,D): ",162,160,160);
                pf ("\n\tElecci%cn: ",162);
                sf("%c",&r);
                fflush(stdin);
            }
            if(r==67)
            {
                pf ("\tRespuesta correcta\n");
                c++;
            }
            else
            {
                pf ("\tRespuesta incorrecta");
                pf ("\n\tLa respuesta correcta era la opci%cn: C) La Primera Guerra Mundial\n",162);
            }
            //==============================PREGUNTA 6==============================
            pf ("\n\t6. %cCu%cnto dura el mandato de un presidente en M%cxico?\n",168,160,130);
            pf ("\t\tA) 4 a%cos \n\t\tB) 6 a%cos \n\t\tC) 3 a%cos \n\t\tD) 7 a%cos ",164,164,164,164);
            pf ("\n\tElecci%cn: ",162);
            sf("%c",&r);
            fflush(stdin);
            while(r!=65 && r!=66 && r!=67 && r!=68)
            {
                pf ("\tOpci%cn no v%clida, ingresa una v%clida (A,B,C,D): ",162,160,160);
                pf ("\n\tElecci%cn: ",162);
                sf("%c",&r);
                fflush(stdin);
            }
            if(r==66)
            {
                pf ("\tRespuesta correcta\n");
                c++;
            }
            else
            {
                pf ("\tRespuesta incorrecta");
                pf ("\n\tLa respuesta correcta era la opci%cn: B) 6 a%cos\n",162,164);
            }
            //==============================PREGUNTA 7==============================
            pf ("\n\t7. %cA qui%cn se le atribuye el lema %cSufragio efectivo, no reelecci%cn%c?\n",168,130,34,162,34);
            pf ("\t\tA) Emiliano Zapata \n\t\tB) Benito Ju%crez \n\t\tC) Francisco I. Madero \n\t\tD) Venustiano Carranza ",160);
            pf ("\n\tElecci%cn: ",162);
            sf("%c",&r);
            fflush(stdin);
            while(r!=65 && r!=66 && r!=67 && r!=68)
            {
                pf ("\tOpci%cn no v%clida, ingresa una v%clida (A,B,C,D): ",162,160,160);
                pf ("\n\tElecci%cn: ",162);
                sf("%c",&r);
                fflush(stdin);

            }
            if(r==67)
            {
                pf ("\tRespuesta correcta\n");
                c++;
            }
            else
            {
                pf ("\tRespuesta incorrecta");
                pf ("\n\tLa respuesta correcta era la opci%cn: C) Francisco I. Madero\n",162);
            }
            //==============================PREGUNTA 8==============================
            pf ("\n\t8. %cCu%cl fue el primer hombre en ir a la luna?\n",168,160);
            pf ("\t\tA) Louis Armstrong \n\t\tB) Neil Armstrong \n\t\tC) Michael Armstrong \n\t\tD) Lance Armstrong ");
            pf ("\n\tElecci%cn: ",162);
            sf("%c",&r);
            fflush(stdin);
            while(r!=65 && r!=66 && r!=67 && r!=68)
            {
                pf ("\tOpci%cn no v%clida, ingresa una v%clida (A,B,C,D): ",162,160,160);
                pf ("\n\tElecci%cn: ",162);
                sf("%c",&r);
                fflush(stdin);
            }
            if(r==66)
            {
                pf ("\tRespuesta correcta\n");
                c++;
            }
            else
            {
                pf ("\tRespuesta incorrecta");
                pf ("\n\tLa respuesta correcta era la opci%cn: B) Neil Armstrong\n",162);
            }
            //==============================PREGUNTA 9==============================
            pf ("\n\t9. %cQu%c sistema pol%ctico predomin%c en la Europa Occidental de la Edad Media?\n",168,130,161,162);
            pf ("\t\tA) Capitalismo \n\t\tB) Comunismo \n\t\tC) Feudalismo \n\t\tD) Socialismo ");
            pf ("\n\tElecci%cn: ",162);
            sf("%c",&r);
            fflush(stdin);
            while(r!=65 && r!=66 && r!=67 && r!=68)
            {
                pf ("\tOpci%cn no v%clida, ingresa una v%clida (A,B,C,D): ",162,160,160);
                pf ("\n\tElecci%cn: ",162);
                sf("%c",&r);
                fflush(stdin);

            }
            if(r==67)
            {
                pf ("\tRespuesta correcta\n");
                c++;
            }
            else
            {
                pf ("\tRespuesta incorrecta");
                pf ("\n\tLa respuesta correcta era la opci%cn: C) Feudalismo\n",162);
            }
            //==============================PREGUNTA 10==============================
            pf ("\n\t10. %cQui%cn fue el %cltimo emperador mexica?\n",168,130,163);
            pf ("\t\tA) Cuauht%cmoc \n\t\tB) Moctezuma \n\t\tC) Nezahualc%cyotl \n\t\tD) Cuitl%chuac ",130,162,160);
            pf ("\n\tElecci%cn: ",162);
            sf("%c",&r);
            fflush(stdin);
            while(r!=65 && r!=66 && r!=67 && r!=68)
            {
                pf ("\tOpci%cn no v%clida, ingresa una v%clida (A,B,C,D): ",162,160,160);
                pf ("\n\tElecci%cn: ",162);
                sf("%c",&r);
                fflush(stdin);
            }
            if(r==65)
            {
                pf ("\tRespuesta correcta\n");
                c++;
            }
            else
            {
                pf ("\tRespuesta incorrecta");
                pf ("\n\tLa respuesta correcta era la opci%cn: A) Cuauht%cmoc\n",162,130);
            }
            pf("Tus aciertos son: %d",c); //Imprime la cantidad de aciertos obtenidos
            /*Dependiendo de la cantidad de aciertos se envia como argumento la cantidad de aciertos y en función de esto se imprime una estrella*/
            /*Ya sea triste feliz y triste o serie*/
            if (c>7)
            {
                ImprimirEstrella(1);
            }
            else if (c==6 || c==7)
            {
                ImprimirEstrella(2);
            }
            else if (c<=5)
            {
                ImprimirEstrella(3);
            }
            break;
        //Se realiza la misma estructura para todas las trivias
        case 2:
            pf("\t========================Trivia de Entretenimiento=======================");
            pf("\n\tRecuerde dar sus respuestas en may%csculas\n",163);
            //==============================PREGUNTA 1==============================
            printf ("\n\n\t1. %cCu%cl fue la primera pel%ccula de Walt Disney?\n",168,160,161);
            printf ("\t\tA) Blancanieves y los siete enanitos \n\t\tB) Cenicienta \n\t\tC) Pinocho \n\t\tD) Dumbo ");
            printf ("\n\tElecci%cn: ",162);
            scanf("%c",&r);
            fflush(stdin);
            while(r!=65 && r!=66 && r!=67 && r!=68)
            {
                printf ("\n\tOpci%cn no v%clida, ingresa una v%clida (A,B,C,D): ",162,160,160);
                printf ("\n\tElecci%cn: ",162);
                scanf("%c",&r);
                fflush(stdin);
            }
            if(r==65)
            {
                printf ("\tRespuesta correcta\n");
                c++;
            }
            else
            {
                printf ("\tRespuesta incorrecta");
                printf ("\n\tLa respuesta correcta era la opci%cn: A) Blancanieves y los siete enanitos\n",162);
            }
            //==============================PREGUNTA 2==============================
            printf ("\n\n\t2. %cQu%c vengador usa un martillo?\n",168,130);
            printf ("\t\tA) Capit%cn Am%crica \n\t\tB) Hulk \n\t\tC) Thor \n\t\tD) Iron man ",160,130);
            printf ("\n\tElecci%cn: ",162);
            scanf("%c",&r);
            fflush(stdin);
            while(r!=65 && r!=66 && r!=67 && r!=68)
            {
                printf ("\n\tOpci%cn no v%clida, ingresa una v%clida (A,B,C,D): ",162,160,160);
                printf ("\n\tElecci%cn: ",162);
                scanf("%c",&r);
                fflush(stdin);
            }
            if(r==67)
            {
                printf ("\tRespuesta correcta\n");
                c++;
            }
            else
            {
                printf ("\tRespuesta incorrecta");
                printf ("\n\tLa respuesta correcta era la opci%cn: C) Thor\n",162);
            }
            //==============================PREGUNTA 3==============================
            printf ("\n\n\t3. %cQu%c personaje de pel%cculas dijo la famosa frase -Yo soy tu padre-?\n",168,130,161);
            printf ("\t\tA) Han Solo \n\t\tB) Darth Maul \n\t\tC) Anakyn Sywalker \n\t\tD) Darth Vader ");
            printf ("\n\tElecci%cn: ",162);
            scanf("%c",&r);
            fflush(stdin);
            while(r!=65 && r!=66 && r!=67 && r!=68)
            {
                printf ("\n\tOpci%cn no v%clida, ingresa una v%clida (A,B,C,D): ",162,160,160);
                printf ("\n\tElecci%cn: ",162);
                scanf("%c",&r);
                fflush(stdin);
            }
            if(r==68)
            {
                printf ("\tRespuesta correcta\n");
                c++;
            }
            else
            {
                printf ("\tRespuesta incorrecta");
                printf ("\n\tLa respuesta correcta era la opci%cn: D) Darth Vader\n",162);
            }
            //==============================PREGUNTA 4==============================
            printf ("\n\n\t4. En las pel%cculas de Harry Potter, %cQu%c utilizaban principalmente para hacer magia?\n",161,168,130);
            printf ("\t\tA) Polvos m%cgicos \n\t\tB) La mente \n\t\tC) Una varita \n\t\tD) Poderes m%cgicos ",160,160);
            printf ("\n\tElecci%cn: ",162);
            scanf("%c",&r);
            fflush(stdin);
            while(r!=65 && r!=66 && r!=67 && r!=68)
            {
                printf ("\n\tOpci%cn no v%clida, ingresa una v%clida (A,B,C,D): ",162,160,160);
                printf ("\n\tElecci%cn: ",162);
                scanf("%c",&r);
                fflush(stdin);
            }
            if(r==67)
            {
                printf ("\tRespuesta correcta\n");
                c++;
            }
            else
            {
                printf ("\tRespuesta incorrecta");
                printf ("\n\tLa respuesta correcta era la opci%cn: C) Una varita\n",162);
            }
            //===================PREGUNTA 5==============================
            printf ("\n\n\t5. %cA qui%cn se considera el rey del pop?\n",168,130);
            printf ("\t\tA) Justin Bieber  \n\t\tB) Michael Jackson \n\t\tC) Zac Efron \n\t\tD) Zayn Malik ");
            printf ("\n\tElecci%cn: ",162);
            scanf("%c",&r);
            fflush(stdin);
            while(r!=65 && r!=66 && r!=67 && r!=68)
            {
                printf ("\n\tOpci%cn no v%clida, ingresa una v%clida (A,B,C,D): ",162,160,160);
                printf ("\n\tElecci%cn: ",162);
                scanf("%c",&r);
                fflush(stdin);
            }
            if(r==66)
            {
                printf ("\tRespuesta correcta\n");
                c++;
            }
            else
            {
                printf ("\tRespuesta incorrecta");
                printf ("\n\tLa respuesta correcta era la opci%cn: B) Michael Jackson\n",162);
            }

            //==============================PREGUNTA 6==============================
            printf ("\n\n\t6. %cCu%cntas personas formaron parte del elenco principal del exitoso programa de televisi%cn Friends?\n",168,160,162);
            printf ("\t\tA) 6 \n\t\tB) 7 \n\t\tC) 5\n\t\tD) 8");
            printf ("\n\tElecci%cn: ",162);
            scanf("%c",&r);
            fflush(stdin);
            while(r!=65 && r!=66 && r!=67 && r!=68)
            {
                printf ("\n\tOpci%cn no v%clida, ingresa una v%clida (A,B,C,D): ",162,160,160);
                printf ("\n\tElecci%cn: ",162);
                scanf("%c",&r);
                fflush(stdin);
            }
            if(r==65)
            {
                printf ("\tRespuesta correcta\n");
                c++;
            }
            else
            {
                printf ("\tRespuesta incorrecta");
                printf ("\n\tLa respuesta correcta era la opci%cn: A) 6\n",162);
            }
            //==============================PREGUNTA 7==============================
            printf ("\n\n\t7. %cQui%cn es la mascota de SEGA?\n",168,130);
            printf ("\t\tA) Mario Bros\n\t\tB) Pac Man\n\t\tC) Sonic\n\t\tD) Ryu");
            printf ("\n\tElecci%cn: ",162);
            scanf("%c",&r);
            fflush(stdin);
            while(r!=65 && r!=66 && r!=67 && r!=68)
            {
                printf ("\n\tOpci%cn no v%clida, ingresa una v%clida (A,B,C,D): ",162,160,160);
                printf ("\n\tElecci%cn: ",162);
                scanf("%c",&r);
                fflush(stdin);
            }
            if(r==67)
            {
                printf ("\tRespuesta correcta\n");
                c++;
            }
            else
            {
                printf ("\tRespuesta incorrecta");
                printf ("\n\tLa respuesta correcta era la opci%cn: C) Sonic\n",162);
            }
            //==============================PREGUNTA 8==============================
            printf ("\n\n\t8. %cQu%c personaje se hizo famoso por su ic%cnica frase %cQu%c hay de nuevo, viejo%c?\n",168,130,162,34,130,34);
            printf ("\t\tA) Piolin\n\t\tB) El pato Lucas\n\t\tC) El correcaminos\n\t\tD) Bugs Bunny");
            printf ("\n\tElecci%cn: ",162);
            scanf("%c",&r);
            fflush(stdin);
            while(r!=65 && r!=66 && r!=67 && r!=68)
            {
                printf ("\n\tOpci%cn no v%clida, ingresa una v%clida (A,B,C,D): ",162,160,160);
                printf ("\n\tElecci%cn: ",162);
                scanf("%c",&r);
                fflush(stdin);
            }
            if(r==68)
            {
                printf ("\tRespuesta correcta\n");
                c++;
            }
            else
            {
                printf ("\tRespuesta incorrecta");
                printf ("\n\tLa respuesta correcta era la opci%cn: D) Bugs Bunny\n",162);
            }
            //==============================PREGUNTA 9==============================
            printf ("\n\n\t9. %cA qu%c familia pertenece Dobby, el elfo dom%cstico en la historia de Harry Potter?\n",168,130,130);
            printf ("\t\tA) Weasly\n\t\tB) Potter\n\t\tC) Malfoy\n\t\tD) Black");
            printf ("\n\tElecci%cn: ",162);
            scanf("%c",&r);
            fflush(stdin);
            while(r!=65 && r!=66 && r!=67 && r!=68)
            {
                printf ("\n\tOpci%cn no v%clida, ingresa una v%clida (A,B,C,D): ",162,160,160);
                printf ("\n\tElecci%cn: ",162);
                scanf("%c",&r);
                fflush(stdin);
            }
            if(r==67)
            {
                printf ("\tRespuesta correcta\n");
                c++;
            }
            else
            {
                printf ("\tRespuesta incorrecta");
                printf ("\n\tLa respuesta correcta era la opci%cn: C) Malfoy \n",162);
            }
            //==============================PREGUNTA 10==============================
            printf ("\n\n\t10. %cC%cmo se llamaba el cantante de Queen?\n",168,162);
            printf ("\t\tA) Freddie Mercury \n\t\tB) Phill Collins \n\t\tC) Robert Plant\n\t\tD) Kurt Cobain");
            printf ("\n\tElecci%cn: ",162);
            scanf("%c",&r);
            fflush(stdin);
            while(r!=65 && r!=66 && r!=67 && r!=68)
            {
                printf ("\n\tOpci%cn no v%clida, ingresa una v%clida (A,B,C,D): ",162,160,160);
                printf ("\n\tElecci%cn: ",162);
                scanf("%c",&r);
                fflush(stdin);
            }
            if(r==65)
            {
                printf ("\tRespuesta correcta\n");
                c++;
            }
            else
            {
                printf ("\tRespuesta incorrecta");
                printf ("\n\tLa respuesta correcta era la opci%cn: A) Freddie Mercury\n",162);
            }

            pf("\nTus aciertos son: %d",c);
            if (c>7)
            {
                ImprimirEstrella(1);
            }
            else if (c==6 || c==7)
            {
                ImprimirEstrella(2);
            }
            else if (c<=5)
            {
                ImprimirEstrella(3);
            }
            break;

        case 3:

            pf("\t========================Trivia de Ciencias========================");
            pf("\n\tRecuerde dar sus respuestas en may%csculas\n",163);
            //==============================PREGUNTA 1==============================
            printf ("\n\n\t1. %cQui%cn es el creador de la famosa empresa Apple?",168,130);
            printf ("\n\t\tA) Mark Zuckeberg \n\t\tB) Bill Gates \n\t\tC) Larry Pages  \n\t\tD) Steve Jobs");
            printf ("\n\tElecci%cn: ",162);
            scanf("%c",&r);
            fflush(stdin);
            while(r!=65 && r!=66 && r!=67 && r!=68)
            {
                printf ("\n\tOpci%cn no v%clida, ingresa una v%clida (A,B,C,D): ",162,160,160);
                printf ("\n\tElecci%cn: ",162);
                scanf("%c",&r);
                fflush(stdin);
            }
            if(r==68)
            {
                printf ("\tRespuesta correcta\n");
                c++;
            }
            else
            {
                printf ("\tRespuesta incorrecta");
                printf ("\n\tLa respuesta correcta era la opci%cn: D) Steve Jobs\n",162);
            }
            //==============================PREGUNTA 2==============================
            printf ("\n\t2. %cCu%cl de estos animales no es mam%cfero?",168,160,161);
            printf ("\n\t\tA) Ballena \n\t\tB) Delf%cn \n\t\tC) Perro \n\t\tD) Gallina ",161);
            printf ("\n\tElecci%cn: ",162);
            scanf("%c",&r);
            fflush(stdin);
            while(r!=65 && r!=66 && r!=67 && r!=68)
            {
                printf ("\n\tOpci%cn no v%clida, ingresa una v%clida (A,B,C,D): ",162,160,160);
                printf ("\n\tElecci%cn: ",162);
                scanf("%c",&r);
                fflush(stdin);
            }
            if(r==68)
            {
                printf ("\tRespuesta correcta\n");
                c++;
            }
            else
            {
                printf ("\tRespuesta incorrecta");
                printf ("\n\tLa respuesta correcta era la opci%cn: D) Gallina\n",162);
            }
            //==============================PREGUNTA 3==============================
            printf ("\n\t3. %cQu%c tipo de carga tienen los electrones?",168,130);
            printf ("\n\t\tA) No tiene carga \n\t\tB) Carga positiva \n\t\tC) Carga negativa \n\t\tD) Carga neutra ");
            printf ("\n\tElecci%cn: ",162);
            scanf("%c",&r);
            fflush(stdin);
            while(r!=65 && r!=66 && r!=67 && r!=68)
            {
                printf ("\n\tOpci%cn no v%clida, ingresa una v%clida (A,B,C,D): ",162,160,160);
                printf ("\n\tElecci%cn: ",162);
                scanf("%c",&r);
                fflush(stdin);
            }
            if(r==67)
            {
                printf ("\tRespuesta correcta\n");
                c++;
            }
            else
            {
                printf ("\tRespuesta incorrecta");
                printf ("\n\tLa respuesta correcta era la opci%cn: C) Carga negativa\n",162);
            }
            //==============================PREGUNTA 4==============================
            printf ("\n\t4. %cEn qu%c direcci%cn apunta la aguja de una br%cjula?\n",168,130,162,163);
            printf ("\t\tA) Sur\n\t\tB) Norte\n\t\tC) Este\n\t\tD) Oeste");
            printf ("\n\tElecci%cn: ",162);
            scanf("%c",&r);
            fflush(stdin);
            while(r!=65 && r!=66 && r!=67 && r!=68)
            {
                printf ("\n\tOpci%cn no v%clida, ingresa una v%clida (A,B,C,D): ",162,160,160);
                printf ("\n\tElecci%cn: ",162);
                scanf("%c",&r);
                fflush(stdin);
            }
            if(r==66)
            {
                printf ("\tRespuesta correcta\n");
                c++;
            }
            else
            {
                printf ("\tRespuesta incorrecta");
                printf ("\n\tLa respuesta correcta era la opci%cn: B) Norte\n",162);
            }
            //==============================PREGUNTA 5==============================
            printf ("\n\t5. %cCu%cntos d%cas tarda la Tierra en dar la vuelta al Sol?\n",168,160,161);
            printf ("\t\tA) 34 d%cas\n\t\tB) 350 d%cas\n\t\tC) 165 d%cas\n\t\tD) 365 d%cas",161,161,161,161);
            printf ("\n\tElecci%cn: ",162);
            scanf("%c",&r);
            fflush(stdin);
            while(r!=65 && r!=66 && r!=67 && r!=68)
            {
                printf ("\n\tOpci%cn no v%clida, ingresa una v%clida (A,B,C,D): ",162,160,160);
                printf ("\n\tElecci%cn: ",162);
                scanf("%c",&r);
                fflush(stdin);
            }
            if(r==68)
            {
                printf ("\tRespuesta correcta\n");
                c++;
            }
            else
            {
                printf ("\tRespuesta incorrecta");
                printf ("\n\tLa respuesta correcta era la opci%cn: D) 365 d%cas\n",162);
            }
            //==============================PREGUNTA 6==============================
            printf ("\n\t6. El Sol es...\n");
            printf ("\t\tA) Una estrella\n\t\tB) Un planeta\n\t\tC) Un sat%clite\n\t\tD) Un cometa",130);
            printf ("\n\tElecci%cn: ",162);
            scanf("%c",&r);
            fflush(stdin);
            while(r!=65 && r!=66 && r!=67 && r!=68)
            {
                printf ("\n\tOpci%cn no v%clida, ingresa una v%clida (A,B,C,D): ",162,160,160);
                printf ("\n\tElecci%cn: ",162);
                scanf("%c",&r);
                fflush(stdin);
            }
            if(r==65)
            {
                printf ("\tRespuesta correcta\n");
                c++;
            }
            else
            {
                printf ("\tRespuesta incorrecta");
                printf ("\n\tLa respuesta correcta era la opci%cn: A) Una estrella\n",162);
            }
            //==============================PREGUNTA 7==============================
            printf ("\n\t7. Es el componente m%cnimo de los seres vivos:\n",161);
            printf ("\t\tA) Tejido\n\t\tB) Part%cculas\n\t\tC) %ctomo\n\t\tD) C%clula",161,181,130);
            printf ("\n\tElecci%cn: ",162);
            scanf("%c",&r);
            fflush(stdin);
            while(r!=65 && r!=66 && r!=67 && r!=68)
            {
                printf ("\n\tOpci%cn no v%clida, ingresa una v%clida (A,B,C,D): ",162,160,160);
                printf ("\n\tElecci%cn: ",162);
                scanf("%c",&r);
                fflush(stdin);
            }
            if(r==68)
            {
                printf ("\tRespuesta correcta\n");
                c++;
            }
            else
            {
                printf ("\tRespuesta incorrecta");
                printf ("\n\tLa respuesta correcta era la opci%cn: D) C%clula\n",162,130);
            }
            //==============================PREGUNTA 8==============================
            printf ("\n\t8. %cC%cmo se llama el cient%cfico que descubri%c la penicilina?\n",168,162,161,162);
            printf ("\t\tA) Walter Scott\n\t\tB) Alexander Fleming\n\t\tC) Edward Jenner\n\t\tD) Dwayne Johnson");
            printf ("\n\tElecci%cn: ",162);
            scanf("%c",&r);
            fflush(stdin);
            while(r!=65 && r!=66 && r!=67 && r!=68)
            {
                printf ("\n\tOpci%cn no v%clida, ingresa una v%clida (A,B,C,D): ",162,160,160);
                printf ("\n\tElecci%cn: ",162);
                scanf("%c",&r);
                fflush(stdin);
            }
            if(r==66)
            {
                printf ("\tRespuesta correcta\n");
                c++;
            }
            else
            {
                printf ("\tRespuesta incorrecta");
                printf ("\n\tLa respuesta correcta era la opci%cn: B) Alexander Fleming\n",162);
            }
            //==============================PREGUNTA 9==============================
            printf ("\n\t9. %cQu%c contiene el n%ccleo de una c%clula?\n",168,130,163,130);
            printf ("\t\tA) Mitocondrias\n\t\tB) ADN\n\t\tC) Citoplasma\n\t\tD) Ribosomas");
            printf ("\n\tElecci%cn: ",162);
            scanf("%c",&r);
            fflush(stdin);
            while(r!=65 && r!=66 && r!=67 && r!=68)
            {
                printf ("\n\tOpci%cn no v%clida, ingresa una v%clida (A,B,C,D): ",162,160,160);
                printf ("\n\tElecci%cn: ",162);
                scanf("%c",&r);
                fflush(stdin);
            }
            if(r==66)
            {
                printf ("\tRespuesta correcta\n");
                c++;
            }
            else
            {
                printf ("\tRespuesta incorrecta");
                printf ("\n\tLa respuesta correcta era la opci%cn: B) ADN\n\n",162);
            }
            //==============================PREGUNTA 10==============================
            printf ("\n\t10. %cCu%cntos cromosomas tiene una c%clula humana?\n",168,160,130);
            printf ("\t\tA) 13 pares\n\t\tB) 53 pares\n\t\tC) 23 pares\n\t\tD) 25 pares");
            printf ("\n\tElecci%cn: ",162);
            scanf("%c",&r);
            fflush(stdin);
            while(r!=65 && r!=66 && r!=67 && r!=68)
            {
                printf ("\n\tOpci%cn no v%clida, ingresa una v%clida (A,B,C,D): ",162,160,160);
                printf ("\n\tElecci%cn: ",162);
                scanf("%c",&r);
                fflush(stdin);
            }
            if(r==67)
            {
                printf ("\tRespuesta correcta\n");
                c++;
            }
            else
            {
                printf ("\tRespuesta incorrecta");
                printf ("\n\tLa respuesta correcta era la opci%cn: C) 23 pares\n",162);
            }
            pf("\nTus aciertos son: %d",c);
            if (c>7)
            {
                ImprimirEstrella(1);
            }
            else if (c==6 || c==7)
            {
                ImprimirEstrella(2);
            }
            else if (c<=5)
            {
                ImprimirEstrella(3);
            }
            break;

        case 4:
            pf("\t========================Trivia de Artes========================");
            pf("\n\tRecuerde dar sus respuestas en may%csculas\n",163);
            //==============================PREGUNTA 1==============================
            printf ("\n\n\t1. %cQui%cn canta la canci%cn We Are The Champions?\n",168,130,162);
            printf ("\t\tA) The Beatles \n\t\tB) Queen \n\t\tC) The Rolling Stones\n\t\tD) BTS ");
            printf ("\n\tElecci%cn: ",162);
            scanf("%c",&r);
            fflush(stdin);
            while(r!=65 && r!=66 && r!=67 && r!=68)
            {
                printf ("\tOpci%cn no v%clida, ingresa una v%clida (A,B,C,D): ",162,160,160);
                printf ("\n\tElecci%cn: ",162);
                scanf("%c",&r);
                fflush(stdin);
            }
            if(r==66)
            {
                printf ("\tRespuesta correcta\n");
                c++;
            }
            else
            {
                printf ("\tRespuesta incorrecta");
                printf ("\n\tLa respuesta correcta era la opci%cn: B) Queen\n",162);
            }
            //==============================PREGUNTA 2==============================
            printf ("\n\t2. %cQui%cn pint%c %cLa %cltima cena%c?\n",168,130,162,34,163,34);
            printf ("\t\tA) Diego Rivera \n\t\tB) Pablo Picasso \n\t\tC) Leonardo da Vinci \n\t\tD) Vincent van Gogh ");
            printf ("\n\tElecci%cn: ",162);
            scanf("%c",&r);
            fflush(stdin);
            while(r!=65 && r!=66 && r!=67 && r!=68)
            {
                printf ("\n\tOpci%cn no v%clida, ingresa una v%clida (A,B,C,D): ",162,160,160);
                printf ("\n\tElecci%cn: ",162);
                scanf("%c",&r);
                fflush(stdin);
            }
            if(r==67)
            {
                printf ("\tRespuesta correcta\n");
                c++;
            }
            else
            {
                printf ("\tRespuesta incorrecta");
                printf ("\n\tLa respuesta correcta era la opci%cn: C) Leonardo da Vinci\n",162);
            }
            //==============================PREGUNTA 3==============================
            printf ("\n\t3. %cEn qu%c pa%cs se encuentra el famoso monumento Taj Mahal?\n",168,130,161,63);
            printf ("\t\tA) China \n\t\tB) India \n\t\tC) M%cxico \n\t\tD) China ",130);
            printf ("\n\tElecci%cn: ",162);
            scanf("%c",&r);
            fflush(stdin);
            while(r!=65 && r!=66 && r!=67 && r!=68)
            {
                printf ("\tOpci%cn no v%clida, ingresa una v%clida (A,B,C,D): ",162,160,160);
                printf ("\n\tElecci%cn: ",162);
                scanf("%c",&r);
                fflush(stdin);
            }
            if(r==66)
            {
                printf ("\tRespuesta correcta\n");
                c++;
            }
            else
            {
                printf ("\tRespuesta incorrecta");
                printf ("\n\tLa respuesta correcta era la opci%cn: B) India\n",162);
            }
            //==============================PREGUNTA 4==============================
            printf ("\n\t4. %cQui%cn escribi%c Cien a%cos de soledad%c\n",168,130,162,164,63);
            printf ("\t\tA) Gabriel Garc%ca Marquez \n\t\tB) Juan Rulfo \n\t\tC) Carlos Fuentes \n\t\tD) Diego Vel%czquez ",161,160);
            printf ("\n\tElecci%cn: ",162);
            scanf("%c",&r);
            fflush(stdin);
            while(r!=65 && r!=66 && r!=67 && r!=68)
            {
                printf ("\tOpci%cn no v%clida, ingresa una v%clida (A,B,C,D): ",162,160,160);
                printf ("\n\tElecci%cn: ",162);
                scanf("%c",&r);
                fflush(stdin);
            }
            if(r==65)
            {
                printf ("\tRespuesta correcta\n");
                c++;
            }
            else
            {
                printf ("\tRespuesta incorrecta");
                printf ("\n\tLa respuesta correcta era la opci%cn: A) Gabriel Garc%ca Marquez\n",162,161);
            }
            //==============================PREGUNTA 5==============================
            printf ("\n\t5. %cCu%cl es el s%cptimo arte%c\n",168,160,130,63);
            printf ("\t\tA) Danza \n\t\tB) Pintura \n\t\tC) Cine \n\t\tD) Literatura ");
            printf ("\n\tElecci%cn: ",162);
            scanf("%c",&r);
            fflush(stdin);
            while(r!=65 && r!=66 && r!=67 && r!=68)
            {
                printf ("\tOpci%cn no v%clida, ingresa una v%clida (A,B,C,D): ",162,160,160);
                printf ("\n\tElecci%cn: ",162);
                scanf("%c",&r);
                fflush(stdin);
            }

            if(r==67)
            {
                printf ("\tRespuesta correcta\n");
                c++;
            }
            else
            {
                printf ("\tRespuesta incorrecta");
                printf ("\n\tLa respuesta correcta era la opci%cn: C) Cine\n",162);
            }
            //===================PREGUNTA 6==============================
            printf ("\n\n\t6. %cQu%c miembro de los Beatles fue asesinado en el a%co 1980? \n",168,130,164);
            printf ("\t\tA) Paul McCartney \n\t\tB) George Harrison \n\t\tC) Ringo Starr \n\t\tD) John Lennon ");
            printf ("\n\tElecci%cn: ",162);
            scanf("%c",&r);
            fflush(stdin);
            while(r!=65 && r!=66 && r!=67 && r!=68)
            {
                printf ("\tOpci%cn no v%clida, ingresa una v%clida (A,B,C,D): ",162,160,160);
                printf ("\n\tElecci%cn: ",162);
                scanf("%c",&r);
                fflush(stdin);
            }
            if(r==68)
            {
                printf ("\tRespuesta correcta\n");
                c++;
            }
            else
            {
                printf ("\tRespuesta incorrecta");
                printf ("\n\tLa respuesta correcta era la opci%cn: D) John Lennon",162);
            }
            //==============================PREGUNTA 7==============================
            printf ("\n\n\t7. %cEn qu%c siglo se inici%c el Renacimiento? \n",168,130,162);
            printf ("\t\tA) Siglo XVI \n\t\tB) Siglo XIV \n\t\tC) Siglo XV \n\t\tD) Siglo XIII ");
            printf ("\n\tElecci%cn: ",162);
            scanf("%c",&r);
            fflush(stdin);
            while(r!=65 && r!=66 && r!=67 && r!=68)
            {
                printf ("\tOpci%cn no v%clida, ingresa una v%clida (A,B,C,D): ",162,160,160);
                printf ("\n\tElecci%cn: ",162);
                scanf("%c",&r);
                fflush(stdin);
            }
            if(r==67)
            {
                printf ("\tRespuesta correcta\n");
                c++;
            }
            else
            {
                printf ("\tRespuesta incorrecta");
                printf ("\n\tLa respuesta correcta era la opci%cn: C) Siglo XV",162);
            }
            //==============================PREGUNTA 8==============================
            printf ("\n\n\t8. %cQui%cn pint%c %cLa noche estrellada%c? \n",168,130,162,34,34);
            printf ("\t\tA) Vincent van Gogh  \n\t\tB) Pablo Neruda \n\t\tC) Frida kahlo \n\t\tD) Ludwig van Beethoven ");
            printf ("\n\tElecci%cn: ",162);
            scanf("%c",&r);
            fflush(stdin);
            while(r!=65 && r!=66 && r!=67 && r!=68)
            {
                printf ("\tOpci%cn no v%clida, ingresa una v%clida (A,B,C,D): ",162,160,160);
                printf ("\n\tElecci%cn: ",162);
                scanf("%c",&r);
                fflush(stdin);
            }
            if(r==65)
            {
                printf ("\tRespuesta correcta\n");
                c++;
            }
            else
            {
                printf ("\tRespuesta incorrecta");
                printf ("\n\tLa respuesta correcta era la opci%cn: A) Vincent van Gogh",162);
            }
            //==============================PREGUNTA 9==============================
            printf ("\n\n\t9. %cCu%cl fue la primera pel%ccula de Pixar Animation Studios? \n",168,160,161);
            printf ("\t\tA) Toy Story  \n\t\tB) Cars \n\t\tC) Los increibles \n\t\tD) Buscando a Nemo ");
            printf ("\n\tElecci%cn: ",162);
            scanf("%c",&r);
            fflush(stdin);
            while(r!=65 && r!=66 && r!=67 && r!=68)
            {
                printf ("\tOpci%cn no v%clida, ingresa una v%clida (A,B,C,D): ",162,160,160);
                printf ("\n\tElecci%cn: ",162);
                scanf("%c",&r);
                fflush(stdin);
            }
            if(r==65)
            {
                printf ("\tRespuesta correcta\n");
                c++;
            }
            else
            {
                printf ("\tRespuesta incorrecta");
                printf ("\n\tLa respuesta correcta era la opci%cn: A) Toy Story",162);
            }
            //===============================PREGUNTA 10==============================
            printf ("\n\n\t10. %cCu%cl es el libro sagrado del Islam? \n",168,160);
            printf ("\t\tA) La Biblia \n\t\tB) El Popol Vuh \n\t\tC) El Cor%cn \n\t\tD) La doctrina ", 160);
            printf ("\n\tElecci%cn: ",162);
            scanf("%c",&r);
            fflush(stdin);
            while(r!=65 && r!=66 && r!=67 && r!=68)
            {
                printf ("\tOpci%cn no v%clida, ingresa una v%clida (A,B,C,D): ",162,160,160);
                printf ("\n\tElecci%cn: ",162);
                scanf("%c",&r);
                fflush(stdin);
            }
            if(r==67)
            {
                printf ("\tRespuesta correcta\n");
                c++;
            }
            else
            {
                printf ("\tRespuesta incorrecta");
                printf ("\n\tLa respuesta correcta era la opci%cn: C) El Cor%cn",162,160);
            }
            pf("\n\tTus aciertos son: %d",c);
            if (c>7)
            {
                ImprimirEstrella(1);
            }
            else if (c==6 || c==7)
            {
                ImprimirEstrella(2);
            }
            else if (c<=5)
            {
                ImprimirEstrella(3);
            }
            break;

            default:
                pf("\n\tOpci%cn invalida (1-4)", 162);
                goto inicioTrivia;

        }


        op=repetir_programa();/*Pregunta si se desea repetir, ir al menú o salir del programa, mediante una función que nos */
    }                         /*regresa el valor de “op”*/
    while(op==1);  /*Se repetirá el programa si se seleccionó repetir (op=1)*/
}

void programa_ahorcado()
{
    texto_ahorcado();
    do /*El ciclo do while, repite el programa las veces que el jugador desee o regresar al menu o se cierra */
    {
        char palabra[100], letra='\0', correcto[100]; /*"palabra" guarda la palabra a adivinar. "letra" guarda la letra dada por el jugador 2, "correcto"imprime la palabra con espacios
                                                       blancos y cada letra correspondiente que el jugaor 2 vaya acertando*/
        char abecedario[27]= {'A','B','C','D','E','F','G','H','I','J','K','L','M','N',165,'O','P','Q','R','S','T','U','V','W','X','Y','Z'}; /*Guarda un arreglo con el abecedario*/
        int i, tam, error=0, bien=0, verificador=0; /*"tam" guarda el num de caracteres de "palabra, verificador verifica que la palabra se completo".
                                                    "bien es para ver los aciertos y asi con error ve cuantas veces te equivocaste" */
        pf("\tBienvendo jugador 1 al ahorcado\n");
        pf("\t\tReglas:\n");
        pf("\t1. Al momento de dar la palabra se escriben todas las letras en MAY%cSCULAS y sin acentos\n",233);
        pf ("\n\tIntroduce tu palabra para jugar:\n\t");
        sf("%s",&palabra);
        fflush(stdin);
        system("cls");  /*Limpia la pantalla para que el jugador 2 no vea cual es la palabra*/

        pf("\tBienvenido jugador 2\n");
        pf("\tTienes 6 oportunidades de equivocarte\n");
        tam=strlen(palabra); /*Pertence a string.h, nos ayuda a conicer la longitud de la palabra*/


        pf("\n\t");
        /*Impresion de la palabra vacia*/
        for (i=0; i<tam; i++)
        {
            correcto [i]=176;
            pf("%c  ",correcto [i]);
        }

        do /*Repite la solicitud de letras hasta que el jugador se haya equivocado 6 veces, es decir perdio; o que haya acompletado la palabra, es decir gano*/
        {

            imprimeAhorcado(error); /*Imprime el dibujo dependiendo cuantas veces se ha equivocado*/

            pf("\n\t");
            /*Imprime el abecedario*/
            for(i=0; i<27; i++)
            {
                pf("%c ",abecedario[i]);
            }
            pf("\n");
            /*Solicitud de letra*/
            pf("\tIngresa letra: ");
            letra=fgetchar(); //solo toma el primer caracter ingresado, pertenece a la liberia stdio.h
            fflush(stdin);
            /*Tacha la letra del abecedario que se ingreso*/
            for(i=0; i<27; i++)
            {
                if(letra == abecedario[i])
                {
                    abecedario[i]=158;
                }
            }
            /*Compara la letra ingresada con cada caracter del con palabra*/
            for (i=0; i<tam; i++)
            {
                if(letra == palabra[i])   /*Si la letra concide la guarda en el arreglo correcto en vez del espaciol vacio y aumenta la variable bien*/
                {
                    correcto [i]=letra;
                    bien++;

                }
            }
            /*En caso de que bien sea 0 quiere decir que el se equivoco, por lo tanto se aumento el error, esta condicion esta fuera del ciclo for porque si hay mas de una letra identica se aumenta n vecez error*/
            if(1>bien)
            {
                error++;
            }
            bien=0;  /*Regresa el valor de bien a cero*/
            /*Imprime el arreglo correcto que contiene los espacios en blancos y las letras ya acertadas */
            for (i=0; i<tam; i++)
            {
                pf ("\t%c ",correcto [i]);
            }
            /*Sirve si ya se completo la palabra, comprando caracter con caracter*/
            for (i=0; i<tam; i++)
            {
                if(correcto[i] == palabra[i])
                {
                    verificador++;  //En caso de que coincidan se aumenta la variable en uno
                }
            }
            /*Si se verificador==tam nos indica que ya se completo la palabra*/
            if(verificador!=tam) /*En caso de que no se haya acompletado regresa la varible verificador a 0*/
            {
                verificador=0;
            }

        }
        while (error<6 && verificador!=tam);

        imprimeAhorcado(error); //Imprime el dibujo con la ultima cantidad de error

        if(error<6) /*En caso de que haya tenido menos de 6 errores significa que el jugador gano y acompleto la palabra*/
        {
            pf("\n\tFelicidades!\n\tSobreviviste");
        }
        else   /*En caso contrario significa que el perdio*/
        {
            pf("\n\tTe ahorcar%cn",162);
        }
        printf("\n");
        op=repetir_programa();  /*Pregunta si se desea repetir, ir al menú o salir del programa, mediante una función que nos */
    }                            /*regresa el valor de “op”)*/
    while(op==1);   /*Se repetirá el programa si se seleccionó repetir (op=1)*/
}

void programa_batalla()
{
    texto_batalla();
    do
    {
        int i=0,j=0,tam=6,barcos=9,barcos2=9,x=0,y=0,turno=0,turnoGeneral=0,pasoTurno=0,ganador=0;
        /*  "tam" le da el tamano a la matriz del tablero
			"barcos" y "barcos2" coresponden a la cantidad de barcos que los jugadores pueden colocar.
			"x" y "y" corresponden a las coordenadas que el jugador ingresa.
			"turno" indica si el jugador vuelve a tirar por haber acertado, su valor es 0, o se pasa el turno al sig. jugador, su valor ser� 1.
			"turnoGeneral" sirve para llevar el flujo del juego siempre que este no se termine, si vale 1 el juego e acaba.
			"pasoTurno" ayuda a que el jugador pueda ver lo que tiro al final de su turno.
			"ganador" se ocupa para imprimir el caso de ganador correspondiente.*/
        char tablero1[tam][tam], tablero2[tam][tam];
        /*	Los tableros del juego*/

        pf("\n\t Reglas del juego:");
        pf("\n\t - Cada jugador coloca sus barcos en las casillas del tablero (Cada jugador tiene su propio\n\t tablero). El tablero de un jugador no puede ser visto por el otro jugador.");
        pf("\n\t - Al inicio el jugador dice las coordenadas a las cuales desea atacar.");
        pf("\n\t - Si en las coordenadas se encuentra un barco, entonces el barco recibe el da%co, \n\t el barco se hunde y el jugador tira de nuevo.",164);
        pf("\n\t - Si en las coordenadas no se encuentra un barco, habr%c fallado el tiro y se cambia de turno.",160);
        pf("\n\t - Todas las coordenadas se marcan en el tablero para que no se repitan. Cuando es una \n\t coordenada es un ataque del jugador se coloca un punto o un c%crculo. Cuando la coordenada",161);
        pf("\n\t es un ataque contra el jugador, se marca una equis ('X') en la casilla.");
        pf("\n\t - Cuando un jugador dice sus coordenadas termina su turno.");
        pf("\n\t - Gana el jugador que hunda primero los 10 barcos de su enemigo.");
        pf("\n\t - Tu tablero es de 6 x 6.");

        pf("\n\n\t+----------------------------+");
        pf("\n\n\t+----------------------------+");
        pf("\n\t|                            |");
        pf("\n\t|    Turno del Jugador 1     |");
        pf("\n\t|    Forma tus Tropas!!      |");
        pf("\n\t|                            |");
        pf("\n\n\t+----------------------------+");
        pf("\n\n\t+----------------------------+\n\n");

        //Llenado de ambos tableros con el caracter 254 (es un cuadrado)
        for(i=0; i<tam; i++)
        {
            for(j=0; j<tam; j++)
            {
                tablero1[i][j]=254;
                tablero2[i][j]=254;
            }
        }

        //Impresion del tablero con coordenadas y cuadritos
        pf("\t  1  2  3  4  5  6\n\n");
        for(i=0; i<tam; i++)
        {
            pf("\t%d",i+1);
            for(j=0; j<tam; j++)
            {
                pf(" %c ",tablero1[i][j]);
            }
            pf("\n\n");
        }

        do  //Ingresar Barcos
        {


                do  //Ciclo de error
                {
                    printf("\n\tIndica coordenadas v%clidas para tu barco %d: ",160,barcos+1);
                    pf("\n\tFila: ");
                    sf("%d",&x);	//Filas

                    //Limitando valores aceptados de coordenadas
                    while(x<=0 || x>6)
                    {
                        pf("\n\tColoca una fila v%clida",160);
                        pf("\n\tFila: ");
                        sf("%d",&x);//filas
                    }
                    x--;//Se le resta 1 porque el indice inicia en 0
                    pf("\n\tColumna: ");
                    sf("%d",&y);	//Columnas

                    //Limitando valores aceptados de coordenadas
                    while(y<=0 || y>6)
                    {
                        pf("\n\tColoca una columna v%clida",160);
                        pf("\n\tColumna: ");
                        sf("%d",&y);//filas
                    }
                    y--;//Se le resta 1 porque el indice inicia en 0

                }
                while(tablero1[x][y]==88);
                //Colocamos barco
                tablero1[x][y]=88;
                barcos--;//Se coloco el barco

        }
        while(barcos!=-1);//Todos los barcos se colocaron y se sale cuando barcos = -1 (porque los indices comienzan en 0)

        //ImpresiOn de Tablero 1 para que el usuario vea lo que puso-----------------
        pf("\t   1  2  3  4  5  6\n\n");
        for(i=0; i<tam; i++)
        {
            pf("\t%d ",i+1);
            for(j=0; j<tam; j++)
            {
                //Impresion responsiva de barcos y espacios vacios
                pf(" %c ",tablero1[i][j]);
            }
            pf("\n\n");
        }

        do//Pausa del programa para que se observe el tablero
        {
            pf("\n\t(0=Si || 1=No) Listo para pasar el Turno? ");
            sf("%d",&pasoTurno);
            while(pasoTurno<0 || pasoTurno>1)
            {
                pf("\n\t(0=Si || 1=No) Ingresa un valor v%clido\n\tListo para pasar el turno? ",160);
                sf("%d",&pasoTurno);
            }
        }
        while(pasoTurno==1);//Se sale cuando se esta listo para pasar de turno



        system("cls");//Se limpia la pantalla para que el jugador 2 no pueda ver los barcos del jugador 1.
        //Jugador 2==================================================================================================================================
        barcos=9;	//Se repite la misma estructura que con el jugador 1 solo que utilizando el tablero del jugador 2.

        pf("\n\n\t+----------------------------+");
        pf("\n\n\t+----------------------------+");
        pf("\n\t|                            |");
        pf("\n\t|    Turno del Jugador 2     |");
        pf("\n\t|    Forma tus Tropas!!      |");
        pf("\n\t|                            |");
        pf("\n\n\t+----------------------------+");
        pf("\n\n\t+----------------------------+\n\n");

        //Impresion del tablero coordenadas y cuadritos
        pf("\t  1  2  3  4  5  6\n\n");
        for(i=0; i<tam; i++)
        {
            pf("\t%d",i+1);
            for(j=0; j<tam; j++)
            {
                pf(" %c ",tablero2[i][j]);
            }
            pf("\n\n");
        }
        do
        {

            //Rellenar el tablero de barquitos.


                do  //Ciclo de llenado de datos y posible error
                {
                    printf("\n\tIndica coordenadas v%clidas para tu barco %d: ",160,barcos+1);
                    pf("\n\tFila: ");
                    sf("%d",&x);	//Filas

                    //Limitando valores aceptados de coordenadas
                    while(x<=0 || x>6)
                    {
                        pf("\n\tColoca una fila v%clida",160);
                        pf("\n\tFila: ");
                        sf("%d",&x);//filas
                    }
                    x--;//Se le resta 1 porque el indice inicia en 0
                    pf("\n\tColumna: ");
                    sf("%d",&y);	//Columnas

                    //Limitando valores aceptados de coordenadas
                    while(y<=0 || y>6)
                    {
                        pf("\n\tColoca una columna v%clida",160);
                        pf("\n\tColumna: ");
                        sf("%d",&y);//filas
                    }
                    y--;//Se le resta 1 porque el indice inicia en 0

                }
                while(tablero2[x][y]==88);
                tablero2[x][y]=88;
                barcos--;

        }
        while(barcos!=-1);

        //Impresiin de Tablero 2-----------------
        pf("\t   1  2  3  4  5  6\n\n");
        for(i=0; i<tam; i++)
        {
            pf("\t%d ",i+1);
            for(j=0; j<tam; j++)
            {
                //Impresiin responsiva de barcos y espacios vacios
                pf(" %c ",tablero2[i][j]);
            }
            pf("\n\n");
        }

        do
        {
            pf("\n\t(0=Si || 1=No) Listo para pasar el turno? ");
            sf("%d",&pasoTurno);
            while(pasoTurno<0 || pasoTurno>1)
            {
                pf("\n\t(0=Si || 1=No) Ingrese un valor v%clido\n\tListo para pasar el turno? ",160);
                sf("%d",&pasoTurno);
            }
        }
        while(pasoTurno==1);

        //=======================================================================================================================================================
        //Se inicia la pelea!!!
        barcos=9;//Las variables se inicializan en los valores necesarios para la correcta ejecucion del juego.
        barcos2=9;
        x=0,y=0;
        do
        {

                            //Reiniciamos las variables de turno y paso turno para que
                            //el siguiente jugador pueda jugar.
            turno=0;
            pasoTurno=0;


            while(turno==0 && pasoTurno==0)   //Turno del jugador 1
            {
                system("cls");//Se limpia la pantalla para que el Jugador 1 no pueda ver el tiro del Jugador 2.

                pf("\n\n\t+----------------------------+");
                pf("\n\n\t+----------------------------+");
                pf("\n\t|                            |");
                pf("\n\t|    Turno del Jugador 1     |");
                pf("\n\t|         Ataca!!!           |");
                pf("\n\t|                            |");
                pf("\n\n\t+----------------------------+");
                pf("\n\n\t+----------------------------+\n\n");

                //Impresion de Tablero 2 para visualizacion, esto porque el Jugador 1 tiene que hundir los barcos del Jugador 2-----------------
                pf("\t   1  2  3  4  5  6\n\n");
                for(i=0; i<tam; i++)
                {
                    pf("\t%d ",i+1);
                    for(j=0; j<tam; j++)
                    {
                        //Impresion responsiva de barcos y espacios vacios
                        if(tablero2[i][j]==88)  //Sensura de tablero, si hay barco imprimir cuadrito (254).
                        {
                            pf(" %c ",254);
                        }
                        else    //Fallo
                        {
                            pf(" %c ",tablero2[i][j]);//Se imprime lo que habia (cuadrito 254, barco destruido o fallo).
                        }
                    }
                    pf("\n\n");
                }

                pasoTurno=1;//Se cambia este valor para que exista una pausa al final del turno del Jugador 1.

                //Atacar los barquitos, insercion de coordenadas.
                printf("\n\tIndica coordenadas para disparar, barcos restantes %d: ",barcos+1);
                pf("\n\tFila: ");
                sf("%d",&x);//Filas

                //Limitando valores aceptados de coordenadas
                while(x<=0 || x>6)
                {
                    pf("\n\tColoca una fila v%clida",160);
                    pf("\n\tFila: ");
                    sf("%d",&x);//filas
                }
                x--;//Se le resta 1 porque el indice inicia en 0

                pf("\tColumna: ");
                sf("%d",&y);//columnas

                //Limitando valores aceptados de coordenadas
                while(y<=0 || y>6)
                {
                    pf("\n\tColoca una columna v%clida",160);
                    pf("\n\tColumna: ");
                    sf("%d",&y);//filas
                }
                y--;//Se le resta 1 porque el indice inicia en 0

				//Comparacion del tiro del Jugador 1 con el tablero del Jugador 2.
                if(tablero2[x][y]==88)   //Tiro Acertado, 88=X
                {
                    tablero2[x][y]=207; //Le diste, 207=Barco destruido
                    turno=0;//Le vuelve a ir al Jugador 1 por acertar el tiro.
                    barcos--;//Se hundio un barco.
                    if(barcos<0)   //Se acaba el juego
                    {
                        ganador=1;//Gano jugador 1
                        goto final;
                    }
                }
                else     //Turno Fallido
                {
                    turno=1;
                    tablero2[x][y]=126;//~
                }

                //Impresion de Tablero 2 despues del tiro-----------------
                pf("\t   1  2  3  4  5  6\n\n");
                for(i=0; i<tam; i++)
                {
                    pf("\t%d ",i+1);
                    for(j=0; j<tam; j++)
                    {
                        //Impresion responsiva de barcos y espacios vacios
                        if(tablero2[i][j]==88)  //Sensura de tablero, si hay barco imprimir cuadrito (254).
                        {
                            pf(" %c ",254);
                        }
                        else    //Fallo
                        {
                            pf(" %c ",tablero2[i][j]);
                        }
                    }
                    pf("\n\n");
                }

                do{
                //Pausa del ejecutable para apreciar el tiro.
                    pf("\n\t(0=Si || 1=No) Listo para pasar el turno? ");
                    sf("%d",&pasoTurno);
                    //Dato no valido, se solicita uno valido.
                    while(pasoTurno<0 || pasoTurno>1)
                    {
                        pf("\n\t(0=Si || 1=No) Ingresa un valor v%clido\n\tListo para pasar el turno? ",160);
                        sf("%d",&pasoTurno);
                    }
                }while (pasoTurno==1);

            }

            //------------------ATACA JUGADOR 2---------------------
                        //Reiniciamos las variables de turno y paso turno para que
                        //el siguiente jugador pueda jugar.
            turno=0;
            pasoTurno=0;



            while(turno==0 && pasoTurno==0)  //Turno jugador 2, se repite el flujo del programa solo que para el Jugador 2.
            {
                system("cls");

                pf("\n\n\t+----------------------------+");
                pf("\n\n\t+----------------------------+");
                pf("\n\t|                            |");
                pf("\n\t|    Turno del Jugador 2     |");
                pf("\n\t|         Ataca!!!           |");
                pf("\n\t|                            |");
                pf("\n\n\t+----------------------------+");
                pf("\n\n\t+----------------------------+\n\n");

                //Impresion de Tablero 2-----------------
                pf("\t   1  2  3  4  5  6\n\n");
                for(i=0; i<tam; i++)
                {
                    pf("\t%d ",i+1);
                    for(j=0; j<tam; j++)
                    {
                        //Impresion responsiva de barcos y espacios vacios
                        if(tablero1[i][j]==88)  //Si hay barco imprimir mar
                        {
                            pf(" %c ",254);
                        }
                        else    //Fallo
                        {
                            pf(" %c ",tablero1[i][j]);
                        }
                    }
                    pf("\n\n");
                }

                pasoTurno=1;
                //Atacar los barquitos.
                printf("\n\tIndica coordenadas para disparar, barcos restantes %d: ",barcos2+1);
                pf("\n\tFila: ");
                sf("%d",&x);//Filas

                //Limitando valores aceptados de coordenadas
                while(x<=0 || x>6)
                {
                    pf("\n\tColoca una fila v%clida",160);
                    pf("\n\tFila: ");
                    sf("%d",&x);//filas
                }
                x--;//Se le resta 1 porque el indice inicia en 0

                pf("\tColumna: ");
                sf("%d",&y);//Columnas

                //Limitando valores aceptados de coordenadas
                while(y<=0 || y>6)
                {
                    pf("\n\tColoca una columna v%clida",160);
                    pf("\n\tColumna: ");
                    sf("%d",&y);//filas
                }
                y--;//Se le resta 1 porque el indice inicia en 0

                if(tablero1[x][y]==88)  //Tiro Acertado
                {
                    tablero1[x][y]=207;//Le diste
                    turno=0;
                    barcos2--;
                    if(barcos2<0)  //Se acaba el juego
                    {
                        ganador=2;//Gano jugador 2
                        goto final;
                    }
                }
                else     //Turno Fallido
                {
                    turno=1;
                    tablero1[x][y]=126;//~
                }

                //Impresion de Tablero 2-----------------
                pf("\t   1  2  3  4  5  6\n\n");
                for(i=0; i<tam; i++)
                {
                    pf("\t%d ",i+1);
                    for(j=0; j<tam; j++)
                    {
                        //Impresion responsiva de barcos y espacios vacios
                        if(tablero1[i][j]==88)  //Si hay barco imprimir mar
                        {
                            pf(" %c ",254);
                        }
                        else    //Fallo
                        {
                            pf(" %c ",tablero1[i][j]);
                        }
                    }
                    pf("\n\n");
                }

                do{
                    pf("\n\t(0=Si || 1=No) Listo para pasar el turno? ");
                    sf("%d",&pasoTurno);
                    while(pasoTurno<0 || pasoTurno>1)
                    {
                        pf("\n\t(0=Si || 1=No) Ingresa un valor v%clido\n\tListo para pasar el turno? ",160);
                        sf("%d",&pasoTurno);
                    }
                }while (pasoTurno==1);

            }
        }
        while(turnoGeneral==0);  //Turno general, es decir, si el juego se ha gandado o no.(0=No || 1=Si).

final://Impresion de letreros de victoria.
        if(ganador==1) //Segun el valor de la variable ganador, se sabe que gano el jugador 1
        {
            pf("\n\n\t+----------------------------+");
            pf("\n\n\t+----------------------------+");
            pf("\n\t|                            |");
            pf("\n\t|   Has ganado Jugador 1!    |");
            pf("\n\t|     Ahora eres Naval!      |");
            pf("\n\t|                            |");
            pf("\n\n\t+----------------------------+");
            pf("\n\n\t+----------------------------+");
        }
        else if(ganador==2)  //Segun el valor de la variable ganador, se sabe que gano el jugador 2
        {
            pf("\n\n\t+----------------------------+");
            pf("\n\n\t+----------------------------+");
            pf("\n\t|                            |");
            pf("\n\t|   Has ganado Jugador 2!    |");
            pf("\n\t|     Ahora eres Naval!      |");
            pf("\n\t|                            |");
            pf("\n\n\t+----------------------------+");
            pf("\n\n\t+----------------------------+");
        }
        //Funcion para repetir el programa.
        op=repetir_programa();
    }
    while(op==1);
}

int repetir_programa()
{
    pf("\n");
    do /*Verifica que se den opciones validas*/
    {
        pf("\n\t%cQuieres jugar de nuevo?\n\t1)S%c  \n\t2)Volver al men%c \n\t3)CERRAR\n",168,161,163);
        pf("\tElecci%cn: ",162);
        sf("%i",&op);
        fflush(stdin);
        pf("--------------------------------------------------------------------------\n\n");
        if(op!=1 && op!=2 && op!=3) /*Si indica que no se dio una opcion valida*/
            pf("Opci%cn inv%clida\n",162,160);
    }
    while(op!=1 && op!=2 && op!=3);
    return op;
}

void texto_Bienvenido()
{
    pf("\n\t   ___      _                                               _        _           ");
    pf("\n\t  | _ )    (_)     ___    _ _     __ __    ___    _ _      (_)    __| |    ___   ");
    pf("\n\t  | _ %c    | |    / -_)  | ' %c    %c V /   / -_)  | ' %c     | |   / _` |   / _ %c  ",92,92,92,92,92);
    pf("\n\t  |___/   _|_|_   %c___|  |_||_|   _%c_/_   %c___|  |_||_|   _|_|_  %c__,_|   %c___/  ",92,92,92,92,92);
    pf("\n\t_|%c%c%c%c%c|_|%c%c%c%c%c|_|%c%c%c%c%c|_|%c%c%c%c%c|_|%c%c%c%c%c|_|%c%c%c%c%c|_|%c%c%c%c%c|_|%c%c%c%c%c|_|%c%c%c%c%c|_|%c%c%c%c%c| ",34,34,34,34,34, 34,34,34,34,34, 34,34,34,34,34, 34,34,34,34,34, 34,34,34,34,34, 34,34,34,34,34, 34,34,34,34,34, 34,34,34,34,34, 34,34,34,34,34, 34,34,34,34,34);
    pf("\n\t%c`-0-0-'%c`-0-0-'%c`-0-0-'%c`-0-0-'%c`-0-0-'%c`-0-0-'%c`-0-0-'%c`-0-0-'%c`-0-0-'%c`-0-0-' ",34,34,34,34,34,34,34,34,34,34);
}

void texto_gato()
{
    pf("\t 888888888   888\n");
    pf("\t 888         888\n");
    pf("\t 888         888\n");
    pf("\t 8888888     888\n");
    pf("\t 888         888\n");
    pf("\t 888         888\n");
    pf("\t 888         888\n");
    pf("\t 888888888   888\n");
    pf("\n\n\n\t                        888\n");
    pf("\t                        888\n");
    pf("\t                     888888888\n");
    pf("\t  .d88b.      8888b.    888     .d88b.\n");
    pf("\t d88  88b        88b    888    d88  88b\n");
    pf("\t 888  888   .d888888    888    888  888\n");
    pf("\t Y88  888   888  888    888    Y88  88P\n");
    pf("\t  Y888888    Y888888    888      Y88P\n");
    pf("\t      888\n");
    pf("\t     .88P\n");
    pf("\t  88888P\n\n");
}

void dibujo_fin_gato()
{
    pf("\n\t                      /^--^%c     /^--^%c     /^--^%c \n",92,92,92);
    pf("\t                      %c____/     %c____/     %C____/ ",92,92,92);
    pf("\n\t                      /    %c     /    %c     /    %c ",92,92,92);
    pf("\n\t                     |      |   |      |   |      | ");
    pf("\n\t                     %c__  __/   %c__  __/   %c__  __/ ",92,92,92);
    pf("\n\t|^|^|^|^|^|^|^|^|^|^|^|^%c %c^|^|^|^/ /^|^|^|^|^%c %c^|^|^|^|^|^|^|^|^|^|^|^|",92,92,92,92);
    pf("\n\t| | | | | | | | | | | | |%c %c| | |/ /| | | | | |%c %c| | | | | | | | | | | |",92,92,92,92);
    pf("\n\t| | | | | | | | | | | | |/ /| | |%c %c| | | | | |/ /| | | | | | | | | | | |",92,92);
    pf("\n\t| | | | | | | | | | | | |%c/ | | | %c/| | | | | |%c/ | | | | | | | | | | | |",92,92,92);
    pf("\n\t#########################################################################");
    pf("\n\t| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |");
    pf("\n\t| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |");
}

void texto_piedra()
{
    int j1, j2;
    pf("\n\t_____________     _________                  ________                    ______");
    pf("\n\t___  __ %c__(_)__________  /____________ _    ___  __ %c_____ ________________  /",92,92);
    pf("\n\t__  /_/ /_  /_  _ %c  __  /__  ___/  __ `/    __  /_/ /  __ `/__  __ %c  _ %c_  / ",92,92,92);
    pf("\n\t_  ____/_  / /  __/ /_/ / _  /   / /_/ /     _  ____// /_/ /__  /_/ /  __/  /  ");
    pf("\n\t/_/     /_/  %c___/%c__,_/  /_/    %c__,_/      /_/     %c__,_/ _  .___/%c___//_/   ",92,92,92,92,92);
    pf("\n\t                                                            /_/                ");
    pf("\n\t            ____________________                                               ");
    pf("\n\t______      ___  __/__(_)_____(_)_________________ _                           ");
    pf("\n\t_  __ %c     __  /  __  /_____  /_  _ %c_  ___/  __ `/                           ",92,92);
    pf("\n\t/ /_/ /     _  /   _  / ____  / /  __/  /   / /_/ /                            ");
    pf("\n\t%c____/      /_/    /_/  ___  /  %c___//_/    %c__,_/                             ",92,92,92);
    pf("\n\t                        /___/                                                 ");
}

void texto_trivia()
{
    pf("\n\t /$$$$$$$$        /$$            /$$          ");
    pf("\n\t|__  $$__/       |__/           |__/          ");
    pf("\n\t   | $$  /$$$$$$  /$$ /$$    /$$ /$$  /$$$$$$ ");
    pf("\n\t   | $$ /$$__  $$| $$|  $$  /$$/| $$ |____  $$");
    pf("\n\t   | $$| $$  %c__/| $$ %c  $$/$$/ | $$  /$$$$$$$",92,92);
    pf("\n\t   | $$| $$      | $$  %c  $$$/  | $$ /$$__  $$",92);
    pf("\n\t   | $$| $$      | $$   %c  $/   | $$|  $$$$$$$",92);
    pf("\n\t   |__/|__/      |__/    %c_/    |__/ %c_______/",92,92);
}

void ImprimirEstrella(int star)
{
    if(star==1)
    {
        pf("\n\t                                                @@@@@                                               ");
        pf("\n\t                                              @@@@@@@@@                                            ");
        pf("\n\t                                              @@@@@@@@@                                             ");
        pf("\n\t                                           @@@@@@@@@@@@@@@                                         ");
        pf("\n\t                                           @@@@@     @@@@@                                          ");
        pf("\n\t                                         @@@@@@@     @@@@@@@                                        ");
        pf("\n\t                                         @@@@@         @@@@@                                        ");
        pf("\n\t                                       @@@@@@@         @@@@@@@                                      ");
        pf("\n\t                                       @@@@               @@@@                                      ");
        pf("\n\t                                    @@@@@@@               @@@@@@@                                   ");
        pf("\n\t                                    @@@@@                   @@@@@                                   ");
        pf("\n\t                                  @@@@@@@                   @@@@@@@                                 ");
        pf("\n\t                               @@@@@@@@                       @@@@@@@@                              ");
        pf("\n\t               @@@@@@@@@@@@@@@@@@@@@@@@                       @@@@@@@@@@@@@@@@@@@@@@@@              ");
        pf("\n\t@@@@@&@@@@@@@@@@@@@@@@@@@@@@@@@@@@                                 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
        pf("\n\t@@@@@@@@@@@@@@@@@                   @&#@@@@@/            @##@@@@@@                   @@@@@@&@&@@@@@@@");
        pf("\n\t   @@@@@@@                        @@    (@@@@@@         @@    @@@@@@                        @@@@@@@  ",37);
        pf("\n\t     @@@@@@@                      @@@@@&@@@@@@@         @@@@&@@@@@@@@                     @@@@@@@    ");
        pf("\n\t        @@@@@@@                   /@@@@@@@&@@@@         @@@@@@@@@@@@                  @@@@@@@       ");
        pf("\n\t            @@@@@@@*                %@@@@@@@@             @@@@@@@@#             @@@@@@@         ");
        pf("\n\t               @@@@@@@                                                        @@@@@@@              ");
        pf("\n\t                 @@@@@@@        ///                               ///         @@@@@@@                ");
        pf("\n\t                   *@@@@@@@                                               @@@@@@@                   ");
        pf("\n\t                   *@@@@@@@                                               @@@@@@@                   ");
        pf("\n\t                      @@@@@            @@@@@@@@@@@@@@@@@@@@@@@@           @@@@@                     ");
        pf("\n\t                      @@@@@            @@@@@(////////////%@@@@@           @@@@@                     ");
        pf("\n\t                      @@@@@             @@/(//////////////((@@            @@@@@                     ");
        pf("\n\t                   *@@@@@@@              @////////////////*@              @@@@@@@                   ");
        pf("\n\t                   *@@@@                    /&(//////(&,                     @@@@                   ");
        pf("\n\t                   *@@@@                                                     @@@@                   ");
        pf("\n\t                   *@@@@                                                     @@@@                   ");
        pf("\n\t                   *@@@@                      @@@@@@@@@                      @@#@                   ");
        pf("\n\t                   *@@@@                 @@@@@@@@@@@@@@@@@@@                 @@@@                   ");
        pf("\n\t                 @@@@@@@            @@@@@@@@@@(@     @@@@@@@@@@@@            @@@@@@@                ");
        pf("\n\t                 @@@@@         @@@@@@@@@@@@               @@@@@@@@@@@#         @@@@@                ");
        pf("\n\t                 @@@@@     @@@@@@@@@@@@ .                     @@@@@@@@@@@@     @@@@@                ");
        pf("\n\t                 @@@@@@@@@@@@@@@@@                                 &@@@@@@@@@@@@@@@@                ");
        pf("\n\t                 @@@@@@@@@@@@                                           @@@@@@@@@@@@      ");
    }
    else if (star==2)
    {
        pf("\n\t                                                @@@@@                                               ");
        pf("\n\t                                              @@@@@@@@@                                            ");
        pf("\n\t                                              @@@@@@@@@                                             ");
        pf("\n\t                                           @@@@@@@@@@@@@@@                                         ");
        pf("\n\t                                           @@@@@     @@@@@                                          ");
        pf("\n\t                                         @@@@@@@     @@@@@@@                                        ");
        pf("\n\t                                         @@@@@         @@@@@                                        ");
        pf("\n\t                                       @@@@@@@         @@@@@@@                                      ");
        pf("\n\t                                       @@@@               @@@@                                      ");
        pf("\n\t                                    @@@@@@@               @@@@@@@                                   ");
        pf("\n\t                                    @@@@@                   @@@@@                                   ");
        pf("\n\t                                  @@@@@@@                   @@@@@@@                                 ");
        pf("\n\t                               @@@@@@@@                       @@@@@@@@                              ");
        pf("\n\t               @@@@@@@@@@@@@@@@@@@@@@@@                       @@@@@@@@@@@@@@@@@@@@@@@@              ");
        pf("\n\t@@@@@&@@@@@@@@@@@@@@@@@@@@@@@@@@@@                                 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
        pf("\n\t@@@@@@@@@@@@@@@@@                                                                   @@@@@@&@&@@@@@@@");
        pf("\n\t   @@@@@@@                                                                                 @@@@@@@  ");
        pf("\n\t     @@@@@@@                       @@@@@@@@@@                                              @@@@@@@    ");
        pf("\n\t        @@@@@@@                   @@@@@@@@@@@@         @          @                   @@@@@@@       ");
        pf("\n\t            @@@@@@@*              @@@@@@@@@@@@         @          @              (@@@@@@@         ");
        pf("\n\t               @@@@@@@              @@@@@@@@             @@@@@@@@              @@@@@@@              ");
        pf("\n\t                 @@@@@@@                                                     @@@@@@@                ");
        pf("\n\t                   *@@@@@@@                                               @@@@@@@                   ");
        pf("\n\t                   *@@@@@@@     @@@                               @@@     @@@@@@@                   ");
        pf("\n\t                      @@@@@       @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@       @@@@@                     ");
        pf("\n\t                      @@@@@                                               @@@@@                     ");
        pf("\n\t                   *@@@@@@@                                               @@@@@@@                   ");
        pf("\n\t                   *@@@@                                                     @@@@                   ");
        pf("\n\t                   *@@@@                                                     @@@@                   ");
        pf("\n\t                   *@@@@                                                     @@@@                   ");
        pf("\n\t                   *@@@@                      @@@@@@@@@                      @@#@                   ");
        pf("\n\t                   *@@@@                 @@@@@@@@@@@@@@@@@@@                 @@@@                   ");
        pf("\n\t                 @@@@@@@            @@@@@@@@@@(@     @@@@@@@@@@@@            @@@@@@@                ");
        pf("\n\t                 @@@@@         @@@@@@@@@@@@               @@@@@@@@@@@#         @@@@@                ");
        pf("\n\t                 @@@@@     @@@@@@@@@@@@ .                     @@@@@@@@@@@@     @@@@@                ");
        pf("\n\t                 @@@@@@@@@@@@@@@@@                                 &@@@@@@@@@@@@@@@@                ");
        pf("\n\t                 @@@@@@@@@@@@                                           @@@@@@@@@@@@      ");
    }
    else if(star=3)
    {
        pf("\n\t                                                @@@@@                                               ");
        pf("\n\t                                              @@@@@@@@@                                            ");
        pf("\n\t                                              @@@@@@@@@                                             ");
        pf("\n\t                                           @@@@@@@@@@@@@@@                                         ");
        pf("\n\t                                           @@@@@     @@@@@                                          ");
        pf("\n\t                                         @@@@@@@     @@@@@@@                                        ");
        pf("\n\t                                         @@@@@         @@@@@                                        ");
        pf("\n\t                                       @@@@@@@         @@@@@@@                                      ");
        pf("\n\t                                       @@@@               @@@@                                      ");
        pf("\n\t                                    @@@@@@@               @@@@@@@                                   ");
        pf("\n\t                                    @@@@@                   @@@@@                                   ");
        pf("\n\t                                  @@@@@@@                   @@@@@@@                                 ");
        pf("\n\t                               @@@@@@@@                       @@@@@@@@                              ");
        pf("\n\t               @@@@@@@@@@@@@@@@@@@@@@@@                       @@@@@@@@@@@@@@@@@@@@@@@@              ");
        pf("\n\t@@@@@&@@@@@@@@@@@@@@@@@@@@@@@@@@@@                                 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
        pf("\n\t@@@@@@@@@@@@@@@@@                                                                   @@@@@@&@&@@@@@@@");
        pf("\n\t   @@@@@@@                                                                                 @@@@@@@  ");
        pf("\n\t     @@@@@@@                                                                             @@@@@@@    ");
        pf("\n\t        @@@@@@@                   @          @         @          @                   @@@@@@@       ");
        pf("\n\t            @@@@@@@*              @          @         @          @              (@@@@@@@         ");
        pf("\n\t               @@@@@@@             @@@@@@@@@@           @@@@@@@@@@             @@@@@@@              ");
        pf("\n\t                 @@@@@@@                                                     @@@@@@@                ");
        pf("\n\t                   *@@@@@@@         @                           @         @@@@@@@                   ");
        pf("\n\t                   *@@@@@@@         @                                     @@@@@@@                   ");
        pf("\n\t                      @@@@@                                               @@@@@                     ");
        pf("\n\t                      @@@@@          @@@@@@@@@@@@@@@@@@@@@@@@@@@          @@@@@                     ");
        pf("\n\t                      @@@@@         @@@@@@@@@@@@@@@@@@@@@@@@@@@@@         @@@@@                     ");
        pf("\n\t                   *@@@@@@@                                               @@@@@@@                   ");
        pf("\n\t                   *@@@@                                                     @@@@                   ");
        pf("\n\t                   *@@@@                                                     @@@@                   ");
        pf("\n\t                   *@@@@                                                     @@@@                   ");
        pf("\n\t                   *@@@@                      @@@@@@@@@                      @@#@                   ");
        pf("\n\t                   *@@@@                 @@@@@@@@@@@@@@@@@@@                 @@@@                   ");
        pf("\n\t                 @@@@@@@            @@@@@@@@@@(@     @@@@@@@@@@@@            @@@@@@@                ");
        pf("\n\t                 @@@@@         @@@@@@@@@@@@               @@@@@@@@@@@#         @@@@@                ");
        pf("\n\t                 @@@@@     @@@@@@@@@@@@ .                     @@@@@@@@@@@@     @@@@@                ");
        pf("\n\t                 @@@@@@@@@@@@@@@@@                                 &@@@@@@@@@@@@@@@@                ");
        pf("\n\t                 @@@@@@@@@@@@                                           @@@@@@@@@@@@      ");
    }
}

void texto_ahorcado()
{
    pf("\n\t8888888888 888\n");
    pf("\t888        888\n");
    pf("\t888        888\n");
    pf("\t8888888    888\n");
    pf("\t888        888\n");
    pf("\t888        888\n");
    pf("\t888        888\n");
    pf("\t8888888888 888\n");
    pf("\n\n\n\t          888                                             888\n");
    pf("\t          888                                             888\n");
    pf("\t          888                                             888\n");
    pf("\t  8888b.  88888b.   .d88b.  888d888 .d8888b  8888b.   .d88888  .d88b.\n");
    pf("\t      88b 888  88b d88  88b 888P   d88P          88b d88  888 d88  88b\n");
    pf("\t .d888888 888  888 888  888 888    888      .d888888 888  888 888  888\n");
    pf("\t 888  888 888  888 Y88  88P 888    Y88b.    888  888 Y88  888 Y88  88P\n");
    pf("\t  Y888888 888  888   Y88P   888      Y8888P  Y888888   Y88888   Y88P");
    pf("\n\n");
}

void imprimeAhorcado(int caso) /*Con base al argumento imprime en que situacion se encuentra el ahorcado*/
{
    if(caso==0)
    {
        pf("\n\t    +---+\n");
        pf("\t    |   |\n");
        pf("\t\t|\n");
        pf("\t\t|\n");
        pf("\t\t|\n");
        pf("\t\t|\n");
        pf("\t=========''', '''\n");

    }
    else if(caso==1)
    {
        pf("\n\t    +---+\n");//
        pf("\t    |   |\n");
        pf("\t    O   |\n");
        pf("\t\t|\n");
        pf("\t\t|\n");
        pf("\t\t|\n");
        pf("\t=========''', '''\n");

    }
    else if(caso==2)
    {
        pf("\n\t    +---+\n");//
        pf("\t    |   |\n");
        pf("\t    O   |\n");
        pf("\t    |   |\n");
        pf("\t\t|\n");
        pf("\t\t|\n");
        pf("\t=========''', '''\n");

    }
    else if(caso==3)
    {
        pf("\n\t    +---+\n");//
        pf("\t    |   |\n");
        pf("\t    O   |\n");
        pf("\t    |%c  |\n",92);
        pf("\t\t|\n");
        pf("\t\t|\n");
        pf("\t=========''', '''\n");

    }
    else if(caso==4)
    {
        pf("\n\t    +---+\n");//
        pf("\t    |   |\n");
        pf("\t    O   |\n");
        pf("\t   /|%c  |\n",92);
        pf("\t\t|\n");
        pf("\t\t|\n");
        pf("\t=========''', '''\n");

    }
    else if(caso==5)
    {
        pf("\n\t    +---+\n");//
        pf("\t    |   |\n");
        pf("\t    O   |\n");
        pf("\t   /|%c  |\n",92);
        pf("\t     %c  |\n",92);
        pf("\t\t|\n");
        pf("\t=========''', '''\n");

    }
    else if(caso==6)
    {
        pf("\n\t    +---+\n");//
        pf("\t    |   |\n");
        pf("\t    O   |\n");
        pf("\t   /|%c  |\n",92);
        pf("\t   / %c  |\n",92);
        pf("\t\t|\n");
        pf("\t=========''', '''\n");

    }
}

void texto_batalla()
{
    pf("\n\t       :::::::::      ::: ::::::::::: :::     :::        :::            :::           ::::    :::     :::     :::     :::     :::     :::  ");
    pf("\n\t      :+:    :+:   :+: :+:   :+:   :+: :+:   :+:        :+:          :+: :+:         :+:+:   :+:   :+: :+:   :+:     :+:   :+: :+:   :+:   ");
    pf("\n\t     +:+    +:+  +:+   +:+  +:+  +:+   +:+  +:+        +:+         +:+   +:+        :+:+:+  +:+  +:+   +:+  +:+     +:+  +:+   +:+  +:+    ");
    pf("\n\t    +#++:++#+  +#++:++#++: +#+ +#++:++#++: +#+        +#+        +#++:++#++:       +#+ +:+ +#+ +#++:++#++: +#+     +:+ +#++:++#++: +#+     ");
    pf("\n\t   +#+    +#+ +#+     +#+ +#+ +#+     +#+ +#+        +#+        +#+     +#+       +#+  +#+#+# +#+     +#+  +#+   +#+  +#+     +#+ +#+      ");
    pf("\n\t  #+#    #+# #+#     #+# #+# #+#     #+# #+#        #+#        #+#     #+#       #+#   #+#+# #+#     #+#   #+#+#+#   #+#     #+# #+#       ");
    pf("\n\t #########  ###     ### ### ###     ### ########## ########## ###     ###       ###    #### ###     ###     ###     ###     ### ########## \n");
}

void Despedida(){
    pf("\n   ___                              _                               _ __                                   ");
    pf("\n  / __|     _ _   __ _     __      (_)    __ _     ___      o O O  | '_ %c   ___      _ _     o O O         ",92);
    pf("\n | (_ |    | '_| / _` |   / _|     | |   / _` |   (_-<     o       | .__/  / _ %c    | '_|   o              ",92);
    pf("\n  %c___|   _|_|_  %c__,_|   %c__|_   _|_|_  %c__,_|   /__/_   TS__[O]  |_|__   %c___/   _|_|_   TS__[O]         ",92,92,92,92,92);
    pf("\n_|*****|_|*****|_|*****|_|*****|_|*****|_|*****|_|*****| {======|_|*****|_|*****|_|*****| {======|         ");
    pf("\n%c`-0-0-'%c`-0-0-'%c`-0-0-'%c`-0-0-'%c`-0-0-'%c`-0-0-'%c`-0-0-'./o--000'%c`-0-0-'%c`-0-0-'%c`-0-0-'./o--000'         ",34,34,34,34,34,34,34,34,34,34);
    pf("\n    (_)            __ _                     _       _               ___     _       _                      ");
    pf("\n    | |   _  _    / _` |  __ _      _ _    | |     | |     ");
    pf("\n   _/ |  | +| |   %c__, | / _` |    | '_|   |_|     |_|    ",92);
    pf("\n  |__/_   %c_,_|   |___/  %c__,_|   _|_|_   _(_)_   _(_)_  ",92,92,92,92);
    pf("\n_|*****|_|*****|_|*****|_|*****|_|*****|_|*****|_|*****| {======|_|*****|_|*****|_|*****|_|*****| {======| ");
    pf("\n%c`-0-0-'%c`-0-0-'%c`-0-0-'%c`-0-0-'%c`-0-0-'%c`-0-0-'%c`-0-0-'./o--000'%c`-0-0-'%c`-0-0-'%c`-0-0-'%c`-0-0-'./o--000'         ",34,34,34,34,34,34,34,34,34,34,34);
    
}
