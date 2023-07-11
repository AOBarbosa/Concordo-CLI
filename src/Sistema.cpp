#include "Sistema.h"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"

Sistema::Sistema()
{
  vector<User*> usersSistema;
  vector<Server*> serversSistema;
}

Sistema::Sistema(vector<User*> users, vector<Server*> servers)
{
  for (auto &&user : users)
  {
    usersSistema.push_back(user);
  }
  
  for (auto &&server : servers)
  {
    serversSistema.push_back(server);
  }
  
}

void Sistema::setUsersInSistema(User* user) { usersSistema.push_back(user); }

void Sistema::setListOfUsersInSistema(vector<User*> users) { this->usersSistema = users; }

void Sistema::setServerInSistema(Server* server) { serversSistema.push_back(server); }

void Sistema::setListOfServersInSistema(vector<Server*> servers) { this->serversSistema = servers; }

void Sistema::setCurrentServer(Server* server) { this->currentServer = server; }

void Sistema::setCurrentChannel(Chanel* channel) { this->currentChanel = channel; }

vector<User*> Sistema::getUsersSistema() { return usersSistema; }

vector<Server*> Sistema::getServersSistema()
{
  return serversSistema;
}

Server* Sistema::getCurrentServer() const { return this->currentServer; }

Chanel* Sistema::getCurrentChanel() const { return this->currentChanel; }

void Sistema::printServers(vector<Server*> servers)
{
  int pos = 1; // Inicie a variável 'pos' com 1 em vez de 0
  cout << GREEN << ">>Estes são os servidores ativos:\n" << RESET;
  for (int i = 0; i < servers.size(); i++)
  {
    if (servers[i]->getServerName() != "")
    {
      cout << YELLOW << pos << ". " << servers[i]->getServerName() << endl << RESET;
      pos++; // Incrementar 'pos' após imprimir um servidor
    }
  }
}

void Sistema::printListOsUsersInCurrentServer(const vector<User*> users, vector<int> listOfIds) 
{
        cout << "Usuários no servidor:\n";
        for (int id : listOfIds) {
            for (const User* user : users) {
                if (user->getUserId() == id) {
                    cout << YELLOW << user->getUserName() << endl << RESET;
                    break;
                }
            }
        }
}

void Sistema::printChannels(Server* server)
{
  vector<Chanel*> channels = server->getChanels();
  vector<Chanel*> text;
  vector<Chanel*> voice;

  for (int i = 0; i < channels.size(); i++)
  {
    if (channels[i]->getChannelType() == "texto")
    {
      text.push_back(channels[i]);
    }
    if (channels[i]->getChannelType() == "voz")
    {
      voice.push_back(channels[i]);
    }   
  }

  cout << YELLOW << "#Canais de Texto\n";
  for (auto t : text)
  {
    cout << "- " << t->getChannelName() << "\n";
  }

  cout << "#Canais de Áudio\n";
  for (auto v : voice)
  {
    cout << "- " << v->getChannelName() << "\n";
  }
  cout << RESET;
}

void Sistema::printMessages(vector<Message*> messages, vector<User*> users)
{
  for (auto message : messages)
  {
    string name;
    for (auto user : users)
    {
      if (user->getUserId() == message->getSentByUserId())
      {
        name = user->getUserName();
      }
      
    }
    
    cout << GREEN << name << "<" << message->getCurrentDateTime() << ">: " << message->getMessageContent() << "\n" << RESET;
  }
  
}

void Sistema::saveUsers() 
{
  ofstream file("usuarios.txt");
  if (!file.is_open())
  {
    cerr << "Erro ao abrir o arquivo 'usuarios.txt'.\n";
    return;
  }

  // Write the amount of users in the file
  file << usersSistema.size() << endl;

  // Write users data in the file 
  for (auto user : usersSistema) 
  {
    file << user->getUserId() << endl;
    file << user->getUserName() << endl;
    file << user->getUserEmail() << endl;
    file << user->getUserPassword() << endl;
  }

  file.close();
  
}

void Sistema::saveServers() 
{
  ofstream file("servidores.txt");
  if (!file.is_open()) 
  {
    cerr << "Erro ao abrir o arquivo.\n";
    return;
  }

  // Write amount of servers in the file
  file << serversSistema.size() << endl;

  // Write each server data in the file
  for (auto server : serversSistema) 
  {
    file << server->getOwnerUserId() << endl;
    file << server->getServerName() << endl;
    file << server->getServerDescription() << endl;
    file << server->getInvitationCode() << endl;
    file << server->getParticipantsId().size() << endl;

    // Write participants users ID in the file    
    for (int userId : server->getParticipantsId()) 
    {
      file << userId << endl;
    }

    // Write amount of channels of a server in the file
    file << server->getChanels().size() << endl;

    // Write each channel data in the file
    for (auto channel : server->getChanels()) 
    {
      file << channel->getChannelName() << endl;
      file << channel->getChannelType() << endl;
      file << channel->getListOfMessages().size() << endl;

      // Write each message data of the channel
      for (auto message : channel->getListOfMessages()) 
      {
        file << message->getSentByUserId() << endl;
        file << message->getCurrentDateTime() << endl;
        file << message->getMessageContent() << endl;
      }
    }
  }

  file.close();
}

void Sistema::save()
{
  saveUsers();
  saveServers();
}

void Sistema::loadUsers()
{
  
  // ifstream file("usuarios.txt");
  // if (!file.is_open())
  // {
  //   cerr << "Arquivo 'usuarios.txt' não encontrado.\n";
  //   return;
  // }

  // usersSistema.clear();

  // // Ler o total de usuários no arquivo 
  // int totalUsers;
  // file >> totalUsers;
  // file.ignore(); // Ignorar o caractere de quebra de linha

  // // Ler as informações de cada usuário
  // for (int i = 0; i < totalUsers; i++) 
  // {
  //   int id;
  //   string name, email, password;

  //   file >> id;
  //   file.ignore(); // Ignorar o caractere de quebra de linha

  //   getline(file, name);
  //   getline(file, email);
  //   getline(file, password);

  //   usersSistema.emplace_back(id, name, email, password);

  // }

  // file.close();
}

void Sistema::loadServers()
{}

void Sistema::load()
{
  loadUsers();
  // loadServers();
}