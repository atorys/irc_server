//
// Created by Achiote Tory on 5/2/22.
//

#pragma once
#include <iostream>
#include <map>


/*
 *  POSTMAN формирует буферы запросов юзеров и ответы на них
 */
class Postman {
    std::map<int, std::string >     _requests;
    std::map<int, std::string >     _replies;

    public:
        void sendRequest(int, const std::string&);
        void sendReply(int, const std::string&);

        void clearRequest(int);
        void clearReply(int);

        std::string   getRequest(int) const;
        std::string   getReply(int) const;

};

//__REPLIES____________________________________________________
#define RPL_MOTDSTART                           "375 :- <server> Message of the day -"
#define RPL_MOTD(message)                       std::string("372 :- ") + (message)
#define RPL_ENDOFMOTD                           "376 :End of /MOTD command"
#define RPL_AWAY(nickname, away_message)        ("301 " + (nickname) + " :" + (away_message))
#define RPL_UNAWAY                              "305 :You are no longer marked as being away"
#define RPL_NOWAWAY                             "306 :You have been marked as being away"


//__ERRORS_____________________________________________________
#define ERR_NOSUCHNICK(nickname)                ("401 " + (nickname) + " :No such nick/channel")
#define ERR_NOSUCHCHANNEL(channel)              ("403 " + (channel) + " :No such channel")
#define ERR_CANNOTSENDTOCHAN(channel)           ("404 " + (channel) + " :Cannot send to channel")
#define ERR_WASNOSUCHNICK(channel)              ("406 " + (channel) + " :There was no such nickname")
#define ERR_TOOMANYTARGETS(nickname)            ("407 " + (nickname) + " :Duplicate recipients. No message dxelivered)"
#define ERR_UNKNOWNCOMMAND(command)             ("421 " + (command) + " :Unknown command")

//NICK
#define ERR_NONICKNAMEGIVEN                     "431 :No nickname given"
#define ERR_ERRONEUSNICKNAME(nickname)          ("432 " + (nickname) + " :Erroneus nickname")
#define ERR_NICKNAMEINUSE(nickname)             ("433 " + (nickname) + " :Nickname is already in use")
#define ERR_NICKCOLLISION(nickname)             ("436 " + (nickname) + " :Nickname collision KILL")

//USER
#define ERR_NOLOGIN(username)                   ("444 " + (username) + " :User not logged in")

//CHANNEL
#define ERR_USERNOTINCHANNEL(nickname, channel) ("441 " + (nickname) + " " + (channel) + " :They aren't on that channel")
#define ERR_NOTONCHANNEL(channel)               ("442 " + (channel) + " :You're not on that channel")
#define ERR_USERONCHANNEL(username, channel)    ("443 " + (username) + " " + (channel) + " :is already on channel")

//PASS
#define ERR_NOTREGISTERED                       "451 :You have not registered"
#define ERR_NEEDMOREPARAMS(command)             (std::string("461 ") + (command) + " :Not enough parameters")
#define ERR_ALREADYREGISTRED                    "462 :You may not reregister"
#define ERR_PASSWDMISMATCH                      "464 :Password incorrect"

//PRIVMSG
#define ERR_NORECIPIENT(command)                ("411 :No recipient given " + (command))
#define ERR_NOTEXTTOSEND                        "421 :No text to send"
