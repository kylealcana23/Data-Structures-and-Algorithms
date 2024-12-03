#include <QApplication>
#include <QMainWindow>
#include <QStack>
#include <QQueue>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QComboBox>
#include <QLabel>
#include <QFont>
#include <QIcon>
#include <QStatusBar>
#include <QGraphicsDropShadowEffect>

class LibraryManagementSystem : public QMainWindow
{
    Q_OBJECT

public:
    LibraryManagementSystem(QWidget *parent = nullptr) : QMainWindow(parent)
    {
        // Set main window properties
        setWindowTitle("Library Management System");
        setWindowIcon(QIcon(":/icons/library_icon.png"));
        resize(800, 600);

        // Create central widget and layout
        QWidget *centralWidget = new QWidget(this);
        setCentralWidget(centralWidget);
        QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

        // Header (App Name)
        QLabel *headerLabel = new QLabel("Library Management System", this);
        headerLabel->setAlignment(Qt::AlignCenter);
        QFont headerFont("Arial", 24, QFont::Bold);
        headerLabel->setFont(headerFont);
        headerLabel->setStyleSheet("color: #4CAF50; margin-bottom: 20px;");
        mainLayout->addWidget(headerLabel);

        // Create layouts for buttons and text areas
        QHBoxLayout *buttonLayout = new QHBoxLayout();

        // Create buttons with icons and styled text
        QPushButton *pushButton = new QPushButton("Add Return (Push)", this);
        QPushButton *popButton = new QPushButton("Remove Return (Pop)", this);
        QPushButton *enqueueButton = new QPushButton("Add Reservation (Enqueue)", this);
        QPushButton *dequeueButton = new QPushButton("Remove Reservation (Dequeue)", this);

        pushButton->setIcon(QIcon(":/icons/return_icon.png"));
        popButton->setIcon(QIcon(":/icons/remove_icon.png"));
        enqueueButton->setIcon(QIcon(":/icons/reservation_icon.png"));
        dequeueButton->setIcon(QIcon(":/icons/queue_icon.png"));

        buttonLayout->addWidget(pushButton);
        buttonLayout->addWidget(popButton);
        buttonLayout->addWidget(enqueueButton);
        buttonLayout->addWidget(dequeueButton);

        // Add buttons to the layout
        mainLayout->addLayout(buttonLayout);

        // Create text areas to display stack and queue contents
        stackTextEdit = new QTextEdit(this);
        queueTextEdit = new QTextEdit(this);
        stackTextEdit->setPlaceholderText("No recent returns");
        queueTextEdit->setPlaceholderText("No reservations");
        stackTextEdit->setReadOnly(true);
        queueTextEdit->setReadOnly(true);

        // Apply initial styling (default theme)
        applyLightTheme();

        // Add text areas to layout
        mainLayout->addWidget(stackTextEdit);
        mainLayout->addWidget(queueTextEdit);

        // Add Status Bar
        statusBar()->showMessage("Welcome to the Library Management System");

        // Add shadow effect to buttons
        applyShadowEffect(pushButton);
        applyShadowEffect(popButton);
        applyShadowEffect(enqueueButton);
        applyShadowEffect(dequeueButton);

        // Connect signals to slots
        connect(pushButton, &QPushButton::clicked, this, &LibraryManagementSystem::onPushButtonClicked);
        connect(popButton, &QPushButton::clicked, this, &LibraryManagementSystem::onPopButtonClicked);
        connect(enqueueButton, &QPushButton::clicked, this, &LibraryManagementSystem::onEnqueueButtonClicked);
        connect(dequeueButton, &QPushButton::clicked, this, &LibraryManagementSystem::onDequeueButtonClicked);
    }

private slots:
    // Push to stack
    void onPushButtonClicked() {
        bookStack.push("Book #" + QString::number(bookStack.size() + 1));
        updateStackDisplay();
        showStatusMessage("A book has been returned.");
    }

    // Pop from stack
    void onPopButtonClicked() {
        if (!bookStack.isEmpty()) {
            bookStack.pop();
            updateStackDisplay();
            showStatusMessage("A book has been removed from the returns.");
        }
    }

    // Enqueue to queue
    void onEnqueueButtonClicked() {
        reservationQueue.enqueue("Reservation #" + QString::number(reservationQueue.size() + 1));
        updateQueueDisplay();
        showStatusMessage("A reservation has been added.");
    }

    // Dequeue from queue
    void onDequeueButtonClicked() {
        if (!reservationQueue.isEmpty()) {
            reservationQueue.dequeue();
            updateQueueDisplay();
            showStatusMessage("A reservation has been processed.");
        }
    }

private:
    // Update the stack display
    void updateStackDisplay() {
        QString stackContents;
        foreach (const QString &book, bookStack) {
            stackContents += book + "\n";
        }
        stackTextEdit->setPlainText(stackContents.isEmpty() ? "No recent returns" : stackContents);
    }

    // Update the queue display
    void updateQueueDisplay() {
        QString queueContents;
        foreach (const QString &reservation, reservationQueue) {
            queueContents += reservation + "\n";
        }
        queueTextEdit->setPlainText(queueContents.isEmpty() ? "No reservations" : queueContents);
    }

    // Show status message
    void showStatusMessage(const QString &message) {
        statusBar()->showMessage(message, 3000);  // Message stays for 3 seconds
    }

    // Apply shadow effect to buttons for a modern look
    void applyShadowEffect(QWidget *widget) {
        QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect;
        shadowEffect->setBlurRadius(15);
        shadowEffect->setColor(Qt::black);
        shadowEffect->setOffset(3, 3);
        widget->setGraphicsEffect(shadowEffect);
    }

    // Apply light theme (default theme)
    void applyLightTheme() {
        QString styleSheet = R"(
            QWidget {
                font-family: 'Segoe UI', sans-serif;
                font-size: 14pt;
                background-color: #fafafa;
                color: #333;
                border-radius: 12px;
            }
            QPushButton {
                background-color: #4CAF50;
                color: white;
                border-radius: 12px;
                padding: 12px 24px;
                margin: 8px;
                font-size: 14pt;
                box-shadow: 0px 4px 8px rgba(0, 0, 0, 0.2);
            }
            QPushButton:hover {
                background-color: #45a049;
            }
            QPushButton:pressed {
                background-color: #388e3c;
            }
            QTextEdit {
                background-color: #fff;
                border: 2px solid #ccc;
                border-radius: 8px;
                padding: 10px;
                font-size: 12pt;
                margin-top: 15px;
                box-shadow: 0px 2px 5px rgba(0, 0, 0, 0.1);
            }
            QWidget#centralWidget {
                background: #fafafa;
                border-radius: 15px;
                padding: 20px;
            }
        )";
        this->setStyleSheet(styleSheet);
    }

private:
    QStack<QString> bookStack;
    QQueue<QString> reservationQueue;
    QTextEdit *stackTextEdit;
    QTextEdit *queueTextEdit;
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LibraryManagementSystem w;
    w.show();
    return a.exec();
}

#include "main.moc"
