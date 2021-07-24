#include "Vec.h"

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