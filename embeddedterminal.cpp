/***************************************************************************
 *   Copyright (C) %{CURRENT_YEAR} by %{AUTHOR} <%{EMAIL}>                            *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA .        *
 ***************************************************************************/

#include "embeddedterminal.h"

#include <QGraphicsLinearLayout>
#include <QGraphicsProxyWidget>
#include <Plasma/Label>

#include <KService>
#include <KMessageBox>
#include <kde_terminal_interface.h>
#include <KParts/Part>


embeddedterminal::embeddedterminal(QObject *parent, const QVariantList &args)
    : Plasma::PopupApplet(parent, args), m_widget(0)
{   
}


embeddedterminal::~embeddedterminal()
{
    if (hasFailedToLaunch()) {
        // Do some cleanup here
    } else {
        // Save settings
    }
}

void embeddedterminal::init()
{
    setAspectRatioMode(Plasma::IgnoreAspectRatio);
    load_terminal();
    
    QGraphicsProxyWidget* proxy = new QGraphicsProxyWidget;
    proxy->setWidget(m_part->widget());
    proxy->setMinimumSize(300, 300);
    
    QGraphicsLinearLayout* layout = new QGraphicsLinearLayout;
    layout->addItem(proxy);
    
    setLayout(layout);
    setPopupIcon("utilities-terminal");
    setGraphicsWidget(proxy);
    
    connect(m_part, SIGNAL(destroyed(QObject*)), SLOT(slotPartDestroyed()));
}


void embeddedterminal::load_terminal()
{
    KService::Ptr service = KService::serviceByDesktopPath("konsolepart.desktop");
    if (service){
      m_part = service->createInstance<KParts::ReadOnlyPart>(0);
      Q_ASSERT(m_part);
      TerminalInterface* interface = dynamic_cast< TerminalInterface* >(m_part);
      Q_ASSERT(interface);
      interface->showShellInDir(QString ()); 
    }
    else{
      KMessageBox::error(0, "Error... no konsole part loader!");
    }
}

void embeddedterminal::slotPartDestroyed()
{
  m_part = 0;
  load_terminal();
  QGraphicsProxyWidget* proxy = new QGraphicsProxyWidget;
  //proxy = qobject_cast< QGraphicsProxyWidget* > (graphicsWidget());
  //Q_ASSERT(proxy);
  proxy->setWidget(m_part->widget());
  proxy->setMinimumSize(300, 300);
  
  QGraphicsLinearLayout* layout = new QGraphicsLinearLayout;
  layout->addItem(proxy);
  
  setLayout(layout);
  setGraphicsWidget(proxy);
  
  connect(m_part, SIGNAL(destroyed(QObject*)), SLOT(slotPartDestroyed()));
}


/*
void embeddedterminal::on_shell_exit(int status)
{
  hidePopup();
}
*/

#include "embeddedterminal.moc"
