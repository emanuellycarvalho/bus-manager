#include "Viagem.cpp";
#include "Reserva.cpp";

class Operacional {
private:
    Reserva **reservas;
    Viagem **viagens;

public:

    // outros metodos
    Reserva* realizarReserva(Data data, string cpf);
    Reserva* realizarReserva(Data data, string cpf, Parada* origem, Parada* destino);

    bool cancelarReserva(Data data, string cpf);

    bool validarCPF(string cpf); 
};
