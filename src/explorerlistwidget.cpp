#include <QListWidget>
#include <string>
#include <iostream>

#include "explorerlistwidget.h"
#include "termwidgetholder.h"

ExplorerListWidget::ExplorerListWidget(TermWidgetHolder &termWidgetHolder) :
    QListWidget (),
    m_termWidgetHolder(termWidgetHolder)
{
    connect(this, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT(changeDirectory(QListWidgetItem *)));
}

void ExplorerListWidget::updateCurrentDirectory()
{
    QString newDir = workingDirectory();
    if(newDir != m_workingDirectory)
    {
        m_workingDirectory = newDir;
        setToolTip(m_workingDirectory);

        for(unsigned int i = 0; i < m_items.size(); i++)
        {
            removeItemWidget(m_items[i]);
            delete m_items[i];
        }

        m_items.clear();

        QFileInfoList itemsInfo = QDir(m_workingDirectory).entryInfoList();

        for(int i = 0; i < itemsInfo.size(); i++)
        {
            QFileInfo file = itemsInfo[i];
            ExplorerListItem *item = new ExplorerListItem(file.fileName());
            m_items.push_back(item);
            addItem(item);
        }
    }
}

void ExplorerListWidget::changeDirectory(QListWidgetItem *item)
{
    QDir directory(m_workingDirectory + "/" + item->text());
    if(directory.exists())
    {
        changeDirectory(item->text());
    }
}

void ExplorerListWidget::changeDirectory(QString dir)
{
    TermWidget *terminal = m_termWidgetHolder.currentTerminal();
    if(terminal != nullptr)
    {
        terminal->impl()->changeDir(dir);
    }
}

QString ExplorerListWidget::workingDirectory()
{
    TermWidget *terminal = m_termWidgetHolder.currentTerminal();
    if(terminal == nullptr) return "";
    return terminal->impl()->workingDirectory();
}


