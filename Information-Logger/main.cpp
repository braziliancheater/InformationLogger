#include "main.hpp"
#include "console.hpp"

int main()
{
   logo();
   shouldLog();

   if (logchecker) { log_ok("checks concluidos, continuando"); logging(); Sleep(2000); }
   else { log_err("o site provavelmente nao esta no ar, verifique seu host"); Sleep(3000); exit(-1); }
   
   log_ok("concluido!, informacoes enviadas.");
   Sleep(5000);
}
