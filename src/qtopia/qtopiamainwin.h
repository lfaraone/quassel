/***************************************************************************
 *   Copyright (C) 2005-07 by The Quassel IRC Development Team             *
 *   devel@quassel-irc.org                                                 *
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
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef _QTOPIAMAINWIN_H_
#define _QTOPIAMAINWIN_H_

#include <QtGui>

#include "client.h"
#include "global.h"

class BufferViewWidget;
class MainWidget;

class QtopiaMainWin : public QMainWindow {
  Q_OBJECT

  public:
    QtopiaMainWin(QWidget *parent = 0, Qt::WFlags f = 0);
    ~QtopiaMainWin();

    AbstractUiMsg *layoutMsg(const Message &);

  protected slots:
    void connectedToCore();
    void disconnectedFromCore();

  signals:
    void connectToCore(const QVariantMap &connInfo);
    void disconnectFromCore();
    void requestBacklog(BufferInfo, QVariant, QVariant);

  private slots:
    void showBuffer(Buffer *);
    void showBufferView();

  private:
    void init();
    void setupActions();

    MainWidget *mainWidget;
    QToolBar *toolBar;
    QAction *showBuffersAction;
    BufferViewWidget *bufferViewWidget;

    friend class QtopiaUi;
};

#endif
