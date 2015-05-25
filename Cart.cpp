#include "Cart.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>

using namespace std;

Cart::Cart(int Valor,int PuntajE,char Color)
{
    this->Valor=Valor;
    this->PuntajE=PuntajE;
    this->Color=Color;
}

void Cart ::imprimir_Atributos_deCarta()
{
    cout<<Valor<<"   ";
    cout<<PuntajE<<"   ";
    cout<<Color<<endl;
}

Jugador::Jugador(string Nombre_Gamer)
{
    Nombre=Nombre_Gamer;
    dijoUno=false;
}

void Jugador::recibir_Cartas(Cart Carta_Recibida)
{
    Seven7Cartas.push_back(Carta_Recibida);
    return;
}

 void Jugador::imprimir_Cartas()
 {
     cout<<"Turno de Jugador: "<<Nombre<<endl;
     cout<<"Cartas"<<endl;
     int contTemporal=0, contCartasPlayer=Seven7Cartas.size();
     while(contTemporal<contCartasPlayer)
     {

      Seven7Cartas[contTemporal].imprimir_Atributos_deCarta();
      cout<<"........................."<<endl;
      contTemporal++;
     }
     return;
 }

 void Jugador::Decir_UNO()
 {
    if(dijoUno==false)
    {
        dijoUno=!dijoUno;
    }
 }

void Jugador::cambio_de_estado_de_haber_dicho_UNO()
{
    if(dijoUno==true)
    {
        dijoUno=!dijoUno;
    }
}

int Jugador::elegir_posicion_de_Carta()
{
    int unsigned posicion_de_Carta=0;
    while(posicion_de_Carta<1 || posicion_de_Carta>Seven7Cartas.size() || posicion_de_Carta==117)
            {
                cout<<"Elige una carta del 1-"<<Seven7Cartas.size()<<endl;
                cin>>posicion_de_Carta;
                if(posicion_de_Carta==117)
               {
                cout<<endl;
                cout<<"UNOOOO"<<endl;
                Decir_UNO(); ///El estado del Jugador es que tiene 1 Carta
                cout<<endl;
                }
            }
    posicion_Last_Cart=posicion_de_Carta-1; ///Guarda el numero de posicion de carta en Jugador
    return posicion_de_Carta-1;
}

Cart Jugador::lanzar_carta(int posicion_Cart)
{
    Cart Carta_Seleccinada(0,0,'c');

    Carta_Seleccinada=Seven7Cartas[posicion_Cart];
    return Carta_Seleccinada;
}

void Jugador::eliminar_Cart_Lanzada()
{
    cout<<Nombre<<" dice    Borre cata de mi baraja "<<endl;
    Seven7Cartas.erase(Seven7Cartas.begin()+posicion_Last_Cart);
}

bool Jugador::encontrar_carta_con_mismo_color(Cart Carta_en_Mesa)
{
    char color=Carta_en_Mesa.Color;
    for(int unsigned gh=0;gh<Seven7Cartas.size();gh++)
    {
        if(Seven7Cartas[gh].Color==color)
        {   return true;
        }
    }
    return false;
}

bool Jugador::buscar_carta_con_color(char color_buscado)
{
    for(int unsigned gh=0;gh<Seven7Cartas.size();gh++)
    {
        if(Seven7Cartas[gh].Color==color_buscado)
        {   return true;
        }
    }
    return false;
}




bool Jugador::encontrar_carta_con_mismo_valor(Cart Carta_en_Mesa)
{
    int valor1=Carta_en_Mesa.Valor;
    for(int unsigned gh=0;gh<Seven7Cartas.size();gh++)
    {
        if(Seven7Cartas[gh].Valor==valor1)
        {   return true;
        }
    }
    return false;
}

bool Jugador::encontrar_carta_espec()
{
    for(int unsigned i=0;i<Seven7Cartas.size();i++)
    {
        if(Seven7Cartas[i].Valor==13 || Seven7Cartas[i].Valor==14)
        {
            return true;
        }
    }
    return false;
}
bool Jugador::buscar_Cart(int valor_Cart)
{
    for(int unsigned i=0;i<Seven7Cartas.size();i++)
    {
        if(Seven7Cartas[i].Valor==valor_Cart);
        {
            return true;
        }
    }
    return false;
}



Baraja::Baraja()
{
    cartasAcumuladas=0;

}

bool Baraja::compararColor(Cart Carta_comparada)
{
    if(BarajaTM[BarajaTM.size()-1].Color==Carta_comparada.Color)
    {
        return true;
    }
    //cout<<"Lance otra carta"<<endl;
    return false;
}
bool Baraja::compararValor(Cart Carta_comparada)
{
    if(BarajaTM[BarajaTM.size()-1].Color==Carta_comparada.Color)
    {
        BarajaTM.push_back(Carta_comparada); ///Agrego la Carta comparada al vector de Cartas
        return true;
    }
  //cout<<"Lance otra carta"<<endl;
    return false;
}



