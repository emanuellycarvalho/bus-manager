#include "Viagem.hpp";

class Reserva {
private:
    Viagem viagem;
    string nomePassageiro;
    double valorPassagem;
    Parada origem;
    Parada destino;

public:
    // construtores
    Reserva(Viagem viagem, string nomePassageiro, double valorPassagem);
    Reserva(Viagem viagem, string nomePassageiro, double valorPassagem, Parada origem, Parada destino);

    // getteres e setteres
    Viagem getViagem();
    void setViagem(Viagem viagem);

    string getNomePassageiro();
    void setNomePassageiro(string nomePassageiro);

    double getValorPassagem();
    void setValorPassagem(double valorPassagem);

    Parada getOrigem();
    void setOrigem(Parada origem);

    Parada getDestino();
    void setDestino(Parada destino);

    Onibus getOnibus();
    void setOnibus(Onibus onibus);

    Data getData();
    void setData(Data data);
};
