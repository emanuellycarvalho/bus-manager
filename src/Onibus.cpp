#include "../include/Onibus.hpp"
#include <iostream>

Onibus::Onibus(string placa, int numAssentos, double velocidadeMedia)
    : placa(placa), numAssentos(numAssentos), velocidadeMedia(velocidadeMedia), valorKm(5.0) {
        if(placa.empty()) {
            throw invalid_argument("Placa não pode ser vazia");
        }
        if(numAssentos < 0) {
            throw invalid_argument("Número de assentos livres não pode ser negativo");
        }
        if(velocidadeMedia < 0) {
            throw invalid_argument("Velocidade média não pode ser negativa");
        }
    }

Onibus::Onibus(string placa, int numAssentos, double velocidadeMedia, double valorKm)
    : placa(placa), numAssentos(numAssentos), velocidadeMedia(velocidadeMedia), valorKm(valorKm) {
        if(placa.empty()) {
            throw invalid_argument("Placa não pode ser vazia");
        }
        if(numAssentos < 0) {
            throw invalid_argument("Número de assentos não pode ser negativo");
        }
        if(velocidadeMedia < 0) {
            throw invalid_argument("Velocidade média não pode ser negativa");
        }
        if(valorKm < 0) {
            throw invalid_argument("Valor por km não pode ser negativo");
        }
    }

string Onibus::getPlaca() {
    return placa;
}

void Onibus::setPlaca(string placa) {
    if(placa.empty()) {
        throw invalid_argument("Placa não pode ser vazia");
    }
    this->placa = placa;
}

int Onibus::getNumAssentos() {
    return numAssentos;
}

void Onibus::setNumAssentos(int numAssentos) {
    if(numAssentos < 0) {
        throw invalid_argument("Número de assentos não pode ser negativo");
    }
    this->numAssentos = numAssentos;
}

double Onibus::getVelocidadeMedia() {
    return velocidadeMedia;
}

void Onibus::setVelocidadeMedia(double velocidadeMedia) {
    if(velocidadeMedia < 0) {
        throw invalid_argument("Velocidade média não pode ser negativa");
    }
    this->velocidadeMedia = velocidadeMedia;
}

double Onibus::getValorKm() {
    return valorKm;
}

void Onibus::setValorKm(double valorKm) {
    if(valorKm < 0) {
        throw invalid_argument("Valor por km não pode ser negativo");
    }
    this->valorKm = valorKm;
}
