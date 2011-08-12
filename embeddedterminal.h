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

// Here we avoid loading the header multiple times
#ifndef EMBEDDEDTERMINAL_HEADER
#define EMBEDDEDTERMINAL_HEADER

#include <Plasma/PopupApplet>
#include <QGraphicsWidget>

namespace KParts
{
  class ReadOnlyPart;
}

class embeddedterminal : public Plasma::PopupApplet
{
    Q_OBJECT
    public:
        embeddedterminal(QObject *parent, const QVariantList &args);
        ~embeddedterminal();
	void init();

//virtual QGraphicsWidget* graphicsWidget() {return m_widget;}

    private:
        QGraphicsWidget* m_widget;
	KParts::ReadOnlyPart* m_part;
	void load_terminal();
	
    private slots:
	void slotPartDestroyed();
};
 
// This is the command that links your applet to the .desktop file
K_EXPORT_PLASMA_APPLET(embeddedterminal, embeddedterminal)
#endif