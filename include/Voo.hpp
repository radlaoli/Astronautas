#ifndef VOO_HPP
#define VOO_HPP

#include <string>
#include <vector>

using std::string;
using std::vector;
class Voo
{
public:
    enum estadoVoo
    {
        planejado,
        emCurso,
        finalizadoSucesso,
        finalizadoExplosao
    };

    int codigo;
    vector<string> CPFs_Astronautas;
    estadoVoo estado;

    Voo(int codigo);
    ~Voo();

    void adicionarPassageiro(string cpf);
    void removerPassageiro(string cpf);
    void exibirVoo();
};
#endif