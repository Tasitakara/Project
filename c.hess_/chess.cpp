#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QWidget>
#include <QLayout>
#include <QLayoutItem>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QObject>
#include <QDebug>



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    QVBoxLayout start_layout;
    QWidget window;

// Create a label and two buttons for the chess game
    QLabel label("Chess Game");
    label.resize(1000, 1600);
    label.show();

    QPushButton startButton("Start");
    QPushButton exitButton("Exit");

    start_layout.addWidget(&label);
    start_layout.addWidget(&startButton);
    start_layout.addWidget(&exitButton);

    window.setLayout(&start_layout);
    window.show();

    return app.exec();
}