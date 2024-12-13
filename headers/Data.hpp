
class Data {
private:
    int dia;
    int mes;
    int ano;

public:
    // construtores
    Data(int dia, int mes, int ano);

    // getteres e setteres
    int getDia();
    void setDia(int dia);

    int getMes();
    void setMes(int mes);

    int getAno();
    void setAno(int ano);
};