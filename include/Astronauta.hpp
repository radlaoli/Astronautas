#ifndef ASTRONAUTA_HPP
#define ASTRONAUTA_HPP

#include <string>
using std::string;
class Astronauta
{
public:
    string CPF, nome;
    int idade;
    bool estado, disponibilidade;
    vector<int> historicoVoos; // TODO: sucetível a mudança se o prof rejeitar essa forma

    Astronauta(string cpf, string nome, int idade);
    ~Astronauta();

    void exibirInfo(); // TODO: certificar que foram listados todos os métodos
};

#endif