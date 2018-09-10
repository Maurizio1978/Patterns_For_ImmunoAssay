#ifndef READER_H
#define READER_H
#include <QObject>

class Reader : public QObject
{
    Q_OBJECT

public:
    Reader();
    ~Reader();

public slots:
    void Initialize();

signals:
    void InitializationStarted();
    void Initialized();
};

#endif // READER_H
