#include <gtest/gtest.h>
#include "../include/Reserva.hpp"

// Testes da classe Parada

TEST(ParadaTest, InicializarParadaComAtributosCorretos) {
    Parada novaParada("Nova Parada", 10.0);
    ASSERT_DOUBLE_EQ(novaParada.getId(), 1);
    ASSERT_EQ(novaParada.getNome(), "Nova Parada");
    ASSERT_DOUBLE_EQ(novaParada.getDistanciaPartida(), 10.0);
}

TEST(ParadaTest, InicializarParadaComNomeVazio) {
    ASSERT_THROW(Parada parada("", 10.0), invalid_argument);
}

TEST(ParadaTest, InicializarParadaComDistanciaNegativa) {
    ASSERT_THROW(Parada parada("Parada", -10.0), invalid_argument);
}

TEST(ParadaTest, CalcularDistanciaEntreParadasSentidoIda) {
    Parada origem("Origem", 10.0);
    Parada destino("Destino", 50.0);
    ASSERT_DOUBLE_EQ(origem.calcularDistancia(destino), 40.0);
}

TEST(ParadaTest, CalcularDistanciaEntreParadasSentidoVolta) {
    Parada origem("Origem", 60.0);
    Parada destino("Destino", 20.0);
    ASSERT_DOUBLE_EQ(origem.calcularDistancia(destino), 40.0);
}

TEST(ParadaTest, CalcularDistanciaEntreParadasMesmaPosicao) {
    Parada origem("Origem", 100.0);
    Parada destino("Destino", 100.0);
    ASSERT_THROW(origem.calcularDistancia(destino), invalid_argument);
}

TEST(ParadaTest, VerificarParadaEAposOutra) {
    Parada origem("Origem", 10.0);
    Parada destino("Destino", 50.0);
    ASSERT_TRUE(origem.eApos(destino));
}

TEST(ParadaTest, AlterarNomeParadaComNomeValido) {
    Parada parada("Origem", 0.0);
    parada.setNome("Nova Origem");
    ASSERT_EQ(parada.getNome(), "Nova Origem");
}

TEST(ParadaTest, AlterarNomeParadaComNomeVazio) {
    Parada parada("Origem", 0.0);
    ASSERT_THROW(parada.setNome(""), invalid_argument);
}

TEST(ParadaTest, DefinirDistanciaParadaComDistanciaValida) {
    Parada parada("Origem", 0.0);
    parada.setDistanciaPartida(200.0);
    ASSERT_DOUBLE_EQ(parada.getDistanciaPartida(), 200.0);
}

TEST(ParadaTest, DefinirDistanciaParadaComDistanciaNegativa) {
    Parada parada("Origem", 0.0);
    ASSERT_THROW(parada.setDistanciaPartida(-10.0), invalid_argument);
}

// Testes da classe Onibus

TEST(OnibusTest, InicializarOnibusComAtributosCorretosSemValorKm) {
    Onibus onibus("XYZ9876", 40, 60.0);
    ASSERT_EQ(onibus.getPlaca(), "XYZ9876");
    ASSERT_EQ(onibus.getNumAssentos(), 40);
    ASSERT_DOUBLE_EQ(onibus.getVelocidadeMedia(), 60.0);
    ASSERT_DOUBLE_EQ(onibus.getValorKm(), 5.0);
}

TEST(OnibusTest, InicializarOnibusComAtributosCorretosComValorKm) {
    Onibus onibus("XYZ9876", 40, 60.0, 10.0);
    ASSERT_EQ(onibus.getPlaca(), "XYZ9876");
    ASSERT_EQ(onibus.getNumAssentos(), 40);
    ASSERT_DOUBLE_EQ(onibus.getVelocidadeMedia(), 60.0);
    ASSERT_DOUBLE_EQ(onibus.getValorKm(), 10.0);
}

TEST(OnibusTest, InicializarOnibusComPlacaVazia) {
    ASSERT_THROW(Onibus onibus("", 40, 60.0), invalid_argument);
}

TEST(OnibusTest, InicializarOnibusComNumAssentosNegativo) {
    ASSERT_THROW(Onibus onibus("XYZ9876", -40, 60.0), invalid_argument);
}

TEST(OnibusTest, InicializarOnibusComVelocidadeMediaNegativa) {
    ASSERT_THROW(Onibus onibus("XYZ9876", 40, -60.0), invalid_argument);
}

