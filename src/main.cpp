#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <memory>
#include <utility>
#include <ctime>

#include "Chanel.h"
#include "User.h"
#include "Message.h"
#include "Server.h"
#include "Sistema.h"
#include "TextChanel.h"
#include "User.h"
#include "VoiceChanel.h"
#include "Funcoes.h"

using namespace std;

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



int main(int argc, char const *argv[])
{
  unique_ptr<Sistema> sistema(new Sistema());
  vector<User*> users;
  vector<Server*> servers;
  //sistema->load();
  sistema->setListOfUsersInSistema(users);
  sistema->setListOfServersInSistema(servers);
  

  string input;

  cout << GREEN << "BEM VINDO AO CONCORDO" << endl << RESET;
  while (input != "quit")
  {
    mainMenu();
    getline(cin, input);
    string command;
    command = getFirstWord(input);

    string  email, name, password;
    // Separar as palavras da string
    vector<string> words = splitString(input, ' ');
    email = words[1];
    password = words[2];

    // Juntar todas as palavras após a terceira
    for (size_t i = 3; i < words.size(); ++i) 
    {
      name += words[i];
      if (i != words.size() - 1) 
      {
        name += " ";
      }
    }

    if (command == "create-user")
    {
      // Verificar se há pelo menos quatro palavras
      if (words.size() >= 4) 
      {
        if (checkUserEmailInSystem(email, *sistema) == false) // checando se ja existe usuario com mesmo email
        {
          // unique_ptr<User> user(new User(name, email, password));
          User* user = new User(name, email, password);
          sistema->setUsersInSistema(user);
          cout << GREEN << "Usuário criado: " << user->getUserName() << "\n" << RESET;
          sistema->save();
        }
        else if(checkUserEmailInSystem(email, *sistema) == true) {
          cout << RED << "Usuário já existe!\n" << RESET;
        }
      }
    }  //! end of create-user if

    else if (command == "login")
    {
      int index{0};
      if ((checkUserEmailInSystem(email, *sistema) == true) && (checkUserPasswordInSystem(password, *sistema) == true))
      { 
        for (int i = 0; i < sistema->getUsersSistema().size(); i++)
        {
          if (sistema->getUsersSistema()[i]->getUserEmail() == email)
          {
            sistema->getUsersSistema()[i]->setLogin();
            index = i;
          }
        }
        
        cout << GREEN << "Logado como " << sistema->getUsersSistema()[index]->getUserEmail() << "\n" << RESET;


        while(sistema->getUsersSistema()[index]->getIsLogged() == true)
        {
          string loggedInput;
          string action, serverName, serverDescription, serverInvitationCode;
          
          loggedMenu();
          getline(cin, loggedInput);
          action = getFirstWord(loggedInput);

          // Separar as palavras da string
          vector<string> loggedWords = splitString(loggedInput, ' ');
          serverName = loggedWords[1];

          // Juntar todas as palavras após a segunda
          for (size_t i = 2; i < loggedWords.size(); ++i) 
          {
            serverDescription += loggedWords[i];
            if (i != loggedWords.size() - 1) 
            {
              serverDescription += " ";
            }
          }
        
          if (action == "disconect")
          {
            if (sistema->getUsersSistema()[index]->getIsLogged() == true)
            {
              sistema->getUsersSistema()[index]->setDisconect();
              cout << RED << "Desconectando usuário " << sistema->getUsersSistema()[index]->getUserEmail() << "\n" << RESET;
            }
            else if (sistema->getUsersSistema()[index]->getIsLogged() == false)
            {
              cout << RED << "Não está conectado\n" << RESET;
            }
          } //! end of disconect

          if (action == "create-server")
          {
            vector<int> participants;
            User* user;
            user = sistema->getUsersSistema()[index];
            // int id{0};
            // id = sistema->getUsersSistema()[index]->getUserId();
              if (checkServerInSystem(serverName, *sistema) == false)
              {
                Server* server = new Server(user, serverName, "", participants);

                sistema->setServerInSistema(server);
                cout << GREEN << "Servidor criado\n" << RESET;
                sistema->save();
              }
              else if(checkServerInSystem(serverName, *sistema) == true)
              {
                cout << RED << "Servidor com esse nome já existe\n" << RESET;
              }
          }

          int loggedID = sistema->getUsersSistema()[index]->getUserId();
          if (action == "set-server-desc")
          {
            if (checkServerInSystem(serverName, *sistema) == false)
            {
              cout << RED << "Servidor '" << serverName << "' não existe\n" << RESET;
            }
            else if (loggedID != sistema->getServersSistema()[loggedID - 1]->getOwnerUserId())
            {
              cout << RED << "Você não pode alterar a descrição de um servidor que não foi criado por você\n" << RESET;
            }
            else if (loggedID == sistema->getServersSistema()[loggedID - 1]->getOwnerUserId())
            {
              sistema->getServersSistema()[loggedID - 1]->setServerDescription(serverDescription);
              cout << GREEN << "Descrição do servidor '" << serverName << "' modificada!\n" << RESET;
              sistema->save();
            }
          }

          if (action == "set-server-invite-code")
          {
            int count{-1};
            int aux{0};
            int i{0};
            while (i < sistema->getServersSistema().size())
            {
              if (sistema->getServersSistema()[i]->getServerName() != serverName)
              {
                count = i;
              }
              i++;
            }
            
            count % 2 == 0 ? aux = count + 1 : aux = count - 1;
            if (serverDescription != "")
            {
              sistema->getServersSistema()[count]->setServerInvitationCode(serverDescription);
              cout << GREEN << "Código de convite do servidor '" << sistema->getServersSistema()[aux]->getServerName() << "' modificado!\n" << RESET;
              sistema->save();
            }
            else{
              sistema->getServersSistema()[count]->setServerInvitationCode("");
              cout << GREEN << "Código de convite do servidor '" << sistema->getServersSistema()[aux]->getServerName() << "' removido!\n" << RESET;
              sistema->save();
            }
          }

          if (action == "list-servers")
          {
            vector<Server*> servers;
            servers = sistema->getServersSistema();

            sistema->printServers(servers);
          }

          if (action == "remove-server")
          {
            // auto owner{0};
            auto servers = sistema->getServersSistema();
            Server* serverToDelete = nullptr;

            if (checkServerInSystem(serverName, *sistema))
            {
              if (loggedID == sistema->getServersSistema()[loggedID - 1]->getOwnerUserId())
              {
                for (int i = 0; i < servers.size(); i++)
                {
                    if (servers[i]->getServerName() == serverName)
                    {
                        serverToDelete = servers[i];
                        break;
                    }
                }

                if (serverToDelete != nullptr)
                {
                    auto it = find(servers.begin(), servers.end(), serverToDelete);
                    if (it != servers.end()) {
                        servers.erase(it); // Remove o elemento apontado pelo iterador
                        delete serverToDelete;

                        servers.erase(std::remove(servers.begin(), servers.end(), nullptr), servers.end());
                        // Libera a memória do objeto Server removido
                        cout << GREEN << "Servidor '" << serverName << "' removido.\n" << RESET;
                        sistema->save();
                    }
                }
              }
              else cout << RED << "Você não é o dono do servidor '" << serverName << "'.\n" << RESET;
            }
            else cout << RED << "Servidor '" << serverName << "' não encontrado.\n" << RESET;
          } //! end of remove-server IF

          if (action == "enter-server")
          {
            auto servers = sistema->getServersSistema();

            if (checkServerInSystem(serverName, *sistema))
            {
              int count{-1}; // usar para invite
              int aux{0}; // usar para serverName
              int i{0};
              while (i < sistema->getServersSistema().size())
              {
                if (sistema->getServersSistema()[i]->getServerName() != serverName)
                {
                  count = i;
                }
                i++;
              }
              count % 2 == 0 ? aux = count + 1 : aux = count - 1;

              if (servers[aux]->getOwnerUserId() != loggedID or servers[count]->getInvitationCode() != "")
              {
                if (servers[count]->getInvitationCode() == serverDescription)
                {
                  sistema->setCurrentServer(servers[aux]);
                  servers[aux]->setParticipantsId(loggedID);
                  cout << GREEN << "Entrou no servidor com sucesso!\n" << RESET; 
                  sistema->save();
                }
                else cout << RED << "Servidor requer código de convite\n" << RESET;
              }
              else
              {
                sistema->setCurrentServer(servers[aux]);
                servers[aux]->setParticipantsId(loggedID);
                cout << GREEN << "Entrou no servidor com sucesso!\n" << RESET;
                sistema->save();
              }
            }
          } //! end of enter-server IF

          if (action == "leave-server")
          {
            auto usersInCurrentServer = sistema->getCurrentServer()->getParticipantsId();

            int count{-1}; // usar para invite
            int aux{0}; // usar para serverName
            int i{0};
            while (i < sistema->getServersSistema().size())
            {
              if (sistema->getServersSistema()[i]->getServerName() != serverName)
              {
                count = i;
              }
              i++;
            }
            count % 2 == 0 ? aux = count + 1 : aux = count - 1;

            bool isInCurrentServer{false};
            for (int j = 0; j < usersInCurrentServer.size(); j++)
            {
              if (loggedID == usersInCurrentServer[j])
              {
                isInCurrentServer = true;
                break;
              }
            }
            isInCurrentServer  ? cout << GREEN << "Saindo do servidor\n" << RESET : cout << RED << "Você não está visualizando nenhum servidor\n" << RESET; 
            sistema->save();     
          } //! end of leave-server IF

          if (action == "list-participants")
          {
            auto idList = sistema->getCurrentServer()->getParticipantsId();
            auto members = sistema->getUsersSistema();

            sistema->printListOsUsersInCurrentServer(members, idList);
          }

          //! _-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_GESTAO DE CANAIS_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
          if (action == "create-channel")
          {
            string channelName = serverName;
            string channelType = serverDescription;
            Message message;
            message.setMessageContent("menssagem teste");
            Server* currentServer = sistema->getCurrentServer();

            if(channelType == "texto")
            {
              if (checkChannelName(channelName, channelType, currentServer) == 0)
              {              
                TextChanel* textChannel2 = new TextChanel(channelName, message);

                sistema->getCurrentServer()->setChannels(textChannel2);

                cout << GREEN << "Canal de texto '" << textChannel2->getChannelName() << "' criado!\n" << RESET;
                sistema->save();
              }
              else cout << RED << "Canal de texto '" << channelName << "' já existe!\n" << RESET;              
            }

            if(channelType == "voz")
            {
              if (checkChannelName(channelName, channelType, currentServer) == 0)
              {
                VoiceChanel* voiceChannel2 = new VoiceChanel();
                voiceChannel2->setChannelName(channelName);

                sistema->getCurrentServer()->setChannels(voiceChannel2);

                cout << GREEN << "Canal de voz '" << voiceChannel2->getChannelName() << "' criado!\n" << RESET;
                sistema->save();
              }
              else cout << RED << "Canal de voz '" << channelName << "' já existe!\n" << RESET;              
            }

          }

          if (action == "list-channels")
          {
            Server* current = sistema->getCurrentServer();
            sistema->printChannels(current);
          }
          
          if (action == "enter-channel")
          {
            string channelName = serverName;

            vector<Chanel*> channels = sistema->getCurrentServer()->getChanels();
            Chanel* channelToEnter = nullptr;

            if (checkChannelInSystem(channelName, *sistema))
            {
              if (getChannel(channels, channelName) != nullptr) channelToEnter = getChannel(channels, channelName);

              sistema->setCurrentChannel(channelToEnter);

              cout << GREEN  << "Entrou no canal '" << sistema->getCurrentChanel()->getChannelName() << "'.\n" << RESET;
              sistema->save();
            }
            else cout << RED << "Canal '" << channelName << "' não existe.\n" << RESET;
            
            while (sistema->getCurrentChanel() != nullptr)
            {
              string input;
              string command, text;
              channelsMenu();
              getline(cin, input);


              vector<string> messageCommand = splitString(input, ' ');
              command = messageCommand[0];
              // Juntar todas as palavras após a primeira
              for (size_t i = 1; i < messageCommand.size(); ++i) 
              {
                text += messageCommand[i];
                if (i != messageCommand.size() - 1) 
                {
                  text += " ";
                }
              }

              if (command == "send-message")
              {
                std::time_t t = std::time(nullptr);
                std::tm* now = std::localtime(&t);            
                char dateTime[128];
                strftime(dateTime, sizeof(dateTime), "%m-%d-%Y %X", now);
                string date(dateTime);

                Message* newMessage = new Message();
                newMessage->setCurrentDateTime(dateTime);
                newMessage->setSentByUserId(loggedID);
                newMessage->setMessageContent(text);

                sistema->getCurrentChanel()->setListOfMessages(newMessage);

                sistema->save();

                // cout << YELLOW << sistema->getCurrentChanel()->getListOfMessages()[0]->getMessageContent() << RESET <<endl;
              }

              if (command == "list-messages")
              {
                vector<User*> users = sistema->getUsersSistema();
                vector<Message*> messages = sistema->getCurrentChanel()->getListOfMessages();
                sistema->printMessages(messages, users);
              }

              if (command == "leave-channel")
              {
                sistema->setCurrentChannel(nullptr);

                cout << RED << "\nSaindo do canal\n" << RESET;

                sistema->save();
              }
            }

          }

        }
      }
      else if ((checkUserEmailInSystem(email, *sistema) == false) || (checkUserPasswordInSystem(password, *sistema) == false))
      {
        cout << RED << "Senha ou usuário inválidos!\n" << RESET;
      }

    } //! end of login if
    
  } //! end of main WHILE loop

  cout << RED << "Saindo do Concordo!\n" << RESET;

  return 0;
}
