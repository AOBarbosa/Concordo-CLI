#ifndef FUNCOES_H
#define FUNCOES_H

#include "Sistema.h"
#include "User.h"

#include <string>
#include <sstream>

#include <vector>

using std::string;
using std::vector;

/*!
 *  @brief A getter.
 * 
 *  Gets the first word of a string.
 * @return The first word.
*/
string getFirstWord(const string& str);

/*!
 *  @brief A function to split a string.
 *
 *  @param str The string to split.
 *  @param delimiter The delimiter.
 * 
 * @return A vector in wich each index its a part of the string.
*/
vector<string> splitString(const string& str, char delimiter);

/*!
 *  @brief A function that checks if there's an user in the system with the same email.
 *
 * @param email The email.
 * @param sistema The current system.
*/
bool checkUserEmailInSystem(string email, Sistema sistema);

/*!
 *  @brief A function that checks if the user password is correct.
 *
 *  @param password The password to be checked.
 *  @param sistema The current system.
*/
bool checkUserPasswordInSystem(string password, Sistema sistema);

/*!
 *  @brief A function that checks if there's a server with the same name.
 *
 *  @param serverName The server name.
 *  @param sistema The current system.
*/
bool checkServerInSystem(string serverName, Sistema sistema);

/*!
 *  @brief A function that checks if there's a channel in the system.
 *
 *  @param name The channel name.
 *  @param sistema The current system.
*/
bool checkChannelInSystem(string name, Sistema sistema);

/*!
 *  @brief A function that checks if there's a channel with the same name and type.
 *
 *  @param channelName The channel name.
 *  @param channelType The channel type.
 *  @param currentServer The current server.
*/
int checkChannelName(string channelName, string channelType, Server* currentServer);

/*!
 *  @brief Gets a channel.
 *  
 *  @param channels A list of channels.
 *  @param name The the name.
*/
Chanel* getChannel(vector<Chanel*> channels, string name);

/*!
 * @brief A function that prints the main menu.
*/
void mainMenu();

/*!
 * @brief A function that prints the logged menu.
*/
void loggedMenu();

/*!
 * @brief A function that prints the channels menu.
*/
void channelsMenu();

#endif // FUNCOES_H 