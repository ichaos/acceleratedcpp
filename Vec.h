#include <memeory>

template<class T> class Vec {
public:
        typedef T* iterator;
        typedef const T* const_iterator;
        typedef size_t size_type;
        typedef T value_type;

        Vec() { create(); };
        explicit Vec(size_type n, const T& t = T()) { create(n, t); };
        Vec(const Vec& v) { create(v.begin(), v.end()); };
        Vec& operator=(const Vec& v);
        ~Vec() { uncreate(); };

        T& operator[](size_type i) { return data[i]; };
        const T& operator[](size_type i) const { return data[i]; };

        size_type size() const { return avail - data; };

        void push_back(const T& t) {
                if (avail == limit) {
                        grow();
                }
                //*avail++ = t;
                unchecked_append(t);
        }

        iterator begin() { return data; }
        const_interator begin() const { return data; }

        iterator end() { return avail; }
        const_iterator end() { return avail; }

private:
        iterator data;
        iterator avail;
        iterator limit;

        std::allocator<T> alloc;

        void create();
        void create(size_type, const T&);
        void create(const iterator, const iterator);

        void uncreate();

        void grow();
        void unchecked_append();
};
