#ifndef TABWIDGET_H
#define TABWIDGET_H

#include<QGridLayout>
#include<QTabWidget>
#include"TabArma.h"

class TabWidget : public QWidget {
    Q_OBJECT
public:
    TabWidget(QWidget *parent);

private:
    QGridLayout *layout;
    QTabWidget *tabwid;
	TabArma* tabArma;
};

#endif // TABWIDGET_H
