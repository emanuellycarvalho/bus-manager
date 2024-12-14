#include "Parada.hpp"

Parada::Parada(int index, string nome, double distanciaPartida)
    : index(index), nome(nome), distanciaPartida(distanciaPartida) {}

double Parada::calcularDistancia(Parada destino) {
    return abs(destino.getDistanciaPartida() - distanciaPartida);
}

bool Parada::eApos(Parada destino) {
    return distanciaPartida < destino.getDistanciaPartida();
}

string Parada::getNome() {
    return nome;
}

void Parada::setNome(string nome) {
    this->nome = nome;
}

double Parada::getDistanciaPartida() {
    return distanciaPartida;
}

void Parada::setDistanciaPartida(double distanciaPartida) {
    this->distanciaPartida = distanciaPartida;
}
