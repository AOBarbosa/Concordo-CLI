#include "VoiceChanel.h"

VoiceChanel::VoiceChanel()
{
  this->chanelName = "";
  this->channelType = "voz";
  Message lastMessage;
}

VoiceChanel::VoiceChanel(string name, Message last)
{
  this->chanelName = name;
  this->channelType = "voz";
  this->lastMessage = last;
}

void VoiceChanel::setLastMessage(Message last) { this->lastMessage = last; }

void VoiceChanel::setChannelName(string name) { this->chanelName = name; }

string VoiceChanel::getChannelName() { return this->chanelName; }

Message VoiceChanel::getLastMessage() { return this->lastMessage; }

string VoiceChanel::getChannelType() { return this->channelType; }