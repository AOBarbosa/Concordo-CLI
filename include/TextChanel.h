#ifndef TEXT_CHANEL_H
#define TEXT_CHANEL_H

#include "Chanel.h"
#include "Message.h"

#include <vector>
#include <string>

using std::vector;
using std::string;

/*!
 *  @brief A class derived from Channel, representing a Text Channel.
 * 
 *  A Text channel is made of a list of text messages.
*/
class TextChanel: public Chanel
{
private:
  vector<Message> textMessages; /*!< The text messages. */

public:
  /*!
   *  @brief A constructor.
   * 
   *  Default empty constructor.
  */
  TextChanel();

  /*!
   *  @brief A constructor.
   * 
   *  A constructor that receives a name and a message.
   * @param name The name.
   * @param message The message.
  */
  TextChanel(string name, Message message);

  /*!
   *  @brief A destructor.
  */ 
  // ~TextChanel();

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
   *  Sets the channel type.
   * @param type A string with a type.
  */
  void setChannelType(string type);

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
   *  Gets a list of messages.
   * @return The list of messages.
  */
  vector<Message> getTextMessages();
};


#endif // _TEXT_CHANEL_H