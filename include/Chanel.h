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

class Chanel
{
protected:
  string chanelName;
  string channelType;
  vector<User*> listOfUsers;
  vector<Message*> listOfMessages;

public:
  Chanel();
  Chanel(string name, string type);
  // ~Chanel();

  void setListOfUsers(User* user);
  void setListOfMessages(Message* message);

  string getChannelName() const;
  string getChannelType() const;
  vector<User*> getListOfUsers() const;
  vector<Message*> getListOfMessages() const;
  
};

#endif // CHANEL_H