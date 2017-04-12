#include <iostream>
#include <memory>
#include "di.hpp"

using namespace std;
namespace di = boost::di;

class IView
{
public:
	virtual void echo() {cout << "iview" << endl;}
	virtual bool isConnected() {return false;}
};

class View1 : public IView
{
public:
	void connect() {
		cout << "connect!!" << endl;
		connected = true;
	}
	virtual bool isConnected() {return connected;}
	virtual void echo() {cout << "view1" << endl;}
	bool connected = false;
};

class View2 : public IView
{
public:
	virtual void echo() {cout << "view2" << endl;}
	virtual bool isConnected() {return false;}
};

class App
{
public:
	App(shared_ptr<IView> view): _view(view){};

	shared_ptr<IView> _view;
};

int main()
{
	auto injector = di::make_injector(
				di::bind<IView>.to([&](const auto& injector) -> shared_ptr<IView> {
						auto v1 = injector.template create<shared_ptr<View1>>();
						v1->connect();
						return v1;
					}).in(di::singleton)
				/* ,di::bind<IView>.to<View2>() [di::override] */
			);

	App app = injector.create<App>();
	app._view->echo();
	cout << app._view->isConnected() << endl;

	App app2 = injector.create<App>();
	cout << app2._view->isConnected() << endl;
	return 0;
}
