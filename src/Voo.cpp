#include <iostream>
#include "../include/Voo.hpp"

using namespace std;

Voo::Voo(int codigo)
{
    this->codigo = codigo;
    this->estado = planejado;
}
Voo::~Voo() {}

void Voo::adicionarAstronauta(string cpf)
{
    this->CPFs_Astronautas.push_back(cpf); // TODO: tratar se o cpf existe e se ele já esta no voo
}

void Voo::removerAstronauta(string cpf)
{ // TODO: tratar se o cpf existe
    for (int i = 0; i < CPFs_Astronautas.size(); i++)
    {
        if (CPFs_Astronautas[i] == cpf)
        {
            this->CPFs_Astronautas.erase(CPFs_Astronautas.begin() + i);
            break;
        }
    }
}

void Voo::exibirVoo()
{
    cout << "Codigo: " << codigo << " | Estado: ";

    switch (estado)
    {
    case planejado:
        cout << "Planejado";
        break;
    case emCurso:
        cout << "Em Curso";
        break;
    case finalizadoSucesso:
        cout << "Finalizado com Sucesso";
        break;
    case finalizadoExplosao:
        cout << "Finalizado com Explosao";
        break;
    }

    cout << endl;

    cout << "----------------------------------------------------" << endl;

    cout << "CPF's dos Astronautas presentes no Voo: " << endl;

    if (CPFs_Astronautas.size() <= 0)
    {
        cout << "Nao existem astronautas nesse voo" << endl;
    }
    else
    {
        for (int i = 0; i <= CPFs_Astronautas.size(); i++)
        {
            cout << CPFs_Astronautas[i] << endl;
        }
    }
    cout << "----------------------------------------------------" << endl;
}