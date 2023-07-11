#ifndef FUNCOES_H
#define FUNCOES_H

#include "Sistema.h"
#include "User.h"

#include <string>
#include <sstream>

#include <vector>

using std::string;
using std::vector;

string getFirstWord(const string& str);
vector<string> splitString(const string& str, char delimiter);
bool checkUserEmailInSystem(string email, Sistema sistema);
bool checkUserPasswordInSystem(string password, Sistema sistema);
bool checkServerInSystem(string serverName, Sistema sistema);
bool checkChannelInSystem(string name, Sistema sistema);
int checkChannelName(string channelName, string channelType, Server* currentServer);
Chanel* getChannel(vector<Chanel*> channels, string name);

void mainMenu();
void loggedMenu();
void channelsMenu();

#endif // FUNCOES_H 