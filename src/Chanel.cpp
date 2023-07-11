#include "Chanel.h"

Chanel::Chanel()
{
  this->chanelName = "";
  this->channelType = "";
}

Chanel::Chanel(string name , string type)
{
  this->chanelName = name;
  this->channelType = type;
}

string Chanel::getChannelName() const { return this->chanelName; }

string Chanel::getChannelType() const { return this->channelType; }

void Chanel::setListOfUsers(User* user) { listOfUsers.push_back(user); }

vector<User*> Chanel::getListOfUsers() const { return this->listOfUsers; }

void Chanel::setListOfMessages(Message* message) { listOfMessages.push_back(std::move(message)); }

vector<Message*> Chanel::getListOfMessages() const { return this->listOfMessages; }
