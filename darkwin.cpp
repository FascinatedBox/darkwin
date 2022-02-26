#include <QApplication>
#include <QWidget>

void usage()
{
    fprintf(stderr, "Usage: darkwin x,y widthxheight\n");
    exit(EXIT_FAILURE);
}

void parsePair(char *s, const char *delim, int *left, int *right)
{
    QString str = QString(s);
    QStringList splitStr = str.split(delim);

    if (splitStr.size() != 2)
        usage();

    bool validLeft, validRight;

    *left = splitStr[0].toInt(&validLeft, 10);
    *right = splitStr[1].toInt(&validRight, 10);

    if (validLeft == false || validRight == false)
        usage();
}

int main(int argc, char **argv)
{
    if (argc != 3)
        usage();

    int x, y;
    int width, height;

    parsePair(argv[1], ",", &x, &y);
    parsePair(argv[2], "x", &width, &height);

    QApplication app(argc, argv);
    QWidget *w = new QWidget;

    w->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnBottomHint);
    w->setStyleSheet("background-color: #000000");
    w->move(x, y);
    w->resize(width, height);
    w->show();
    app.exec();
}
