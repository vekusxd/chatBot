#pragma once

#include <QObject>
#include <QSyntaxHighlighter>
#include <QTextCharFormat>

class SyntaxHiglighter : public QSyntaxHighlighter{
    Q_OBJECT

public:
    explicit SyntaxHiglighter(QTextDocument *parent = nullptr);

private:
    QStringList mathCommands;
    QStringList commonCommands;

    // QSyntaxHighlighter interface
protected:
    void highlightBlock(const QString &text) override;
};