TEST(OnibusTest, InicializarOnibusComValorKmNegativo) {
    ASSERT_THROW(Onibus onibus("XYZ9876", 40, 60.0, -10.0), invalid_argument);
}

// Testes da classe Viagem

TEST(ViagemTest, InicializarViagemComAtributosCorretos) {
    Onibus onibus("XYZ9876", 40, 60.0, 10.0);
    Parada origem("Origem", 0.0);
    Parada destino("Destino", 400.0);
    Data data(1, 1, 2024);

    Viagem viagem(&origem, &destino, &onibus, data);
    ASSERT_EQ(viagem.getOrigem()->getNome(), "Origem");
    ASSERT_EQ(viagem.getDestino()->getNome(), "Destino");
    ASSERT_EQ(viagem.getOnibus()->getPlaca(), "XYZ9876");
    ASSERT_EQ(viagem.getData().getAno(), 2024);
    ASSERT_EQ(viagem.getData().getMes(), 1);
    ASSERT_EQ(viagem.getData().getDia(), 1);
}

TEST(ViagemTest, InicializarViagemComOrigemNula) {
    Onibus onibus("XYZ9876", 40, 60.0, 10.0);
    Parada destino("Destino", 400.0);
    Data data(1, 1, 2024);

    ASSERT_THROW(Viagem viagem(nullptr, &destino, &onibus, data), invalid_argument);
}

TEST(ViagemTest, InicializarViagemComDestinoNulo) {
    Onibus onibus("XYZ9876", 40, 60.0, 10.0);
    Parada origem("Origem", 0.0);
    Data data(1, 1, 2024);

    ASSERT_THROW(Viagem viagem(&origem, nullptr, &onibus, data), invalid_argument);
}

TEST(ViagemTest, InicializarViagemComOnibusNulo) {
    Parada origem("Origem", 0.0);
    Parada destino("Destino", 400.0);
    Data data(1, 1, 2024);

    ASSERT_THROW(Viagem viagem(&origem, &destino, nullptr, data), invalid_argument);
}

TEST(ViagemTest, VerificarDisponibilidadeDeAssentos) {
    Onibus onibus("XYZ9876", 40, 60.0, 10.0);
    Parada origem("Origem", 0.0);
    Parada destino("Destino", 400.0);
    Data data(1, 1, 2024);

    Viagem viagem(&origem, &destino, &onibus, data);
    ASSERT_TRUE(viagem.verificarDisponibilidade());
}

TEST(ViagemTest, VerificarSeIncluiTrechoIncluso) {
    Onibus onibus("XYZ9876", 40, 60.0, 10.0);
    Parada origem("Origem", 0.0);
    Parada destino("Destino", 400.0);
    Data data(1, 1, 2024);

    Viagem viagem(&origem, &destino, &onibus, data);
    Parada novaParada("Nova Parada", 200.0);
    ASSERT_TRUE(viagem.incluiOTrecho(&origem, &novaParada));
}

TEST(ViagemTest, VerificarSeIncluiTrechoNaoIncluso) {
    Onibus onibus("XYZ9876", 40, 60.0, 10.0);
    Parada origem("Origem", 0.0);
    Parada destino("Destino", 400.0);
    Data data(1, 1, 2024);

    Viagem viagem(&origem, &destino, &onibus, data);
    Parada novaParada("Nova Parada", 500.0);
    ASSERT_FALSE(viagem.incluiOTrecho(&origem, &novaParada));
}

TEST(ViagemTest, CalcularTempoViagemCompleta) {
    Onibus onibus("XYZ9876", 40, 60.0, 10.0);
    Parada origem("Origem", 0.0);
    Parada destino("Destino", 400.0);
    Data data(1, 1, 2024);

    Viagem viagem(&origem, &destino, &onibus, data);
    ASSERT_DOUBLE_EQ(viagem.calcularTempoViagemCompleta(), 400.0 / 60.0);
}

TEST(ViagemTest, CalcularTempoTrecho) {
    Onibus onibus("XYZ9876", 40, 60.0, 10.0);
    Parada origem("Origem", 0.0);
    Parada destino("Destino", 400.0);
    Data data(1, 1, 2024);

    Viagem viagem(&origem, &destino, &onibus, data);
    Parada novaParada("Nova Parada", 200.0);
    ASSERT_DOUBLE_EQ(viagem.calcularTempoTrecho(&origem, &novaParada), 200.0 / 60.0);
}

