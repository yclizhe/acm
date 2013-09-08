#include <iostream>
#include <stack>
using namespace std;

template <typename T>
class min_stack {
	private:
		stack<T> m_data;
		stack<T> m_min;
	public:
		void push(T t);
		void pop();
		T min();
};

template<typename T>
void min_stack<T>::push(T t) {
	m_data.push(t);
	if(m_min.size() == 0) {
		m_min.push(t);
		return;
	}
	T temp = m_min.top();
	if(temp > t)
		m_min.push(t);
	else
		m_min.push(temp);
}

template<typename T>
void min_stack<T>::pop() {
	if(m_data.size() == 0)
		return ;
	m_data.pop();
	m_min.pop();
	return;
}

template <typename T>
T min_stack<T>::min() {
	return m_min.top();
}
int main() {
	min_stack<int> st;
	int a,b;
	while(cin >> a >> b) {
		switch(a) {
		case 1:
			st.push(b);
			cout << "MIN:"  << st.min() << endl;
			break;
		case 2:
			st.pop();
			cout << "MIN:" << st.min() << endl;
			break;
		}
	}
	return 0;
}


