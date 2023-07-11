#ifndef TEXT_CHANEL_H
#define TEXT_CHANEL_H

#include "Chanel.h"
#include "Message.h"

#include <vector>
#include <string>

using std::vector;
using std::string;

class TextChanel: public Chanel
{
private:
  vector<Message> textMessages;

public:
  TextChanel();
  TextChanel(string name, Message messages);
  // ~TextChanel();

  void setChannelName(string name);
  void setChannelType(string type);

  string getChannelName();
  vector<Message> getTextMessages();
};


#endif // _TEXT_CHANEL_H