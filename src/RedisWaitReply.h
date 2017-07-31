#ifndef _REDIS_WAIT_REPLY_H
#define _REDIS_WAIT_REPLY_H

#include "BaseWaitReply.h"

class RedisSingleWaitReply : public BaseWaitReply
{
public:
    RedisSingleWaitReply(const ClientSession::PTR& client);
private:
    virtual void    onBackendReply(int64_t dbServerSocketID, const BackendParseMsg::PTR&);
    void            mergeAndSend(const ClientSession::PTR&);
};

class RedisStatusReply : public BaseWaitReply
{
public:
    RedisStatusReply(const ClientSession::PTR& client, const char* status);
private:
    virtual void    onBackendReply(int64_t dbServerSocketID, const BackendParseMsg::PTR&);
    void            mergeAndSend(const ClientSession::PTR&);

private:
    const std::string   mStatus;
};

class RedisErrorReply : public BaseWaitReply
{
public:
    RedisErrorReply(const ClientSession::PTR& client, const char* error);
private:
    virtual void    onBackendReply(int64_t dbServerSocketID, const BackendParseMsg::PTR&);
    void            mergeAndSend(const ClientSession::PTR&);

private:
    const std::string   mErrorCode;
};

class RedisWrongTypeReply : public BaseWaitReply
{
public:
    RedisWrongTypeReply(const ClientSession::PTR& client, const char* wrongType, const char* detail);
private:
    virtual void    onBackendReply(int64_t dbServerSocketID, const BackendParseMsg::PTR&);
    void            mergeAndSend(const ClientSession::PTR&);

private:
    const std::string   mWrongType;
    const std::string   mWrongDetail;
};

class RedisMgetWaitReply : public BaseWaitReply
{
public:
    RedisMgetWaitReply(const ClientSession::PTR& client);
private:
    virtual void    onBackendReply(int64_t dbServerSocketID, const BackendParseMsg::PTR&);
    void            mergeAndSend(const ClientSession::PTR&);
};

class RedisMsetWaitReply : public BaseWaitReply
{
public:
    RedisMsetWaitReply(const ClientSession::PTR& client);
private:
    virtual void    onBackendReply(int64_t dbServerSocketID, const BackendParseMsg::PTR&);
    void            mergeAndSend(const ClientSession::PTR&);
};

class RedisDelWaitReply : public BaseWaitReply
{
public:
    RedisDelWaitReply(const ClientSession::PTR& client);
private:
    virtual void    onBackendReply(int64_t dbServerSocketID, const BackendParseMsg::PTR&);
    void            mergeAndSend(const ClientSession::PTR&);
};

#endif