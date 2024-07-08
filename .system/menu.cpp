#include "exam.hpp"

// ==> Animation of exercise name
void exam::exam_random_show(void)
{
    int pot_pts;
    if (level == 0)
        pot_pts = 0;
    else
        pot_pts = level_per_ex_save;
    std::map<int, exercise>::iterator it = list_ex_lvl.begin();
    std::cout << "    " << YELLOW << current_ex->get_assignement() << RESET << ": " << LIME << it->second.get_name() << RESET << " para " << pot_pts << " pontos potenciais(" << CYAN << "atual" << RESET << ")" << std::endl;
    double time = 100000;
    for (int i = 0; i < 20; i++)
    {
        std::cout << REMOVE_LINE;
        std::cout << "    " << YELLOW << current_ex->get_assignement() << RESET << ": " << LIME << it->second.get_name() << RESET << " para " << pot_pts << " pontos potenciais (" << CYAN << "atual" << RESET << ")" << std::endl;
        it++;
        if (it == list_ex_lvl.end())
            it = list_ex_lvl.begin();
        if (list_ex_lvl.size() == 1)
            break;
        usleep(time);
        time += 10000;
    }
    std::cout << REMOVE_LINE;
    std::cout << "    " << YELLOW << current_ex->get_assignement() << RESET << ": " << LIME << current_ex->get_name() << RESET << " para " << pot_pts << " pontos potenciais (" << CYAN << "atual" << RESET << ")" << std::endl;
    if (level_per_ex != 100)
    {
        for (int i = 0; i < level_per_ex_save && level == 0; i++)
        {
            std::cout << REMOVE_LINE;
            std::cout << "    " << YELLOW << current_ex->get_assignement() << RESET << ": " << LIME << current_ex->get_name() << RESET << " para " << i << " pontos potenciais (" << CYAN << "atual" << RESET << ")" << std::endl;
            usleep(40000);
        }
    }
    std::cout << REMOVE_LINE;
    std::cout << "    " << YELLOW << current_ex->get_assignement() << RESET << ": " << LIME << current_ex->get_name() << RESET << " para " << (int)level_per_ex_save << " pontos potenciais (" << CYAN << "atual" << RESET << ")" << std::endl;
}

// ==> Help section
void exam::exam_help()
{
    std::cout << "Comandos:" << std::endl;
    std::cout << LIME << "    help:" << RESET << " Exibir esta ajuda" << std::endl;
    std::cout << LIME << "    settings: " << RESET << "Exibir Menu de Configuracao" << std::endl;
    std::cout << LIME << "    status:" << RESET << " Exibir informacoes sobre o exame" << std::endl;
    std::cout << LIME << "    finish:" << RESET << " Sair do Exame" << std::endl;
    std::cout << LIME << "    grademe:" << RESET << " Avaliar seu exercicio" << std::endl;
    std::cout << LIME << "    repo_git:" << RESET << " Visitar repo Git" << std::endl;
    std::cout << "Veja o repositório no github para mais comandos 'cheat'" << std::endl;
    if (vip)
    {
        std::cout << BOLD << LIME << "VIP MENU:" << RESET << std::endl;
        std::cout << LIME << "    force_success:" << RESET << " forçar um exercício a ser bem-sucedido" << std::endl;
        std::cout << LIME << "    remove_grade_time:" << RESET << " remover limite de tempo entre duas grademe" << std::endl;
        std::cout << LIME << "    gradenow:" << RESET << " avaliar instantaneamente um exercício" << std::endl;
        std::cout << LIME << "    new_ex:" << RESET << " gerar um novo exercício para o mesmo nível" << std::endl;
    }
}

