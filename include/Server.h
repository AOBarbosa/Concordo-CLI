#ifndef SERVER_H
#define SERVER_H

#include "Chanel.h"
#include "TextChanel.h"
#include "VoiceChanel.h"
#include "User.h"

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <utility>
#include <memory>

using std::string;
using std::vector;
using std::unique_ptr;
using std::move;

/*!
 *  @brief A class representing a server.
 * 
 *  A server is made of the id of the owner user, a name, a description, an invitation code, alist of cahnnels and a list the participants id.
*/
class Server
{
private:
  int ownerUserId;              /*!< The owner user ID. */
  string serverName;            /*!< The server name. */
  string serverDescription;     /*!< The server description. */
  string invitationCode;        /*!< The server invitation code. */
  vector<Chanel*> chanels;      /*!< The list of channels. */
  vector<int> participantsId;   /*!< The list of participants id. */

public:
  /*!
   *  @brief A constructor.
   * 
   *  Default empty constructor.
  */
  Server();

  /*!
   *  @brief A constructor.
   * 
   *  A constructor that receives an user, a name, a description and a list with the participants id..
  */
  Server(User* user, string name, string description, vector<int> participantsId);
  
  /*!
   *  @brief A destructor.
  */
  // ~Server();

  /*!
   *  @brief A setter.
   * 
   *  Sets the server name.
   * @param content A string with a name.
  */
  void setServerName(string name);

  /*!
   *  @brief A setter.
   * 
   *  Sets the server name.
   * @param content A string with a name.
  */
  void setServerDescription(string description);

  /*!
   *  @brief A setter.
   * 
   *  Sets a new channel to the list.
   * @param channel A new channel.
  */
  void setChannels(Chanel* channel);

  /*!
   *  @brief A setter.
   * 
   *  Sets a new participant id to the list.
   * @param channel A new participant id.
  */
  void setParticipantsId(int id);

  /*!
   *  @brief A setter.
   * 
   *  Sets a the invitation code.
   * @param invitationCode A string with the invitation code.
  */
  void setServerInvitationCode(string invitationCode);

  /*!
   *  @brief A getter.
   * 
   *  Gets the id of the owner.
   * @return The owner id.
  */
  int getOwnerUserId() const;

  /*!
   *  @brief A getter.
   * 
   *  Gets the server name.
   * @return The server name.
  */
  string getServerName() const;

  /*!
   *  @brief A getter.
   * 
   *  Gets the server description.
   * @return The server description.
  */
  string getServerDescription() const;

  /*!
   *  @brief A getter.
   * 
   *  Gets the server invitation code.
   * @return The server invitation code.
  */
  string getInvitationCode() const;

  /*!
   *  @brief A getter.
   * 
   *  Gets the list of channels.
   * @return The list of channels.
  */
  vector<Chanel*> getChanels() const;

  /*!
   *  @brief A getter.
   * 
   *  Gets the list of participants id.
   * @return The list of participants id.
  */
  vector<int> getParticipantsId() const;
};

#endif // SERVER_H