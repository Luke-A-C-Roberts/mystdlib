#include "primatives.hpp"

#ifndef CONTAINER
#define CONTAINER

namespace msl {
    template<class T> class _Container {
    protected:
        u64 _size;
        T&  _start;
    public:
        _Container(void);
        _Container(const T& t);
        virtual auto operator[](const u64 index) -> T&;
        virtual auto first(void) -> T&;
        virtual auto last(void) -> T&;
    };

    template<class T> class _Resizeable {
    public:
        virtual void append(const T);
        virtual void remove(const T);
        virtual void remove_at(const u64 index);
        virtual void insert_at(const u64 index, const T);
        virtual void clear(void);
    };

    template<class T> class _ResizeableContainer: public _Container<T>, public _Resizeable<T> {
        using _Container<T>;
    public:
        List(void)      : _Container<T>::_Container()  {}
        List(const T& t): _Container<T>::_Container(t) {}

        auto operator[](const u64 index) -> T&;
        virtual void append(const T);
        virtual void remove(const T);
        virtual void remove_at(const u64 index);
        virtual void insert_at(const u64 index, const T);
        virtual void clear(void);
    };
}

#endif