// ==> display of exam status
void exam::info(void)
{
    // std::cout << "⚠️  V2 of 42_EXAM was release " << lastupdate(time(0)) << " ago." << std::endl << "If you encounter any problems, please report them on the Github repo."<< std::endl << std::endl;
    std::cout << "==================================================================" << std::endl << std::endl;
    // std::cout << "Level: " << LIME << level << RESET << " ";
    if (reelmode)
        std::cout << "Modo: " << MAGENTA << "REAL" << RESET << " | ";
    else
        std::cout << "Modo: " << YELLOW << "TESTE" << RESET << " (Sua nota não será contabilizada)" << std::endl;
    std::cout << "Nota Atual: " << LIME << level_per_ex_save * level << RESET << " / 100" << std::endl;
    // std::cout << "Assignments: " << std::endl;
    std::cout << std::endl;

    for (std::map<int, exercise>::iterator it = lvl_ex.begin(); it != lvl_ex.end(); it++)
    {
        std::cout << "  Nivel " << LIME << it->second.get_lvl() << RESET << ": " << std::endl;
        for (unsigned int i = 0; i < it->second.get_assignement(); i++)
        {
            std::cout << "    " << YELLOW << i << RESET << ": " << LIME << it->second.get_name() << RESET << " para " << (int)level_per_ex_save  << " pontos potencias (" << RED << "Erro" << RESET << ")" << std::endl;
        }
        std::cout << "    " << YELLOW << it->second.get_assignement() << RESET << ": " << LIME << it->second.get_name() << RESET << " para " << (int)level_per_ex_save << " pontos potenciais (" << LIME << "Sucesso" << RESET << ")" << std::endl;
    }

    std::cout << "  Nivel " << LIME << level << RESET << ": " << std::endl;
    if (current_ex->get_assignement() == 0 && backup == 0 && !changex)
        exam_random_show();
    else
    {
        for (unsigned int i = 0; i < current_ex->get_assignement(); i++)
        {
            std::cout << "    " << YELLOW << i << RESET << ": " << LIME << current_ex->get_name() << RESET << " para " << (int)level_per_ex_save << " pontos potencias (" << RED << "Erro" << RESET << ")" << std::endl;
        }
        std::cout << "    " << YELLOW << current_ex->get_assignement() << RESET << ": " << LIME << current_ex->get_name() << RESET << " para " << (int)level_per_ex_save << " pontos potencias (" << CYAN << "Atual" << RESET << ")" << std::endl;
    }
    std::cout << std::endl
              << "Assignment: " << LIME << current_ex->get_name() << RESET << " para " << LIME << BOLD << (double)(((double)level + 1) / (double)level_max * 100) << RESET << "xp" <<RESET << ", ";
    std::cout << "try: " << YELLOW << current_ex->get_assignement() << RESET << std::endl << std::endl;
    std::cout << "Subject location:  " << LIME << current_path() << "/subjects/subject.en.txt" << RESET << std::endl;
    std::cout << "Exercise location: " << RED << current_path() << "/rendu/" << current_ex->get_name() << "/" << RESET << std::endl;
    std::cout << "Estas aqui " << RED << BOLD << "Nao precisa" << RESET <<" usar o git." << std::endl
              << std::endl;
    std::cout << "Tempo de avaliacao: " << LIME << std::put_time(std::localtime(&end_time), "%d/%m/%Y %H:%M:%S") << RESET << std::endl;
    std::cout << "Tempo restante: " << LIME << remaining_time(end_time) << RESET << std::endl;
    std::cout << std::endl
              << "==================================================================" << std::endl;
    std::cout << "Use o  \"" << LIME << "grademe" << RESET << "\" para ser avaliado, ou \"" << LIME << "help" << RESET << "\" para obter ajuda" << std::endl;
    backup = 1;
}

