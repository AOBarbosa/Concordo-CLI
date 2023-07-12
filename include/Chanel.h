#ifndef CHANEL_H
#define CHANEL_H

#include "User.h"
#include "Message.h"

#include <string>
#include <vector>
#include <utility>

using std::string;
using std::vector;
using std::move;

/*!
 * @brief A class representing a Channel.
 * 
 * A channel is made of a name, a type, a vector with the users and a vector with the messages.
*/
class Chanel
{
protected:
  string chanelName;                /*!< The name of the channel. */
  string channelType;               /*!< The channel type (voice or text). */
  vector<User*> listOfUsers;        /*!< The list of users. */
  vector<Message*> listOfMessages;  /*!< The list of messages. */

public:

  /*!
   *  @brief A constructor.
   * 
   *  Default empty constructor.
  */
  Chanel();

  /*!
   *  @brief A constructor.
   * 
   *  A constructor thar receives a name and the type.
   * @param name A string with the name.
   * @param type A string with the type.
  */
  Chanel(string name, string type);

  /*!
   *  @brief A destructor.
  */
  // ~Chanel();

  /*!
   *  @brief A setter.
   * 
   *  Sets the list of users.
   * @param user A new user.
  */
  void setListOfUsers(User* user);

  /*!
   *  @brief A setter.
   * 
   *  Sets the list of messages.
   * @param message A new message.
  */
  void setListOfMessages(Message* message);

  /*!
   *  @brief A getter.
   * 
   *  Gets the channel name.
   * @return The channel name.
  */
  string getChannelName() const;

  /*!
   *  @brief A getter.
   * 
   *  Gets the channel type.
   * @return The channel type.
  */
  string getChannelType() const;

  /*!
   *  @brief A getter.
   * 
   *  Gets the list of users in the current channel.
   * @return A list of users.
  */
  vector<User*> getListOfUsers() const;

  /*!
   *  @brief A getter.
   * 
   *  Gets the list of messages in the current channel.
   * @return A list of messages.
  */
  vector<Message*> getListOfMessages() const;
  
};

#endif // CHANEL_H