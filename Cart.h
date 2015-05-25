#ifndef CART_H
#define CART_H
#include <iostream>
#include <vector>


using namespace std;




class Cart
{
    public:
        int Valor,PuntajE;
        char Color;
        Cart(int,int,char);
        void imprimir_Atributos_deCarta();
};


class Jugador
{
    public:
        Jugador *siguiente,*anterior;
        string Nombre;
        int posicion_Last_Cart;
        bool dijoUno;
        vector <Cart> Seven7Cartas;
        ///Baraja Baraja_player;


        Jugador(string);
        ///Metodos
        void recibir_Cartas(Cart);
        void imprimir_Cartas();
        int elegir_posicion_de_Carta(); ///elige una carta de su vector Seven7Cartas
        Cart lanzar_carta(int); /// una variable de tipo CARTA se le asigna esa carta
        void eliminar_Cart_Lanzada();
        void sacar_carta_de_Mesa();
        void Decir_UNO();
        void cambio_de_estado_de_haber_dicho_UNO();
        bool encontrar_carta_con_mismo_color(Cart);
        bool encontrar_carta_con_mismo_valor(Cart);
        bool encontrar_carta_espec();
        bool buscar_Cart(int);
        bool buscar_carta_con_color(char);


};

class Baraja
{
    public:
        vector <Cart> BarajaTM;
        Cart *actual;
        Baraja ();///forma la baraja
        vector <Cart> FormBaraja();
        vector<Cart> Aleatoriar(vector<Cart>);
        char color_requisi; ///Variable para funcion lanzar_Carta_de_color(), utilizada al lanzar Cartas +4 || Cambio de Color
        bool act_desc_requisito;
        int cartasAcumuladas; ///
        void Print_Baraja();

        void Aumentar_n_Cart(vector<Cart>,int);   ///Aumenta n cartas al jugador
        void Cambiar_Direccion();
        char pedir_ingrese_un_color(); ///funcion para las cartas '+4' y para 'Cambio de Color'
        bool compararColor(Cart); ///compara el color de BarajaTM y Carta Lanzada
        bool compararValor(Cart);
        bool preguntar_compatibilidad(Cart); ///Pregunta si es compatible la Cartlanzada con la CartUltima de BarajaMesa
        bool Comparar_si_cartas_identicas(Cart, Cart);
        Cart lanzar_Carta_de_color(char,Cart);
        Cart accesa_noAccesa_Cart(Cart,Jugador* );
};



class Lista_Circular_de_Jugadores
{
    public:
        Jugador *jugador1,*p;
        bool ante_sigui;

        Lista_Circular_de_Jugadores(int);
        void cambiar_direccion_de_juego(); ///Cambia la direccion de turno de Player
        void Continuidad_de_Jugadores();
};

class Juego
{
    public:


        int cantidad_Jugadores;
        Jugador *TurnoJugador; ///Pointer to actual jugador
        Lista_Circular_de_Jugadores Lista;
        vector <Cart> BarajaGame;
        Juego();

        ///Funciones de CC, CCE, CE

        ///Hacer grupo de Jugadores
        void Forma_Grupo_de_Jugadores();  ///Pide la cantidad de jugadores, Se llama al Constructor de Lista_Circular_de_Jugadores
        void repartir_Cartas_a_BarajaGame_Y_Players(); ///Interactuar con BarajaGame y l miembr Baraja_player de la clase Jugador
        void Siguiente_turno_AND_give_puntaje(Cart); /// ~  se incluye a la funcion reversa =>Si la carta lanzada es reversa , entonces el puntero TurnoJugador debe ir hacia el otro sentido


};

#endif // CART_H
