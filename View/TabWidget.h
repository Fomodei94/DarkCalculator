#ifndef TABWIDGET_H
#define TABWIDGET_H

#include<QGridLayout>
#include<QTabWidget>

class TabWidget : public QWidget {
    Q_OBJECT
public:
    TabWidget(QWidget *parent);

private:
    QGridLayout *layout;
    QTabWidget *tabwid;

};

#endif // TABWIDGET_H