void exam::infovip(void)
{
    std::cout << "==================================================================" << std::endl;
    std::cout << "voce esta atualmente no nivel " << LIME << level << RESET << std::endl;
    if (reelmode)
        std::cout << "Voce esta executando" << MAGENTA << "REAL" << RESET << " no modo (sua noto sera contada)" << std::endl;
    else
        std::cout << "Voce esta executando " << YELLOW << "TESTE" << RESET << " no modo (sua nota nao sera contada)" << std::endl;
    std::cout << "Sua nota atual é" << LIME << level_per_ex_save * level << RESET << "/100" << std::endl;
    std::cout << "Atividade: " << std::endl;

    for (std::map<int, exercise>::iterator it = lvl_ex.begin(); it != lvl_ex.end(); it++)
    {
        std::cout << "  Nivel " << LIME << it->second.get_lvl() << RESET << ": " << std::endl;
        for (unsigned int i = 0; i < it->second.get_assignement(); i++)
        {
            std::cout << "    " << YELLOW << i << RESET << ": " << LIME << it->second.get_name() << RESET << " para " << (int)level_per_ex_save * (it->second.get_lvl() + 1) << " pontos potencias(" << RED << "Erro! Don't Panic" << RESET << ")" << std::endl;
        }
        std::cout << "    " << YELLOW << it->second.get_assignement() << RESET << ": " << LIME << it->second.get_name() << RESET << " para " << (int)level_per_ex_save * (it->second.get_lvl() + 1) << " pontos potencias (" << LIME << "Rumo ao Sucesso" << RESET << ")" << std::endl;
    }

    std::cout << "  Nivel " << LIME << level << RESET << ": " << std::endl;
    if (current_ex->get_assignement() == 0 && backup == 0 && !changex)
        exam_random_show();
    else
    {
        for (unsigned int i = 0; i < current_ex->get_assignement(); i++)
        {
            std::cout << "    " << YELLOW << i << RESET << ": " << LIME << current_ex->get_name() << RESET << " para " << (int)(((double)level + 1) / (double)level_max * 100) << " pontos potencias (" << RED << "Erro: Don't Panic " << RESET << ")" << std::endl;
        }
        std::cout << "    " << YELLOW << current_ex->get_assignement() << RESET << ": " << LIME << current_ex->get_name() << RESET << " para " << (int)(((double)level + 1) / (double)level_max * 100) << " pontos potencias (" << CYAN << "Atual" << RESET << ")" << std::endl;
    }

    std::cout << std::endl
              << "A sua contribuicao atual é " << LIME << current_ex->get_name() << RESET << " para " << LIME << (int)(((double)level + 1) / (double)level_max * 100) << RESET << " pontos potencias" << std::endl;
    std::cout << "É a sua contribuicao " << YELLOW << current_ex->get_assignement() << RESET << " para nivel " << LIME << level << RESET << std::endl;
    std::cout << "O assunto está localizado em: " << LIME << current_path() << "/subjects/subject.en.txt" << RESET << std::endl;
    std::cout << "Você deve entregar seus arquivos em um subdiretório com o" << std::endl;
    std::cout << "mesmo nome da atribuição (" << RED << current_path() << "/rendu/" << current_ex->get_name() << RESET << "/)." << std::endl;
    std::cout << "Aqui você não precisa usar git." << std::endl
              << std::endl;
    std::cout << "A data de término deste exame é: " << LIME << std::put_time(std::localtime(&end_time), "%d/%m/%Y %H:%M:%S") << RESET << std::endl;
    std::cout << "Você tem " << LIME << remaining_time(end_time) << RESET << " restantes" << std::endl;
    std::cout << std::endl
              << "=============================================================================" << std::endl;
    std::cout << " Você pode trabalhar em sua atribuição. Quando estiver certo de que terminou," << std::endl;
    std::cout << "use o \"" << LIME << "grademe" << RESET << "\" para ser avaliado, ou \"" << LIME << "help" << RESET << "\" para obter ajuda." << std::endl;
}

// ==> display connexion animation
void connexion(void)
{
    system("clear");
    std::cout << RESET;
    std::string examsystem = "simulador examshell";
    for (int i = 0; i < examsystem.length(); i++)
    {
        std::cout << examsystem[i];
        usleep(70000);
        fflush(stdout);
    }
    std::cout << std::endl;
    usleep(600000);
    system("clear");
    std::cout << BOLD << UNDERLINE << "ExamShell v2.1.1" << RESET << std::endl
              << std::endl;
    std::cout << BOLD << "login:" << RESET;
    fflush(stdout);
    usleep(600000);
    std::string login = getenv("USER");
    for (int i = 0; i < login.size(); i++)
    {
        usleep(100000);
        std::cout << login[i];
        fflush(stdout);
    }

    usleep(400000);
    std::cout << std::endl
              << BOLD << "password:" << RESET;
    fflush(stdout);
    srand(time(NULL));
    int password_size = rand() % 10 + 4;
    for (int i = 0; i < password_size; i++)
    {
        usleep(150000);
        std::cout << "*";
        fflush(stdout);
    }
    std::cout << std::endl
              << std::endl
              << std::endl;
    // usleep(200000);
}

