#ifndef PLUGINLISTEDITOR_H
#define PLUGINLISTEDITOR_H

#include <QMainWindow>

namespace Ui {
    class PluginListEditor;
}

class PluginListEditor : public QMainWindow
{
    Q_OBJECT

public:
    explicit PluginListEditor(QString filepath);
    ~PluginListEditor();

private:
    Ui::PluginListEditor *ui;
    QString filepath;

public slots:
    void saveIt();
    void newPlugin();
};

#endif // PLUGINLISTEDITOR_H
