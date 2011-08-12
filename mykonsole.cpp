#include "konsolewidget.h"
#include <KApplication>
#include <KCmdLineArgs>
#include <KAboutData>

int main(int argc, char* argv[])
{
  KAboutData aboutData( "mykonsole", "mykonsole",
        ki18n("Terminal"), "0.1",
        ki18n("A MainWindow for a KonsolePart."),
        KAboutData::License_GPL,
        ki18n("Copyright (c) 2011 Developer") );
  
  KCmdLineArgs::init(argc, argv, &aboutData);
  KApplication app;
  KonsoleWidget* konsole = new KonsoleWidget;
  konsole->show();
  return app.exec();
}