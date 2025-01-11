#include <gtest/gtest.h>
#include "Reserva.hpp"
#include "Database.hpp"
#include "OnibusService.hpp"
#include <iostream>

TEST(OnibusTeste, AdicionarERecuperarOnibusComSucesso) {
    Database db(":memory:");
    db.initializeTables();

    OnibusService onibusService(db);

    int id = onibusService.adicionarOnibus(Onibus("ABC1234", 50, 60.0, 2.5));

    Onibus* onibus = onibusService.buscarOnibusPorId(id);

    ASSERT_TRUE(onibus != nullptr);
    ASSERT_EQ(onibus->getId(), id);
    ASSERT_EQ(onibus->getNumAssentos(), 50);
    ASSERT_DOUBLE_EQ(onibus->getVelocidadeMedia(), 60.0);
    ASSERT_DOUBLE_EQ(onibus->getValorKm(), 2.5);
    ASSERT_EQ(onibus->getPlaca(), "ABC1234");

    delete onibus;
}

TEST(OnibusTeste, BuscarOnibusPorIdInvalido) {
    Database db(":memory:");
    db.initializeTables();

    OnibusService onibusService(db);

    Onibus* onibus = onibusService.buscarOnibusPorId(999); 

    ASSERT_TRUE(onibus == nullptr);

    delete onibus;
}


TEST(OnibusTeste, AdicionarEDeletarOnibusComSucesso) {
    Database db(":memory:");
    db.initializeTables();

    OnibusService onibusService(db);

    int id = onibusService.adicionarOnibus(Onibus("ABC1234", 50, 60.0, 2.5));

    Onibus* onibus = onibusService.buscarOnibusPorId(id);

    ASSERT_TRUE(onibus != nullptr);

    onibusService.deletarOnibus(id);
    onibus = onibusService.buscarOnibusPorId(id);

    ASSERT_TRUE(onibus == nullptr);

    delete onibus;
}

TEST(OnibusTeste, ListarTodosOnibusComSucesso) {
    Database db(":memory:");
    db.initializeTables();

    OnibusService onibusService(db);

    onibusService.adicionarOnibus(Onibus("ABC1234", 50, 60.0, 2.5));
    onibusService.adicionarOnibus(Onibus("XYZ9876", 60, 70.0, 3.0));

    std::vector<Onibus> onibusList = onibusService.listarTodosOnibus();

    ASSERT_EQ(onibusList.size(), 2);

    ASSERT_EQ(onibusList[0].getPlaca(), "ABC1234");
    ASSERT_EQ(onibusList[1].getPlaca(), "XYZ9876");
}
