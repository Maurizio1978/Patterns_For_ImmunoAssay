#ifndef LISTITERATOR
#define LISTITERATOR

#include <list>
namespace Templates
{
template <typename T>
class TListIterator
{
protected:
    std::list<T> _List;
};

} // end Templates namespace
#endif // LISTITERATOR

