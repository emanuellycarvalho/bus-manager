# Definições
CXX = g++
CXXFLAGS = -std=c++14 -Wall -I./include -g
LDFLAGS = -lgtest -lgtest_main -pthread -lsqlite3 --coverage

CXXFLAGS += --coverage

SRC_DIR = src
BUILD_DIR = build
TEST_DIR = tests
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
TEST_OBJ = $(BUILD_DIR)/Testes.o
EXEC = $(BUILD_DIR)/test_executavel

# Criar diretório de build
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compilação dos arquivos fonte
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compilação dos arquivos de teste
$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compilação dos testes
$(EXEC): $(OBJ) $(TEST_OBJ)
	$(CXX) $(OBJ) $(TEST_OBJ) $(LDFLAGS) -o $(EXEC)

# Rodar os testes
run_tests: $(EXEC)
	./$(EXEC)

# Limpeza dos arquivos gerados
clean:
	rm -rf $(BUILD_DIR)

# Alvo padrão
all: run_tests
