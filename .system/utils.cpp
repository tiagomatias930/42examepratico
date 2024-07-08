#include "exam.hpp"

std::string current_path(void)
{
    std::string current_path = getcwd(NULL, 0);
    if (current_path.find(getenv("HOME")) != std::string::npos)
        current_path.replace(current_path.find(getenv("HOME")), std::string(getenv("HOME")).length(), "~");
    return current_path;
}

std::string time_in_string(time_t rawtime)
{
    struct tm *timeinfo;
    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, sizeof(buffer), "%d-%m-%Y_%H:%M:%S", timeinfo);
    std::string str(buffer);

    return str;
}

std::string remaining_time(time_t end_time)
{
    time_t now = time(0);
    time_t remaining_time = end_time - now;
    if (remaining_time < 0)
        return "0";
    int hours = remaining_time / 3600;
    int minutes = (remaining_time % 3600) / 60;
    int seconds = (remaining_time % 3600) % 60;
    std::stringstream ss;
    ss << hours << "hrs, " << std::setw(2) << minutes << "min e " << std::setw(2) << seconds << "seg";
    return ss.str();
}

std::string lastupdate(time_t end_time)
{
    time_t now = 1662477376;
    time_t remaining_time = end_time - now;
    int day = remaining_time / 86400;
    int hours = (remaining_time % 86400) / 3600;
    std::string ret = MAGENTA + std::to_string(day) + RESET + " dias e " + MAGENTA + std::to_string(hours) + RESET + " horas";
    return ret;
}

void sigd(void)
{
    std::cout << std::endl
              << "Você foi desconectado após usar Ctrl+D" << std::endl;
    exit(0);
}

void sigc(int sig)
{
    if (sig == SIGINT)
    {
        std::cout << std::endl
                  << "Você foi desconectado após usar Ctrl+C" << std::endl;
        exit(0);
    }
    if (sig == SIGQUIT)
    {
        std::cout << std::endl
                  << "Você foi desconectado após usar Ctrl+\\ (SIGQUIT)" << std::endl;
        exit(0);
    }
    if (sig == SIGTSTP)
    {
        std::cout << WHITE << BOLD << std::endl
                  << "Sair do exame..." << std::endl;
        exit(0);
    }
}

bool file_exists(std::string path)
{
    std::ifstream infile(path);
    return infile.good();
}

// ==> Restaurar pasta para o padrão
bool exam::clean_all()
{
    if (file_exists("rendu") && level == 0)
        system("rm -rf rendu");
    if (file_exists("subjects"))
        system("rm -rf subjects");
    if (file_exists(".system/grading"))
        system("rm -rf .system/grading");
    if (file_exists(".system/grading/passed"))
        system("rm -rf .system/grading/passed");
    if (file_exists(".dev"))
        system("rm -f .dev");
    return true;
}

void reset_folder(void)
{
    system("rm -rf .system/grading/*");
    system("rm -rf rendu/*");
    system("rm -rf subject");
    system("rm -rf traces");
    system("rm -rf a.out");
    system("rm -rf a.out.dSYM");
}

// ==> Retorna os minutos de espera relativo ao número da tarefa
double exercise::grade_time(void)
{
    // vetor que contém todos os números de Fibonacci
    std::vector<double> fib;
    if (get_assignement() == 0)
        return 0;
    fib.push_back(0.5);
    fib.push_back(2.5);
    for (int i = 2; i < 100; i++)
    {
        fib.push_back(fib[i - 1] + fib[i - 2]);
        if (i - 2 == get_assignement() - 1)
            return fib[i - 2];
    }
    return 0;
}

// ==> FUNCIONALIDADE: Verifica se o readline está instalado no sistema
void check_readline()
{
    // se o readline não estiver instalado
    int is_linux = 0;
#ifdef __linux__
    is_linux = 1;
#endif

    if (!file_exists("/usr/include/readline/readline.h") && is_linux)
    {
        std::cout << "Erro: readline não está instalado no seu computador" << std::endl
                  << std::endl;

        std::cout << "Instalar readline automaticamente? (s/n)" << std::endl;
        std::string input;
        std::getline(std::cin, input);
        if (input == "s")
        {
            std::cout << "Instalando readline..." << std::endl;
            system("sudo apt-get install libreadline-dev");
            std::cout << "Readline instalado, por favor reinicie o programa" << std::endl;
            exit(0);
        }
        else
        {
            std::cout << "O readline é necessário para usar este programa, por favor instale-o e reinicie o programa" << std::endl;
            exit(0);
        }
        exit(0);
    }
}
