// Copyright 2016 Cutehacks AS. All rights reserved.
// License can be found in the LICENSE file.

#ifndef DUPERAGENT_H
#define DUPERAGENT_H

#include <QtCore/QObject>
#include <QtQml/QJSValue>
#include <QtQml/qqml.h>

class QQmlEngine;

namespace com::cutehacks::duperagent {

class ResponseType : public QObject {
    Q_OBJECT
    Q_ENUMS(Types)
public:
    enum Types {
        Auto        = 0,
        Text        = 1,
        Json        = 2,
        Blob        = 3,
        ArrayBuffer = 4
    };
};

class Request : public QObject
{
    Q_OBJECT

public:
    explicit Request(QQmlEngine *engine, QObject *parent = nullptr);

    Q_PROPERTY(QJSValue cookie READ cookie WRITE setCookie)

    Q_INVOKABLE [[maybe_unused]] static void config(const QJSValue &);

    Q_INVOKABLE [[maybe_unused]] [[nodiscard]] QJSValue get(const QJSValue&,
                              const QJSValue& = QJSValue(),
                              const QJSValue& = QJSValue()) const;
    Q_INVOKABLE [[maybe_unused]] [[nodiscard]] QJSValue head(const QJSValue&,
                              const QJSValue& = QJSValue(),
                              const QJSValue& = QJSValue()) const;
    Q_INVOKABLE [[maybe_unused]] [[maybe_unused]] [[nodiscard]] QJSValue del(const QJSValue&,
                              const QJSValue& = QJSValue()) const;
    Q_INVOKABLE [[maybe_unused]] [[nodiscard]] QJSValue patch(const QJSValue&,
                              const QJSValue& = QJSValue(),
                              const QJSValue& = QJSValue()) const;
    Q_INVOKABLE [[maybe_unused]] [[nodiscard]] QJSValue post(const QJSValue&,
                              const QJSValue& = QJSValue(),
                              const QJSValue& = QJSValue()) const;
    Q_INVOKABLE [[maybe_unused]] [[nodiscard]] QJSValue put(const QJSValue&,
                              const QJSValue& = QJSValue(),
                              const QJSValue& = QJSValue()) const;

    [[nodiscard]] QJSValue cookie() const;
    void setCookie(const QJSValue &);

    Q_INVOKABLE [[maybe_unused]] void clearCookies();

private:
    QQmlEngine *m_engine;
};

}

#endif // DUPERAGENT_H
