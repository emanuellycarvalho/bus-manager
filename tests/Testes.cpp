#include <gtest/gtest.h>
#include "../include/Reserva.hpp"

// Testes da classe Data

void assertInvalidDate(int dia, int mes, int ano) {
    EXPECT_THROW(Data(dia, mes, ano), std::invalid_argument);
}

TEST(DataTest, ConstrutorComDataCorreta) {
    EXPECT_NO_THROW(Data(1, 1, 2000));
    EXPECT_NO_THROW(Data(31, 12, 2023));
}

TEST(DataTest, ConstrutorComDataIncorreta) {
    assertInvalidDate(0, 1, 2000);
    assertInvalidDate(32, 1, 2000);
    assertInvalidDate(1, 0, 2000);
    assertInvalidDate(1, 13, 2000);
    assertInvalidDate(1, 1, -1);     
}

TEST(DataTest, CasosLimiteValidos) {
    EXPECT_NO_THROW(Data(31, 1, 2023));
    EXPECT_NO_THROW(Data(28, 2, 2023));
    EXPECT_NO_THROW(Data(29, 2, 2024));
    EXPECT_NO_THROW(Data(30, 4, 2023));
}

TEST(DataTest, AlteracoesValidasComGetteresESetteres) {
    Data data(10, 12, 2023);
    
    data.setDia(15);
    data.setMes(11);
    data.setAno(2022);

    EXPECT_EQ(data.getDia(), 15);
    EXPECT_EQ(data.getMes(), 11);
    EXPECT_EQ(data.getAno(), 2022);
}

TEST(DataTest, AlteracoesInvalidasComGetteresESetteres) {
    Data data(10, 12, 2023);

    EXPECT_THROW(data.setDia(32), std::invalid_argument);
    EXPECT_THROW(data.setMes(13), std::invalid_argument);
    EXPECT_THROW(data.setAno(-1), std::invalid_argument);
}

TEST(DataTest, OperadoresDeIgualdade) {
    Data data1(10, 12, 2023);
    Data data2(11, 12, 2023);
    Data data3(10, 12, 2023);

    EXPECT_TRUE(data1 == data3);
    EXPECT_FALSE(data1 == data2);
}

TEST(DataTest, OperadoresDeMenorOuIgualQue) {
    Data data1(10, 12, 2023);
    Data data2(11, 12, 2023);
    Data data3(10, 12, 2023);

    EXPECT_TRUE(data1 < data2);
    EXPECT_FALSE(data2 < data1);

    EXPECT_TRUE(data1 <= data3);
    EXPECT_TRUE(data1 <= data2);
    EXPECT_FALSE(data2 <= data1);
}

TEST(DataTest, OperadoresDeMaiorOuIgualQue) {
    Data data1(10, 12, 2023);
    Data data2(11, 12, 2023);
    Data data3(10, 12, 2023);

    EXPECT_TRUE(data2 > data1);
    EXPECT_FALSE(data1 > data2);


    EXPECT_TRUE(data2 >= data1);
    EXPECT_TRUE(data1 >= data3);
    EXPECT_FALSE(data1 >= data2);
}


TEST(DataTest, OperacoesDeInput) {
    Data data(10, 12, 2023);

    std::ostringstream oss;
    oss << data;
    EXPECT_EQ(oss.str(), "10/12/2023");
}

TEST(DataTest, OperacoesDeOutnput) {
    Data data(10, 12, 2023);

    std::istringstream issValid("15/11/2022");
    issValid >> data;
    EXPECT_EQ(data.getDia(), 15);
    EXPECT_EQ(data.getMes(), 11);
    EXPECT_EQ(data.getAno(), 2022);

    std::istringstream issInvalid("15-11-2022");
    issInvalid >> data;
    EXPECT_TRUE(issInvalid.fail());
}


// Testes com classe Parada

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

TEST(OnibusTest, MudaPlacaDeOnibusComSetters) {
    Onibus onibus("XYZ9876", 40, 60.0, 10.0);
    ASSERT_EQ(onibus.getPlaca(), "XYZ9876");

    onibus.setPlaca("ABC1234");
    ASSERT_EQ(onibus.getPlaca(), "ABC1234");
}

