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


#ifndef KONSOLEWIDGET_H
#define KONSOLEWIDGET_H

#include <KParts/MainWindow>
#include <QtGui/QWidget>



class KonsoleWidget : public KParts::MainWindow
{
Q_OBJECT

public:
KonsoleWidget();
virtual ~KonsoleWidget();

private:
  KParts::ReadOnlyPart* m_part;
  void loadKonsole();
  
private slots:
  void slotKonsoleDestroyed();
};

#endif // KONSOLEWIDGET_H
