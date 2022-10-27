#ifndef __SINGLETON_H__
#define __SINGLETON_H__

#define SINGLETHREAD 0
#define MULTITHREAD  0
#define DOULEMUTEX   0
#define CXX11        0
#define CALL_ONCE    1



#if  SINGLETHREAD
class Singleton
{
public:
    static Singleton * getInstance()
    {

        if(!m_singleton)
        {
            m_singleton = new Singleton;
        }
        return m_singleton;

    }

private:
    Singleton() = default;
    Singleton* m_singleton{nullptr};

};
#endif 


#if MULTITHREAD

#include <mutex>

std::mutex m_mutex;

class Singleton
{
public:
    static Singleton* getInstance()
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        if (!m_singleton)
        {
            m_singleton = new Singleton;
        }
        lock.unlock();
        lock.release();

        return m_singleton;
    }

private:
    Singleton() = default;
    Singleton* m_singleton{ nullptr };

};

#endif 


#if DOULEMUTEX

#include <mutex>
std::mutex m_mutex;

class Singleton
{
public:
    static Singleton* getInstance()
    {
        if (!m_singleton)
        {
            std::unique_lock<std::mutex> lock(m_mutex);
            if (!m_singleton)
            {
                m_singleton = new Singleton;
            }
            lock.unlock();
            lock.release();
        }

        return m_singleton;
    }

private:
    Singleton() = default;
    Singleton* m_singleton{ nullptr };

};

#endif


#if CXX11

class Singleton
{
public:
    static Singleton& getInstance()
    {
        static Singleton m_instance;
        return m_instance;
    }

public:
    Singleton() = default;

    Singleton(const Singleton& another) = delete;
    Singleton(const Singleton&& another) = delete;

    Singleton& operator=(const Singleton& another) = delete;
    Singleton& operator=(const Singleton&& another) = delete;

};

#endif


#if CALL_ONCE

#include <thread>
#include <mutex>
#include <memory>

std::once_flag flag;

class Singleton
{
public:
    static Singleton& getInstance()
    {
        std::call_once(flag, []() {m_instance.reset(new Singleton()); });

        return *m_instance;

    }

public:
    Singleton() = default;

    Singleton(const Singleton& another) = delete;
    Singleton(const Singleton&& another) = delete;

    Singleton& operator=(const Singleton& another) = delete;
    Singleton& operator=(const Singleton&& another) = delete;

private:

    static std::unique_ptr<Singleton> m_instance;


};

std::unique_ptr<Singleton> Singleton::m_instance;

#endif


#endif // !__SINGLETON_H__
