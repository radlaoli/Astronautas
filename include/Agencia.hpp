#ifndef AGENCIA_HPP
#define AGENCIA_HPP

#include "Astronauta.hpp"
#include "Voo.hpp"
#include <vector>
#include <string>
using std::string;
using std::vector;

class Agencia
{
public:
    vector<Astronauta> astronautas;
    vector<Voo> voos;

    void cadastrarAstronauta(string &cpf, int idade, string &nome);
    void cadastrarVoo(int codigo);
    void addAstronautaEmVoo(string &cpf, int codigo);
    void rmAstronautaDoVoo(string &cpf, int codigo);
    void lancarVoo(int codigo);
    void explodirVoo(int codigo);
    void finalizarVooSucesso(int codigo);
    void listarVoos();
    void listarAstronautasMortos();

    int buscarIndiceAstronauta(string &cpf);
    int buscarIndiceVoo(int codigo);
};

#endif