# information logger 🕵️
uma alternativa para obter informações de um hospedeiro e enviá-las atraves de curl.

# como executar? 
primeiro um programa como [xampp](https://www.apachefriends.org/pt_br/index.html) e necessario para a hospedagem dos arquivos em php,
ao hospedar os 4 arquivos e verificar que os mesmos funcionam o programa deve funcionar de maneira automatica, primeiramente verificando se o site esta online.<br>
caso contrario notificando pelo terminal o erro tanto em curl() como em conexão, vale lembrar que existem maneiras mais eficiente de criar algo similar porem como eu
queria criar certa familiaridade com curl acabei escolhendo-o como biblioteca principal desse projeto.<br><br>
<p align="center"><img src="https://i.imgur.com/huaaAYA.png"/><br>caso tudo de certo algo como isso sera o output</p><br><br>
caso o programa encontre algum erro o output sera de acordo com o mesmo.

# curllib
o programa exige a biblioteca curl que e incluida no projeto, caso a mesma esteja desatualizada ou necessite de reparos você precisara recompilar-la usando o "x64 Native Tools Command Prompt"
que e incluido com todas as instalações do vs-community pra fazer isso existe um tuturial bem simples nesse [link](https://store.chipkin.com/articles/building-libcurl-on-windows-with-mt-and-mtd/)
ou se preferir pesquise por conta propria.

# phps
os arquivos em php que fazem parte do programa foram incluidos na pasta "php" hospede todos e modifique de acordo com seu uso, obviamete o servidor não precisa ser hospedado localmente.

### todo

- [ ] um bot que pega o texto do site e printa em no discord.
- [ ] pegar token do discord
- [ ] pegar senhas e logins 
- [ ] pegar ip
- [ ] cleanup no codigo
- [ ] implementar algo diferente de curl 
