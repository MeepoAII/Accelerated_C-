#include <cstddef>
#include <memory>
using std::allocator;
using std::uninitialized_fill;
using std::uninitialized_copy;
template <class T> class Vec {
public:
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef T value_type;

    Vec() { create(); }
    explicit Vec(size_type n, const T& val=T()) { create(n, val); }
    Vec(const Vec& v) { create(v.begin(), v.end()); }
    Vec& operator=(const Vec&);
    ~Vec() { uncreate(); }

    size_type size() const { return limit - data; }
    T& operator[](size_type i) { return data[i]; }
    const T& operator[](size_type i) const { return data[i]; }

    iterator begin() { return data; }
    iterator end() { return limit; }
    const_iterator begin() const { return data; }
    const_iterator end() const { return limit; }

    void push_back(const T& val) {
        if (avail == limit) grow();
        unckecked_append(val);
    }


private:
    iterator data;
    iterator avail;
    iterator limit;

    allocator<T> alloc;

    void create();
    void create(size_type, const T&);
    void create(const_iterator, const_iterator);

    void uncreate();

    void grow();
    void unchecked_append(const T&);
    

};

template<class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs) {
    if (&rhs != this) {
        uncreate();
        create(rhs.begin(), rhs.end());
    }
    return *this;
}

template<class T> 
void Vec<T>::create() {
    data = avail = limit = 0;
}

template<class T> 
void Vec<T>::create(size_type n, const T& val) {
    data = alloc.allocate(n);       // 分配空间
    limit = avail = data + n;
    uninitialized_fill(data, limit, val);   // 分配完空间，然后直接用val做初始化
}

template<class T>
void Vec<T>::create(const_iterator i, const_iterator j) {
    data = alloc.allocate(j - i);
    limit = aval = uninitialized_copy(i, j, data);
}

template<class T>
void Vec<T>::uncreate() {
    if (data) {
        iterator it = data;
        while (it != data) {
            alloc.destroy(--i);
        }
        alloc.deallocate(data, limit - data);
    }
    data = limit = avail = 0;
}

template<class T>
void Vec<T>::grow() {
    // 如果要扩展，直接扩展两倍大小的空间
    size_type new_size = max(2*(limit-data), ptrdiff_t(1));

    // 分配新的内存空间并将已经存在的元素复制到新内存中
    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = uninitialized_copy(data, avail, new_data);
    // 别忘了把原来的内存空间清理掉
    uncreate();
    // 重置指针，使其指向新分配的空间
    data = new_data;
    avail = new_avail;
    limit = data + new_size;
}

// avial 指向的是已经分配好但是没有被初始化的空间
template<class T>
void Vec<T>::unchecked_append(const T& val) {
    alloc.construct(aval++, val);
}

