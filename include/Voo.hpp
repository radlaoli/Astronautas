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

    void adicionarAstronauta(string cpf);
    void removerAstronauta(string cpf);
    void exibirVoo();
};
#endif