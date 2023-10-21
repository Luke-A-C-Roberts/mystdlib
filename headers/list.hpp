#include "primatives.hpp"
#include "containers.hpp"

#ifndef LIST
#define LIST

namespace msl {

    template<class T> class List: public _ResizeableContainer<T> {
    public:
        List(void)      : _Container<T>::_Container()  {}
        List(const T& t): _Container<T>::_Container(t) {}
        auto operator[](const u64 index) -> T& override;
        void append(const T) override;
        void remove(const T) override;
        void remove_at(const u64 index) override;
        void insert_at(const u64 index, const T) override;
        void clear(void) override;
    };

}

#endif