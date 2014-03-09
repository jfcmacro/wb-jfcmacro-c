#include <kapp.h>
#include <klocale.h>
#include <qpushbutton.h>
 
int main( int argc, char **argv )
{
    KApplication a( argc, argv , "Programa 2");
 
    QPushButton *hello=new QPushButton( i18n("Hello World !"), 0 );
    hello->setAutoResize( TRUE );
 
    QObject::connect( hello, SIGNAL(clicked()), &a, SLOT(quit()) );
 
    a.setMainWidget( hello );
    hello->show();
 
    return a.exec();
} 
