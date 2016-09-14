# このソフトウェアについて #

GlibUstringFile201609141732は私個人が学習目的で作成したソフトウェアです。

Gtk::WindowでFILE*をもちいてUTF-8ファイルを書き込む。

# 開発環境 #

* Windows XP Pro SP3 32bit
* VC++ 2010 Express
    * C++/Win32

## ライブラリ ##

* [Gtkmm 2.22](http://ftp.gnome.org/pub/GNOME/binaries/win32/gtkmm/2.22/gtkmm-win32-devel-2.22.0-2.exe)
    * GTKmm 2.4
        * GTK+ 2.22.0
    * glibmm 2.4
        * glib 2.0

# イメージ #

![Window](https://cdn-ak.f.st-hatena.com/images/fotolife/y/ytyaru/20160912/20160912231342.png)

# 説明 #

[前回](https://github.com/ytyaru/GtkOnFstream201609130731)、fstreamを使うとエラーになった。
STLがスレッドセーフでないことが原因。
GTKmmはマルチスレッドのようなので、STL内のクラスであるfstreamは使えない。

FILE構造体、fopen,fclose,fprintf関数をもちいることでファイル書込できた。
今回はエラーにならない。

書き出すファイルの先頭3バイトにはBOMを書き込んでおく。
Gtk::Entryで入力した値はUTF-8なので直接書き込んでいる。

# ライセンス #

このソフトウェアはCC0ライセンスです。

[![CC0](http://i.creativecommons.org/p/zero/1.0/88x31.png "CC0")](http://creativecommons.org/publicdomain/zero/1.0/deed.ja)
