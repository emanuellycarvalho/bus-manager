
#include <iostream>

using namespace std;

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

    // sobrecarga de operadores
    bool operator==(const Data &other) const {
        return dia == other.dia && mes == other.mes && ano == other.ano;
    }

    bool operator!=(const Data &other) const {
        return !(*this == other);
    }

    bool operator<(const Data &other) const {
        if (ano < other.ano) return true;
        if (ano == other.ano && mes < other.mes) return true;
        if (ano == other.ano && mes == other.mes && dia < other.dia) return true;
        return false;
    }

    bool operator<=(const Data &other) const {
        return *this < other || *this == other;
    }

    bool operator>(const Data &other) const {
        return !(*this <= other);
    }

    bool operator>=(const Data &other) const {
        return !(*this < other);
    }

    friend ostream &operator<<(ostream &out, const Data &data) {
        out << (data.dia < 10 ? "0" : "") << data.dia << "/"
            << (data.mes < 10 ? "0" : "") << data.mes << "/"
            << data.ano;
        return out;
    }

    friend istream &operator>>(istream &in, Data &data) {
        char sep1, sep2;
        in >> data.dia >> sep1 >> data.mes >> sep2 >> data.ano;
        if (sep1 != '/' || sep2 != '/') {
            in.setstate(ios::failbit);
        }
        return in;
    }
};