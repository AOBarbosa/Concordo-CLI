#include "Message.h"

Message::Message()
{
  currentDateTime = "";
  sentByUserId = 0;
  messageContent = "";
}

Message::Message(string date, int userId, string content)
{
  currentDateTime = date;
  sentByUserId = userId;
  messageContent = content;
}

void Message::setMessageContent(const string& content) { this->messageContent = content; }

void Message::setCurrentDateTime(const string& dateTime) { this->currentDateTime = dateTime; }

void Message::setSentByUserId(int userId) { this->sentByUserId = userId; }

string Message::getCurrentDateTime() const { return this->currentDateTime; }

int Message::getSentByUserId() const { return sentByUserId; }

string Message::getMessageContent() const { return this->messageContent; }