// ==> First menu display
int exam::stud_or_swim(void)
{
    std::string choice = "";
    while (choice != "1" && choice != "2")
    {
        system("clear");
        std::cout << WHITE << GREEN << "     CAMPO  42EXAME " << std::endl;
        if(vip)
            std::cout << "   Voce é um " << LIME << "VIP" << WHITE << BOLD << " usuário" << RESET << std::endl << std::endl;
        else
            std::cout << "     Atualiazdo por " << LIME << "timatias" << RESET << std::endl
                  << std::endl
                  << std::endl;
        std::cout << LIME << BOLD << "            1" << RESET << std::endl;
        std::cout << WHITE << BOLD << "    |  opcao Piscina C  |" << RESET << BOLD << std::endl
                  << "     \\ ------------ /" << std::endl
                  << std::endl;
        std::cout << LIME << BOLD << "            2" << RESET << std::endl;
        std::cout << WHITE << BOLD << "    |  opcao 42Curso  |" << RESET << BOLD << std::endl
                  << "     \\ ------------ /" << std::endl
                  << std::endl << std::endl;

        std::cout << LIME << BOLD << "            3" << RESET << std::endl;
        std::cout << WHITE << BOLD << "    |" << RESET << BOLD << "  Opcao Configuracao " << WHITE << BOLD << "|" << RESET << BOLD << std::endl
                  << "     \\ ------------ /" << std::endl
                  << std::endl
                  << std::endl;
        
        if (choice == "-1")
            std::cout << BOLD << RED;
        else 
            std::cout << WHITE << BOLD;
        std::cout << "    Insira sua escolha:" << RESET << std::endl
                  << "            ";
        // std::cin >> choice;
        if (!std::getline(std::cin, choice))
            sigd();
        if (choice == "3")
        {
            settings_menu();
            std::cin.ignore();
        }
        else if (choice != "1" && choice != "2" )
            choice = "-1";
    }
    return (atoi(choice.c_str()));
}

// ==> Setting MENU
void exam::settings_menu(void)
{
    load_settings();
    char* logname = std::getenv("LOGNAME");
    char* lognameexam;
    std::string input = "";
    while (input != "0")
    {
        system("clear");

        lognameexam = std::getenv("LOGNAMELOG42EXAM");

        std::cout << WHITE << BOLD << "     === MENU DE CONFIGURAÇÕES ===" << std::endl << RED << "          BACK" << RESET << WHITE << BOLD << " with " << RED << "0" << RESET << std::endl << std::endl;

        std::cout << LIME << "1." << WHITE << BOLD << " Ativar exercícios que você já passou";
        if (setting_dse)
            std::cout << LIME << BOLD << " ON" << RESET << std::endl;
        else
            std::cout << RED << BOLD << " OFF" << RESET << std::endl;

        std::cout << LIME << "2." << WHITE << BOLD << " Ativar comandos de trapaça";
        if (setting_dcc)
            std::cout << LIME << BOLD << " ON" << RESET << std::endl;
        else
            std::cout << RED << BOLD << " OFF" << RESET << std::endl;

        std::cout << LIME << "3." << WHITE << BOLD << " Anonimizar envio de dados para LOG : ";
        if (setting_an)
            std::cout << LIME << BOLD << " ON" << RESET << std::endl;
        else
            std::cout << RED << BOLD << " OFF" << RESET << std::endl;
        std::cout << "   > O envio de nome para o log está atualmente :  " << LIME << BOLD << lognameexam << RESET << std::endl;
        std::cin >> input;
        if (input == "1")
        {
            setting_dse = !setting_dse;
        }
        if (input == "2")
            setting_dcc = !setting_dcc;

        if (input == "3")
        {
            setting_an = !setting_an;
            if (setting_an)
                setenv("LOGNAMELOG42EXAM", generate_unique_id().c_str(), 1);
            else 
                setenv("LOGNAMELOG42EXAM", logname, 1);
        }
    }

    std::cout << REMOVE_LINE << RESET << WHITE << BOLD << "Salvando configurações..." << std::endl;
    std::string tmp = "bash .system/data_sender.sh \"settings_out:enable_ead>" + std::to_string(setting_dse);
    tmp += "__settings:enable_cheat>" + std::to_string(setting_dcc) + "\"";
    system(tmp.c_str());
    save_settings();
}




