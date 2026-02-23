#pragma once
#include <QMainWindow>
#include <QTableWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QDateTimeEdit>
#include <QPushButton>
#include "UIController.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = nullptr);

private slots:
    void onAddTask();
    void onGenerate();

private:
    void refreshTasksTable();
    void refreshSessionsTable();

    UIController m_controller;

    QLineEdit*   m_titleEdit{};
    QComboBox*   m_typeCombo{};
    QLineEdit*   m_durationEdit{};
    QDateTimeEdit* m_deadlineEdit{};
    QPushButton* m_addBtn{};
    QPushButton* m_generateBtn{};

    QTableWidget* m_tasksTable{};
    QTableWidget* m_sessionsTable{};
};
