#include "../include/Viagem.hpp"
#include <iostream>

Viagem::Viagem(Parada* origem, Parada* destino, Onibus* onibus, Data data)
    : origem(origem), destino(destino), onibus(onibus), data(data) {
        if(origem == nullptr) {
            throw invalid_argument("Origem não pode ser nula");
        }
        if(destino == nullptr) {
            throw invalid_argument("Destino não pode ser nulo");
        }
        if(onibus == nullptr) {
            throw invalid_argument("Onibus não pode ser nulo");
        }
        this->numAssentosLivres = onibus->getNumAssentos();
}

bool Viagem::verificarDisponibilidade() {
    return numAssentosLivres > 0;
}

bool Viagem::incluiOTrecho(Parada* origem, Parada* destino) {
    return origem->getDistanciaPartida() >= this->origem->getDistanciaPartida() &&
           destino->getDistanciaPartida() <= this->destino->getDistanciaPartida();
}

double Viagem::calcularTempoViagemCompleta() {
    return origem->calcularDistancia(*destino) / onibus->getVelocidadeMedia();
}

double Viagem::calcularTempoTrecho(Parada* origem, Parada* destino) {
    return origem->calcularDistancia(*destino) / onibus->getVelocidadeMedia();
}

Parada* Viagem::getOrigem() {
    return origem;
}

void Viagem::setOrigem(Parada* origem) {
    if(origem == nullptr) {
        throw invalid_argument("Origem não pode ser nula");
    }
    this->origem = origem;
}

Parada* Viagem::getDestino() {
    return destino;
}

void Viagem::setDestino(Parada* destino) {
    if(destino == nullptr) {
        throw invalid_argument("Destino não pode ser nulo");
    }
    this->destino = destino;
}

Onibus* Viagem::getOnibus() {
    return onibus;
}

void Viagem::setOnibus(Onibus* onibus) {
    if(onibus == nullptr) {
        throw invalid_argument("Onibus não pode ser nulo");
    }
    this->onibus = onibus;
}

int Viagem::getNumAssentosLivres() {
    return numAssentosLivres;
}

void Viagem::ocuparAssento() {
    if(this->numAssentosLivres == 0) {
        throw invalid_argument("Não há assentos livres");
    }
    this->numAssentosLivres = this->numAssentosLivres - 1;
}

void Viagem::desocuparAssento() {
    this->numAssentosLivres = this->numAssentosLivres + 1;
}

Data Viagem::getData() {
    return data;
}

void Viagem::setData(Data data) {
    this->data = data;
}
