/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) 2011  <copyright holder> <email>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include "konsolewidget.h"
#include <KParts/Part>
#include <KService>
#include <KLibLoader>
#include <KMessageBox>
#include <kde_terminal_interface.h>

KonsoleWidget::KonsoleWidget() : m_part(0)
{
//setupGUI(ToolBar | Keys | StatusBar, "/home/israel/src/plasmoids/embeddedterminal/build/mykonsoleui.rc");
  loadKonsole();
  connect(m_part, SIGNAL(destroyed(QObject*)), SLOT(close()));
  resize(600, 400);
}

KonsoleWidget::~KonsoleWidget()
{

}

void KonsoleWidget::loadKonsole()
{
  
  KService::Ptr service = KService::serviceByDesktopPath("konsolepart.desktop");
  
  if (service){
    m_part = service->createInstance<KParts::ReadOnlyPart>(0);
    if (m_part) {
      setCentralWidget(m_part->widget());
      
      TerminalInterface* interface = qobject_cast< TerminalInterface* >(m_part);
      Q_ASSERT(interface);
      interface->showShellInDir(QString ());
    }
    else{ 
      KMessageBox::error(this, "No part!");
    }
  }
  
  else {
    KMessageBox::error(this, "service konsolepart.desktop not found");
  }
}

void KonsoleWidget::slotKonsoleDestroyed()
{
  m_part = 0;
  loadKonsole();
}

#include "konsolewidget.moc"
