#include "MyWindow.h"
#include <gtkmm.h>
#include <locale.h>
#include <shlwapi.h>
#include <stdlib.h>
#include <stdio.h>
#pragma comment(lib, "shlwapi.lib")
int main(int argc, char* argv[])
{
	setlocale( LC_CTYPE, "jpn" );

	// 実行パスを取得する
	::PathRemoveFileSpecA(argv[0]);
	char runPath[1024];
	memset(runPath, '\0', 1024);
	strcat_s(runPath, 1024, argv[0]);

	Gtk::Main kit( argc, argv );
	MyWindow window(runPath);
	Gtk::Main::run( window );
	return 0;
}
