#include "../include/helpcommandswidget.hpp"
#include <QVBoxLayout>

HelpCommandsWidget::HelpCommandsWidget(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    view = new QListView;
    model = new CommandModel;

    view->setModel(model);

    mainLayout->addWidget(view);
    connect(view, &QListView::doubleClicked, this, &HelpCommandsWidget::onDoubleClickedView);
}

void HelpCommandsWidget::onDoubleClickedView(const QModelIndex& index)
{
    int indexRow = index.row();
    emit sendClickedCommand(model->getCommandItem(indexRow).getTitle());
}
