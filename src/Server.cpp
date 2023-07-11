#include "Server.h"

Server::Server()
{
  this->ownerUserId = 0;
  this->serverName = "";
  this->serverDescription = "";
  this->invitationCode = "";
  vector<Chanel*> chanels;
  vector<int> participantsId;
}

Server::Server(User* user, string name, string description, vector<int> participants)
{
  int id{0};
  id = user->getUserId();
  this->ownerUserId = id;
  this->serverName = name;
  this->serverDescription = description;
  this->invitationCode = "";
  vector<int> participantsId;
}

void Server::setServerName(string name) { this->serverName = name; }

void Server::setServerDescription(string description) { this->serverDescription = description; }

void Server::setChannels(Chanel* channel) { chanels.push_back(channel); }

void Server::setParticipantsId(int id) { participantsId.push_back(id); }

void Server::setServerInvitationCode(string invitationCode) { this->invitationCode = invitationCode; }

int Server::getOwnerUserId() const { return this->ownerUserId; }

string Server::getServerName() const { return this->serverName; }

string Server::getServerDescription() const { return this->serverDescription; }

string Server::getInvitationCode() const { return this->invitationCode; }

vector<Chanel*> Server::getChanels() const { return this->chanels; }

vector<int> Server::getParticipantsId() const { return this->participantsId; }