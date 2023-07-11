#include "User.h"

int User::lastId = 0;

User::User()
{
  userId = ++lastId;
  userName = "";
  userEmail = "";
  userPassword = "";
  isLogged = false;
}

User::User(string name, string email, string password)
{
  this->userId = ++lastId;
  this->userName = name;
  this->userEmail = email;
  this->userPassword = password;
  this->isLogged = false;
}

int User::getUserId() const { return this->userId; }

void User::setUserName(string name) { this->userName = name; }

string User::getUserName() const { return this->userName; }

void User::setUserEmail(string email) { this->userEmail = email; }

string User::getUserEmail() const { return this->userEmail; }

void User::setUserPassword(string password) { this->userPassword = password; }

string User::getUserPassword() const { return this->userPassword; }

void User::setLogin() { this->isLogged = true; }

void User::setDisconect() { this->isLogged = false; }

bool User::getIsLogged() const { return this->isLogged; }

void User::setChannelLoggedIn(string channelName) { this->channelLoggedIn = channelName; }

string User::getChannelLoggedIn() const { return this->channelLoggedIn; }