#ifndef SERVER_H
#define SERVER_H

#include "Chanel.h"
#include "TextChanel.h"
#include "VoiceChanel.h"
#include "User.h"

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <utility>
#include <memory>

using std::string;
using std::vector;
using std::unique_ptr;
using std::move;

class Server
{
private:
  int ownerUserId;
  string serverName;
  string serverDescription;
  string invitationCode;
  //bool isOpen;
  vector<Chanel*> chanels;
  vector<int> participantsId;

public:
  Server();
  Server(User* user, string name, string description, vector<int> participantsId);
  // ~Server();

  void setServerName(string name);
  void setServerDescription(string description);
  void setChannels(Chanel* channel);
  void setParticipantsId(int id);
  void setServerInvitationCode(string invitationCode);

  int getOwnerUserId() const;
  string getServerName() const;
  string getServerDescription() const;
  string getInvitationCode() const;
  vector<Chanel*> getChanels() const;
  vector<int> getParticipantsId() const;
};

#endif // SERVER_H