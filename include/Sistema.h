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

/*!
 *  @brief A class representing a system.
 * 
 *  A system is made of a list of users and a list of servers.
*/
class Sistema
{
  private:
    vector<User*> usersSistema;     /*!< The list of users. */
    vector<Server*> serversSistema; /*!< The list os servers. */
    Server* currentServer;          /*!< The current server. */
    Chanel* currentChanel;          /*!< The current channel. */

    /*!
     * @brief A function that save the users in the sistema in a file.
    */
    void saveUsers();   

    /*!
     * @brief A function that save the servers in the sistema in a file.
    */
    void saveServers(); 

    void loadUsers();
    void loadServers();
    
  public:
    /*!
     *  @brief A constructor.
     * 
     *  Default empty constructor.
    */
    Sistema();

    /*!
     *  @brief A constructor.
     * 
     *  A constructor that receives a list of users and a list of servers.
     * @param users The list of users.
     * @param servers The list of servers.
    */
    Sistema(vector<User*> users, vector<Server*> servers);
    
    /*!
     *  @brief A destructor.
    */
    // ~Sistema();

    /*!
     *  @brief A setter.
     * 
     *  Sets a new user in the system.
     * @param user A new user.
    */
    void setUsersInSistema(User* user);

    /*!
     *  @brief A setter.
     * 
     *  Sets the list of users in the system.
     * @param users A list of users.
    */
    void setListOfUsersInSistema(vector<User*> users);

    /*!
     *  @brief A setter.
     * 
     *  Sets a new server in the system.
     * @param server A new server.
    */
    void setServerInSistema(Server* server);

    /*!
     *  @brief A setter.
     * 
     *  Sets the list of servers in the system.
     * @param servers A list of servers.
    */
    void setListOfServersInSistema(vector<Server*> servers);

    /*!
     *  @brief A setter.
     * 
     *  Sets the current server.
     * @param server The server.
    */
    void setCurrentServer(Server* server);

    /*!
     *  @brief A setter.
     * 
     *  Sets the current channel.
     * @param channel The channel.
    */
    void setCurrentChannel(Chanel* channel);

    /*!
     *  @brief A getter.
     * 
     *  Gets the list of users.
     * @return The list of users.
    */
    vector<User*> getUsersSistema();

    /*!
     *  @brief A getter.
     * 
     *  Gets the list of servers.
     * @return The list of servers.
    */
    vector<Server*> getServersSistema();

    /*!
     *  @brief A getter.
     * 
     *  Gets the current server.
     * @return The current server.
    */
    Server* getCurrentServer() const;

    /*!
     *  @brief A getter.
     * 
     *  Gets the current channel.
     * @return The current channel.
    */
    Chanel* getCurrentChanel() const;

    /*!
     *  @brief Prints all the servers in the system.
     *  @param servers The list of servers.
    */
    void printServers(vector<Server*> servers);

    /*!
     *  @brief Prints all the users in the current server.
     *  @param users The list of users.
     *  @param listOfIds The list of ids.
    */
    void printListOsUsersInCurrentServer(const vector<User*> users, vector<int> listOfIds);

    /*!
     *  @brief Prints all the channels in the system.
     *  @param server The server.
    */
    void printChannels(Server* server);

    /*!
     *  @brief Prints all the messages in the current channel.
     *  @param messages The list of messages.
     *  @param users The list of users.
    */
    void printMessages(vector<Message*> messages, vector<User*> users);

    /*!
     * @brief A function that calls the private functions saveUsers() and saveServers().
    */
    void save();
    
    void load();
};

#endif // SISTEMA_H