// ==> Display the menu for the student part
int exam::stud_menu(void)
{
    std::string choice = "-2";
    while (choice == "-1" || choice == "-2")
    {
        system("clear");
        std::cout << WHITE << BOLD << "         42EXAM " << std::endl
                  << RED << "   VOLTAR" << RESET << WHITE << BOLD << " ao menu com " << RED << "0" << RESET << std::endl;
        std::cout << LIME << BOLD << "            " << RESET << std::endl
                  << std::endl
                  << std::endl;
        std::cout << WHITE << BOLD << "    |  Opcao Piscina C  |" << RESET << BOLD << std::endl
                  << "     \\ ------------ /" << std::endl
                  << std::endl
                  << LIME << "            •           " << std::endl;
        std::cout << WHITE << BOLD << "    |  Opcao 42Curso  |" << std::endl;
        std::cout << std::endl
                  << LIME << "            2" << RESET << WHITE << BOLD << std::endl
                  << "       RANK EXAME 02" << std::endl;
        std::cout << std::endl
                  << LIME << "            3" << RESET << WHITE << BOLD << std::endl
                  << "      RANK EXAME 03" << std::endl;
        std::cout << std::endl
                  << LIME << "            4" << RESET << WHITE << BOLD << std::endl
                  << "       RANK EXAME04" << std::endl;
        std::cout << std::endl
                  << LIME << "            5" << RESET << WHITE << BOLD << std::endl
                  << "       RANK EXAME05" << std::endl;
        std::cout << std::endl
                  << LIME << "            6" << RESET << WHITE << BOLD << std::endl
                  << "       RANK EXAME06";
        std::cout << RESET << BOLD << std::endl
                  << "     \\ ------------ /" << std::endl;
        if (choice == "-1")
            std::cout << BOLD << RED;
        std::cout << std::endl
                  << std::endl;
        std::cout << "    Insira sua escolha:" << RESET << std::endl
                  << "            ";
        if (!std::getline(std::cin, choice))
            sigd();

        if (choice != "2" && choice != "3" && choice != "4" && choice != "5" && choice != "6" && choice != "0")
            choice = "-1";
    }
    return (atoi(choice.c_str()));
}

// ==> Display the menu for the piscine part
int exam::piscine_menu(void)
{
    std::string choice = "-2";
    while (choice == "-1" || choice == "-2")
    {
        system("clear");
        std::cout << WHITE << BOLD << "         42EXAM " << std::endl
                  << RED << "   VOLTAR" << RESET << WHITE << BOLD << " ao menu com " << RED << "0" << RESET << std::endl;
        std::cout << LIME << BOLD << "            " << RESET << std::endl
                  << std::endl
                  << LIME << "            •           " << std::endl
                  << WHITE << BOLD << "    |  Opcao Piscina C |" << std::endl;
        std::cout << std::endl
                  << LIME << "            1" << RESET << WHITE << BOLD << std::endl
                  << "       SEMANA DE EXAME 01" << std::endl;
        std::cout << std::endl
                  << LIME << "            2" << RESET << WHITE << BOLD << std::endl
                  << "       SEMANA DE EXAME 02" << std::endl;
        std::cout << RESET << BOLD << std::endl
                  << "     \\ ------------ /" << std::endl
                  << std::endl
                  << std::endl;
        std::cout << WHITE << BOLD << "    |  Opcao 42Curso  |" << RESET << BOLD << std::endl
                  << "     \\ ------------ /" << std::endl
                  << std::endl;
        if (choice == "-1")
            std::cout << BOLD << RED;
        std::cout << std::endl;
        std::cout << "    Insira sua escolha:" << RESET << std::endl
                  << "            ";
        if (!std::getline(std::cin, choice))
            sigd();
        if (choice != "1" && choice != "2" && choice != "0")
            choice = "-1";
    }
    return (atoi(choice.c_str()));
}
