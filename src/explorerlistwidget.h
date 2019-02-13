#ifndef EXPLORERLISTWIDGET_H
#define EXPLORERLISTWIDGET_H

#include <QListWidget>
#include <vector>

#include "termwidgetholder.h"
#include "explorerlistitem.h"

class ExplorerListWidget : public QListWidget
{
    Q_OBJECT
public:
    ExplorerListWidget(TermWidgetHolder &termWidgetHolder);

public slots:
    void updateCurrentDirectory();

private slots:
    void changeDirectory(QListWidgetItem *item);

private:
    QString workingDirectory();
    void changeDirectory(QString filename);

    QString m_workingDirectory;
    TermWidgetHolder &m_termWidgetHolder;
    std::vector<ExplorerListItem *> m_items;
};

#endif // EXPLORERLISTWIDGET_H
