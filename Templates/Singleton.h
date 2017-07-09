#ifndef SINGLETON_H
#define SINGLETON_H

#include <Logger/Logger.h>

namespace Templates
{
template <typename T>
class Singleton
{
public:
    static T& Instance()
    {
//        Logger::Info("checking instance");
        if (_Instance == 0)
        {
//            Logger::Info("creating singleton instance");
            _Instance = CreateInstance();
        }
        return *(_Instance);
    }

protected:
    virtual ~Singleton() {}
    inline explicit Singleton() {}

private:
    static T* _Instance;
    static T* CreateInstance()
    {
        return new T();
    }
};

template<typename T>
T* Singleton<T>::_Instance = 0;

} // namespace Templates

#endif // SINGLETON_H

