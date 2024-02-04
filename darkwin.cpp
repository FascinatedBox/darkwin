#include <QApplication>
#include <QCommandLineParser>
#include <QWidget>

typedef struct {
    int x;
    int y;
    int width;
    int height;
} Options;

#define DEFINE_POSARG(argName, argDesc) \
parser.addPositionalArgument(argName, \
    QCoreApplication::translate("main", argDesc));

Options *parseArgs(QApplication *app, int argc, char **argv)
{
    QCommandLineParser parser;
    parser.setApplicationDescription("Create borderless black window");
    parser.addHelpOption();
    parser.addVersionOption();
    DEFINE_POSARG("x",      "Window x coordinate")
    DEFINE_POSARG("y",      "Window y coordinate")
    DEFINE_POSARG("height", "Window height")
    DEFINE_POSARG("width",  "Window width")
    parser.process(*app);

    QStringList args = parser.positionalArguments();
    Options *result = new Options;
    int i = 0;

    if (args.size() != 4)
        parser.showHelp(EXIT_FAILURE);

    result->x      = args.at(i).toInt(); i++;
    result->y      = args.at(i).toInt(); i++;
    result->height = args.at(i).toInt(); i++;
    result->width  = args.at(i).toInt(); i++;

    return result;
}

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QCoreApplication::setApplicationName("darkwin");
    QCoreApplication::setApplicationVersion("1.0");

    Options *o = parseArgs(&app, argc, argv);
    QWidget *w = new QWidget;

    w->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnBottomHint);
    w->setStyleSheet("background-color: #000000");
    w->move(o->x, o->y);
    w->resize(o->width, o->height);
    w->show();
    app.exec();
}
