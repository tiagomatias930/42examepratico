#include "exam.hpp"

// ==> Aceitação dos Termos e Condições Gerais

void CGVAcceptation(void)
{
    system("clear");
    std::cout << BOLD << WHITE;
    std::cout << "Você deve aceitar estas regras para usar este programa:" << std::endl
              << std::endl;
    std::cout << RESET;
    std::ifstream arquivo(".system/CGV.txt");
    std::string linha;
    while (std::getline(arquivo, linha))
        std::cout << linha << std::endl;

    std::cout << BOLD << WHITE << std::endl;
    std::cout << RESET;
    std::string entrada;
    std::getline(std::cin, entrada);
    if (entrada != "aceito")
    {
        std::cout << "Você deve aceitar estas regras para usar este programa." << std::endl;
        exit(0);
    }
    else
    {
        std::ofstream arquivo(".system/acceptCGV");
        arquivo << "1";
        arquivo.close();
        // Obrigado por aceitar
        std::cout << "Obrigado por aceitar estas regras, e boa sorte no seu exame!" << std::endl;
        sleep(2);
    }
}

// ==> Prompt do Shell de Exame
void exam::exam_prompt(void)
{
    std::string entrada;
    int is_linux = 0;
#ifdef __linux__
    is_linux = 1;
#endif

    while (1)
    {
        char *linha = readline("\e[93mexamshell\e[0m> ");
        if (linha == NULL)
            sigd();
        entrada = linha;
        while (entrada.back() == ' ')
            entrada.pop_back();
        while (entrada.front() == ' ')
            entrada.erase(entrada.begin());
        if (entrada.empty())
            continue;
        add_history(entrada.c_str());
        if ((entrada == "remover_tempo_nota" || entrada == "novo_ex" || entrada == "forcar_sucesso") && !setting_dcc)
            std::cout << " ❌ Comandos de trapaça estão atualmente desativados, use " << LIME << BOLD << "configurações" << RESET << " comando." << std::endl;
        else if (entrada == "finalizar" || entrada == "sair" || entrada == "sair")
        {
            std::cout << "Tem certeza de que deseja" << RED << " sair" << RESET << " do exame?" << std::endl;
            std::cout << "Todo o seu progresso será " << RED << "perdido" << RESET << "." << std::endl;
            std::cout << "Digite " << LIME << BOLD << "sim" << RESET << " para confirmar." << std::endl;
            // ler entrada
            std::string entrada;
            std::getline(std::cin, entrada);
            if (entrada == "sim")
            {
                if (std::ifstream(".system/exam_token/actuel_token.txt"))
                    remove(".system/exam_token/actuel_token.txt");
                exit(0);
            }
            else
                std::cout << " ** Abortar ** " << std::endl;
        }
        else if (entrada == "definicao")
        {
            changex = 1;
            settings_menu();
            if (vip)
                infovip();
            else
                info();
        }
        else if (entrada == "grademe")
        {
            grademe();
        }
        else if (entrada == "estado")
        {
            changex = 1;
            if (vip)
                infovip();
            else
                info();
        }
        else if (entrada == "novo_ex")
        {
            change_ex();
            using_cheatcode++;
        }
        else if (entrada == "forcar_sucesso")
        {
            using_cheatcode++;
            success_ex(1);
        }
        else if (entrada == "ajuda")
        {
            exam_help();
        }
        else if (entrada == "repo_git")
        {
            std::string tmp = "bash .system/data_sender.sh \"cheatcode:repo_git\"";
            system(tmp.c_str());
            std::cout << "Abrindo repositório git..." << std::endl;
            if (is_linux)
                std::system("xdg-open http://git.grademe.fr");
            else
                std::system("open http://git.grademe.fr");
        }
        else if (entrada == "remover_tempo_nota")
        {
            std::string tmp = "bash .system/data_sender.sh \"cheatcode:remover_tempo_nota\"";
            system(tmp.c_str());
            std::cout << "Tempo entre as avaliações foi removido para este exame" << std::endl;
            waiting_time = false;
            using_cheatcode++;
        }
        else if (entrada == "avaliagora" && vip)
        {
            grade_request(1);
        }
        else if (entrada == "")
            std::cout << REMOVE_LINE;
        else if (entrada != "")
            std::cout << "           **Comando desconhecido**     digite " << LIME << "ajuda" << RESET << " para mais ajuda" << std::endl;
        // info();
    }
}
// jo je taime

// ==> Iniciando um novo exercício/exame
bool exam::start_new_ex(void)
{
    load_settings();
    if (!backup)
    {
        list_ex_lvl = list_dir();
        exercise ex = *randomize_exercise(list_ex_lvl, setting_dse);
        current_ex = new exercise(ex);
        prepare_current_ex();
        store_data();
    }
    if (vip)
        infovip();
    else
        info();
    exam_prompt();
    return (true);
}

int main(int argc, char **argv)
{
    signal(SIGINT, sigc);
    signal(SIGQUIT, sigc);
    signal(SIGTERM, sigc);

    if (file_exists("a.out"))
        remove("a.out");

    exam exm;

    // Adicionando Aceitação dos Termos e Condições Gerais
    if (!file_exists(".system/acceptCGV"))
        CGVAcceptation();

    if (file_exists(".system/exam_token/current_token.txt"))
        exm.restore_data();
    else
        exm.ask_param();

    exm.start_new_ex();

    return (0);
}
