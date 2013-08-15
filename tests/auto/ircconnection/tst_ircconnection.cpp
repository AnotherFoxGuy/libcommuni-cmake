/*
 * Copyright (C) 2008-2013 The Communi Project
 *
 * This test is free, and not covered by the LGPL license. There is no
 * restriction applied to their modification, redistribution, using and so on.
 * You can study them, modify them, use them in your own program - either
 * completely or partially.
 */

#include "irc.h"
#include "irccommand.h"
#include "ircconnection.h"
#include "ircmessage.h"
#include <QtTest/QtTest>
#include <QtCore/QTextCodec>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#ifndef QT_NO_OPENSSL
#include <QtNetwork/QSslSocket>
#endif

class tst_IrcConnection : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void cleanupTestCase();

    void testDefaults();

    void testHost_data();
    void testHost();

    void testPort_data();
    void testPort();

    void testUserName_data();
    void testUserName();

    void testNickName_data();
    void testNickName();

    void testRealName_data();
    void testRealName();

    void testEncoding_data();
    void testEncoding();

    void testSocket_data();
    void testSocket();

    void testConnection();
    void testSendCommand();
    void testSendData();

private:
    QTcpServer server;
};

void tst_IrcConnection::initTestCase()
{
    server.listen();
}

void tst_IrcConnection::cleanupTestCase()
{
    server.close();
}

void tst_IrcConnection::testDefaults()
{
    IrcConnection connection;
    QVERIFY(connection.host().isNull());
    QCOMPARE(connection.port(), 6667);
    QVERIFY(connection.userName().isNull());
    QVERIFY(connection.nickName().isNull());
    QVERIFY(connection.realName().isNull());
    QCOMPARE(connection.encoding(), QByteArray("ISO-8859-15"));
    QVERIFY(connection.socket());
    QVERIFY(connection.socket()->inherits("QAbstractSocket"));
}

void tst_IrcConnection::testHost_data()
{
    QTest::addColumn<QString>("host");

    QTest::newRow("null") << QString();
    QTest::newRow("empty") << QString("");
    QTest::newRow("space") << QString(" ");
    QTest::newRow("invalid") << QString("invalid");
    QTest::newRow(qPrintable(server.serverAddress().toString())) << server.serverAddress().toString();
}

void tst_IrcConnection::testHost()
{
    QFETCH(QString, host);

    IrcConnection connection;
    connection.setHost(host);
    QCOMPARE(connection.host(), host);
}

void tst_IrcConnection::testPort_data()
{
    QTest::addColumn<int>("port");

    QTest::newRow("-1") << -1;
    QTest::newRow("0") << 0;
    QTest::newRow("6666") << 6666;
    QTest::newRow("6667") << 6667;
    QTest::newRow("6668") << 6668;
    QTest::newRow(qPrintable(QString::number(server.serverPort()))) << static_cast<int>(server.serverPort());
}

void tst_IrcConnection::testPort()
{
    QFETCH(int, port);

    IrcConnection connection;
    connection.setPort(port);
    QCOMPARE(connection.port(), port);
}

void tst_IrcConnection::testUserName_data()
{
    QTest::addColumn<QString>("name");
    QTest::addColumn<QString>("result");

    QTest::newRow("null") << QString() << QString();
    QTest::newRow("empty") << QString("") << QString("");
    QTest::newRow("space") << QString(" ") << QString("");
    QTest::newRow("spaces") << QString(" foo bar ") << QString("foo");
}

void tst_IrcConnection::testUserName()
{
    QFETCH(QString, name);
    QFETCH(QString, result);

    IrcConnection connection;
    connection.setUserName(name);
    QCOMPARE(connection.userName(), result);
}

void tst_IrcConnection::testNickName_data()
{
    QTest::addColumn<QString>("name");
    QTest::addColumn<QString>("result");

    QTest::newRow("null") << QString() << QString();
    QTest::newRow("empty") << QString("") << QString("");
    QTest::newRow("space") << QString(" ") << QString("");
    QTest::newRow("spaces") << QString(" foo bar ") << QString("foo");
}

void tst_IrcConnection::testNickName()
{
    QFETCH(QString, name);
    QFETCH(QString, result);

    IrcConnection connection;
    connection.setNickName(name);
    QCOMPARE(connection.nickName(), result);
}

void tst_IrcConnection::testRealName_data()
{
    QTest::addColumn<QString>("name");
    QTest::addColumn<QString>("result");

    QTest::newRow("null") << QString() << QString();
    QTest::newRow("empty") << QString("") << QString("");
    QTest::newRow("space") << QString(" ") << QString(" ");
    QTest::newRow("spaces") << QString(" foo bar ") << QString(" foo bar ");
}

