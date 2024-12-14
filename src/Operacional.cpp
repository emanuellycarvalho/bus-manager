#include "Operacional.hpp"
#include <iostream>

using namespace std;

Reserva* Operacional::realizarReserva(Data data, string cpf) {
    if(!validarCPF(cpf)){
        cout << "CPF inválido." << endl;
        return nullptr;
    }

    string erro = "";
    for (int i = 0; viagens[i] != nullptr; i++) {
        Viagem* viagem = viagens[i];
        erro = "Não há viagem para esta data.";

        if (viagem->getData() == data) {
            erro = "A viagem para esta data está lotada.";
            if (viagem->verificarDisponibilidade()) {
                Reserva* novaReserva = new Reserva(viagem, cpf);
                Onibus* onibus = viagem->getOnibus();
                onibus->setNumAssentosLivres(onibus->getNumAssentosLivres() - 1);

                cout << "Reserva realizada." << endl;
                return novaReserva;
            }
        }
    }

    cout << erro << endl;
    return nullptr;
}

Reserva* Operacional::realizarReserva(Data data, string cpf, Parada* origem, Parada* destino) {
    if(!validarCPF(cpf)){
        cout << "CPF inválido." << endl;
        return nullptr;
    }

    string erro = "";
    for (int i = 0; viagens[i] != nullptr; i++) {
        Viagem* viagem = viagens[i];
        erro = "Não há viagem para esta data.";

        if (viagem->getData() == data) {
            erro = "A viagem para esta data está lotada.";
            if (viagem->estaNoTrecho(origem, destino) && viagem->verificarDisponibilidade()) {
                Reserva* novaReserva = new Reserva(viagem, cpf);
                Onibus* onibus = viagem->getOnibus();
                onibus->setNumAssentosLivres(onibus->getNumAssentosLivres() - 1);

                cout << "Reserva realizada." << endl;
                return novaReserva;
            }
        }
    }

    cout << erro << endl;
    return nullptr;
}

bool Operacional::cancelarReserva(Data data, string cpf) {
    for (int i = 0; reservas[i] != nullptr; i++) {
        Reserva* reserva = reservas[i];
        
        if (reserva->getCPF() == cpf && reserva->getData() == data) {
            Viagem* viagem = reserva->getViagem();
            Onibus* onibus = viagem->getOnibus();
            onibus->setNumAssentosLivres(onibus->getNumAssentosLivres() + 1);
            
            delete reserva;
            reservas[i] = nullptr;
            return true;
        }
    }

    return false; 
}

bool Operacional::validarCPF(string cpf) {
    // Implementar lógica para validar CPF
    return cpf.length() == 11; 
}
