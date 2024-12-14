#include <string>

using namespace std;

class Onibus {
private:
    string placa;
    int numAssentos;
    double velocidadeMedia;
    double valorKm;

public:
    // construtores
    Onibus(string placa, int numAssentos, double velocidadeMedia); // valor padrão: 5,00
    Onibus(string placa, int numAssentos, double velocidadeMedia, double valorKm);

    // getters e setters
    string getPlaca();
    void setPlaca(string placa);
    
    int getNumAssentos();
    void setNumAssentos(int numAssentos);
    
    double getVelocidadeMedia();
    void setVelocidadeMedia(double velocidadeMedia);
    
    double getValorKm();
    void setValorKm(double valorKm);
};
