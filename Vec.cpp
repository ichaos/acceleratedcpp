#include "Vec.h"
#include <algorithm>

template <class T> void Vec<T>::create() {
        data = avail = limit = 0;
}

template <class T> void Vec<T>::create(size_type n, const T& val) {
        data = alloc.allocate(n);
        avali = limit = data + n;
        for (int i = 0; i < n; i++)
                alloc.construct(data + i, val); //data[i] = val;
}

template <class T> void Vec<T>::create(const_iterator begin, const_iterator end) {
        data = alloc.allocate(begin - end);
        avail = limit = data + n;
}

template <class T> void Vec<T>::uncreate() {
        if (data) {
                while (avail != data) {
                        alloc.destroy(avail);
                        avail--;
                }
                alloc.deallocate();
        }
        data = avail = limit = 0;
}

template <class T> void Vec<T>::grow() {
        size_type new_size = max(2 * (limit - data), 1);
        iterator tmp = alloc.allocate(new_size);
        size_type i = 0;
        while (i < new_size / 2) {
                tmp[i] = data[i];
                i++;
        }
        uncreate();
        data = tmp;
        avail = data + new_size / 2;
        limit = data + new_size;
}

template <class T> void Vec<T>::unchecked_append(const T& t) {
        alloc.construct(avail++, t);
}
