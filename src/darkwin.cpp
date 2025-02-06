#include <QApplication>
#include <QCommandLineParser>
#include <QWidget>

typedef struct {
    int x;
    int y;
    int width;
    int height;
    int color;
} Options;

#define DEFINE_POSARG(argName, argDesc) \
parser.addPositionalArgument(argName, \
    QCoreApplication::translate("main", argDesc));

Options *parseArgs(QApplication *app, int argc, char **argv)
{
    QCommandLineParser parser;
    parser.setApplicationDescription("Create borderless window");
    parser.addHelpOption();
    parser.addVersionOption();
    DEFINE_POSARG("x",      "Window x coordinate")
    DEFINE_POSARG("y",      "Window y coordinate")
    DEFINE_POSARG("height", "Window height")
    DEFINE_POSARG("width",  "Window width")

    QCommandLineOption colorOption("c",
            QCoreApplication::translate("main",
                "hex color (RRGGBB) (default: 000000)"),
            QCoreApplication::translate("main", "color"));
    parser.addOption(colorOption);
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

    QString colorStr = parser.value(colorOption);
    int color = 0;

    if (colorStr.size() == 6 && colorStr[1] != 'x')
        color = colorStr.toInt(nullptr, 16);

    result->color = color;
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
    w->setStyleSheet(QString("background-color: #%1").arg(o->color, 6, 16,
            QChar('0')));
    w->move(o->x, o->y);
    w->resize(o->width, o->height);
    w->show();
    app.exec();
}
