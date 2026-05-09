#ifndef ASTRONAUTA_HPP
#define ASTRONAUTA_HPP

#include <string>
#include <vector>
using std::string;
using std::vector;
class Astronauta
{
public:
    string CPF, nome;
    int idade;
    bool estado, disponibilidade;
    vector<int> historicoVoos;

    Astronauta(string &cpf, string &nome, int idade); // Passagem da string que é um tipo pesado por referencia
    ~Astronauta();

    void exibirInfo();
};

#endif