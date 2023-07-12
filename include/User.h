#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

using std::string;
using std::vector;

/*!
 * @brief A class that represents an user.
 * 
 * An user is made up of four attributes: ID, name, email and password.
 * 
*/

class User
{
private:
  static int lastId;        /*!< A static integer informing the id of the last user created. */
  int userId;               /*!< The user ID. */
  string userName;          /*!< The user name. */
  string userEmail;         /*!< The user email. */
  string userPassword;      /*!< The user password */
  bool isLogged;            /*!< A boolean variable that informes if the user is logged or not. */
  string channelLoggedIn;   /*!< A variable that informe wich channel the user is logged in. */

public:

  /*!
   *  @brief A constructor
   * 
   *  Default empty constructor.
  */
  User();

  /*!
   *  @brief A constructor
   * 
   *  A constructor that receives a name, an email and a password.
   * @see name; email; password
   * @param name a string with the user name.
   * @param email a string with the user email.
   * @param password a string with the user password
  */
  User(string name, string email, string password);

  /*!
   *  @brief A destructor.
  */
  // ~User();

  /*!
   *  @brief A setter method.
   * 
   *  Sets the user name.
   *  @param name a string with the user name.
  */
  void setUserName(string name);

  /*!
   *  @brief A setter method.
   * 
   *  Sets the user email.
   *  @param email a string with the user email.
  */
  void setUserEmail(string email);

  /*!
   *  @brief A setter method.
   * 
   *  Sets the user password.
   *  @param name a string with the user password.
  */
  void setUserPassword(string password);

  /*!
   *  @brief A setter method.
   * 
   *  Sets if the user as logged.
   * @see isLogged
  */
  void setLogin();

  /*!
   *  @brief A setter method.
   * 
   *  Sets the user as not logged.
   *  @see isLogged
  */
  void setDisconect();

  /*!
   *  @brief A setter method.
   * 
   *  Sets the channel the user is logged in.
   *  @param channelName a string with the channel name.
  */
  void setChannelLoggedIn(string channelName);

  /*!
   *  @brief A getter method.
   * 
   *  Gets the user ID.
   *  @return The user ID.
  */
  int getUserId() const;

  /*!
   *  @brief A getter method.
   * 
   *  Gets the user name.
   *  @return The user name.
  */
  string getUserName() const;

  /*!
   *  @brief A getter method.
   * 
   *  Gets the user email.
   *  @return The user email.
  */
  string getUserEmail() const;

  /*!
   *  @brief A getter method.
   * 
   *  Gets the user password.
   *  @return The user password.
  */
  string getUserPassword() const;

  /*!
   *  @brief A getter method.
   * 
   *  Gets ih the user is logged in.
   *  @return The user situation.
  */
  bool getIsLogged() const;

  /*!
   *  @brief A getter method.
   * 
   *  Gets the channel wich the user is logged in.
   *  @return The user ID.
  */
  string getChannelLoggedIn() const;
};

#endif