#ifndef GUARD_VEC_H
#define GUARD_VEC_H
#include <cstddef>

template <class T> class Vec {
public:

    // 下面是为了与STL保持一致
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef T value_type;

	Vec() { create(); }
	explicit Vec(size_type n, const T& val=T()) { create(n, val); }

    // 复制构造函数
    // 开辟新的内存空间
    Vec(const Vec& v) { create(v.begin(), v.end()); }

    // 赋值运算符
	// 赋值运算符跟拷贝构造(复制构造)的区别是，前者是对一个已经存在的值擦去，然后赋上一个新的值取而代之
	// 而后者不需要对之前的对象里面的内容进行清空操作
	// 别忘了处理自我赋值的问题
	// 总结：赋值总是删除一个旧值，而初始化则没有这步操作，初始化包括创造一个新的对象并同时给它一个初始的值
    Vec& operator=(const Vec&);

	~Vec() { uncreate(); }

    // get Vec大小和索引
    size_type size() const { return (limit - data); }
    T& operator[](size_type i) { return data[i]; }
    const T& operator[](size_type i) const { return data[i]; }

    // 返回迭代器的函数begin, end
    iterator begin() { return data; }
    const_iterator begin() const { return data; }
    iterator end() { return limit; }
    const_iterator end() const { return limit; }


private:
    iterator data;
    iterator limit;
	// 为什么不用 new T[N]的方式分配内存呢？
	// 因为T必须有默认构造函数，而标准的vector是没有这个限制的

};


#endif