#include "MainWindow.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QMessageBox>
#include <QDateTime>

using namespace std::chrono;

static system_clock::time_point toSys(const QDateTime& dt) {
    return system_clock::time_point(seconds(dt.toSecsSinceEpoch()));
}

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    auto* central = new QWidget(this);
    setCentralWidget(central);
    auto* root = new QVBoxLayout(central);

    // Form
    auto* form = new QFormLayout();
    m_titleEdit = new QLineEdit(this);

    m_typeCombo = new QComboBox(this);
    m_typeCombo->addItem("Assignment", static_cast<int>(TaskType::Assignment));
    m_typeCombo->addItem("Exam",       static_cast<int>(TaskType::Exam));
    m_typeCombo->addItem("Reading",    static_cast<int>(TaskType::Reading));

    m_durationEdit = new QLineEdit(this);
    m_durationEdit->setPlaceholderText("Minutes (e.g., 60)");
    m_deadlineEdit = new QDateTimeEdit(QDateTime::currentDateTime().addDays(1), this);
    m_deadlineEdit->setCalendarPopup(true);

    form->addRow("Title:", m_titleEdit);
    form->addRow("Type:", m_typeCombo);
    form->addRow("Duration:", m_durationEdit);
    form->addRow("Deadline:", m_deadlineEdit);

    // Buttons
    auto* btnRow = new QHBoxLayout();
    m_addBtn = new QPushButton("Add Task", this);
    m_generateBtn = new QPushButton("Generate Schedule", this);
    btnRow->addWidget(m_addBtn);
    btnRow->addWidget(m_generateBtn);

    // Tables
    m_tasksTable = new QTableWidget(this);
    m_tasksTable->setColumnCount(4);
    m_tasksTable->setHorizontalHeaderLabels({"Title", "Type", "Duration (min)", "Deadline"});
    m_tasksTable->horizontalHeader()->setStretchLastSection(true);

    m_sessionsTable = new QTableWidget(this);
    m_sessionsTable->setColumnCount(3);
    m_sessionsTable->setHorizontalHeaderLabels({"Task", "Start", "End"});
    m_sessionsTable->horizontalHeader()->setStretchLastSection(true);

    root->addLayout(form);
    root->addLayout(btnRow);
    root->addWidget(m_tasksTable);
    root->addWidget(m_sessionsTable);

    connect(m_addBtn, &QPushButton::clicked, this, &MainWindow::onAddTask);
    connect(m_generateBtn, &QPushButton::clicked, this, &MainWindow::onGenerate);

    setWindowTitle("Smart Study Buddy (D2)");
    resize(900, 700);
}

void MainWindow::onAddTask()
{
    bool ok = false;
    int minutes = m_durationEdit->text().toInt(&ok);
    if (!ok || minutes <= 0 || m_titleEdit->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Invalid Input", "Provide a title and positive duration (minutes).");
        return;
    }
    auto type = static_cast<TaskType>(m_typeCombo->currentData().toInt());
    auto title = m_titleEdit->text().trimmed().toStdString();
    auto deadline = toSys(m_deadlineEdit->dateTime());

    m_controller.addTask(type, title, minutes, deadline);
    refreshTasksTable();

    // clear title/duration for convenience
    m_titleEdit->clear();
    m_durationEdit->clear();
}

void MainWindow::onGenerate()
{
    m_controller.generate();
    refreshSessionsTable();
}

void MainWindow::refreshTasksTable()
{
    const auto& tasks = m_controller.engine().schedule().tasks();
    m_tasksTable->setRowCount(static_cast<int>(tasks.size()));
    int row = 0;
    for (const auto& t : tasks) {
        auto deadline = QDateTime::fromSecsSinceEpoch(
            duration_cast<seconds>(t->deadline().time_since_epoch()).count());

        m_tasksTable->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(t->title())));
        m_tasksTable->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(to_string(t->type()))));
        m_tasksTable->setItem(row, 2, new QTableWidgetItem(QString::number(t->durationMinutes())));
        m_tasksTable->setItem(row, 3, new QTableWidgetItem(deadline.toString(Qt::ISODate)));
        ++row;
    }
}

void MainWindow::refreshSessionsTable()
{
    const auto& sessions = m_controller.engine().schedule().sessions();
    m_sessionsTable->setRowCount(static_cast<int>(sessions.size()));
    int row = 0;
    for (const auto& s : sessions) {
        auto qStart = QDateTime::fromSecsSinceEpoch(
            duration_cast<seconds>(s.start().time_since_epoch()).count());
        auto qEnd = QDateTime::fromSecsSinceEpoch(
            duration_cast<seconds>(s.end().time_since_epoch()).count());

        m_sessionsTable->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(s.taskTitle())));
        m_sessionsTable->setItem(row, 1, new QTableWidgetItem(qStart.toString(Qt::ISODate)));
        m_sessionsTable->setItem(row, 2, new QTableWidgetItem(qEnd.toString(Qt::ISODate)));
        ++row;
    }
}
