#include "exam.hpp"

void exam::fail_ex()
{
    std::string tmp = "bash .system/data_sender.sh \"fail_ex:" + current_ex->get_name() + " level:" + std::to_string(level) + " assignement:" + std::to_string(current_ex->get_assignement()) + "\"";
    system(tmp.c_str());
    current_ex->up_assignement();
    current_ex->set_time_bef_grade(time(NULL) + current_ex->grade_time() * 60);
    store_data();
}

void exam::success_ex(bool force)
{
    // insert current_ex in lvl_ex
    lvl_ex.insert(std::pair<int, exercise>(current_ex->get_lvl(), *current_ex));
    // insert the success exercise into file .system/exam_token/success_ex
    if (!force)
    {
        std::ofstream file;
        file.open("success/success_ex", std::ios::app);
        file << current_ex->get_name() << std::endl;
    }
    std::cout << std::endl
              << LIME << ">>>>>>>>>> CADETE VOCE ACERTOU <<<<<<<<<<" << RESET << std::endl
              << std::endl;
    std::string tmp;
    if (force)
        tmp = "bash .system/data_sender.sh \"cheat_success_ex: " + current_ex->get_name() + " level:" + std::to_string(level) + " assignment:" + std::to_string(current_ex->get_assignement()) + "\"";
    else
        tmp = "bash .system/data_sender.sh \"success_ex: " + current_ex->get_name() + " level:" + std::to_string(level) + " assignment:" + std::to_string(current_ex->get_assignement()) + "\"";
    system(tmp.c_str());
    up_lvl();
    std::cout << "(Pressione enter para continuar...)" << std::endl;
    std::string input;
    if (!std::getline(std::cin, input))
        sigd();
    level_per_ex += level_per_ex_save;
    changex = 0;
    backup = 0;
    if (!force)
    {
        if (file_exists("rendu/"))
        {
            if (!file_exists("success"))
                system("mkdir success");
            system("cp -r rendu/* success/ 2> /dev/null");
        }
    }
    if (level_per_ex > 100)
        end_exam();
    start_new_ex();
}

void exam::end_exam()
{
    std::string tmp;
    remove(".system/exam_token/actuel_token.txt");
    if (using_cheatcode == 0)
    {
        if (student)
            tmp = "bash .system/data_sender.sh \"exam_success_end: examrank0" + std::to_string(exam_number) + "\"";
        else
            tmp = "bash .system/data_sender.sh \"exam_success_end: examweek0" + std::to_string(exam_number) + "\"";
        system(tmp.c_str());
        std::cout << WHITE << BOLD << "🥳 Para Cadete, estas pronto para  fazer o exame real" << exam_number << " !" << std::endl;
    }
    else
    {
        std::cout << WHITE << BOLD << "🙁 Você concluiu o Exam Rank 0" << exam_number << ", " << RED << BOLD << "depois de usar " << using_cheatcode << " comando de trapaça..." << WHITE << BOLD << std::endl;
        if (student)
            tmp = "bash .system/data_sender.sh \"exam_success_cheat" + std::to_string(using_cheatcode) + ": examrank0" + std::to_string(exam_number) + "\"";
        else
            tmp = "bash .system/data_sender.sh \"exam_success_cheat" + std::to_string(using_cheatcode) + ": examweek0" + std::to_string(exam_number) + "\"";
        system(tmp.c_str());
    }
    std::cout << "AMA" << MAGENTA << " 42LUANDA_EXAME" << WHITE << BOLD << " ? Escaneie este QRCode para dar uma estrela no repositório do Github 👋" << std::endl
              << std::endl;
    // show file .system/qrcode
    system("cat .system/qrcode");
    std::cout << std::endl
              << "Abrir repositório do Github? (y/n" << std::endl;
    char c;
    std::cin >> c;
    if (c == 'y' || c == 'Y')
    {
        int is_linux = 0;
#define O 1
#ifdef __linux__
        is_linux = 1;
#endif
        if (is_linux)
            system("xdg-open https://github.com/1tiagomanuel");
        else
            system("open https://github.com/1tiagomanuel");
    }
    std::cout << WHITE << BOLD << "Obrigado por estudar usando o nosso Programa" << LIME << BOLD << username << WHITE << BOLD << " ❤️" << std::endl;
    exit(0);
}