vector<Cart> Baraja ::FormBaraja()
{
    int i;
    int cont;
    char colores[4] = {'r','b','y','g'};

   for (int ap1=0;ap1<4;ap1++)  ///Forma las cartas 0 de cada color. comentVariab Contador_cartas = 4
    {
        actual=new Cart(0,0,colores[ap1]);

        BarajaTM.push_back(*actual);
    }

/// ****Esta es otra forma de agregar las Cartas sin ustilizar *actual
    /*
    for (int ap2=0;ap2<4;ap2++) ///Forma las cartas 0 de cada color. comentVariab Contador_cartas = 4
    {
        BarajaTM.push_back(Cart(0,0,colores[ap2]));
    }*/



    for (i=1; i<=14; i++)
    {
        if (i<=9)   ///Forma las cartas de 1-9 dous veces
        {   cont=2;
            while (cont>0)
            {
                actual=new Cart(i,i,'r');
                BarajaTM.push_back(*actual);
                actual=new Cart(i,i,'b');
                BarajaTM.push_back(*actual);
                actual=new Cart(i,i,'y');
                BarajaTM.push_back(*actual);
                actual=new Cart(i,i,'g');
                BarajaTM.push_back(*actual);
                cont--;
            }
        }
        if (i==10 || i==11 || i==12) ///Forma Cartas Color Especial (+2, Reversa, o/)
        {
            cont=2;
            while (cont>0)
            {
            /* Activar esto y comentar esto /for/ ,si ocurren errores.*/
              /*  actual=new Cart(i,20,'r');
                BarajaTM.push_back(*actual);
                actual=new Cart(i,20,'b');
                BarajaTM.push_back(*actual);
                actual=new Cart(i,20,'y');
                BarajaTM.push_back(*actual);
                actual=new Cart(i,20,'g');
                BarajaTM.push_back(*actual);*/
              //for//
                for(int asU1=0;asU1<4;asU1++)
                {
                    actual=new Cart(i,20,colores[asU1]);
                    BarajaTM.push_back(*actual);
                }
            //for//
                cont--;
            }
        }
        if (i==13 || i==14)
        {   cont=4;
            while(cont>0)
            {
                actual=new Cart(i,50,'S');
                BarajaTM.push_back(*actual);
                cont--;
            }
        }

    }
    return BarajaTM;
}

vector<Cart> Baraja::Aleatoriar(vector<Cart> Baraja_sin_Mezclar)
{
    int n;
    int num_Aleatorio;

    srand(time(NULL));
    vector <Cart> Baraja_Temp2;
    n=Baraja_sin_Mezclar.size();
    while (n!=0)
    {
        num_Aleatorio=rand()%n;
        Baraja_Temp2.push_back(Baraja_sin_Mezclar[num_Aleatorio]);
        Baraja_sin_Mezclar.erase(Baraja_sin_Mezclar.begin()+num_Aleatorio); ///borra el begin mas la posicion deseada menos 1
        n--;

    }
    Baraja_sin_Mezclar=Baraja_Temp2;
    return Baraja_sin_Mezclar;///agrego cartas a mazo (oficial)y las borro de mazo para aleatorear el mazo
}

void Baraja::Print_Baraja()
{
    int cantCarts=BarajaTM.size()-1;
    int cont=0;
    cout<<"Baraja con "<<BarajaTM.size()<<" cartas."<<'\n';

    while(cont<=cantCarts)
    {
        cout<<BarajaTM[cont].Valor<<"   ";
        cout<<BarajaTM[cont].PuntajE<<"   ";
        cout<<BarajaTM[cont].Color<<endl;
        cont++;
    }
}

/// unfinished
void Baraja::Aumentar_n_Cart(vector<Cart> Cartas_de_Jugador,int masN)  ///Funcion de Baraja que recibe la baraja del Jugador, masN puede ser '+2' or '+4'
{
    while(masN>0)
    {
    Cartas_de_Jugador.push_back(BarajaTM[BarajaTM.size()-1]); ///Se le agrega la ultima carta de la Baraja
    BarajaTM.erase(BarajaTM.begin()+(BarajaTM.size()-1));
    }
}



char Baraja::pedir_ingrese_un_color()
{
    char color='X';
    while(color!='r'&& color!='b' && color!='g'&&
           color!='y')
    {   cout<<"Elija un color"<<endl;
        cout<<"Red -> r"<<'\n'<<"Blue -> b"<<endl;
        cout<<"Green -> g"<<'\n'<<"Yellow -> y"<<endl;
        cin>>color;
    }
    color_requisi=color;
    return color;
}

bool Baraja::preguntar_compatibilidad(Cart Lanzada)
{
    if(compararColor(Lanzada)==false || compararValor(Lanzada)==false)
    {
        return false;
    }
    return true;
}
/*
bool Baraja::Comparar_si_cartas_identicas(Cart Carta_aComparar, Cart Cart_Comparada)
{
    if (Carta_aComparar.Valor==Cart_Comparada)
        {return true;}
    return false;
}*/



