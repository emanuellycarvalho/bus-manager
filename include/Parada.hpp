#include <string>

using namespace std;


class Parada {
    private:
        int id;
        string nome;
        double distanciaPartida;

    public:
        static int contadorId;

        // construtores
        Parada(string nome, double distanciaPartida);
        
        // outros metodos
        double calcularDistancia(Parada destino);
        bool eApos(Parada destino); // verifica se o destino está após o objeto

        // getters e setters
        int getId();

        string getNome();
        void setNome(string nome);

        double getDistanciaPartida();
        void setDistanciaPartida(double distanciaPartida);
};