// ==> GradeMe function call by entering `grademe` into prompt
void exam::grademe(void)
{
    if (file_exists(".system/grading/beta"))
    {
        std::cout << std::endl;
        std::cout << YELLOW << " ⚠️  Aviso: " << RESET << "Este exercicio foi contribuido por ";
        // output what is in .system/grading/beta
        std::ifstream file;
        file.open(".system/grading/beta");
        std::string line;
        std::getline(file, line);
        std::cout << YELLOW << line << RESET;
        std::cout << ", ainda está em " << YELLOW << "testes beta" << RESET << "." << std::endl;
        std::cout << " Se você deseja adicionar sua contribuição, visite o ReadME do Github 👋" << std::endl;
        std::cout << " Se voce encontrar algum " << RED << "bug" << RESET << ", por favor, reporte no repositorio do github." << std::endl;
    }

    std::cout << std::endl
              << "Antes de continuar, por favor, tenha " << RED << "ABSOLUTA CERTEZA" << RESET << " de que você está no diretório certo," << std::endl;
    std::cout << "que não esqueceu de nada, etc..." << std::endl;
    std::cout << "Se sua atribuição estiver errada, você terá a mesma atribuição" << std::endl;
    std::cout << std::endl
              << " mas com menos pontos potenciais para ganhar !" << std::endl;
    std::cout << RED << "Você tem certeza?" << RESET << " [y/N] ";
    std::string input;
    if (!std::getline(std::cin, input))
        sigd();
    if (input == "y" || input == "Y")
    {
        if (current_ex->time_bef_grade > time(NULL) && waiting_time)
        {
            std::cout << RED << "ERROR: " << RESET << "Você deve esperar pelo menos " << YELLOW << BOLD;
            if ((((current_ex->time_bef_grade - time(NULL))) / 60) >= 1)
                std::cout << (current_ex->time_bef_grade - time(NULL)) / 60 << " minutos" << RESET << " e " << YELLOW << BOLD << (current_ex->time_bef_grade - time(NULL)) % 60 << " segundos" << RESET;
            else
                std::cout << (current_ex->time_bef_grade - time(NULL)) << " segundos" << RESET;
            std::cout << " até a próxima solicitação de avaliação, então aproveite para fazer mais testes e tenha certeza de que terá sucesso na próxima tentativa!" << std::endl;
            return;
        }
         std::cout << "Ok, fazendo solicitação de avaliação para o servidor agora." << std::endl;
        grade_request(0);
    }
    else
    {
        std::cout << " Sobre" << std::endl;
    }
}

// ==> Function that call the bash grade system
void exam::grade_request(bool i)
{
    if (!i)
    {
        std::cout << std::endl
                  << "Agora vamos esperar o trabalho ser concluído." << std::endl
                  << "Por favor, seja " << LIME << "paciente" << RESET << ", isso " << LIME << "PODE" << RESET << " levar vários minutos..." << std::endl;
        std::cout << "(10 segundos é rápido, 30 segundos é esperado, 3 minutos é o máximo)" << std::endl;
        srand(time(NULL));
        int waiting_seconds = rand() % 5 + 1;
        for (int i = 0; i < waiting_seconds; i++)
        {
            srand(time(NULL));
            double random = rand() % 6500000 + 250000;
            std::cout << "esperando..." << std::endl;
            usleep(random);
        }
    }

    if (!file_exists(".system/grading/tester.sh"))
    {
         std::cout << "Erro: Não foi possível encontrar o script de avaliação para este exercício, está chegando em breve. Você pode usar \"force_success\" para passar este ex." << std::endl;
        return;
    }

    system("bash .system/grading/tester.sh");

    if (file_exists(".system/grading/passed"))
    {
        success_ex(0);
    }
    else
    {
        std::cout << RED << ">>>>>>>>>> Te falta odeio!  Don't Panic<<<<<<<<<<" << RESET << std::endl;
        sleep(1);
        std::cout << "Erro de segmentacao." << std::endl;

        // if there is a traceback file, create a folder traces and copy the file to it with the good name
        if (file_exists("traceback"))
        {
            system("mkdir -p traces");
            std::string trace_name = std::to_string(level) + "-" + std::to_string(current_ex->get_assignement()) + "_" + current_ex->get_name() + ".trace";
            std::string cmd_system_call = "mv traceback traces/" + trace_name;
            system(cmd_system_call.c_str());
            std::cout << "Trace saved to " << LIME << current_path() << "/traces/" << trace_name << RESET << std::endl
                      << std::endl;
        }
        else
        {
            std::cout << "No traceback found." << std::endl
                      << std::endl;
        }
        fail_ex();
        std::cout << "(Pressione enter para continuar...)" << std::endl;
        std::string input;
        if (!std::getline(std::cin, input))
            sigd();
        if (vip)
            infovip();
        else
            info();
    }
}