void tst_IrcConnection::testRealName()
{
    QFETCH(QString, name);
    QFETCH(QString, result);

    IrcConnection connection;
    connection.setRealName(name);
    QCOMPARE(connection.realName(), result);
}

void tst_IrcConnection::testEncoding_data()
{
    QTest::addColumn<QByteArray>("encoding");
    QTest::addColumn<QByteArray>("actual");

    QTest::newRow("null") << QByteArray() << QByteArray("ISO-8859-15");
    QTest::newRow("empty") << QByteArray("") << QByteArray("ISO-8859-15");
    QTest::newRow("space") << QByteArray(" ") << QByteArray("ISO-8859-15");
    QTest::newRow("invalid") << QByteArray("invalid") << QByteArray("ISO-8859-15");
    foreach (const QByteArray& codec, QTextCodec::availableCodecs())
        QTest::newRow(codec) << codec << codec;
}

void tst_IrcConnection::testEncoding()
{
    QFETCH(QByteArray, encoding);
    QFETCH(QByteArray, actual);

    IrcConnection connection;
    connection.setEncoding(encoding);
    QCOMPARE(connection.encoding(), actual);
}

Q_DECLARE_METATYPE(QAbstractSocket*)
void tst_IrcConnection::testSocket_data()
{
    QTest::addColumn<QAbstractSocket*>("socket");

    QTest::newRow("null") << static_cast<QAbstractSocket*>(0);
    QTest::newRow("tcp") << static_cast<QAbstractSocket*>(new QTcpSocket(this));
#ifndef QT_NO_OPENSSL
    QTest::newRow("ssl") << static_cast<QAbstractSocket*>(new QSslSocket(this));
#endif
}

void tst_IrcConnection::testSocket()
{
    QFETCH(QAbstractSocket*, socket);

    IrcConnection connection;
    connection.setSocket(socket);
    QCOMPARE(connection.socket(), socket);
}

Q_DECLARE_METATYPE(QString*)
Q_DECLARE_METATYPE(IrcMessage*)
void tst_IrcConnection::testConnection()
{
    qRegisterMetaType<QString*>();
    qRegisterMetaType<IrcMessage*>();

    IrcConnection connection;
    QSignalSpy connectingSpy(&connection, SIGNAL(connecting()));
    QSignalSpy connectedSpy(&connection, SIGNAL(connected()));
    QSignalSpy disconnectedSpy(&connection, SIGNAL(disconnected()));
    QSignalSpy messageReceivedSpy(&connection, SIGNAL(messageReceived(IrcMessage*)));

    QVERIFY(connectingSpy.isValid());
    QVERIFY(connectedSpy.isValid());
    QVERIFY(disconnectedSpy.isValid());
    QVERIFY(messageReceivedSpy.isValid());

    connection.setUserName("user");
    connection.setNickName("nick");
    connection.setRealName("real");
    connection.setHost(server.serverAddress().toString());
    connection.setPort(server.serverPort());

    connection.open();
    QVERIFY(server.waitForNewConnection(2000));
    QTcpSocket* serverSocket = server.nextPendingConnection();
    QVERIFY(serverSocket);

    QVERIFY(connection.socket()->waitForConnected());
    QCOMPARE(connectingSpy.count(), 1);

    QVERIFY(serverSocket->write(":irc.ser.ver 001 nick :Welcome to the Internet Relay Chat Network nick\r\n"));
    QVERIFY(serverSocket->waitForBytesWritten());
    QVERIFY(connection.socket()->waitForReadyRead());
    QCOMPARE(connectedSpy.count(), 1);

    connection.close();
    connection.socket()->waitForDisconnected();
    QCOMPARE(disconnectedSpy.count(), 1);
}

void tst_IrcConnection::testSendCommand()
{
    IrcConnection connection;
    QVERIFY(!connection.sendCommand(0));
    QVERIFY(!connection.sendCommand(IrcCommand::createQuit()));

    connection.setUserName("user");
    connection.setNickName("nick");
    connection.setRealName("real");
    connection.setHost(server.serverAddress().toString());
    connection.setPort(server.serverPort());
    connection.open();
    QVERIFY(connection.socket()->waitForConnected());

    QVERIFY(!connection.sendCommand(0));
    QVERIFY(connection.sendCommand(IrcCommand::createQuit()));
    connection.close();
}

void tst_IrcConnection::testSendData()
{
    IrcConnection connection;
    QVERIFY(!connection.sendData("QUIT"));

    connection.setUserName("user");
    connection.setNickName("nick");
    connection.setRealName("real");
    connection.setHost(server.serverAddress().toString());
    connection.setPort(server.serverPort());
    connection.open();
    QVERIFY(connection.socket()->waitForConnected());

    QVERIFY(connection.sendData("QUIT"));
    connection.close();
}

QTEST_MAIN(tst_IrcConnection)

#include "tst_ircconnection.moc"