#include <string>

using namespace std;

class Parada {
private:
    string nome;
    double distanciaPartida;

public:
    // construtores
    Parada(string nome, double distanciaPartida);

    // getteres e setteres
    string getNome();
    void setNome(string nome);

    double getDistanciaPartida();
    void setDistanciaPartida(double distanciaPartida);
};