Cart Baraja:: accesa_noAccesa_Cart (Cart Cart_en_Mesa,Jugador* jugadorActual)
{
    cout<<"ok"<<endl;
Cart Cart_Lanzada(0,0,'p');
int posicionCart;
jugadorActual->imprimir_Cartas();
posicionCart=jugadorActual->elegir_posicion_de_Carta();
cout<<"Debio imprimir peticion de elegir posicion de cart"<<endl;
Cart_Lanzada=jugadorActual->lanzar_carta(posicionCart);
Cart_Lanzada.imprimir_Atributos_deCarta();

 ///Jugador eligio su carta
if(Cart_en_Mesa.Valor<10)
{
    if(Cart_Lanzada.Color==Cart_en_Mesa.Color || Cart_Lanzada.Valor==Cart_en_Mesa.Valor || Cart_Lanzada.Valor>12)
    {
        return Cart_Lanzada;
    }
    else
    {
        return accesa_noAccesa_Cart(Cart_en_Mesa,jugadorActual);
    }
}
if(Cart_en_Mesa.Valor==10)
{
    if(Cart_Lanzada.Valor==10)
        {
            //cartasAcumuladas=cartasAcumuladas+2; ///No stoy segura
            return Cart_Lanzada;
        }
    if(cartasAcumuladas>1 && Cart_Lanzada.Valor!=10)
    {
        return accesa_noAccesa_Cart(Cart_en_Mesa,jugadorActual);
    }
    else
    {
        if(Cart_Lanzada.Color!=Cart_en_Mesa.Color)
        {
            return accesa_noAccesa_Cart(Cart_en_Mesa,jugadorActual);
        }
        return Cart_Lanzada;

    }

}
if(Cart_en_Mesa.Valor==11)
{
    if(Cart_Lanzada.Color==Cart_en_Mesa.Color || Cart_Lanzada.Valor==Cart_en_Mesa.Valor)
    {
        return Cart_Lanzada;
    }
    else
    {
        return accesa_noAccesa_Cart(Cart_en_Mesa,jugadorActual);
    }
}

if (Cart_en_Mesa.Valor==12)
{
    if(Cart_Lanzada.Color==Cart_en_Mesa.Color || Cart_Lanzada.Valor==Cart_en_Mesa.Valor)
    {
        return Cart_Lanzada;
    }
    else
    {
    return accesa_noAccesa_Cart(Cart_en_Mesa,jugadorActual);
    }
}

if(Cart_en_Mesa.Valor==13)
{
    if(Cart_Lanzada.Valor==13)
    {
       // cartasAcumuladas=cartasAcumuladas+4;
        return Cart_Lanzada;
    }
    else{
        if(act_desc_requisito==true && Cart_Lanzada.Color==color_requisi)
        {
            return Cart_Lanzada;
            act_desc_requisito=!act_desc_requisito;  ///Desact requisito
        }
        else{
            return accesa_noAccesa_Cart(Cart_en_Mesa,jugadorActual);}
    }
}

if(Cart_en_Mesa.Valor==14)
{
    if(Cart_Lanzada.Valor==14 || (act_desc_requisito==true && Cart_Lanzada.Color==color_requisi))
    {
        return Cart_Lanzada;
        act_desc_requisito=!act_desc_requisito;  ///Desact requisito
    }
    ///else
    return accesa_noAccesa_Cart(Cart_en_Mesa,jugadorActual);
}
 return Cart_Lanzada;

}





Lista_Circular_de_Jugadores::Lista_Circular_de_Jugadores(int cant_Players)
{
    ante_sigui=true;  /// el jugador proximo es el siguiente
    string Nombre_Player;
    Jugador *Puntero_Temporal_ant,*Puntero_Temporal_Auxiliar;

    cout<<"Ingrese su nombre"<<endl;
    cin>>Nombre_Player;
    jugador1=new Jugador(Nombre_Player);
    Puntero_Temporal_Auxiliar=Puntero_Temporal_ant=jugador1;

    while(cant_Players>1)
    {

        cout<<"Ingrese su nombre"<<endl;
        cin>>Nombre_Player;
        jugador1=new Jugador(Nombre_Player);
        jugador1->anterior=Puntero_Temporal_Auxiliar;
        Puntero_Temporal_Auxiliar->siguiente=jugador1;
        cant_Players--;
        Puntero_Temporal_Auxiliar=Puntero_Temporal_Auxiliar->siguiente;


    }
    Puntero_Temporal_ant->anterior=Puntero_Temporal_Auxiliar;
    Puntero_Temporal_Auxiliar->siguiente=Puntero_Temporal_ant;
    jugador1=jugador1->siguiente; ///El puntero jugador1 apunta al primer elemento creado , para que este inicie la partida

}

void Lista_Circular_de_Jugadores::cambiar_direccion_de_juego()
{
    if(ante_sigui==true) /// ==1
    {
        cout<<"Cambio Anti "<<endl;
        ante_sigui=!ante_sigui;

    }
    else
    {
        ante_sigui=!ante_sigui;
        //p=jugador1->anterior;
    }
}

void Lista_Circular_de_Jugadores::Continuidad_de_Jugadores()
{
    if(ante_sigui==true)   /// si recibo un true la direcc es siguiente
    {
        jugador1=jugador1->siguiente;
    }
    else
    {  jugador1=jugador1->anterior; }
}
