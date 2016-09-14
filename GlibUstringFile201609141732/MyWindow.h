#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <gtkmm.h>
class MyWindow : public Gtk::Window
{
public:
	explicit MyWindow(char* runPath);
	virtual ~MyWindow(void);
private:
	void on_activate();
	Gtk::Entry m_entry;
	FILE* m_fp;
	char m_runPath[1024];
};
