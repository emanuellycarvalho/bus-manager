#include "Onibus.hpp"

Onibus::Onibus(string placa, int numAssentosLivres, double velocidadeMedia)
    : placa(placa), numAssentosLivres(numAssentosLivres), velocidadeMedia(velocidadeMedia), valorKm(5.0) {}

Onibus::Onibus(string placa, int numAssentosLivres, double velocidadeMedia, double valorKm)
    : placa(placa), numAssentosLivres(numAssentosLivres), velocidadeMedia(velocidadeMedia), valorKm(valorKm) {}

string Onibus::getPlaca() {
    return placa;
}

void Onibus::setPlaca(string placa) {
    this->placa = placa;
}

int Onibus::getNumAssentosLivres() {
    return numAssentosLivres;
}

void Onibus::setNumAssentosLivres(int numAssentosLivres) {
    this->numAssentosLivres = numAssentosLivres;
}

double Onibus::getVelocidadeMedia() {
    return velocidadeMedia;
}

void Onibus::setVelocidadeMedia(double velocidadeMedia) {
    this->velocidadeMedia = velocidadeMedia;
}

double Onibus::getValorKm() {
    return valorKm;
}

void Onibus::setValorKm(double valorKm) {
    this->valorKm = valorKm;
}
