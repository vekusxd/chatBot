#include "../include/syntaxhighlighter.hpp"

SyntaxHiglighter::SyntaxHiglighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    mathCommands << "/сложить" << "/умножить" << "/разделить" << "/вычесть";
    commonCommands << "/погода" << "/очистить" << "/история";
}

void SyntaxHiglighter::highlightBlock(const QString &text)
{
    QStringList textList = text.split(' ');

    if(mathCommands.contains(text)){
        setFormat(0, text.size(), Qt::magenta);
        return;
    }
    else if(commonCommands.contains(text)){
        setFormat(0, text.size(), Qt::blue);
        return;
    }
    else{
        return;
    }

    //todo
}
