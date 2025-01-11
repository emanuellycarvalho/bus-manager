CXX = g++
CXXFLAGS = -std=c++14 -Wall -I./include -I./include/models -I./include/services -g
LDFLAGS = -lgtest -lgtest_main -pthread -lsqlite3 --coverage

CXXFLAGS += --coverage

SRC_DIR = src
BUILD_DIR = build
TEST_DIR = tests

# Fontes organizados por subdiretórios
SRC_MODELS = $(wildcard $(SRC_DIR)/models/*.cpp)
SRC_SERVICES = $(wildcard $(SRC_DIR)/services/*.cpp)
SRC_MAIN = $(wildcard $(SRC_DIR)/*.cpp)
SRC = $(SRC_MODELS) $(SRC_SERVICES) $(filter-out $(SRC_DIR)/main.cpp, $(SRC_MAIN))

OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
TEST_OBJ = $(BUILD_DIR)/Testes.o
EXEC = $(BUILD_DIR)/test_executavel

# Criar diretório de build
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compilação dos arquivos fonte (subdiretórios inclusos)
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(BUILD_DIR)
	@mkdir -p $(dir $@)
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
