#include "Viagem.hpp";

class Reserva {
private:
    Viagem *viagem;
    string cpf;
    double valorPassagem;
    Parada *origem;
    Parada *destino;

public:
    // construtores
    Reserva(Viagem *viagem, string cpf);
    Reserva(Viagem *viagem, string cpf, Parada* origem, Parada* destino);
    
    // outros metdos 
    bool cancelarReserva();
    
    bool calcularValorPassagem(Parada* origem, Parada* destino);
    bool calcularValorPassagem();
    
    // getteres e setteres
    Viagem* getViagem();
    void setViagem(Viagem *viagem);

    string getCPF();
    void setCPF(string cpf);

    double getValorPassagem();
    void setValorPassagem(double valorPassagem);

    Parada* getOrigem();
    void setOrigem(Parada* origem);

    Parada* getDestino();
    void setDestino(Parada* destino);

    Data getData();
    void setData(Data data);
};
