#include <QtTest/QtTest>
#include <D:\TEST\natkaaaa\sapr-bntu-Mediaplayer-7e902b2\mainwindow.h>

class TestQString: public QObject
{
    Q_OBJECT
private slots:
    void toUpper();
    void test1();
    void test2();
    void test3();
    void test4();
   void test5();

};

void TestQString::test1()
{
 MainWindow TEST;
TEST.curentIndex = 1;
TEST.next();
QCOMPARE(TEST.curentIndex,2);
}
void TestQString::test2()
{ MainWindow TEST2;
    TEST2.curentIndex=1;
        TEST2.play();
    QCOMPARE(TEST2.curentIndex,1);
}
void TestQString::test3()
{ MainWindow TEST3;
    TEST3.curentIndex=2;
        TEST3.prev();
    QCOMPARE(TEST3.curentIndex,1);
}

void TestQString::test4()
{ MainWindow TEST4;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Playlist.s3db");
    db.open();
            QSqlQuery query;
            query.exec("DELETE from tablica");
            TEST4.Insert("D:/MUSIC/Disco/ATB.mp3");
            query.exec("SELECT * from tablica");
            query.numRowsAffected();

    QCOMPARE(query.numRowsAffected(),1);
}

void TestQString::test5()
{ MainWindow TEST5;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Playlist.s3db");
    db.open();
            QSqlQuery query;
            query.exec("SELECT * from tablica");
            query.first();
            qDebug()<<query.record().field("ID").value().toInt();
            TEST5.currentid=query.record().indexOf("ID");
            TEST5.delete1();
            query.exec("SELECT * from tablica");
            query.numRowsAffected();

    QCOMPARE(query.numRowsAffected(),0);
}

void TestQString::toUpper()
{
    QString str = "Hello";
    QCOMPARE(str.toUpper(), QString("HELLO"));
}

QTEST_MAIN(TestQString)
#include "testqstring.moc"
