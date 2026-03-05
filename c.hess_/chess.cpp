#include <iostream>
#include <cmath>
#include <QApplication>
#include <QCoreApplication>
#include <QPushButton>
#include <QLabel>
#include <QWidget>
#include <QLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QObject>
#include <QDebug>
#include <QFont>
#include <QResizeEvent>
#include <QChar>
#include <QStackedWidget>
using namespace std;

struct chess_piece
{
    int position_x;
    int position_y;
    int value;
    string role;
    QChar color;

    chess_piece(int x, int y, int v, string r, QChar c)
        : position_x(x), position_y(y), value(v), role(r), color(c){}
};
chess_piece White_Pieces[6] = {
    {0,0,1,"P",QChar(0x2659u)},
    {0,0,3,"N",QChar(0x2658u)},
    {0,0,3,"B",QChar(0x2657u)},
    {0,0,5,"R",QChar(0x2656u)},
    {0,0,9,"Q",QChar(0x2655u)},
    {0,0,0,"K",QChar(0x2654u)}
};
chess_piece Black_Pieces[6] = {
    {0,0,1,"P",QChar(0x2659u)},
    {0,0,3,"N",QChar(0x2658u)},
    {0,0,3,"B",QChar(0x2657u)},
    {0,0,5,"R",QChar(0x2656u)},
    {0,0,9,"Q",QChar(0x2655u)},
    {0,0,0,"K",QChar(0x2654u)}
};
class Window : public QWidget
{
public:
    QPushButton startButton;
    QPushButton settingsButton;
    QPushButton exitButton;
    QPushButton backButton;

    Window(QWidget *parent = nullptr) : QWidget(parent) {
        setWindowTitle("C.hess");
        resize(800, 600);
    }
protected:
    void resizeEvent(QResizeEvent *event) override {
        int w = event->size().width();
        int h = event->size().height();
        QFont font = this->font();
        font.setPointSize(min(w, h) / 20);
        QPushButton *buttons[] = {&startButton, &settingsButton, &exitButton, &backButton};
        for (QPushButton *button : buttons) {
            button->setFont(font);
        }
        QLabel *label = findChild<QLabel *>();
        if (label) {
            label->setFont(font);
            label->setAlignment(Qt::AlignCenter);
        }
    }
};
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QStackedWidget *stackedWidget = new QStackedWidget;
    Window start_window;
    Window settings_window;
    stackedWidget->addWidget(&start_window);
    stackedWidget->addWidget(&settings_window);
    QVBoxLayout *start_layout = new QVBoxLayout;
    QVBoxLayout *settings_layout = new QVBoxLayout;

    QLabel label("C.hess");
    start_window.startButton.setText("Start");
    start_window.settingsButton.setText("Settings");
    start_window.exitButton.setText("Exit");

    start_layout->addWidget(&label);
    start_layout->addWidget(&start_window.startButton);
    start_layout->addWidget(&start_window.settingsButton);
    start_layout->addWidget(&start_window.exitButton);

    start_window.setLayout(start_layout);
    start_window.resize(800, 600);
    start_window.show();
    start_window.setStyleSheet(
        "QPushButton { background-color: darkgray; } "
        "QPushButton:hover { background-color: white; color: black; }"
    );

    QLabel settings_label("Settings");
    settings_layout->addWidget(&settings_label);
    settings_window.setLayout(settings_layout);
    settings_window.backButton.setText("Back");

    QObject::connect(&start_window.startButton, &QPushButton::clicked, []() {
        qDebug() << "Start button clicked!";
    });

    QObject::connect(&start_window.settingsButton, &QPushButton::clicked, [stackedWidget, &settings_window]() {
        stackedWidget->setCurrentWidget(&settings_window);
    });

    QObject::connect(&start_window.exitButton, &QPushButton::clicked, []() {
        qDebug() << "Exit button clicked!";
        QCoreApplication::quit();
    });

    QObject::connect(&settings_window.backButton, &QPushButton::clicked, [stackedWidget, &start_window]() {
        stackedWidget->setCurrentWidget(&start_window);
    });



    return app.exec();
}