#include <string>

using namespace std;

class Onibus {
private:
    string placa;
    int numAssentosLivres;
    double velocidadeMedia;
    double valorKm;

public:
    // construtores
    Onibus(string placa, int numAssentosLivres, double velocidadeMedia);
    Onibus(string placa, int numAssentosLivres, double velocidadeMedia, double valorKm);

    // getteres e setteres
    string getPlaca();
    void setPlaca(string placa);
    
    int getNumAssentosLivres();
    void setNumAssentosLivres(int numAssentosLivres);
    
    double getVelocidadeMedia();
    void setVelocidadeMedia(double velocidadeMedia);
    
    double getValorKm();
    void setValorKm(double valorKm);
};
