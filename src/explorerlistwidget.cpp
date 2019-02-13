#include <QListWidget>
#include <string>

#include "explorerlistwidget.h"
#include "explorerlistitem.h"
#include "termwidgetholder.h"

ExplorerListWidget::ExplorerListWidget(TermWidgetHolder &termWidgetHolder) :
    QListWidget (),
    m_termWidgetHolder(termWidgetHolder)
{
    addItem(new ExplorerListItem("Element1"));
    addItem(new ExplorerListItem("Element2"));
    addItem(new ExplorerListItem("Element3"));
    addItem(new ExplorerListItem("Element4"));
    addItem(new ExplorerListItem("Element5"));
    addItem(new ExplorerListItem("Element6"));
    addItem(new ExplorerListItem("Element7"));
    addItem(new ExplorerListItem("Element8"));
}

void ExplorerListWidget::setCurrentDirectory()
{
    changeDirectory("telecom-robotics");
}

void ExplorerListWidget::changeDirectory(QString filename)
{
    TermWidget *terminal = m_termWidgetHolder.currentTerminal();
    terminal->sendText("\003\ncd " + filename + "\n");
}


