#pragma once
#include <vector>
#include <algorithm>
using namespace std;

template <class T> class RepoTemplate {
protected:
	vector<T> elem;
public:
	RepoTemplate();
	void add(T&);
	T get(int i);
	void update(T&, T&);
	void remove(T&);
	int size();
	vector<T> getAll();
};

template<class T>
inline RepoTemplate<T>::RepoTemplate()
{
}

template<class T>
inline void RepoTemplate<T>::add(T& e)
{
	elem.push_back(e);
}

template<class T>
inline T RepoTemplate<T>::get(int i)
{

	return elem.at(i);

}

template<class T>
inline void RepoTemplate<T>::update(T& vechi, T& nou)
{
	std::replace(elem.begin(), elem.end(), vechi, nou);
}

template<class T>
inline void RepoTemplate<T>::remove(T& e)
{
	
				typename vector<T>::iterator it;
				it = find(elem.begin(), elem.end(), e);
				if (it != elem.end())
				{
					elem.erase(it);
				}
			}
		


template<class T>
inline int RepoTemplate<T>::size()
{
	return elem.size();
}

template<class T>
inline vector<T> RepoTemplate<T>::getAll()
{
	return elem;
}

