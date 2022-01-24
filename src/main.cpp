#include "../include/LogIn.h"
#include <string.h>
#include <QApplication>

int main(int argc, char *argv[]) {   

  QApplication a(argc, argv);
  MainWindow newMainWindow;
  LogIn newLogInWindow;
  Account tempAccount;
  bool checkStart = false;

  if(argc == 2){
      if(!strcmp(argv[1], "admin")) {          
          checkStart = true;
          tempAccount.setAdmin();
          newMainWindow.setUser(&tempAccount);
          newMainWindow.show();
      } else if (!strcmp(argv[1], "user")) {
          checkStart = true;
          tempAccount.setNormalUser();
          newMainWindow.setUser(&tempAccount);
          newMainWindow.show();
      }
  }
  if(!checkStart)
    newLogInWindow.show();

  return a.exec();
}
