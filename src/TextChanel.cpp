#include "TextChanel.h"

TextChanel::TextChanel()
{
  this->chanelName = "";
  this->channelType = "texto";
  vector<Message> textMessages;
}

TextChanel::TextChanel(string name, Message message)
{
  this->chanelName = name;
  this->channelType = "texto";
  this->textMessages.push_back(message);
}

void TextChanel::setChannelName(string name) { this->chanelName = name; }

void TextChanel::setChannelType(string type) { this->channelType = type; }

string TextChanel::getChannelName() { return this->chanelName; }

vector<Message> TextChanel::getTextMessages() { return this->textMessages; }