#include "Reserva.hpp"

Reserva::Reserva(Viagem viagem, string cpf)
    : viagem(viagem), cpf(cpf), valorPassagem(0.0), origem(viagem.getOrigem()), destino(viagem.getDestino()) {}

Reserva::Reserva(Viagem viagem, string cpf, Parada origem, Parada destino)
    : viagem(viagem), cpf(cpf), origem(origem), destino(destino) {
    calcularValorPassagem();
}

bool Reserva::realizarReserva(Data data, string cpf) {
    // Implementar lógica de reserva com validação de CPF
    return true;
}

bool Reserva::realizarReserva(Data data, string cpf, Parada origem, Parada destino) {
    // Implementar lógica de reserva com origem/destino específicos
    return true;
}

bool Reserva::cancelarReserva(Data data, string cpf) {
    // Implementar lógica de cancelamento
    return true;
}

bool Reserva::validarCPF(string cpf) {
    // Implementar lógica de validação de CPF
    return true;
}

bool Reserva::cancelarReserva() {
    // Implementar lógica de cancelamento com base no objeto
    return true;
}

bool Reserva::calcularValorPassagem(Parada origem, Parada destino) {
    valorPassagem = origem.calcularDistancia(destino) * viagem.getOnibus().getValorKm();
    return true;
}

bool Reserva::calcularValorPassagem() {
    return calcularValorPassagem(origem, destino);
}

Viagem Reserva::getViagem() {
    return viagem;
}

void Reserva::setViagem(Viagem viagem) {
    this->viagem = viagem;
}

string Reserva::getCPF() {
    return cpf;
}

void Reserva::setCPF(string cpf) {
    this->cpf = cpf;
}

double Reserva::getValorPassagem() {
    return valorPassagem;
}

void Reserva::setValorPassagem(double valorPassagem) {
    this->valorPassagem = valorPassagem;
}

Parada Reserva::getOrigem() {
    return origem;
}

void Reserva::setOrigem(Parada origem) {
    this->origem = origem;
}

Parada Reserva::getDestino() {
    return destino;
}

void Reserva::setDestino(Parada destino) {
    this->destino = destino;
}
