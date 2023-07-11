#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

using std::string;
using std::vector;

class User
{
private:
  static int lastId;
  int userId;
  string userName;
  string userEmail;
  string userPassword;
  bool isLogged;
  string channelLoggedIn;

public:
  User();

  User(string name, string email, string password);

  // ~User();

  void setUserName(string name);
  void setUserEmail(string email);
  void setUserPassword(string password);
  void setLogin();
  void setDisconect();
  void setChannelLoggedIn(string channelName);


  int getUserId() const;
  string getUserName() const;
  string getUserEmail() const;
  string getUserPassword() const;
  bool getIsLogged() const;
  string getChannelLoggedIn() const;
};

#endif