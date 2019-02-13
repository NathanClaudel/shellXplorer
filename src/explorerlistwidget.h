#ifndef EXPLORERLISTWIDGET_H
#define EXPLORERLISTWIDGET_H

#include <QListWidget>

#include "termwidgetholder.h"

class ExplorerListWidget : public QListWidget
{
public:
    ExplorerListWidget(TermWidgetHolder &termWidgetHolder);
    void setCurrentDirectory();

private:
    TermWidgetHolder &m_termWidgetHolder;
    void changeDirectory(QString filename);
};

#endif // EXPLORERLISTWIDGET_H
