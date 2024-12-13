#include "Parada.hpp";
#include "Onibus.hpp";
#include "Data.hpp";

class Viagem {
private:
    Parada origem;
    Parada destino;
    Onibus onibus;
    Data data;

public:
    // construtores
    Viagem(Parada origem, Parada destino, Onibus onibus, Data data);
    
    // getteres e setteres
    Parada getOrigem();
    void setOrigem(Parada origem);

    Parada getDestino();
    void setDestino(Parada destino);

    Onibus getOnibus();
    void setOnibus(Onibus onibus);

    Data getData();
    void setData(Data data);
};