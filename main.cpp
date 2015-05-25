#include <iostream>

#include "Cart.h"


#include <stdlib.h>
#include <cstddef>
#include <vector>

using namespace std;


    ///Juego UNO;

    ///1) preguntr cuantos jugadores
    ///2) Pedir nombres
    ///3)Juego.Forma_Grupo_de_Jugadores(int cantidad);

    ///4 Forma Baraja Aleaoriada
    ///reparte Cartas a:
        ///5 Jugador
        ///6 Mesa:
            ///6.1Compruba que la Primeracarta  es diferente a +4
            ///6.2Pila boca_Arriba
            ///6.3Pila boca_Abajo


    ///ComienzaBucle: mientras que el numero de elementos de la Baraja del jugador que esta siendo apuntado (Baraja_player.size()> a 0)
        ///7 Imprime Carta de Mesa, boca arriba
        ///8. Imprime las Cartas del Jugador
        ///9 El Juugador lanza su Carta
        /// Comparar compatibilidad entree carta de Mesa y CartaLanzada:
        ///..................................................................
        ///int valor_Carta_BarajaMesa=BarajaMesa.BarajaTM[0].Valor;    char color_de_Cata_Baraja_Mesa=BarajaMesa.BarajaTM[0].Color;
            ///if(BarajaMesa.BarajaTM[0].Valor<10)
            ///{ LLAMAR A AFUNCION        ***Comparando_Baraja_con_CC(Carta Carta_Lanzada)***
///**** esto va dentro de la Funcion****///
                ///int valor_Carta_BarajaMesa=BarajaMesa.BarajaTM[0].Valor;    char color_de_Cata_Baraja_Mesa=BarajaMesa.BarajaTM[0].Color;
                /// if(cartaLanzada.Valor<10)
                    ///if(valor_Carta_BarajaMesa==Carta_Lanzada.Valor || color_de_Cata_Baraja_Mesa==Carta_Lanzada.Color)
                        ///{
                            ///BarajaTM.push_back(Carta_Lanzada);
                        ///}
                    ///else {cout<<""Ingrese una carta valida"
                        ///Lista.jugador1->imprimir_Cartas();
                        ///int posicionCart;
                        ///cin>>posicionCart;
                        ///Lista.jugador->lanzar_carta(posicionCart);

                /// else
                    ///{
                    /// if(cartaLanzada.Valor==10)
                        ///Comprobar con un functin que se del mismo color
                        ///Darle +2 Cartas al siguiente Jugador
                    ///else
                        ///{
                             ///if(cartaLanzada.Valor==11)
                                ///{Comprobar que sea del mismo Color}
                                ///Lamar a la FUNTION CAMBIO DE SENTIDO
                             ///else
                                ///{
                                    ///if(cartaLanzada.Valor==12)
                                        ///Comprabar que sea del mismo color
                                        ///hacer que el puntero recorra un lugar mas, para quitar turno a sgt jugador
                                    ///else
                                        ///{
                                            ///if(cartaLanzada.Valor==13)
                                                ///Darle +4 Cartas al siguiente Jugador
                                                ///Pasar de Turno
                                            ///else
                                                ///{
                                                    ///if(cartaLanzada.Valor==14)
                                                        ///{

                                                        ///}
                                                ///}
                                        ///}
                                ///}
                        ///}
                    ///}
            ///}
            ///if(BarajaMesa.BarajaTM[0].Valor>=10 || BarajaMesa.BarajaTM[0].Valor<13)
                ///{
                    ///
                ///}
int Preguntar_si_Carta_es_MasCuatro(Baraja A,int siguienteCarta)
    {
        while(A.BarajaTM[siguienteCarta].Valor==13)
        {
            siguienteCarta=siguienteCarta+1;
        }
        return siguienteCarta;
    }


