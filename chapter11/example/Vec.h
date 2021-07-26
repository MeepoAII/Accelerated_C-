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

    // ������Ϊ����STL����һ��
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef T value_type;

	Vec() { create(); }
	explicit Vec(size_type n, const T& val=T()) { create(n, val); }

    // ���ƹ��캯��
    // �����µ��ڴ�ռ�
    Vec(const Vec& v) { create(v.begin(), v.end()); }

    // ��ֵ�����
	// ��ֵ���������������(���ƹ���)�������ǣ�ǰ���Ƕ�һ���Ѿ����ڵ�ֵ��ȥ��Ȼ����һ���µ�ֵȡ����֮
	// �����߲���Ҫ��֮ǰ�Ķ�����������ݽ�����ղ���
	// �����˴������Ҹ�ֵ������
	// �ܽ᣺��ֵ����ɾ��һ����ֵ������ʼ����û���ⲽ��������ʼ����������һ���µĶ���ͬʱ����һ����ʼ��ֵ
    Vec& operator=(const Vec&);

	~Vec() { uncreate(); }

    // get Vec��С������
    size_type size() const { return (avail - data); }
    T& operator[](size_type i) { return data[i]; }
    const T& operator[](size_type i) const { return data[i]; }

    // ���ص������ĺ���begin, end
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
	// Ϊʲô���� new T[N]�ķ�ʽ�����ڴ��أ�
	// ��ΪT������Ĭ�Ϲ��캯��������׼��vector��û��������Ƶ�

	// �ڴ�������
	allocator<T> alloc;
	
	// Ϊ�ײ���������ռ䲢�������г�ʼ��
	void create();
	void create(size_type, const T&);
	void create(const_iterator, const_iterator);

	// ɾ�������е�Ԫ�ز��ͷ���ռ�õ��ڴ�
	void uncreate();

	// ֧��push_back()�ĺ���
	void grow();
	void unchecked_append(const T&);
};

template <class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs)
{
	// �ж��Ƿ�������Ҹ�ֵ
	if (&rhs != this)
	{
		// ɾ���������������
		uncreate();
		// ���Ҳิ��Ԫ�ص����
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
	// ����չ�����С��ʱ��Ϊ�������ʵ��ʹ�õ�������С���ڴ�ռ�
	size_type new_size = max(2 * (limit - data), ptrdiff_t(1));
	// �����µ��ڴ�ռ䲢���Ѵ��ڵĶ���Ԫ�ظ��Ƶ����ڴ���
	iterator new_data = alloc.allocate(new_size);
	iterator new_avail = uninitialized_copy(data, avail, new_data);
	// ԭ���Ŀռ�����ͷŵ�
	uncreate();
	//����ָ�룬ʹ��ָ���·�����ڴ�ռ�
	data = new_data;
	avail = new_avail;
	limit = data + new_size;
}

// availָ��һƬ�·��䵫��δ����ʼ�����ڴ�ռ�
template <class T>
void Vec<T>::unchecked_append(const T&val)
{
	alloc.construct(avail++, val);
}


#endif 