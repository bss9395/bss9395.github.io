/* Cpp_Notification.cpp
Author: BSS9395
Update: 2024-10-21T13:35:00+08@China-Guangdong-Zhanjiang+08
*/

#include <functional>
#include <iostream>
#include <list>
#include <string>


template <typename Memb_>
void* castmemb(Memb_ memb) {
	union Func {
		void* _func;
		Memb_ _memb;
	};

	Func func;
	func._memb = memb;
	return func._func;
}

template<typename Para_>
class Publisher {
	struct SubscriberBase {
		virtual ~SubscriberBase() = default;
		virtual void _Invoke(Para_ para) = 0;
		virtual bool _Equal(void *type, void *func) = 0;
		virtual bool _Equal(void *type) = 0;
	};

public:
	std::list<SubscriberBase *> _subscribers;

public:
	virtual ~Publisher() {
		fprintf(stdout, "[%s] \n", __FUNCTION__);
		for (auto iter = _subscribers.begin(); iter != _subscribers.end();) {
			SubscriberBase *subscriber = (*iter);
			delete subscriber;
			iter = _subscribers.erase(iter);
		}
	}

public:
	template<typename Type_>
	void _Subscribe(Type_ *type, void(Type_::*func)(Para_)) {
		fprintf(stdout, "[%s] type=%p, func=%p, (void*)func=%p\n", __FUNCTION__, type, func, castmemb(func));
		struct Subscriber : public SubscriberBase {
			Type_ *_type = nullptr;
			void(Type_::*_func)(Para_) = nullptr;

			Subscriber(Type_ *type, void(Type_::*func)(Para_)) {
				fprintf(stdout, "[%s] \n", __FUNCTION__);
				_type = type;
				_func = func;
			}

			virtual ~Subscriber() override {
				fprintf(stdout, "[%s] \n", __FUNCTION__);
			}

			virtual void _Invoke(Para_ para) override {
				fprintf(stdout, "[%s] \n", __FUNCTION__);
				(_type->*_func)(para);
			}

			virtual bool _Equal(void *type, void *func) override {
				fprintf(stdout, "[%s] \n", __FUNCTION__);
				if ((void *)_type == type && castmemb(_func) == func) {
					return true;
				}
				return false;
			}

			virtual bool _Equal(void *type) override {
				fprintf(stdout, "[%s] \n", __FUNCTION__);
				if ((void*)_type == type) {
					return true;
				}
				return false;
			}
		};

		_subscribers.push_back(new Subscriber(type, func));
	}

	template<typename Type_>
	void _Subscribe(Type_ *type, std::function<void(Para_)> func) {
		fprintf(stdout, "[%s] \n", __FUNCTION__);
		struct Subscriber : public SubscriberBase {
			Type_ *_type = nullptr;
			std::function<void(Para_)> _func = nullptr;

			Subscriber(Type_ *type, std::function<void(Para_)> func) {
				fprintf(stdout, "[%s] \n", __FUNCTION__);
				_type = type;
				_func = func;
			}

			virtual ~Subscriber() override {
				fprintf(stdout, "[%s] \n", __FUNCTION__);
			}

			virtual void _Invoke(Para_ para) override {
				fprintf(stdout, "[%s] \n", __FUNCTION__);
				_func(para);
			}

			virtual bool _Equal(void *type, void *func) override {
				fprintf(stdout, "[%s] \n", __FUNCTION__);
				return false;
			}

			virtual bool _Equal(void *type) override {
				fprintf(stdout, "[%s] \n", __FUNCTION__);
				if ((void*)_type == type) {
					return true;
				}
				return false;
			}
		};

		_subscribers.push_back(new Subscriber(type, func));
	}

	template<typename Type_>
	void _Unsubscribe(Type_ *type, void(Type_::*func)(Para_)) {
		fprintf(stdout, "[%s] type=%p, func=%p, (void *)func=%p\n", __FUNCTION__, type, func, castmemb(func));
		for (auto iter = _subscribers.begin(); iter != _subscribers.end(); ) {
			SubscriberBase *subscriber = (*iter);
			if (subscriber->_Equal(type, castmemb(func)) == true) {
				delete subscriber;
				iter = _subscribers.erase(iter);
				continue;
			} 
			++iter;
		}
	}

	template<typename Type_>
	void _Unsubscribe(Type_ *type) {
		fprintf(stdout, "[%s] type=%p\n", __FUNCTION__, type);
		for (auto iter = _subscribers.begin(); iter != _subscribers.end(); ) {
			SubscriberBase *subscriber = (*iter);
			if (subscriber->_Equal(type) == true) {
				delete subscriber;
				iter = _subscribers.erase(iter);
				continue;
			}
			++iter;
		}
	}

	void _Publish(Para_ para) {
		fprintf(stdout, "[%s] \n", __FUNCTION__);
		for (auto iter = _subscribers.begin(); iter != _subscribers.end(); ) {
			SubscriberBase *subscriber = (*iter);
			subscriber->_Invoke(para);
			++iter;
		}
	}
};

class Sender {
public:
	Publisher<std::string> _publisher;
};

class Receiver0 {
public:
	void _Print0(std::string para) {
		fprintf(stdout, "[%s] %s\n", __FUNCTION__, para.data());
	}
};

class Receiver1 {
public:
	void _Print1(std::string para) {
		fprintf(stdout, "[%s] %s\n", __FUNCTION__, para.data());
	}
};

class Receiver2 {
public:
	void _Print2(std::string para) {
		fprintf(stdout, "[%s] %s\n", __FUNCTION__, para.data());
	}
};

static void _Test_Member() {
	fprintf(stdout, "========================================\n");
	Sender sender;
	Receiver0 receiver0;
	Receiver1 receiver1;
	Receiver2 receiver2;
	sender._publisher._Subscribe(&receiver0, &Receiver0::_Print0);
	sender._publisher._Subscribe(&receiver1, &Receiver1::_Print1);
	sender._publisher._Subscribe(&receiver2, &Receiver2::_Print2);
	sender._publisher._Publish("Hello, World!");

	fprintf(stdout, "========================================\n");
	// sender._publisher._Unsubscribe(&receiver1, &Receiver1::_Print1);
	sender._publisher._Unsubscribe(&receiver1);
	sender._publisher._Publish("Hello!");
}

static void _Test_Lambda() {
	fprintf(stdout, "========================================\n");
	Sender sender;
	Receiver0 receiver0;
	sender._publisher._Subscribe(&receiver0, [](std::string para) -> void {
		fprintf(stdout, "[%s] %s\n", __FUNCTION__, para.data());
	});
	sender._publisher._Publish("Hello, World!");

	fprintf(stdout, "========================================\n");
	sender._publisher._Unsubscribe(&receiver0);
	sender._publisher._Publish("Hello!");
}

int main(int argc, char *argv[]) {
	// _Test_Member();
	_Test_Lambda();

	return 0;
}
