#ifndef SISTEMA_H
#define SISTEMA_H

#include "User.h"
#include "Server.h"
#include "Chanel.h"
#include "Message.h"

#include <iostream>
#include <fstream>
#include <vector>

using std::ofstream;
using std::ifstream;
using std::cerr;
using std::cout;
using std::endl;
using std::vector;
using std::getline;

class Sistema
{
  private:
    vector<User*> usersSistema;
    vector<Server*> serversSistema;
    Server* currentServer;
    Chanel* currentChanel;

    void saveUsers();
    void saveServers();

    void loadUsers();
    void loadServers();
    
  public:
    Sistema();
    Sistema(vector<User*> users, vector<Server*> servers);
    // ~Sistema();

    void setUsersInSistema(User* user);
    void setListOfUsersInSistema(vector<User*> users);
    void setServerInSistema(Server* server);
    void setListOfServersInSistema(vector<Server*> servers);
    void setCurrentServer(Server* server);
    void setCurrentChannel(Chanel* channel);

    vector<User*> getUsersSistema();
    vector<Server*> getServersSistema();
    Server* getCurrentServer() const;
    Chanel* getCurrentChanel() const;

    void printServers(vector<Server*> servers);
    void printListOsUsersInCurrentServer(const vector<User*> users, vector<int> listOfIds);
    void printChannels(Server* server);
    void printMessages(vector<Message*> messages, vector<User*> users);

    void save();
    void load();
};

#endif // SISTEMA_H