TEST(OnibusTest, MudaNumAssentosDeOnibusComSetters) {
    Onibus onibus("XYZ9876", 40, 60.0, 10.0);
    ASSERT_EQ(onibus.getNumAssentos(), 40);
    
    onibus.setNumAssentos(55);
    ASSERT_EQ(onibus.getNumAssentos(), 55);
}

TEST(OnibusTest, MudaVelocidadeMediaDeOnibusComSetters) {
    Onibus onibus("XYZ9876", 40, 60.0, 10.0);
    ASSERT_DOUBLE_EQ(onibus.getVelocidadeMedia(), 60.0);
    
    onibus.setVelocidadeMedia(80.0);
    ASSERT_DOUBLE_EQ(onibus.getVelocidadeMedia(), 80.0);
}

TEST(OnibusTest, MudaValorKmDeOnibusComSetters) {
    Onibus onibus("XYZ9876", 40, 60.0, 10.0);
    ASSERT_DOUBLE_EQ(onibus.getValorKm(), 10.0);
    
    onibus.setValorKm(5.0);
    ASSERT_DOUBLE_EQ(onibus.getValorKm(), 5.0);
}

TEST(OnibusTest, MudaPlacaDeOnibusInvalidaComSetters) {
    Onibus onibus("XYZ9876", 40, 60.0, 10.0);
    ASSERT_EQ(onibus.getPlaca(), "XYZ9876");

    ASSERT_THROW(onibus.setPlaca(""), invalid_argument);
}

TEST(OnibusTest, MudaNumAssentosDeOnibusInvalidoComSetters) {
    Onibus onibus("XYZ9876", 40, 60.0, 10.0);
    ASSERT_EQ(onibus.getNumAssentos(), 40);
    
    ASSERT_THROW(onibus.setNumAssentos(0), invalid_argument);
}

TEST(OnibusTest, MudaVelocidadeMediaDeOnibusInvalidaComSetters) {
    Onibus onibus("XYZ9876", 40, 60.0, 10.0);
    ASSERT_DOUBLE_EQ(onibus.getVelocidadeMedia(), 60.0);
    
    ASSERT_THROW(onibus.setVelocidadeMedia(0), invalid_argument);
}

