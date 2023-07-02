#pragma once

#include <iostream>
#include <list>
#include <exception>


// comparator that takes two template variables and returns the difference between them
template <class T>
struct MyComparator {
	T operator()(T a, T b) const {
		return a - b;

	}
};


template <class T>
class PriorityQueue {

public:

	// add new element to queue (priority is lowest to highset)
	void push(const T& t) {
		auto iterator = _queue.begin();

		while (iterator != _queue.end() && MyComparator<T>()(*iterator, t) < 0)
			++iterator;
		_queue.insert(iterator, t);
	}

	// remove and retu7rn first element from queue
	T poll() {
		if (_queue.empty()) {
			throw std::runtime_error("PriorityQueue empty !");
		}

		T top = _queue.front();
		_queue.pop_front();

		return top;
	}

private:
	std::list<T> _queue;
};