TEST(ViagemTest, OcuparAssentoComAssentosDisponiveis) {
    Onibus onibus("XYZ9876", 40, 60.0, 10.0);
    Parada origem("Origem", 0.0);
    Parada destino("Destino", 400.0);
    Data data(1, 1, 2024);

    Viagem viagem(&origem, &destino, &onibus, data);
    viagem.ocuparAssento();
    ASSERT_EQ(viagem.getNumAssentosLivres(), 39);
}

TEST(ViagemTest, OcuparAssentoSemAssentosDisponiveis) {
    Onibus onibus("XYZ9876", 1, 60.0, 10.0);
    Parada origem("Origem", 0.0);
    Parada destino("Destino", 400.0);
    Data data(1, 1, 2024);

    Viagem viagem(&origem, &destino, &onibus, data);
    viagem.ocuparAssento();
    ASSERT_THROW(viagem.ocuparAssento(), invalid_argument);
}

// Testes da classe Reserva

TEST(ReservaTest, InicializarReservaComAtributosCorretos) {
    Onibus onibus("XYZ9876", 40, 60.0, 10.0);
    Parada origem("Origem", 0.0);
    Parada destino("Destino", 400.0);
    Data data(1, 1, 2024);
    Viagem viagem(&origem, &destino, &onibus, data);

    Reserva reserva(&viagem, "12345678901", &origem, &destino);
    ASSERT_EQ(reserva.getViagem()->getOrigem()->getNome(), "Origem");
    ASSERT_EQ(reserva.getViagem()->getDestino()->getNome(), "Destino");
    ASSERT_EQ(reserva.getViagem()->getOnibus()->getPlaca(), "XYZ9876");
    ASSERT_EQ(reserva.getViagem()->getData().getAno(), 2024);
    ASSERT_EQ(reserva.getViagem()->getData().getMes(), 1);
    ASSERT_EQ(reserva.getViagem()->getData().getDia(), 1);
    ASSERT_EQ(reserva.getCPF(), "12345678901");
    ASSERT_DOUBLE_EQ(reserva.getValorPassagem(), 400.0 * 10.0);
}

TEST(ReservaTest, InicializarReservaComViagemNula) {
    Parada origem("Origem", 0.0);
    Parada destino("Destino", 400.0);
    ASSERT_THROW(Reserva reserva(nullptr, "12345678901", &origem, &destino), invalid_argument);
}

TEST(ReservaTest, InicializarReservaComCPFNulo) {
    Onibus onibus("XYZ9876", 40, 60.0, 10.0);
    Parada origem("Origem", 0.0);
    Parada destino("Destino", 400.0);
    Data data(1, 1, 2024);
    Viagem viagem(&origem, &destino, &onibus, data);

    ASSERT_THROW(Reserva reserva(&viagem, "", &origem, &destino), invalid_argument);
}

TEST(ReservaTest, InicializarReservaComOrigemNula) {
    Onibus onibus("XYZ9876", 40, 60.0, 10.0);
    Parada origem("Origem", 0.0);
    Parada destino("Destino", 400.0);
    Data data(1, 1, 2024);
    Viagem viagem(&origem, &destino, &onibus, data);

    ASSERT_THROW(Reserva reserva(&viagem, "12345678901", nullptr, &destino), invalid_argument);
}

TEST(ReservaTest, InicializarReservaComDestinoNulo) {
    Onibus onibus("XYZ9876", 40, 60.0, 10.0);
    Parada origem("Origem", 0.0);
    Parada destino("Destino", 400.0);
    Data data(1, 1, 2024);
    Viagem viagem(&origem, &destino, &onibus, data);

    ASSERT_THROW(Reserva reserva(&viagem, "12345678901", &origem, nullptr), invalid_argument);
}

TEST(ReservaTest, CancelarReserva) {
    Onibus onibus("XYZ9876", 40, 60.0, 10.0);
    Parada origem("Origem", 0.0);
    Parada destino("Destino", 400.0);
    Data data(1, 1, 2024);
    Viagem viagem(&origem, &destino, &onibus, data);

    Reserva reserva(&viagem, "12345678901", &origem, &destino);
    reserva.cancelarReserva();
    ASSERT_EQ(viagem.getNumAssentosLivres(), 40);
    ASSERT_EQ(reserva.estaAtiva(), false);
}
