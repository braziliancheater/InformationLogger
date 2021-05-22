// todos os includes necessarios pra rodar o programa
// mantem tudo organizado e fofo ><
#pragma warning(disable:4996)
#define CURL_STATICLIB

#ifdef _DEBUG
#pragma comment (lib, "curllib/libcurl_a_debug.lib")
#else
#pragma comment (lib, "curl/libcurl_a.lib")
#endif
#pragma comment (lib, "Normaliz.lib")
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Wldap32.lib")
#pragma comment (lib, "advapi32.lib")
#pragma comment (lib, "Crypt32.lib")

// <-- includes obrigatorios -->
#include <string>
#include <random>
#include <iostream>
#include <stdio.h>

// <-- imports que cuidam da web -->
#include "curllib/curl.h"
#pragma comment(lib,"WinInet.lib")
#include <WinInet.h>
#pragma comment(lib, "Ws2_32.lib")
#include <Winsock2.h>

// <-- arquivos locais -->
#include "console.hpp"
#include "xor.hpp"