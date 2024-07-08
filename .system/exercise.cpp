#include "exam.hpp"

// ==> Construtor
exercise::exercise(void) {
    this->name = "UNKNOWN";
    assignement = 0;
    level_ex = 0;
    time_bef_grade = time(NULL);
}

// ==> Função para trocar exercício
int exam::change_ex(void)
{
    backup = false;
    // se houver apenas 1 exercício, não podemos trocá-lo
    if (list_ex_lvl.size() == 1)
    {
        std::cout << "Você não pode trocar o exercício, há apenas um exercício neste nível" << std::endl;
        return (0);
    }
    clean_all();
    system("clear");
    std::cout << "  > Você gerou um novo exercício" << std::endl;
    changex = 1;
    delete current_ex;
    start_new_ex();
    return (0);
}

// ==> Configurar pasta correta e copiar assuntos, etc...
bool exam::prepare_current_ex(void)
{
    if (level == level_max)
    {
        std::cout << "Você alcançou o nível máximo deste exame." << std::endl;
        return (false);
    }
    if (!file_exists(get_path()))
    {
        std::cout << "Erro: Não é possível carregar o exercício, não foi possível encontrar um caminho válido" << std::endl;
        return (false);
    }

    // limpar todos os arquivos antigos
    clean_all();

    // criar diretório para o exercício atual
    system("mkdir rendu 2> /dev/null");
    system("mkdir subjects 2> /dev/null");
    system("mkdir .system/grading 2> /dev/null");

    // copiar todos os arquivos no caminho atual + attachment/* para o diretório subjects
    std::string cmd_system_call = "cp -r " + get_path() + "/attachment/*" + " subjects/";
    system(cmd_system_call.c_str());

    // copiar todos os arquivos no caminho atual sem a pasta attachment para o diretório .system/grading/
    cmd_system_call = "cp " + get_path() + "* .system/grading/ >/dev/null 2>&1";
    system(cmd_system_call.c_str());

    return (false);
}

// ==> Randomizar exercício (escolher 1 da lista)
exercise *randomize_exercise(std::map<int, exercise> list, bool remove_success)
{
    // se setting_dse for 1, remover todos os exercícios na lista que tenham um nome em .system/exam_token/success_ex 
    if (remove_success == 0)
    {
        std::ifstream success_ex("success/success_ex");
        std::string line;
        std::string name;
        int assignement;
        int level_ex;
        int time_bef_grade;
        while (std::getline(success_ex, line))
        {
            std::istringstream iss(line);
            iss >> name;
            for (std::map<int, exercise>::iterator it = list.begin(); it != list.end(); it++)
            {
                if (it->second.get_name() == name)
                {
                    list.erase(it);
                    break;
                }
            }
        }
        success_ex.close();
    }

    // Verificar se ainda há exercícios na lista
    std::map<int, exercise>::iterator it = list.begin();
    if (list.size() == 0)
    {
        std::cout << "Erro: todos os exercícios deste nível foram concluídos" << std::endl;
        std::cout << "Por favor, defina para" << RED << BOLD << " OFF " << RESET << "a opção 1 nas configurações." << std::endl;
        std::cout << "Ou edite/exclua seu arquivo success/success_ex" << std::endl;
        std::cout << "Depois reinicie 42_EXAM e recupere seu exame" << std::endl;
        exit(0);
    }
    bool dosrandom = true;
    // se a lista contiver rostring, remova-o
    for (std::map<int, exercise>::iterator it = list.begin(); it != list.end(); it++)
    {
        if (it->second.get_name() == "rostring")
            dosrandom = false;
    }
    if (dosrandom)
        srand(time(NULL));
    int random = rand() % list.size();
    for (int i = 0; i < random; i++)
        it++;
    return (&it->second);
}

// ==> Construtor com parâmetros
exercise::exercise(int level, std::string ex_name) {
    this->name = ex_name;
    level_ex = level;
    assignement = 0;
    time_bef_grade = time(NULL);
}

// ==> Construtor com mais parâmetros
exercise::exercise(int level, std::string ex_name, int assign, time_t tbg) {
    this->name = ex_name;
    level_ex = level;
    assignement = assign;
    time_bef_grade = tbg;
}

// ==> Construtor de cópia
exercise::exercise(exercise const & src) {
    this->name = src.name;
    level_ex = src.level_ex;
    assignement = src.assignement;
    time_bef_grade = src.time_bef_grade;
}

// ==> Destrutor
exercise::~exercise(void) {
}

// ==> Operador de atribuição
exercise&  exercise::operator=(exercise const & src) {
    this->name = src.name;
    level_ex = src.level_ex;
    assignement = src.assignement;
    time_bef_grade = src.time_bef_grade;
    return (*this);
}

// ==> GETTER/SETTER
void exercise::set_time_bef_grade(time_t time)
{
    time_bef_grade = time;
}

std::string exercise::get_name(void) {
    return (this->name);
}

void exercise::reset_assignement(void)
{
    assignement = 0;
}

void exercise::up_assignement(void) {
    this->assignement++;
}

int exercise::get_lvl(void) {
    return (this->level_ex);
}

void exercise::up_lvl(void) {
    level_ex++;
}

int exercise::get_assignement(void) {
    return (this->assignement);
}

void exercise::set_assignement(int assignement) {
    this->assignement = assignement;
}