int main()
{
    int cantidad_Jugadores=0;
    bool aceptaCartaLanzada;  /// esta variable me permite definir si la Carta Lanzada entrra a Baraja Mesa, so , si la carta Lanzada es correcta
    Baraja BarajaCompleta;  ///Se llama Baraja completa porque aqui se origina la baraja para todo el juego, depues de 5)se convierte en la Pila boca_Abajo
    bool cambio_de_color; ///esta variable me dira si el jugador debe lanzar una carta de un color especifico
    char selec_color; ///es el color elegido por el jugador que lanzo'  '+4' , 'CAMBIO DE COLOR'
    bool act_desc_requisitoC=false; ///esta variable activa o desazctiva la funcion para lanzar carta con requisito

    Baraja BarajaMesa;  ///Pila boca_Arriba
    BarajaCompleta.FormBaraja(); ///Forma la Baraja completa
    /*  P.I   // */
        //BarajaCompleta.Print_Baraja();  ///Imprime la Baraja Ordenada
    /*  P.I    */
    cout<<"Ingrese Cantidad de Jugadores"<<endl;

    /*1)*/while(cantidad_Jugadores<2 || cantidad_Jugadores>4)
    {
        cout<<"2"<<endl;
        cout<<"3"<<endl;
        cout<<"4"<<endl<<endl;
        cin>>cantidad_Jugadores;
    }
    /*2) 3)*/Lista_Circular_de_Jugadores Lista(cantidad_Jugadores);
    /*4*/BarajaCompleta.BarajaTM=BarajaCompleta.Aleatoriar(BarajaCompleta.BarajaTM );

/* P.I // */
 int g;
 cout<<"Continuar >7"<<endl;
cin>>g;
 if(g==7)
 {
    system("CLS");
 }


    cout<<"Baraja.Aleatoriar"<<endl;
    BarajaCompleta.Print_Baraja();   ///Imprime la baraja desordenada

/* P.I */

    ///Reparto cartas a los jugadores
    for (int cont=0;cont<cantidad_Jugadores*7;cont++)
    {
        Lista.jugador1->Seven7Cartas.push_back(BarajaCompleta.BarajaTM[cont]);  ///Jugador 1 recibe la 1 Carta. Tambien se puede utilizar la linea de abajo para que el jugador reciba la carta mediante UNA FUNCION DE Jugador
       /// Lista.jugador1->recibir_Cartas(BarajaCompleta.BarajaTM[cont]);
        BarajaCompleta.BarajaTM.erase(BarajaCompleta.BarajaTM.begin()+0);  ///Elimino cada Cart repartida de la BarajaCompleta
        Lista.jugador1=Lista.jugador1->siguiente;                       ///El puntero avanza al siguiente Jugador, para que reciba la siguietne carta
    }
        ///El puntero jugador1 apuntara al primer Jugador que haya ingresado su nombre


    cout<<"reparti baraja a jugadores , la baraja queda asi"<<endl;
    BarajaCompleta.Print_Baraja();



    int sigCarta=0;
 /// 6.1
    sigCarta=Preguntar_si_Carta_es_MasCuatro(BarajaCompleta,sigCarta); ///Uso la funcion para preguntar si la primera Carta es +4, si fuese entoncess sigCarta cambia a segunda y asi hasta encontrar una carta que no se +4

    /* P.I// */
    cout<<"SiguiCarta (si sale 0, significa que la primerqa carta en la mesa no era +4): "<<sigCarta<<endl;
    /* P.I */

    /// 6.2         Reparto la primera carta de BarajaCompleta_ a la Mesa

    BarajaMesa.BarajaTM.push_back(BarajaCompleta.BarajaTM[sigCarta]); ///BarajaMesa recibe la primera carta diferente  de Carta +4 de BarajaCompleta

    /// 6.3
    BarajaCompleta.BarajaTM.erase(BarajaCompleta.BarajaTM.begin()+sigCarta);  /// BarajaCompleta elimina esa Cart de su vector  , se convierte en Pila Boca Abajo



    cout<<"Cartas Boca Arriba: "<<endl;
    BarajaMesa.Print_Baraja();

    ///Condicionales de las Cartas CCE Y CE
    if(BarajaMesa.BarajaTM[0].Valor==10)
    {
        cout<<"El jugadpor "<<Lista.jugador1->Nombre<<" Roba 2 Cart"<<endl;
        cout<<"Terminar esta seccion"<<endl;
    }

/* P.I */
    cout<<"Continuar -> 7"<<endl;
    cin>>g;
    if (g==7)
    {
        system("CLS");
    }

    cout<<"reparti baraja a Mesa, la baraja boca abajo queda asi"<<endl;
    BarajaCompleta.Print_Baraja();
/* P.I */

    Cart Carta_Mesa(0,0,'m'),Carta_Lanzada(0,0,'l');  /// los colores de estas cartas son referenciales , sirven para instanciarlas porque se les asignara otras Cartas
    int unsigned Posicion_de_Carta=0;  /// Variable para que el usuario elija la posicion
    int unsigned Last_Posicion_de_cartaBoocaArriba=0;
    //int opcion;
    bool sig_ant_Jugador=true;  ///Variable que determina el direccion de juego
/// Comienza el juego

while(Lista.jugador1->Seven7Cartas.size()>0)
{
    cout<<"Mesa"<<endl;
    Carta_Mesa=BarajaMesa.BarajaTM[BarajaMesa.BarajaTM.size()-1];  ///Se asigna la ultima carta de BarajaMesa a Carta_Mesa
    Carta_Mesa.imprimir_Atributos_deCarta();           ///Se imprime la ultima carta de BarajaMesa
    cout<<".................."<<endl;


    ///Comprueba si jugador tiene cartas  para lanzar
     if (BarajaMesa.act_desc_requisito==true)  /// pregunta si hay algun requisito de color para lanzar Cart
     {
         if(Carta_Mesa.Valor==13 && Lista.jugador1->encontrar_carta_con_mismo_valor(Carta_Mesa)==true) ///Si jgador tiene Cart+4 y la cart_en _mesa es +4 entonces el jugador no recibe 4 cart
         {
             cout<<"Lanzar Cart"<<endl;
             Carta_Lanzada=BarajaMesa.accesa_noAccesa_Cart(Carta_Mesa,Lista.jugador1);
             ///A dar paso a cart
         }
         else
        {   cout<<Lista.jugador1->Nombre<<" Roba "<<BarajaMesa.cartasAcumuladas<<" Cart"<<endl;
            BarajaCompleta.Aumentar_n_Cart(Lista.jugador1->Seven7Cartas,BarajaCompleta.cartasAcumuladas);   ///Roba n Cart

        }

         if (Carta_Mesa.Valor==14) ///Si Cart en mesa es 'CAMBIO DE COLOR'
         {
            ///pregunta si el jugador tiene una carta con el color requerido  or  igual a la Cart_Mesa
            if(Lista.jugador1->buscar_carta_con_color(BarajaMesa.color_requisi)==true ||Lista.jugador1->encontrar_carta_con_mismo_valor(Carta_Mesa)==true)
            {
                cout<<"Lanzar Cart"<<endl;
                Carta_Lanzada=BarajaMesa.accesa_noAccesa_Cart(Carta_Mesa,Lista.jugador1);
                ///a dar paso a cart
            }
            else/// si no tiene entonces Robar Cartas_Acumuladas
            {
            cout<<Lista.jugador1->Nombre<<" Roba "<<BarajaMesa.cartasAcumuladas<<" Cart"<<endl;
            BarajaCompleta.Aumentar_n_Cart(Lista.jugador1->Seven7Cartas,BarajaCompleta.cartasAcumuladas);
            }
         }
     }
     else{

     if(BarajaMesa.act_desc_requisito==false) ///Si no hay requisito para lanzar Cart
     {

         cout<<"entre.......................................................................****"<<endl;
         if(Carta_Mesa.Valor==10 && BarajaMesa.cartasAcumuladas>1)  /// el ultimo argumento de if pregunta si el jugador previo se llevo las 2 or more cartas acumuladas
         {
            if(Lista.jugador1->encontrar_carta_con_mismo_valor(Carta_Mesa)==true)
            {
               Carta_Lanzada=BarajaMesa.accesa_noAccesa_Cart(Carta_Mesa,Lista.jugador1);
                ///a dar_paso_a_Car
            }
            else
            {

            cout<<Lista.jugador1->Nombre<<" Roba "<<BarajaMesa.cartasAcumuladas<<" Cart"<<endl;
             BarajaCompleta.Aumentar_n_Cart(Lista.jugador1->Seven7Cartas,BarajaCompleta.cartasAcumuladas);
            }
         }
         else
         {
             cout<<"entre"<<endl;
            if(Lista.jugador1->encontrar_carta_con_mismo_color(Carta_Mesa)==true || Lista.jugador1->encontrar_carta_con_mismo_valor(Carta_Mesa)==true|| Lista.jugador1->encontrar_carta_espec())
            {
                cout<<"Lanzar Cart"<<endl;
                Carta_Lanzada=BarajaMesa.accesa_noAccesa_Cart(Carta_Mesa,Lista.jugador1);
                ///a dar_paso_a_Car
            }
            else
            {
                BarajaCompleta.Aumentar_n_Cart(Lista.jugador1->Seven7Cartas,BarajaCompleta.cartasAcumuladas);
            }
         }
     }
     }
/**************************************/
    ///Borrar Cart Lanzada de Seven7Cart
    Lista.jugador1->eliminar_Cart_Lanzada();
    if(Carta_Lanzada.Valor==10)
    {
        BarajaCompleta.cartasAcumuladas=BarajaCompleta.cartasAcumuladas+2;
    }

    if(Carta_Lanzada.Valor==11)  ///Si Car. Lanzada es reversa
    {
        Lista.cambiar_direccion_de_juego();

    }

    if(Carta_Lanzada.Valor==12)
    {

        Lista.Continuidad_de_Jugadores();  //Reemplaza a lo de abjao
        cout<<Lista.jugador1->Nombre<<" pierde turn"<<endl;
        /*
        if(Lista.ante_sigui==true){
            Lista.jugador1=Lista.jugador1->siguiente;
         }
        else{
            Lista.jugador1=Lista.jugador1->anterior;
        }*/
    }

    if(Carta_Lanzada.Valor==14)
    {
        BarajaMesa.act_desc_requisito=!BarajaMesa.act_desc_requisito;
        BarajaMesa.pedir_ingrese_un_color();
    }


    ///A la barajaMesa add Carta Lanzada, si llego aqui es valida
    BarajaMesa.BarajaTM.push_back(Carta_Lanzada);





     cout<<"Continuar -> 7"<<endl;
    cin>>g;
    if (g==7)
    {
        system("CLS");
    }




    Lista.Continuidad_de_Jugadores(); ///probr q funcione
    cout<<"JuGADOR SIGUIENTE"<<endl;
    }



    return 0;
}
