#include <string>

using namespace std;

class Parada {
private:
    int index;
    string nome;
    double distanciaPartida;

public:
    // construtores
    Parada(int index, string nome, double distanciaPartida);
    
    // outros metodos
    double calcularDistancia(Parada destino);
    bool eApos(Parada destino); // verifica se o destino está após o objeto

    // getteres e setteres
    string getNome();
    void setNome(string nome);

    double getDistanciaPartida();
    void setDistanciaPartida(double distanciaPartida);
};