TEST(OnibusTest, MudaValorKmDeOnibusInvalidoComSetters) {
    Onibus onibus("XYZ9876", 40, 60.0, 10.0);
    ASSERT_DOUBLE_EQ(onibus.getValorKm(), 10.0);
    
    ASSERT_THROW(onibus.setValorKm(0), invalid_argument);
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

TEST(OnibusTest, InicializarOnibusComNumAssentosIgualAZero) {
    ASSERT_THROW(Onibus onibus("XYZ9876", 0, 60.0), invalid_argument);
}

TEST(OnibusTest, InicializarOnibusComVelocidadeMediaIgualAZero) {
    ASSERT_THROW(Onibus onibus("XYZ9876", 40, 0), invalid_argument);
}

TEST(OnibusTest, InicializarOnibusComValorKmIgualAZero) {
    ASSERT_THROW(Onibus onibus("XYZ9876", 40, 60.0, 0), invalid_argument);
}

// Testes da classe Viagem

TEST(ViagemTest, InicializarViagemComAtributosCorretos) {
    Onibus onibus("XYZ9876", 40, 60.0, 10.0);
    Parada origem("Origem", 0.0);
    Parada destino("Destino", 400.0);
    Data data(1, 1, 2024);

    Viagem viagem(data);
    viagem.setOrigem(&origem);
    viagem.setOnibus(&onibus);
    viagem.setDestino(&destino);
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
    Onibus* onibus = new Onibus("XYZ9876", 40, 60.0, 10.0);
    Parada* origem = new Parada("Origem", 0.0);
    Parada* destino = new Parada("Destino", 400.0);
    Data data(1, 1, 2024);

    
    Viagem viagem(data);
    viagem.setOrigem(origem);
    viagem.setOnibus(onibus);
    viagem.setDestino(destino);
    ASSERT_TRUE(viagem.verificarDisponibilidade());
}

TEST(ViagemTest, VerificarSeIncluiTrechoIncluso) {
    Onibus onibus("XYZ9876", 40, 60.0, 10.0);
    Parada origem("Origem", 0.0);
    Parada destino("Destino", 400.0);
    Data data(1, 1, 2024);

    
    Viagem viagem(data);
    viagem.setOrigem(&origem);
    viagem.setOnibus(&onibus);
    viagem.setDestino(&destino);
    Parada novaParada("Nova Parada", 200.0);
    ASSERT_TRUE(viagem.incluiOTrecho(&origem, &novaParada));
}

TEST(ViagemTest, VerificarSeIncluiTrechoNaoIncluso) {
    Onibus onibus("XYZ9876", 40, 60.0, 10.0);
    Parada origem("Origem", 0.0);
    Parada destino("Destino", 400.0);
    Data data(1, 1, 2024);

    
    Viagem viagem(data);
    viagem.setOrigem(&origem);
    viagem.setOnibus(&onibus);
    viagem.setDestino(&destino);
    Parada novaParada("Nova Parada", 500.0);
    ASSERT_FALSE(viagem.incluiOTrecho(&origem, &novaParada));
}

TEST(ViagemTest, CalcularTempoViagemCompleta) {
    Onibus* onibus = new Onibus("XYZ9876", 40, 60.0, 10.0);
    Parada* origem = new Parada("Origem", 0.0);
    Parada* destino = new Parada("Destino", 400.0);
    Data data(1, 1, 2024);

    
    Viagem viagem(data);
    viagem.setOrigem(origem);
    viagem.setOnibus(onibus);
    viagem.setDestino(destino);
    ASSERT_DOUBLE_EQ(viagem.calcularTempoViagemCompleta(), 400.0 / 60.0);
}

TEST(ViagemTest, CalcularTempoTrecho) {
    Onibus onibus("XYZ9876", 40, 60.0, 10.0);
    Parada origem("Origem", 0.0);
    Parada destino("Destino", 400.0);
    Data data(1, 1, 2024);

    
    Viagem viagem(data);
    viagem.setOrigem(&origem);
    viagem.setOnibus(&onibus);
    viagem.setDestino(&destino);
    Parada novaParada("Nova Parada", 200.0);
    ASSERT_DOUBLE_EQ(viagem.calcularTempoTrecho(&origem, &novaParada), 200.0 / 60.0);
}

TEST(ViagemTest, OcuparAssentoComAssentosDisponiveis) {
    Onibus* onibus = new Onibus("XYZ9876", 40, 60.0, 10.0);
    Parada* origem = new Parada("Origem", 0.0);
    Parada* destino = new Parada("Destino", 400.0);
    Data data(1, 1, 2024);

    
    Viagem viagem(data);
    viagem.setOrigem(origem);
    viagem.setOnibus(onibus);
    viagem.setDestino(destino);
    viagem.ocuparAssento();
    ASSERT_EQ(viagem.getNumAssentosLivres(), 39);
}

TEST(ViagemTest, OcuparAssentoSemAssentosDisponiveis) {
    Onibus* onibus = new Onibus("XYZ9876", 40, 60.0, 10.0);
    Parada* origem = new Parada("Origem", 0.0);
    Parada* destino = new Parada("Destino", 400.0);
    Data data(1, 1, 2024);

    
    Viagem viagem(data);
    viagem.setOrigem(origem);
    viagem.setOnibus(onibus);
    viagem.setDestino(destino);

    viagem.setNumAssentosLivres(0);
    ASSERT_THROW(viagem.ocuparAssento(), invalid_argument);
}

// Testes da classe Reserva

TEST(ReservaTest, InicializarReservaComAtributosCorretos) {
    Onibus* onibus = new Onibus("XYZ9876", 40, 60.0, 10.0);
    Parada* origem = new Parada("Origem", 0.0);
    Parada* destino = new Parada("Destino", 400.0);
    Data data(1, 1, 2024);

    
    Viagem viagem(data);
    viagem.setOrigem(origem);
    viagem.setOnibus(onibus);
    viagem.setDestino(destino);

    Reserva reserva(&viagem, "12345678901", origem, destino);
    ASSERT_EQ(reserva.getViagem()->getOrigem()->getNome(), "Origem");
    ASSERT_EQ(reserva.getViagem()->getDestino()->getNome(), "Destino");
    ASSERT_EQ(reserva.getViagem()->getOrigem()->getNome(), "Origem");
    ASSERT_EQ(reserva.getViagem()->getDestino()->getNome(), "Destino");
    ASSERT_EQ(reserva.getViagem()->getOnibus()->getPlaca(), "XYZ9876");
    ASSERT_EQ(reserva.getData().getAno(), 2024);
    ASSERT_EQ(reserva.getData().getMes(), 1);
    ASSERT_EQ(reserva.getData().getDia(), 1);
    ASSERT_EQ(reserva.getCPF(), "12345678901");
    ASSERT_DOUBLE_EQ(reserva.getValorPassagem(), 400.0 * 10.0);
}

TEST(ReservaTest, InicializarReservaComViagemNula) {
    Parada origem("Origem", 0.0);
    Parada destino("Destino", 400.0);
    ASSERT_THROW(Reserva reserva(nullptr, "12345678901", &origem, &destino), invalid_argument);
}

TEST(ReservaTest, InicializarReservaComCPFNulo) {
    Onibus* onibus = new Onibus("XYZ9876", 40, 60.0, 10.0);
    Parada* origem = new Parada("Origem", 0.0);
    Parada* destino = new Parada("Destino", 400.0);
    Data data(1, 1, 2024);

    
    Viagem viagem(data);
    viagem.setOrigem(origem);
    viagem.setOnibus(onibus);
    viagem.setDestino(destino);

    ASSERT_THROW(Reserva reserva(&viagem, "", origem, destino), invalid_argument);
}

TEST(ReservaTest, InicializarReservaComOrigemNula) {
    Onibus onibus("XYZ9876", 40, 60.0, 10.0);
    Parada origem("Origem", 0.0);
    Parada destino("Destino", 400.0);
    Data data(1, 1, 2024);
    
    Viagem viagem(data);
    viagem.setOrigem(&origem);
    viagem.setOnibus(&onibus);
    viagem.setDestino(&destino);

    ASSERT_THROW(Reserva reserva(&viagem, "12345678901", nullptr, &destino), invalid_argument);
}

TEST(ReservaTest, InicializarReservaComDestinoNulo) {
    Onibus onibus("XYZ9876", 40, 60.0, 10.0);
    Parada origem("Origem", 0.0);
    Parada destino("Destino", 400.0);
    Data data(1, 1, 2024);
    
    Viagem viagem(data);
    viagem.setOrigem(&origem);
    viagem.setOnibus(&onibus);
    viagem.setDestino(&destino);

    ASSERT_THROW(Reserva reserva(&viagem, "12345678901", &origem, nullptr), invalid_argument);
}

TEST(ReservaTest, CancelarReserva) {
    Onibus onibus("XYZ9876", 40, 60.0, 10.0);
    Parada origem("Origem", 0.0);
    Parada destino("Destino", 400.0);
    Data data(1, 1, 2024);
    
    Viagem viagem(data);
    viagem.setOrigem(&origem);
    viagem.setOnibus(&onibus);
    viagem.setDestino(&destino);

    Reserva reserva(&viagem, "12345678901", &origem, &destino);
    reserva.cancelarReserva();
    ASSERT_EQ(viagem.getNumAssentosLivres(), 40);
    ASSERT_EQ(reserva.estaAtiva(), false);
}

TEST(ViagemTest, CancelarAssentoSemAssentoOcupado) {
    Onibus onibus("XYZ9876", 40, 60.0, 10.0);
    Parada origem("Origem", 0.0);
    Parada destino("Destino", 400.0);
    Data data(1, 1, 2024);

    
    Viagem viagem(data);
    viagem.setOrigem(&origem);
    viagem.setOnibus(&onibus);
    viagem.setDestino(&destino);
    ASSERT_THROW(viagem.desocuparAssento(), invalid_argument);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS(); 
}
