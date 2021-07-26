#ifndef GUARD_VEC_H
#define GUARD_VEC_H
#include <cstddef>
#include <memory>
using std::allocator;
using std::uninitialized_fill;
using std::uninitialized_copy;
using std::max;

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
    size_type size() const { return (avail - data); }
    T& operator[](size_type i) { return data[i]; }
    const T& operator[](size_type i) const { return data[i]; }

    // 返回迭代器的函数begin, end
    iterator begin() { return data; }
    const_iterator begin() const { return data; }
    iterator end() { return avail; }
    const_iterator end() const { return avail; }

	void push_back(const T& val) {
		if (avail == limit) {
			grow();
		}
		unchecked_append(val);
	}


private:
    iterator data;
	iterator avail;
    iterator limit;
	// 为什么不用 new T[N]的方式分配内存呢？
	// 因为T必须有默认构造函数，而标准的vector是没有这个限制的

	// 内存管理相关
	allocator<T> alloc;
	
	// 为底层的数组分配空间并对它进行初始化
	void create();
	void create(size_type, const T&);
	void create(const_iterator, const_iterator);

	// 删除数字中的元素并释放其占用的内存
	void uncreate();

	// 支持push_back()的函数
	void grow();
	void unchecked_append(const T&);
};

template <class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs)
{
	// 判断是否进行自我赋值
	if (&rhs != this)
	{
		// 删除运算符左侧的数组
		uncreate();
		// 从右侧复制元素到左侧
		create(rhs.begin(), rhs.end());
	}
	return *this;
}

template <class T>
void Vec<T>::create()
{
	data = avail = limit = 0;
}

template <class T>
void Vec<T>::create(size_type n, const T& val)
{
	data = alloc.allocate(n);
	limit = avail = data+n;
	uninitialized_fill(data, limit, val);
	
}

template <class T>
void Vec<T>::create(const_iterator i, const_iterator j)
{
	data = alloc.allocate(j-i);
	limit = avail = uninitialized_copy(i, j, data);
}

template <class T>
void Vec<T>::uncreate()
{
	if (data) {
		iterator it = avail;
		while (it != data)
		{
			alloc.destroy(--it);
		}
		alloc.deallocate(data, limit - data);
	}
	data = limit = avail = 0;
}


template <class T>
void Vec<T>::grow()
{
	// 在扩展对象大小的时候，为对象分配实际使用的两倍大小的内存空间
	size_type new_size = max(2 * (limit - data), ptrdiff_t(1));
	// 分配新的内存空间并将已存在的对象元素复制到新内存中
	iterator new_data = alloc.allocate(new_size);
	iterator new_avail = uninitialized_copy(data, avail, new_data);
	// 原来的空间把它释放掉
	uncreate();
	//重置指针，使其指向新分配的内存空间
	data = new_data;
	avail = new_avail;
	limit = data + new_size;
}

// avail指向一片新分配但尚未被初始化的内存空间
template <class T>
void Vec<T>::unchecked_append(const T&val)
{
	alloc.construct(avail++, val);
}


#endif 