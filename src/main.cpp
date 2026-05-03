#include <iostream>
#include <string>
#include <vector>
#include "../include/Agencia.hpp"

using namespace std;

int main()
{
    Agencia agencia;
    string comando;

    while (cin >> comando)
    {
        if (comando == "FIM")
        {
            break;
        }

        if (comando == "CADASTRAR_ASTRONAUTA")
        {
            string cpf, nome;
            int idade;
            cin >> cpf >> idade;
            getline(cin >> ws, nome);
            agencia.cadastrarAstronauta(cpf, idade, nome);
        }
        else if (comando == "CADASTRAR_VOO")
        {
            int codigo;
            cin >> codigo;
            agencia.cadastrarVoo(codigo);
        }
        else if (comando == "ADICIONAR_ASTRONAUTA")
        {
            string cpf;
            int codigo;
            cin >> cpf >> codigo;
            agencia.addAstronautaEmVoo(cpf, codigo);
        }
        else if (comando == "REMOVER_ASTRONAUTA")
        {
            string cpf;
            int codigo;
            cin >> cpf >> codigo;
            agencia.rmAstronautaDoVoo(cpf, codigo);
        }
        else if (comando == "LANCAR_VOO")
        {
            int codigo;
            cin >> codigo;
            agencia.lancarVoo(codigo);
        }
        else if (comando == "EXPLODIR_VOO")
        {
            int codigo;
            cin >> codigo;
            agencia.explodirVoo(codigo);
        }
        else if (comando == "FINALIZAR_VOO")
        {
            int codigo;
            cin >> codigo;
            agencia.finalizarVooSucesso(codigo);
        }
        else if (comando == "LISTAR_VOOS")
        {
            agencia.listarVoos();
        }
        else if (comando == "LISTAR_MORTOS")
        {
            agencia.listarAstronautasMortos();
        }
    }

    return 0;
}