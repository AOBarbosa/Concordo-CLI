#ifndef MESSAGE_H
#define MESSAGE_H

#include "User.h"

#include <string>

using std::string;

class Message
{
private:
  string currentDateTime;
  int sentByUserId;
  string messageContent;

public:
  Message();
  Message(string date, int userId, string content);
  // ~Message();

  void setMessageContent(const string& content);
  void setCurrentDateTime(const string& dateTime);
  void setSentByUserId(int userId);

  string getCurrentDateTime() const;
  int getSentByUserId() const;
  string getMessageContent() const;
};

#endif