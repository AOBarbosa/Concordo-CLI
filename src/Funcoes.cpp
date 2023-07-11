#include "Funcoes.h"

// Códigos de escape ANSI para cores
#define RESET   "\033[0m"
#define PINK "\033[1;35m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

using namespace std;

string getFirstWord(const string& str) 
{
    string firstWord;
    size_t spacePos = str.find(' ');
    if (spacePos != string::npos) {
        firstWord = str.substr(0, spacePos);
    } else {
        // Caso não haja espaço na string, a string inteira é considerada como a primeira palavra.
        firstWord = str;
    }
    return firstWord;
}

vector<string> splitString(const string& str, char delimiter) 
{
    vector<string> tokens;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

bool checkUserEmailInSystem(string email, Sistema sistema)
{
  vector<User*> users = sistema.getUsersSistema();
  for (int i = 0; i < users.size(); i++)
  {
    if (users[i]->getUserEmail() == email)
    {
      return true;
    }
  }
  return false;
}

bool checkUserPasswordInSystem(string password, Sistema sistema)
{
  vector<User*> users = sistema.getUsersSistema();
  for (int i = 0; i < users.size(); i++)
  {
    if (users[i]->getUserPassword() == password)
    {
      return true;
    }
  }
  return false;
}

bool checkServerInSystem(string serverName, Sistema sistema)
{
  vector<Server*> servers = sistema.getServersSistema();
  for (int i = 0; i < servers.size(); i++)
  {
    if (servers[i]->getServerName() == serverName)
    {
      return true;
    }
  }
  return false;
}

int checkChannelName(string channelName, string channelType, Server* currentServer)
{
  vector<Chanel*> channels = currentServer->getChanels();
  int count{0};

  for (int i = 0; i < channels.size(); i++)
  {
      if (channels[i]->getChannelType() == channelType)
      {
        if (channels[i]->getChannelName() == channelName) count++;  
      }       
  }

  return count;
}

bool checkChannelInSystem(string name, Sistema sistema)
{
  vector<Chanel*> channels = sistema.getCurrentServer()->getChanels();

  for (int i = 0; i < channels.size(); i++)
  {
    if (channels[i]->getChannelName() == name) return true;
  }
  return false;
}

Chanel* getChannel(vector<Chanel*> channels, string name) 
{
  for (auto channel : channels)
  {
    if (channel->getChannelName() == name)
    {
      return channel;
    }
  }
  return nullptr;
}

void mainMenu()
{
  cout << CYAN << "MAIN MENU\n"
         << "- Para criar usuario, digite: "<< RESET << YELLOW << "'create-user <email> <senha_sem_espaços> <nome com espaços>'\n" << RESET
         << CYAN << "- Para fazer login, digite: "<< RESET << YELLOW <<"'login <email> <senha>'\n" << RESET
         << CYAN << "- Para sair, digite:"<< RESET << YELLOW <<" 'quit'\n" << RESET;

    cout << PINK << "Digite seu comando: " << RESET;
}

void loggedMenu()
{
  cout << BLUE << "\nLOGGED MENU\n"
               << "- Para criar um servidor digite: "<< RESET << YELLOW << "'create-server <nome>'\n" << RESET
               << BLUE << "- Para mudar a descrição do servidor atual, digite: " << RESET << YELLOW <<"'set-server-desc <nome> <descrição>'\n" << RESET
               << BLUE << "- Para setar código de convite para o servidor, digite: " << RESET << YELLOW <<"'set-server-invite-code <nome> <codigo>'\n" << RESET
               << BLUE << "- Para listar os servidores, digite: " << RESET << YELLOW <<"'list-servers'\n" << RESET
               << BLUE << "- Para listar pessoas no servidor, digite: " << RESET << YELLOW <<"'list-participants'\n" << RESET
               << BLUE << "- Para remover servidor, digite: " << RESET << YELLOW <<"'enter-server <nome>'\n" << RESET
               << BLUE << "- Para entrar em um servidor, digite: " << RESET << YELLOW <<"'remove-server <nome>'\n" << RESET
               << BLUE << "- Para sair de um servidor, digite: " << RESET << YELLOW <<"'leave-server'\n" << RESET
               << BLUE << "- Para listar pessoas no servidor, digite: " << RESET << YELLOW <<"list-participants'\n" << RESET
               << BLUE << "- Para criar um canal, digite: " << RESET << YELLOW <<"create-channel <nome> <tipo>'\n" << RESET
               << BLUE << "- Para entrar em um canal do servidor, digite: " << RESET << YELLOW <<"list-channels'\n" << RESET
               << BLUE << "- Para listar os canais do servidor, digite: " << RESET << YELLOW <<"enter-channel <nome>'\n" << RESET
               << BLUE << "- Para desconectar do Concordo, digite: " << RESET << YELLOW <<"disconnect'\n" << RESET;

  cout << PINK << "Digite seu comando: " << RESET;
}

void channelsMenu()
{
  cout << MAGENTA << "\nCHANNELS MENU\n" << RESET
       << MAGENTA << "- Para enviar uma mensagem para o canal, digite: '" << RESET << YELLOW << "send-message <mensagem>'\n" << RESET
       << MAGENTA << "- Para visualizar as mensagens do canal, digite: '" << RESET << YELLOW << "list-messages'\n" << RESET;

  cout << WHITE << "Digite o comando: " << RESET;
}