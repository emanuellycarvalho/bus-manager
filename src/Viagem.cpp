#include "Viagem.hpp"

Viagem::Viagem(Parada* origem, Parada* destino, Onibus* onibus, Data data)
    : origem(origem), destino(destino), onibus(onibus), data(data) {}

bool Viagem::verificarDisponibilidade() {
    return onibus->getNumAssentosLivres() > 0;
}

bool Viagem::estaNoTrecho(Parada* origem, Parada* destino) {
    return origem->getDistanciaPartida() >= this->origem->getDistanciaPartida() &&
           destino->getDistanciaPartida() <= this->destino->getDistanciaPartida();
}

double Viagem::calcularTempoViagem() {
    return origem->calcularDistancia(*destino) / onibus->getVelocidadeMedia();
}

double Viagem::calcularTempoTrecho(Parada* origem, Parada* destino) {
    return origem->calcularDistancia(*destino) / onibus->getVelocidadeMedia();
}

Parada* Viagem::getOrigem() {
    return origem;
}

void Viagem::setOrigem(Parada* origem) {
    this->origem = origem;
}

Parada* Viagem::getDestino() {
    return destino;
}

void Viagem::setDestino(Parada* destino) {
    this->destino = destino;
}

Onibus* Viagem::getOnibus() {
    return onibus;
}

void Viagem::setOnibus(Onibus* onibus) {
    this->onibus = onibus;
}

Data Viagem::getData() {
    return data;
}

void Viagem::setData(Data data) {
    this->data = data;
}
