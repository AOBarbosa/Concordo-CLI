#ifndef VOICE_CHANEL_H
#define VOICE_CHANEL_H

#include "Chanel.h"
#include "Message.h"

class VoiceChanel: public Chanel
{
private:
  Message lastMessage;
  
public:
  VoiceChanel();
  VoiceChanel(string name, Message last);
  // ~VoiceChanel();

  void setChannelName(string name);
  void setLastMessage(Message last);

  string getChannelName();
  Message getLastMessage();
  string getChannelType();
};

#endif // VOICE_CHANEL_H