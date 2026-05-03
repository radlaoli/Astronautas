#include <iostream>
#include "../include/Voo.hpp"

using namespace std;

Voo::Voo(int codigo)
{
    this->codigo = codigo;
    this->estado = planejado;
}
Voo::~Voo() {}

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
}