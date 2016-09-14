#include <glibmm.h>
#include "MyWindow.h"
#include <stdio.h>
#include <stdlib.h>
MyWindow::MyWindow(char* runPath)
{
	// ファイル作成
	// STLのfstreamでなくFILE*を使う。
	// 理由はSTLがスレッドセーフでないからエラーになってしまうため。
	// gtkmmはマルチスレッドらしい。
	memset(m_runPath, '\0', 1024);
	strcpy_s(m_runPath, 1024, runPath);
	strcat_s(m_runPath, 1024, "\\entry.log");

	// ファイルが存在しないとき
	if ((m_fp = fopen(m_runPath, "r")) == NULL) {
		g_print("file not exist. created file 'entry.log'\n");
		// ファイルを新規作成する
		if ((m_fp = fopen(m_runPath, "a")) == NULL) {
			g_print("failed create file !!\n");
			exit(EXIT_FAILURE);
		}
		// BOMを書く
		unsigned char BOM[3];
		BOM[0] = 0xEF;
		BOM[1] = 0xBB;
		BOM[2] = 0xBF;
		fwrite(BOM, 1, 3, m_fp);
	}
	// ファイルが存在するとき
	else {
		fclose(m_fp);
		// ファイルが開けないとき（メモリ不足時）
		if ((m_fp = fopen(m_runPath, "a")) == NULL) {
			g_print("failed file open 'entry.log'\n");
			exit(EXIT_FAILURE);
		}
	}

	m_entry.set_text(Glib::locale_to_utf8("Gtk::Entry テキストボックス"));
	m_entry.signal_activate().connect(sigc::mem_fun( *this, &MyWindow::on_activate ) );
	add( m_entry );
	show_all_children();
}
MyWindow::~MyWindow(void)
{
	fclose(m_fp);
}
void MyWindow::on_activate()
{
	if (NULL == m_fp) {
		Gtk::MessageDialog( m_entry.get_text() ).run();
	} else {
		fprintf(m_fp, "%s\0", m_entry.get_text().c_str());
		fprintf(m_fp, "\n");
		fflush(m_fp);
	}
}