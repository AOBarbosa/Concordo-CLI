#ifndef MESSAGE_H
#define MESSAGE_H

#include "User.h"

#include <string>

using std::string;

/*!
 *  @brief A class representing a message.
 * 
 *  A message is made of the current date and time it was sent, the ID of the user who sent it and it content.
*/
class Message
{
private:
  string currentDateTime;   /*!< The current date and time of the message.  */
  int sentByUserId;         /*!< The ID of the user who sent the message.  */
  string messageContent;    /*!< The content of the message. */

public:

  /*!
   *  @brief A constructor.
   * 
   *  Default empty constructor.
  */
  Message();

  /*!
   *  @brief A constructor.
   * 
   *  A constructor that receives a date, an ID and the content of the message.
   * @param date The date and time of the message.
   * @param id The ID of the user who sent the message.
   * @param content The content of the message.
  */
  Message(string date, int userId, string content);

  /*!
   *  @brief A destructor.
  */
  // ~Message();

  /*!
   *  @brief A setter.
   * 
   *  Sets the content of the message.
   * @param content A string with the message content.
  */
  void setMessageContent(const string& content);

  /*!
   *  @brief A setter.
   * 
   *  Sets the date and time the message was created.
   * @param dateTime A string with the date and time.
  */
  void setCurrentDateTime(const string& dateTime);

  /*!
   *  @brief A setter.
   * 
   *  Sets the id of the user who sent the message.
   * @param userId An integer with the user ID.
  */
  void setSentByUserId(int userId);

  /*!
   *  @brief A getter.
   * 
   *  Gets the date and time the message was created.
   * @return The date and time.
  */
  string getCurrentDateTime() const;

  /*!
   *  @brief A getter.
   * 
   *  Gets the id of the user who sent the message.
   * @return The id.
  */
  int getSentByUserId() const;

  /*!
   *  @brief A getter.
   * 
   *  Gets the message content.
   * @return The content.
  */
  string getMessageContent() const;
};

#endif