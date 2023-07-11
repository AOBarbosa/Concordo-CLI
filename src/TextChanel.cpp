#include "TextChanel.h"

TextChanel::TextChanel()
{
  this->chanelName = "";
  this->channelType = "texto";
  vector<Message> textMessages;
}

TextChanel::TextChanel(string name, Message messages)
{
  this->chanelName = name;
  this->channelType = "texto";
  this->textMessages.push_back(messages);
}

void TextChanel::setChannelName(string name) { this->chanelName = name; }

void TextChanel::setChannelType(string type) { this->channelType = type; }

string TextChanel::getChannelName() { return this->chanelName; }

vector<Message> TextChanel::getTextMessages() { return this->textMessages; }