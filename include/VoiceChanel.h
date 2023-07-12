#ifndef VOICE_CHANEL_H
#define VOICE_CHANEL_H

#include "Chanel.h"
#include "Message.h"

/*!
 *  @brief A class derived from Channel, representing a Voice Channel.
 * 
 *  A Voice Channel is made of a single message.
*/
class VoiceChanel: public Chanel
{
private:
  Message lastMessage;  /*!< The last message sent. */
  
public:
  /*!
   *  @brief A constructor.
   * 
   *  Default empty constructor.
  */
  VoiceChanel();

  /*!
   *  @brief A constructor.
   * 
   *  A constructor that receives a name and a message.
  */
  VoiceChanel(string name, Message last);

  /*!
   *  @brief A destructor.
  */
  // ~VoiceChanel();

  /*!
   *  @brief A setter.
   * 
   *  Sets the channel name.
   * @param name A string with a name.
  */
  void setChannelName(string name);

  /*!
   *  @brief A setter.
   * 
   *  Sets the last message.
   * @param last A string with a message.
  */
  void setLastMessage(Message last);

  /*!
   *  @brief A getter.
   * 
   *  Gets the channel name.
   * @return The channel name.
  */
  string getChannelName();

  /*!
   *  @brief A getter.
   * 
   *  Gets the last message.
   * @return The last message.
  */
  Message getLastMessage();

  /*!
   *  @brief A getter.
   * 
   *  Gets the channel type.
   * @return The channel type.
  */
  string getChannelType();
};

#endif // VOICE_CHANEL_H