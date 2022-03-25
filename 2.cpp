template <class ls>
class Queue {
public:
	list <ls> queue;

	void push(ls n) {
		queue.push_back(n);
	}

	ls pop() {
		ls need = queue.front();
		queue.pop_front();
		return need;
	}
};