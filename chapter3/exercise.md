# chapter3 exercise
## 3-0
homework.cpp
## 3-1
根据中位数的定义，，肯定不能丢弃的。。。
## 3-2
计算四分位数  
3-2.cpp  
[参考wiki的method1](https://en.wikipedia.org/wiki/Quartile#Method_1)
## 3-3
3-3.cpp  
自己写的有点麻烦，其实可以再cin的时候就判断是否之前已经有过了，可以[参考这里](https://github.com/anirudhtopiwala/Accelerated-C-Solutions/blob/master/Accelerated%20C%2B%2B/chapter03/3-3.cpp)
## 3-4
3-4.cpp  
可以边输入边检查
## 3-5
3-5.cpp
题目中说，平时成绩的次数要是一个确定的值，的确用while(cin >> name)的话，程序不能坚持到下一个cin >> name，因为在cin >> homework的时候那个end-of-file没有被clear，所有cin>>name 还是会读到那个end-of-file，然后直接退出最外面那个while
## 3-6
double homework_grade = (count > 0) ? sum / count : 0.0

