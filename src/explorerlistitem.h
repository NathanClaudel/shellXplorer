#ifndef EXPLORERLISTITEM_H
#define EXPLORERLISTITEM_H

#include <QListWidgetItem>

class QString;

class ExplorerListItem : public QListWidgetItem
{
public:
    ExplorerListItem(QString filename);
};

#endif // EXPLORERLISTITEM_H
